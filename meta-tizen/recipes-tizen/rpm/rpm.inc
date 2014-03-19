DESCRIPTION = "The RPM Package Manager"
HOMEPAGE = "http://www.rpm.org"
SECTION = "Base/Package Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rpm-security-plugin 
PROVIDES += "rpm-security-plugin"
RPROVIDES_rpm-security-plugin += "rpm-security-plugin"

#PROVIDES by rpm-build 
PROVIDES += "rpm-build"
RPROVIDES_rpm-build += "rpm-build"
# the PROVIDES rules is ignore "rpmbuild  "
PROVIDES += "rpmbuild"
RPROVIDES_rpm-build += "rpmbuild"
# the PROVIDES rules is ignore "rpm:/usr/bin/rpmbuild  "
PROVIDES += "rpm:/usr/bin/rpmbuild"
RPROVIDES_rpm-build += "rpm:/usr/bin/rpmbuild"

#PROVIDES by rpm-locale  
PROVIDES += "rpm-locale "
RPROVIDES_rpm-locale  += "rpm-locale "
# the PROVIDES rules is ignore "rpm-lang-all = 4.11.0.1"
PROVIDES += "rpm-lang-all"
RPROVIDES_rpm-locale  += "rpm-lang-all"

#PROVIDES by rpm-devel 
PROVIDES += "rpm-devel"
RPROVIDES_rpm-devel += "rpm-devel"
RPROVIDES_rpm-devel += "rpm-dev"

#PROVIDES by rpm 
PROVIDES += "rpm"
RPROVIDES_rpm += "rpm"
# the PROVIDES rules is ignore "rpminst  "
PROVIDES += "rpminst"
RPROVIDES_rpm += "rpminst"
# the PROVIDES rules is ignore "rpm-libs  "
PROVIDES += "rpm-libs"
RPROVIDES_rpm += "rpm-libs"

#PROVIDES by rpm-docs  
PROVIDES += "rpm-docs "
RPROVIDES_rpm-docs  += "rpm-docs "

RDEPENDS = ""
#RDEPENDS of rpm-security-plugin (${PN}-security-plugin)
RDEPENDS_${PN}-security-plugin += "libxml2"
RDEPENDS_${PN}-security-plugin += "smack"
RDEPENDS_${PN}-security-plugin += "nss"
RDEPENDS_${PN}-security-plugin += "rpm"

#RDEPENDS of rpm-build (${PN}-build)
RDEPENDS_${PN}-build += "glibc-dev"
RDEPENDS_${PN}-build += "bzip2"
RDEPENDS_${PN}-build += "make"
RDEPENDS_${PN}-build += "gcc"
RDEPENDS_${PN}-build += "patch"
RDEPENDS_${PN}-build += "xz"
RDEPENDS_${PN}-build += "findutils"
RDEPENDS_${PN}-build += "gzip"
RDEPENDS_${PN}-build += "rpm"
RDEPENDS_${PN}-build += "binutils"

#RDEPENDS of rpm-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "rpm"

#RDEPENDS of rpm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "popt-dev"
RDEPENDS_${PN}-devel += "rpm"


DEPENDS = ""
#DEPENDS of rpm 
DEPENDS += "pkgconfig(nss)"
DEPENDS += "findutils"
DEPENDS += "file"
DEPENDS += "popt"
DEPENDS += "patch"
DEPENDS += "make"
DEPENDS += "gcc-cross"
DEPENDS += "xz-devel"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "lua-native"
DEPENDS += "uthash-devel"
DEPENDS += "libcap"
DEPENDS += "pkgconfig(libsmack)"
DEPENDS += "ncurses"
DEPENDS += "bzip2"
DEPENDS += "libtool-cross"
DEPENDS += "attr"
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "acl"
DEPENDS += "gzip"
DEPENDS += "elfutils"
DEPENDS += "binutils"

