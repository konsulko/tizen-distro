DESCRIPTION = "Application basic"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by app-core-efl 
PROVIDES += "app-core-efl"
RPROVIDES_app-core-efl += "app-core-efl"

#PROVIDES by app-core-template 
PROVIDES += "app-core-template"
RPROVIDES_app-core-template += "app-core-template"

#PROVIDES by app-core 
PROVIDES += "app-core"
RPROVIDES_app-core += "app-core"

#PROVIDES by app-core-common-devel 
PROVIDES += "app-core-common-devel"
RPROVIDES_app-core-common-devel += "app-core-common-devel"
RPROVIDES_app-core-common-devel += "app-core-common-dev"

#PROVIDES by app-core-common 
PROVIDES += "app-core-common"
RPROVIDES_app-core-common += "app-core-common"

#PROVIDES by app-core-efl-devel 
PROVIDES += "app-core-efl-devel"
RPROVIDES_app-core-efl-devel += "app-core-efl-devel"
RPROVIDES_app-core-efl-devel += "app-core-efl-dev"

RDEPENDS = ""
#RDEPENDS of app-core-efl (${PN}-efl)
RDEPENDS_${PN}-efl += "/sbin/ldconfig"

#RDEPENDS of app-core-common-devel (${PN}-common-devel)
RDEPENDS_${PN}-common-devel += "pkgconfig(aul)"
RDEPENDS_${PN}-common-devel += "pkgconfig(sensor)"
RDEPENDS_${PN}-common-devel += "app-core-common"
RDEPENDS_${PN}-common-devel += "pkgconfig(vconf)"
RDEPENDS_${PN}-common-devel += "pkgconfig(elementary)"

#RDEPENDS of app-core-common (${PN}-common)
RDEPENDS_${PN}-common += "/sbin/ldconfig"

#RDEPENDS of app-core-efl-devel (${PN}-efl-devel)
RDEPENDS_${PN}-efl-devel += "app-core-efl"
RDEPENDS_${PN}-efl-devel += "app-core-common-dev"


DEPENDS = ""
#DEPENDS of app-core 
DEPENDS += "pkgconfig(rua)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "pkgconfig(ecore)"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(sensor)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/app-core.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . \
 -Dwith_wayland=TRUE\
 -DENABLE_GTK=OFF
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 install -d ${D}/lib/systemd/user/core-efl.target.wants
 install -m0644 ${S}/packaging/core-efl-wayland.target ${D}/lib/systemd/user/core-efl.target
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/app-core
 
 
 
}

PACKAGES = ""
PACKAGES += "app-core-efl-devel"
PACKAGES += "app-core-efl"
PACKAGES += "app-core-common"
PACKAGES += "app-core-common-devel"

app-core-efl-devel_files = ""
app-core-efl-devel_files += "app-core.manifest"
app-core-efl-devel_files += "/usr/include/appcore/appcore-efl.h"
app-core-efl-devel_files += "/usr/lib/libappcore-efl.so"
app-core-efl-devel_files += "/usr/lib/pkgconfig/appcore-efl.pc"

app-core-efl_files = ""
app-core-efl_files += "app-core.manifest"
app-core-efl_files += "/usr/lib/libappcore-efl.so.*"

app-core-common_files = ""
app-core-common_files += "app-core.manifest"
app-core-common_files += "/usr/lib/libappcore-common.so.*"
app-core-common_files += "/usr/lib/systemd/user/core-efl.target"
app-core-common_files += "/usr/lib/systemd/user/core-efl.target.wants/"
app-core-common_files += "/usr/share/license/app-core"

app-core-common-devel_files = ""
app-core-common-devel_files += "app-core.manifest"
app-core-common-devel_files += "/usr/lib/libappcore-common.so"
app-core-common-devel_files += "/usr/lib/pkgconfig/appcore-common.pc"
app-core-common-devel_files += "/usr/include/appcore/appcore-common.h"
app-core-common-devel_files += "/usr/include/SLP_Appcore_PG.h"

FILES_${PN}-efl-devel = "${app-core-efl-devel_files}"
FILES_${PN}-efl = "${app-core-efl_files}"
FILES_${PN}-common = "${app-core-common_files}"
FILES_${PN}-common-devel = "${app-core-common-devel_files}"

PKG_app-core-efl-devel= "app-core-efl-devel"
PKG_app-core-efl= "app-core-efl"
PKG_app-core-common= "app-core-common"
PKG_app-core-common-devel= "app-core-common-devel"

require app-core-extraconf.inc
