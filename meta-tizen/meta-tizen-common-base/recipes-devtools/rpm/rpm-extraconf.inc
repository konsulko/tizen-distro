SRC_URI += "file://disable_debuginfo.patch \
            file://disable_shortcircuited.patch \
            file://fix_libdir.patch \
            file://rpm-scriptetexechelp.patch \
            file://fix-python-rpm-conf.patch \
            file://rpmmodule.c.patch \
            file://python-rpm.Makefile.am.patch \
            file://pythondeps.sh \
           "

DEPENDS += "popt-native"
DEPENDS += "uthash-native"
DEPENDS += "smack-native"
DEPENDS += "acl-native"
DEPENDS += "lua-native"
DEPENDS += "python-native"
DEPENDS_remove = "make"
DEPENDS += "python"
DEPENDS_append_class-native = " libcap-native"
DEPENDS_append_class-target = " libcap"

CFLAGS_append = " -DRPM_VENDOR_OE "

#BBCLASSEXTEND += " nativesdk "

do_compile_prepend() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;

 ### BUILD BEGIN ###
 CPPFLAGS="$CPPFLAGS `pkg-config --cflags nss`"
 export CPPFLAGS
 export LDFLAGS="${LDFLAGS} -Wl,-Bsymbolic-functions -ffunction-sections"

 export CCFLAGS="${CCFLAGS} -fPIC "
 export CXXFLAGS="${CXXFLAGS} -fPIC "
 export CFLAGS="${CFLAGS} -fPIC "

 cd db3
 ./configure --build=${BUILD_SYS} --host=${HOST_SYS} --target=${TARGET_SYS}
 cd ..

 cp db3/configure  db3/configure.ac

 export CFLAGS="${CFLAGS} -DRPM_VENDOR_OE "
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  CPPFLAGS="$CPPFLAGS `pkg-config --cflags nss`"
  export CPPFLAGS
  export CFLAGS="$CFLAGS -ffunction-sections"
  export LDFLAGS="${LDFLAGS} -Wl,-Bsymbolic-functions -ffunction-sections"
  
  export CFLAGS="${CFLAGS} -DRPM_VENDOR_OE "
  autoreconf -i -f
  oe_runconf
  
  make ${PARALLEL_MAKE}
}

EXTRA_OECONF += " --with-python-inc-dir=${STAGING_INCDIR}/python${PYTHON_BASEVERSION} "
EXTRA_OECONF += " --with-python-lib-dir=${libdir}/python${PYTHON_BASEVERSION}/site-packages "
#EXTRA_OECONF += " --host=tizen-linux "

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}

 mkdir -p ${D}${prefix}/lib
 mkdir -p ${D}${prefix}/share/locale
 ln -s ../share/locale ${D}${prefix}/lib/locale

   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install
   rm -f ${D}${infodir}/dir
   find ${D} -regex ".*\.la$" | xargs rm -f --
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -m 644 db3/db.h ${D}${prefix}/include/rpm
 mkdir -p ${D}${sysconfdir}/rpm
 cp -a tizen_macros ${D}${prefix}/lib/rpm
 mkdir -p ${D}${prefix}/lib/rpm/tizen
 install -m 755 ${S}/packaging/find-docs.sh ${D}${prefix}/lib/rpm/tizen
 install -m 755 ${S}/packaging/find-provides.ksyms ${D}${prefix}/lib/rpm
 install -m 644 ${S}/packaging/device-sec-policy ${D}${sysconfdir}/device-sec-policy
 install -m 644 ${S}/packaging/device-sec-policy ${D}${prefix}/lib/rpm-plugins/msm-device-sec-policy
 ln -s ../tizen_macros ${D}${prefix}/lib/rpm/tizen/macros
 for d in BUILD RPMS SOURCES SPECS SRPMS BUILDROOT ; do
   mkdir -p ${D}${prefix}/src/packages/$d
   chmod 755 ${D}${prefix}/src/packages/$d
 done
 for d in ${D}${prefix}/lib/rpm/platform/*-linux/macros ; do
   dd=${d%-linux/macros}
   dd=${dd##*/}
   mkdir -p ${D}${prefix}/src/packages/RPMS/$dd
   chmod 755 ${D}${prefix}/src/packages/RPMS/$dd
 done
 mkdir -p ${D}${localstatedir}/lib/rpm
 gzip -9 ${D}${mandir}/man[18]/*.[18]
 export RPM_BUILD_ROOT
 chmod 755 doc/manual
 rm -rf doc/manual/Makefile*
 rm -f ${D}${prefix}/lib/rpmpopt
 rm -rf ${D}${mandir}/{fr,ja,ko,pl,ru,sk}
 rm -f ${D}${prefix}/share/locale/de/LC_MESSAGES/rpm.mo
 rm -f ${D}${prefix}/lib/rpm/cpanflute ${D}${prefix}/lib/rpm/cpanflute2
 install -m 755 scripts/find-supplements ${D}${prefix}/lib/rpm
 install -m 755 scripts/find-supplements.ksyms ${D}${prefix}/lib/rpm
 install -m 755 scripts/firmware.prov ${D}${prefix}/lib/rpm
 install -m 755 scripts/debuginfo.prov ${D}${prefix}/lib/rpm
 rm -f ${D}${prefix}/lib/locale ${D}${prefix}/lib/rpmrc
 mkdir -p ${D}${sysconfdir}/rpm
 chmod 755 ${D}${sysconfdir}/rpm
 mkdir -p ${D}${prefix}/lib/rpm/macros.d
 # remove some nonsense or non-working scripts
 cd ${D}${prefix}/lib/rpm/
 for f in rpm2cpio.sh rpm.daily rpmdiff* rpm.log rpm.xinetd freshen.sh u_pkg.sh \
          magic magic.mgc magic.mime* rpmfile *.pl javadeps brp-redhat \
          brp-strip-static-archive vpkg-provides*.sh http.req sql.req tcl.req \
          rpmdb_* brp-sparc64-linux brp-strip-comment-note brp-java-gcjcompile
 do
     rm -f $f
 done
 for i in ${prefix}/share/automake-*/*; do
   if test -f "$i" && test -f "${i##*/}"; then
     rm -f "${i##*/}"
   fi
 done
 cd ${S}
 rm -f ${D}${prefix}/lib/*.la
 rm -f ${D}${prefix}/lib/rpm-plugins/*.la


  _target="";
  _symlinks=0;

 #sh ${D}${prefix}/lib/rpm/find-lang.sh ${D} rpm



}



do_install_append() {
 rm -fr ${D}/var/tmp
 rm -fr ${D}/var/volatile

 mkdir -p ${D}${prefix}/lib/rpm/bin
 ln -s ../debugedit ${D}${prefix}/lib/rpm/bin/debugedit
 ln -s ../rpmdeps ${D}${prefix}/lib/rpm/bin/rpmdeps-oecore
}

FILES_${PN}-dbg += "\
    ${libdir}/rpm-plugins/.debug/* \
    ${libdir}/python2.7/site-packages/rpm/.debug/* \
    "

DEPENDS_native += "popt-native"
DEPENDS_native += "uthash-native"
DEPENDS_native += "smack-native"
