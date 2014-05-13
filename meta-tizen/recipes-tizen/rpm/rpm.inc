DESCRIPTION = "The RPM Package Manager"
HOMEPAGE = "http://www.rpm.org"
SECTION = "Base/Package Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by rpm-security-plugin 


#PROVIDES by rpm-build 
# the PROVIDES rules is ignore "rpmbuild  "
PROVIDES += "rpmbuild"
RPROVIDES_rpm-build += "rpmbuild"
# the PROVIDES rules is ignore "rpm:${prefix}/bin/rpmbuild  "
PROVIDES += "rpm:${prefix}/bin/rpmbuild"
RPROVIDES_rpm-build += "rpm:${prefix}/bin/rpmbuild"


#PROVIDES by rpm-locale  
# the PROVIDES rules is ignore "rpm-lang-all = 4.11.0.1"
PROVIDES += "rpm-lang-all"
RPROVIDES_rpm-locale  += "rpm-lang-all"


#PROVIDES by rpm-dev 


#PROVIDES by rpm 
# the PROVIDES rules is ignore "rpminst  "
PROVIDES += "rpminst"
RPROVIDES_rpm += "rpminst"
# the PROVIDES rules is ignore "rpm-libs  "
PROVIDES += "rpm-libs"
RPROVIDES_rpm += "rpm-libs"


#PROVIDES by rpm-docs  


RDEPENDS = ""
#RDEPENDS of rpm-security-plugin (${PN}-security-plugin)
RDEPENDS_${PN}-security-plugin += "libxml2"
RDEPENDS_${PN}-security-plugin += "smack"
RDEPENDS_${PN}-security-plugin += "nss"
RDEPENDS_${PN}-security-plugin += "rpm"

#RDEPENDS of rpm-build (${PN}-build)
RDEPENDS_${PN}-build += "bzip2"
RDEPENDS_${PN}-build += "make"
RDEPENDS_${PN}-build += "gcc"
RDEPENDS_${PN}-build += "patch"
RDEPENDS_${PN}-build += "xz"
RDEPENDS_${PN}-build += "eglibc"
RDEPENDS_${PN}-build += "findutils"
RDEPENDS_${PN}-build += "gzip"
RDEPENDS_${PN}-build += "rpm"
RDEPENDS_${PN}-build += "binutils"

#RDEPENDS of rpm-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "rpm"

#RDEPENDS of rpm-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "rpm"
RDEPENDS_${PN}-dev += "popt"


