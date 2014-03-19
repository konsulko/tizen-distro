DESCRIPTION = "Library to control privilege of application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Access Control"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libprivilege-control 
PROVIDES += "libprivilege-control"
RPROVIDES_libprivilege-control += "libprivilege-control"

#PROVIDES by libprivilege-control-conf 
PROVIDES += "libprivilege-control-conf"
RPROVIDES_libprivilege-control-conf += "libprivilege-control-conf"

#PROVIDES by libprivilege-control-devel 
PROVIDES += "libprivilege-control-devel"
RPROVIDES_libprivilege-control-devel += "libprivilege-control-devel"
RPROVIDES_libprivilege-control-devel += "libprivilege-control-dev"

RDEPENDS = ""
#RDEPENDS of libprivilege-control-conf (${PN}-conf)
RDEPENDS_${PN}-conf += "libprivilege-control"

#RDEPENDS of libprivilege-control-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libprivilege-control"


DEPENDS = ""
#DEPENDS of libprivilege-control 
DEPENDS += "pkgconfig(libsmack)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libprivilege-control.manifest .
 
 
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
 
 export CFLAGS="${CFLAGS} -Wno-implicit-function-declaration"
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DCMAKE_BUILD_TYPE=
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/usr/share/privilege-control/
 
 
}

PACKAGES = ""
PACKAGES += "libprivilege-control"
PACKAGES += "libprivilege-control-conf"
PACKAGES += "libprivilege-control-devel"

libprivilege-control_files = ""
libprivilege-control_files += "libprivilege-control.manifest"
libprivilege-control_files += "/usr/lib/*.so.*"
libprivilege-control_files += "/usr/bin/slp-su"
libprivilege-control_files += "/usr/share/privilege-control"
libprivilege-control_files += "/usr/share/privilege-control/*"

libprivilege-control-conf_files = ""
libprivilege-control-conf_files += "libprivilege-control.manifest"
libprivilege-control-conf_files += "/opt/etc/smack/*"
libprivilege-control-conf_files += "/opt/dbspace/.privilege_control*.db"

libprivilege-control-devel_files = ""
libprivilege-control-devel_files += "libprivilege-control.manifest"
libprivilege-control-devel_files += "/usr/include/*.h"
libprivilege-control-devel_files += "/usr/lib/*.so"
libprivilege-control-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libprivilege-control_files}"
FILES_${PN}-conf = "${libprivilege-control-conf_files}"
FILES_${PN}-devel = "${libprivilege-control-devel_files}"

PKG_libprivilege-control= "libprivilege-control"
PKG_libprivilege-control-conf= "libprivilege-control-conf"
PKG_libprivilege-control-devel= "libprivilege-control-devel"

require libprivilege-control-extraconf.inc