do_patch() {
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

do_configure() {
}

do_compile() {
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
 
 export CCFLAGS+=" -fPIC "
 export CXXFLAGS+=" -fPIC "
 export CFLAGS+=" -fPIC "
 
 cd db3
 ./configure --build=${TARGET_SYS} --host=x86_64-linux-gnu
 cd ..
 
 cp db3/configure  db3/configure.ac
 autoreconf -Wcross --verbose --install --force
 ./configure --build=${TARGET_SYS} --host=x86_64-linux-gnu \
  --disable-dependency-tracking \
  --prefix=/usr \
  --mandir=/usr/share/man \
  --infodir=/usr/share/info \
  --libdir=/usr/lib \
  --sysconfdir=/etc \
  --localstatedir=/var \
  --with-lua \
  --with-acl \
  --with-cap \
  --enable-shared  \
  --with-msm $BUILDTARGET
 
 make -j16
 ### BUILD END ###
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
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
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -m 644 db3/db.h ${D}/usr/include/rpm
 # remove .la file and the static variant of libpopt
 # have to remove the dependency from other .la files as well
 #for f in ${D}//usr/lib/*.la; do
 #    sed -i -e "s,/lib/libpopt.la,-lpopt,g" $f
 #done
 mkdir -p ${D}/etc/rpm
 cp -a tizen_macros ${D}/usr/lib/rpm
 mkdir -p ${D}/usr/lib/rpm/tizen
 install -m 755 ${S}/packaging/find-docs.sh ${D}/usr/lib/rpm/tizen
 install -m 755 ${S}/packaging/find-provides.ksyms ${D}/usr/lib/rpm
 install -m 644 ${S}/packaging/device-sec-policy ${D}/etc/device-sec-policy
 install -m 644 ${S}/packaging/device-sec-policy ${D}/usr/lib/rpm-plugins/msm-device-sec-policy
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
 gzip -9 ${D}//usr/share/man/man[18]/*.[18]
 export RPM_BUILD_ROOT
 chmod 755 doc/manual
 rm -rf doc/manual/Makefile*
 rm -f ${D}/usr/lib/rpmpopt
 rm -rf ${D}/usr/share/man/{fr,ja,ko,pl,ru,sk}
 rm -f ${D}/usr/share/locale/de/LC_MESSAGES/rpm.mo
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
 rm -rf ${D}//usr/lib/python2.7
 rm -f ${D}/usr/lib/*.la
 rm -f ${D}/usr/lib/rpm-plugins/*.la
 sh ${D}/usr/lib/rpm/find-lang.sh ${D} rpm
 
 
}

PACKAGES = ""
PACKAGES += "rpm-security-plugin"
PACKAGES += "rpm-build"
PACKAGES += "rpm-devel"
PACKAGES += "rpm-locale"
PACKAGES += "rpm-docs"
PACKAGES += "rpm"

rpm-security-plugin_files = ""
rpm-security-plugin_files += "rpm.manifest"
rpm-security-plugin_files += "/usr/lib/rpm-plugins/msm.so"
rpm-security-plugin_files += "/usr/lib/rpm-plugins/msm-device-sec-policy"
rpm-security-plugin_files += "/etc/device-sec-policy"

rpm-build_files = ""
rpm-build_files += "rpm.manifest"
rpm-build_files += "/usr/bin/rpmbuild"
rpm-build_files += "/usr/bin/gendiff"
rpm-build_files += "/usr/bin/rpmspec"
rpm-build_files += "/usr/bin/rpmsign"
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

rpm-devel_files = ""
rpm-devel_files += "rpm.manifest"
rpm-devel_files += "/usr/bin/rpmgraph"
rpm-devel_files += "/usr/include/rpm"
rpm-devel_files += "/usr/lib/librpm.so"
rpm-devel_files += "/usr/lib/librpmbuild.so"
rpm-devel_files += "/usr/lib/librpmio.so"
rpm-devel_files += "/usr/lib/librpmsign.so"
rpm-devel_files += "/usr/lib/pkgconfig/rpm.pc"

rpm-locale_files = ""

rpm-docs_files = ""
rpm-docs_files += "/usr/share/info"
rpm-docs_files += "/usr/share/man"
rpm-docs_files += "GROUPS"

rpm_files = ""
rpm_files += "rpm.manifest"
rpm_files += "/etc/rpm"
rpm_files += "/bin/rpm"
rpm_files += "/usr/bin/rpm2cpio"
rpm_files += "/usr/bin/rpmdb"
rpm_files += "/usr/bin/rpmkeys"
rpm_files += "/usr/bin/rpmquery"
rpm_files += "/usr/bin/rpmverify"
rpm_files += "/usr/bin/rpmqpack"
rpm_files += "/usr/lib/rpm/macros"
rpm_files += "/usr/lib/rpm/macros.d"
rpm_files += "/usr/lib/rpm/rpmpopt*"
rpm_files += "/usr/lib/rpm/rpmrc"
rpm_files += "/usr/lib/rpm/tizen/macros"
rpm_files += "/usr/lib/rpm/tizen_macros"
rpm_files += "/usr/lib/rpm/rpm.supp"
rpm_files += "/usr/lib/rpm/tgpg"
rpm_files += "/usr/lib/rpm/platform"
rpm_files += "/usr/lib/rpm-plugins"
rpm_files += "/usr/lib/rpm-plugins/exec.so"
rpm_files += "/usr/lib/librpm.so.*"
rpm_files += "/usr/lib/librpmio.so.*"
rpm_files += "/usr/lib/librpmbuild.so.*"
rpm_files += "/usr/lib/librpmsign.so.*"
rpm_files += "/var/lib/rpm"
#Remove rpm attribut "%attr(755,root,root)"
rpm_files += "/usr/src/packages/BUILD"
#Remove rpm attribut "%attr(755,root,root)"
rpm_files += "/usr/src/packages/SPECS"
#Remove rpm attribut "%attr(755,root,root)"
rpm_files += "/usr/src/packages/SOURCES"
#Remove rpm attribut "%attr(755,root,root)"
rpm_files += "/usr/src/packages/SRPMS"

FILES_${PN}-security-plugin = "${rpm-security-plugin_files}"
FILES_${PN}-build = "${rpm-build_files}"
FILES_${PN}-devel = "${rpm-devel_files}"
FILES_${PN}-locale = "${rpm-locale_files}"
FILES_${PN}-docs = "${rpm-docs_files}"
FILES_${PN} = "${rpm_files}"

PKG_rpm-security-plugin= "rpm-security-plugin"
PKG_rpm-build= "rpm-build"
PKG_rpm-devel= "rpm-devel"
PKG_rpm-locale= "rpm-locale"
PKG_rpm-docs= "rpm-docs"
PKG_rpm= "rpm"

require rpm-extraconf.inc
