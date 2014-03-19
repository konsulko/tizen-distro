DESCRIPTION = "UI Gadget Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ui-gadget-1-devel 
PROVIDES += "ui-gadget-1-devel"
RPROVIDES_ui-gadget-1-devel += "ui-gadget-1-devel"
RPROVIDES_ui-gadget-1-devel += "ui-gadget-1-dev"

#PROVIDES by ui-gadget-1 
PROVIDES += "ui-gadget-1"
RPROVIDES_ui-gadget-1 += "ui-gadget-1"

RDEPENDS = ""
#RDEPENDS of ui-gadget-1-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ui-gadget-1"

#RDEPENDS of ui-gadget-1 (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of ui-gadget-1 
DEPENDS += "edje"
DEPENDS += "pkgconfig(capi-appfw-app-manager)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libtzplatform-config)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "app-svc"
DEPENDS += "dlog"
DEPENDS += "app-core"
DEPENDS += "bundle"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(capi-appfw-application)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ui-gadget-1.manifest .
 
 
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
 -DTZ_SYS_ETC=%TZ_SYS_ETC \
 -Dwith_wayland=TRUE
 
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
 mkdir -p ${D}/usr/share/license
 install LICENSE ${D}/usr/share/license/ui-gadget-1
 
 
}

PACKAGES = ""
PACKAGES += "ui-gadget-1-devel"
PACKAGES += "ui-gadget-1"

ui-gadget-1-devel_files = ""
ui-gadget-1-devel_files += "ui-gadget-1.manifest"
ui-gadget-1-devel_files += "/usr/include/ug-1/*.h"
ui-gadget-1-devel_files += "/usr/lib/libui-gadget-1.so"
ui-gadget-1-devel_files += "/usr/lib/pkgconfig/ui-gadget-1.pc"

ui-gadget-1_files = ""
ui-gadget-1_files += "ui-gadget-1.manifest"
ui-gadget-1_files += "/usr/lib/*.so.*"
ui-gadget-1_files += "/usr/lib/libui-gadget-1-efl-engine.so"
ui-gadget-1_files += "/usr/share/edje/ug_effect.edj"
ui-gadget-1_files += "/usr/bin/ug-client"
ui-gadget-1_files += "/usr/share/edje/ug-client/*.edj"
ui-gadget-1_files += "/usr/share/license/ui-gadget-1"

FILES_${PN}-devel = "${ui-gadget-1-devel_files}"
FILES_${PN} = "${ui-gadget-1_files}"

PKG_ui-gadget-1-devel= "ui-gadget-1-devel"
PKG_ui-gadget-1= "ui-gadget-1"

require ui-gadget-1-extraconf.inc