DEPENDS = ""
#DEPENDS of rpm 
DEPENDS += "aul-1"
DEPENDS += "libxml2"
DEPENDS += "xz"
DEPENDS += "findutils"
DEPENDS += "file"
DEPENDS += "popt"
DEPENDS += "uthash"
DEPENDS += "nss"
DEPENDS += "bzip2"
DEPENDS += "elfutils"
DEPENDS += "patch"
DEPENDS += "lua"
DEPENDS += "libcap"
DEPENDS += "ncurses"
DEPENDS += "smack"
DEPENDS += "libtool-cross"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "attr"
DEPENDS += "zlib"
DEPENDS += "acl"
DEPENDS += "gzip"
DEPENDS += "make"
DEPENDS += "binutils"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n rpm-4.11.0.1
 ### PREP BEGIN ###
 cp ${S}/packaging/rpm.manifest .
 rm -rf sqlite
 tar xjf ${S}/packaging/db-4.8.30.tar.bz2
 ln -s db-4.8.30 db
 chmod -R u+w db/*
 # will get linked from db3
 rm -f rpmdb/db.h
 patch -p0 < ${S}/packaging/db-4.8.30-integration.dif
 
 if [ -s /etc/rpm/tizen_macros ]; then
 	cp -a /etc/rpm/tizen_macros ${S}/packaging/rpm-tizen_macros
 fi
 cp -a ${S}/packaging/rpm-tizen_macros tizen_macros
 rm -f m4/libtool.m4
 rm -f m4/lt*.m4
 ### PREP END ###
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 ### BUILD BEGIN ###
 CPPFLAGS="$CPPFLAGS `pkg-config --cflags nss`"
 export CPPFLAGS 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -ffunction-sections"
 export LDFLAGS="-Wl,-Bsymbolic-functions -ffunction-sections"
 
 BUILDTARGET="--build=x86_64-tizen-linux"
 
 autoreconf -i -f
 ./configure --disable-dependency-tracking --prefix=${prefix} --mandir=${mandir} --infodir=${infodir} \
 --libdir=${prefix}/lib --sysconfdir=/etc --localstatedir=/var  --with-lua \
 --with-acl --with-cap  --enable-shared  --with-msm $BUILDTARGET
 
 make -j16
 ### BUILD END ###
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/lib
 mkdir -p ${D}/usr/share/locale
 ln -s ../share/locale ${D}/usr/lib/locale
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -m 644 db3/db.h ${D}/usr/include/rpm
 # remove .la file and the static variant of libpopt
 # have to remove the dependency from other .la files as well
 #for f in ${D}/${prefix}/lib/*.la; do
 #    sed -i -e "s,/lib/libpopt.la,-lpopt,g" $f
 #done
 mkdir -p ${D}${sysconfdir}/rpm
 cp -a tizen_macros ${D}/usr/lib/rpm
 mkdir -p ${D}/usr/lib/rpm/tizen
 install -m 755 ${S}/packaging/find-docs.sh ${D}/usr/lib/rpm/tizen
 install -m 755 ${S}/packaging/find-provides.ksyms ${D}/usr/lib/rpm
 install -m 644 ${S}/packaging/device-sec-policy ${D}${sysconfdir}/device-sec-policy
 install -m 644 ${S}/packaging/device-sec-policy ${D}${prefix}/lib/rpm-plugins/msm-device-sec-policy
 ln -s ../tizen_macros ${D}/usr/lib/rpm/tizen/macros
 for d in BUILD RPMS SOURCES SPECS SRPMS BUILDROOT ; do
   mkdir -p ${D}/usr/src/packages/$d
   chmod 755 ${D}/usr/src/packages/$d
 done
 for d in ${D}/usr/lib/rpm/platform/*-linux/macros ; do
   dd=${d%-linux/macros}
   dd=${dd##*/}
   mkdir ${D}/usr/src/packages/RPMS/$dd
   chmod 755 ${D}/usr/src/packages/RPMS/$dd
 done
 mkdir -p ${D}/var/lib/rpm
 gzip -9 ${D}/${mandir}/man[18]/*.[18]
 export RPM_BUILD_ROOT
 chmod 755 doc/manual
 rm -rf doc/manual/Makefile*
 rm -f ${D}/usr/lib/rpmpopt
 rm -rf ${D}${mandir}/{fr,ja,ko,pl,ru,sk}
 rm -f ${D}${prefix}/share/locale/de/LC_MESSAGES/rpm.mo
 rm -f ${D}/usr/lib/rpm/cpanflute ${D}/usr/lib/rpm/cpanflute2
 install -m 755 scripts/find-supplements{,.ksyms} ${D}/usr/lib/rpm
 install -m 755 scripts/firmware.prov ${D}/usr/lib/rpm
 install -m 755 scripts/debuginfo.prov ${D}/usr/lib/rpm
 rm -f ${D}/usr/lib/locale ${D}/usr/lib/rpmrc
 mkdir -p ${D}/etc/rpm
 chmod 755 ${D}/etc/rpm
 mkdir -p ${D}/usr/lib/rpm/macros.d
 # remove some nonsense or non-working scripts
 pushd ${D}/usr/lib/rpm/
 for f in rpm2cpio.sh rpm.daily rpmdiff* rpm.log rpm.xinetd freshen.sh u_pkg.sh \
          magic magic.mgc magic.mime* rpmfile *.pl javadeps brp-redhat \
          brp-strip-static-archive vpkg-provides*.sh http.req sql.req tcl.req \
          rpmdb_* brp-sparc64-linux brp-strip-comment-note brp-java-gcjcompile
 do
     rm -f $f
 done
 for i in /usr/share/automake-*/*; do
   if test -f "$i" && test -f "${i##*/}"; then
     rm -f "${i##*/}"
   fi
 done
 popd
 rm -rf ${D}/${prefix}/lib/python2.7
 rm -f ${D}${prefix}/lib/*.la
 rm -f ${D}${prefix}/lib/rpm-plugins/*.la
 sh ${D}/usr/lib/rpm/find-lang.sh ${D} rpm
 
 
}

PACKAGES += " rpm-security-plugin "
PACKAGES += " rpm-build "
PACKAGES += " rpm-docs "

rpm-security-plugin_files = ""
rpm-security-plugin_files += "rpm.manifest"
rpm-security-plugin_files += "${prefix}/lib/rpm-plugins/msm.so"
rpm-security-plugin_files += "${prefix}/lib/rpm-plugins/msm-device-sec-policy"
rpm-security-plugin_files += "${sysconfdir}/device-sec-policy"

rpm-build_files = ""
rpm-build_files += "rpm.manifest"
rpm-build_files += "${prefix}/bin/rpmbuild"
rpm-build_files += "${prefix}/bin/gendiff"
rpm-build_files += "${prefix}/bin/rpmspec"
rpm-build_files += "${prefix}/bin/rpmsign"
rpm-build_files += "/usr/lib/rpm/tizen/find-*"
rpm-build_files += "/usr/lib/rpm/brp-*"
rpm-build_files += "/usr/lib/rpm/find-supplements*"
rpm-build_files += "/usr/lib/rpm/check-*"
rpm-build_files += "/usr/lib/rpm/debugedit"
rpm-build_files += "/usr/lib/rpm/find-debuginfo.sh"
rpm-build_files += "/usr/lib/rpm/find-lang.sh"
rpm-build_files += "/usr/lib/rpm/find-provides.ksyms"
rpm-build_files += "/usr/lib/rpm/*provides*"
rpm-build_files += "/usr/lib/rpm/*requires*"
rpm-build_files += "/usr/lib/rpm/*deps*"
rpm-build_files += "/usr/lib/rpm/*.prov"
rpm-build_files += "/usr/lib/rpm/*.req"
rpm-build_files += "/usr/lib/rpm/macros.*"
rpm-build_files += "/usr/lib/rpm/fileattrs"

rpm-dev_files = ""
rpm-dev_files += "rpm.manifest"
rpm-dev_files += "${prefix}/bin/rpmgraph"
rpm-dev_files += "/usr/include/rpm"
rpm-dev_files += "${prefix}/lib/librpm.so"
rpm-dev_files += "${prefix}/lib/librpmbuild.so"
rpm-dev_files += "${prefix}/lib/librpmio.so"
rpm-dev_files += "${prefix}/lib/librpmsign.so"
rpm-dev_files += "${prefix}/lib/pkgconfig/rpm.pc"

rpm-locale_files = ""

rpm-docs_files = ""
rpm-docs_files += "GROUPS"

rpm_files = ""
rpm_files += "rpm.manifest"
rpm_files += "/etc/rpm"
rpm_files += "/bin/rpm"
rpm_files += "${prefix}/bin/rpm2cpio"
rpm_files += "${prefix}/bin/rpmdb"
rpm_files += "${prefix}/bin/rpmkeys"
rpm_files += "${prefix}/bin/rpmquery"
rpm_files += "${prefix}/bin/rpmverify"
rpm_files += "${prefix}/bin/rpmqpack"
rpm_files += "%dir /usr/lib/rpm"
rpm_files += "/usr/lib/rpm/macros"
rpm_files += "/usr/lib/rpm/macros.d"
rpm_files += "/usr/lib/rpm/rpmpopt*"
rpm_files += "/usr/lib/rpm/rpmrc"
rpm_files += "/usr/lib/rpm/tizen/macros"
rpm_files += "/usr/lib/rpm/tizen_macros"
rpm_files += "/usr/lib/rpm/rpm.supp"
rpm_files += "/usr/lib/rpm/tgpg"
rpm_files += "/usr/lib/rpm/platform"
rpm_files += "${prefix}/lib/rpm-plugins"
rpm_files += "${prefix}/lib/rpm-plugins/exec.so"
rpm_files += "${prefix}/lib/librpm.so.*"
rpm_files += "${prefix}/lib/librpmio.so.*"
rpm_files += "${prefix}/lib/librpmbuild.so.*"
rpm_files += "${prefix}/lib/librpmsign.so.*"
rpm_files += "/var/lib/rpm"
rpm_files += "%attr(755,root,root) /usr/src/packages/BUILD"
rpm_files += "%attr(755,root,root) /usr/src/packages/SPECS"
rpm_files += "%attr(755,root,root) /usr/src/packages/SOURCES"
rpm_files += "%attr(755,root,root) /usr/src/packages/SRPMS"

FILES_${PN}-security-plugin = "${rpm-security-plugin_files}"
FILES_${PN}-build = "${rpm-build_files}"
FILES_${PN}-dev = "${rpm-dev_files}"
FILES_${PN}-locale = "${rpm-locale_files}"
FILES_${PN}-docs = "${rpm-docs_files}"
FILES_${PN} = "${rpm_files}"

PKG_rpm-security-plugin= "rpm-security-plugin"
PKG_rpm-build= "rpm-build"
PKG_rpm-dev= "rpm-dev"
PKG_rpm-locale= "rpm-locale"
PKG_rpm-docs= "rpm-docs"
PKG_rpm= "rpm"

require rpm-extraconf.inc

