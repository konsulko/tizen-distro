DESCRIPTION = "System for rendering interactive 3-D graphics"
HOMEPAGE = "http://www.mesa3d.org"
SECTION = "Graphics & UI Framework/Hardware Adaptation"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mesa-libEGL 
PROVIDES += "mesa-libEGL"
RPROVIDES_mesa-libEGL += "mesa-libEGL"

#PROVIDES by libgbm 
PROVIDES += "libgbm"
RPROVIDES_libgbm += "libgbm"

#PROVIDES by mesa-libEGL-devel 
PROVIDES += "mesa-libEGL-devel"
RPROVIDES_mesa-libEGL-devel += "mesa-libEGL-devel"
RPROVIDES_mesa-libEGL-devel += "mesa-libEGL-dev"

#PROVIDES by mesa-libGLESv1_CM-devel 
PROVIDES += "mesa-libGLESv1_CM-devel"
RPROVIDES_mesa-libGLESv1_CM-devel += "mesa-libGLESv1_CM-devel"
RPROVIDES_mesa-libGLESv1_CM-devel += "mesa-libGLESv1_CM-dev"

#PROVIDES by mesa-libGLESv1_CM 
PROVIDES += "mesa-libGLESv1_CM"
RPROVIDES_mesa-libGLESv1_CM += "mesa-libGLESv1_CM"

#PROVIDES by mesa-libglapi 
PROVIDES += "mesa-libglapi"
RPROVIDES_mesa-libglapi += "mesa-libglapi"

#PROVIDES by libwayland-egl 
PROVIDES += "libwayland-egl"
RPROVIDES_libwayland-egl += "libwayland-egl"

#PROVIDES by libgbm-devel 
PROVIDES += "libgbm-devel"
RPROVIDES_libgbm-devel += "libgbm-devel"
RPROVIDES_libgbm-devel += "libgbm-dev"

#PROVIDES by mesa-libGLESv2 
PROVIDES += "mesa-libGLESv2"
RPROVIDES_mesa-libGLESv2 += "mesa-libGLESv2"

#PROVIDES by mesa-libGLESv3-devel 
PROVIDES += "mesa-libGLESv3-devel"
RPROVIDES_mesa-libGLESv3-devel += "mesa-libGLESv3-devel"
RPROVIDES_mesa-libGLESv3-devel += "mesa-libGLESv3-dev"

#PROVIDES by mesa 
PROVIDES += "mesa"
RPROVIDES_mesa += "mesa"
# the PROVIDES rules is ignore "Mesa = 9.2.1"
PROVIDES += "Mesa"
RPROVIDES_mesa += "Mesa"

#PROVIDES by mesa-libGLESv2-devel 
PROVIDES += "mesa-libGLESv2-devel"
RPROVIDES_mesa-libGLESv2-devel += "mesa-libGLESv2-devel"
RPROVIDES_mesa-libGLESv2-devel += "mesa-libGLESv2-dev"

#PROVIDES by mesa-devel 
PROVIDES += "mesa-devel"
RPROVIDES_mesa-devel += "mesa-devel"
RPROVIDES_mesa-devel += "mesa-dev"

RDEPENDS = ""
#RDEPENDS of mesa-libEGL-devel (${PN}-libEGL-devel)
RDEPENDS_${PN}-libEGL-devel += "mesa-libEGL"

#RDEPENDS of mesa-libGLESv1_CM-devel (${PN}-libGLESv1_CM-devel)
RDEPENDS_${PN}-libGLESv1_CM-devel += "mesa-libGLESv1_CM"
RDEPENDS_${PN}-libGLESv1_CM-devel += "pkgconfig(egl)"

#RDEPENDS of libgbm-devel (libgbm-devel)
RDEPENDS_libgbm-devel += "libgbm"

#RDEPENDS of mesa-libGLESv3-devel (${PN}-libGLESv3-devel)
RDEPENDS_${PN}-libGLESv3-devel += "pkgconfig(egl)"

#RDEPENDS of mesa-libGLESv2-devel (${PN}-libGLESv2-devel)
RDEPENDS_${PN}-libGLESv2-devel += "pkgconfig(egl)"
RDEPENDS_${PN}-libGLESv2-devel += "mesa-libGLESv2"

#RDEPENDS of mesa-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "mesa-libGLESv1_CM-dev"
RDEPENDS_${PN}-devel += "mesa-libEGL-dev"
RDEPENDS_${PN}-devel += "libgbm-dev"
RDEPENDS_${PN}-devel += "libwayland-egl"
RDEPENDS_${PN}-devel += "mesa-libglapi"
RDEPENDS_${PN}-devel += "mesa"
RDEPENDS_${PN}-devel += "mesa-libGLESv2-dev"


DEPENDS = ""
#DEPENDS of mesa 
DEPENDS += "flex"
DEPENDS += "gcc-cross"
DEPENDS += "fdupes-native"
DEPENDS += "pkgconfig(wayland-server)"
DEPENDS += "pkgconfig(libdrm_intel)"
inherit pythonnative
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "expat"
DEPENDS += "pkgconfig-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "libxml2-python"
DEPENDS += "bison-native"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(libudev)"
DEPENDS += "autoconf-native"
DEPENDS += "llvm"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/mesa.manifest .
 
 rm -rf docs/README.{VMS,WIN32,OS2}
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -f src/mesa/depend
 autoreconf -fi
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --enable-gles1 \
            --enable-gles2 \
            --with-egl-platforms=drm,wayland \
            --disable-glx \
            --enable-shared-glapi \
            --enable-texture-float \
            --enable-gbm \
            --with-dri-searchpath=/usr/lib/dri/updates:/usr/lib/dri \
            --enable-gallium-llvm \
            --with-dri-drivers=i915,i965,swrast \
            --with-gallium-drivers="swrast,svga" \
            CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -DNDEBUG"
 make -j16
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 rm -rf ${D}/usr/include/GL
 rm -f ${D}/usr/lib/pkgconfig/gl.pc
 
 # DRI driver update mechanism
 mkdir -p ${D}/usr/lib/dri/updates
 install -m 644 $RPM_SOURCE_DIR/README.updates \
   ${D}/usr/lib/dri/updates
 # global drirc file
 mkdir -p ${D}/etc
 install -m 644 $RPM_SOURCE_DIR/drirc ${D}/etc
 
 
 
}

PACKAGES = ""
PACKAGES += "mesa-libEGL"
PACKAGES += "libgbm"
PACKAGES += "mesa-libEGL-devel"
PACKAGES += "mesa-libGLESv1_CM-devel"
PACKAGES += "mesa-libGLESv1_CM"
PACKAGES += "mesa-libglapi"
PACKAGES += "libwayland-egl"
PACKAGES += "libgbm-devel"
PACKAGES += "mesa-libGLESv2"
PACKAGES += "mesa-libGLESv3-devel"
PACKAGES += "mesa"
PACKAGES += "mesa-libGLESv2-devel"
PACKAGES += "mesa-devel"

mesa-libEGL_files = ""
mesa-libEGL_files += "mesa.manifest"
mesa-libEGL_files += "/usr/lib/libEGL.so.1*"

libgbm_files = ""
libgbm_files += "mesa.manifest"
libgbm_files += "/usr/lib/libgbm.so.1*"

mesa-libEGL-devel_files = ""
mesa-libEGL-devel_files += "mesa.manifest"
mesa-libEGL-devel_files += "/usr/include/EGL"
mesa-libEGL-devel_files += "/usr/include/KHR"
mesa-libEGL-devel_files += "/usr/lib/libEGL.so"
mesa-libEGL-devel_files += "/usr/lib/pkgconfig/egl.pc"

mesa-libGLESv1_CM-devel_files = ""
mesa-libGLESv1_CM-devel_files += "mesa.manifest"
mesa-libGLESv1_CM-devel_files += "/usr/include/GLES"
mesa-libGLESv1_CM-devel_files += "/usr/lib/libGLESv1_CM.so"
mesa-libGLESv1_CM-devel_files += "/usr/lib/pkgconfig/glesv1_cm.pc"

mesa-libGLESv1_CM_files = ""
mesa-libGLESv1_CM_files += "mesa.manifest"
mesa-libGLESv1_CM_files += "/usr/lib/libGLESv1_CM.so.1*"

mesa-libglapi_files = ""
mesa-libglapi_files += "mesa.manifest"
mesa-libglapi_files += "/usr/lib/libglapi.so.0*"

libwayland-egl_files = ""
libwayland-egl_files += "mesa.manifest"
libwayland-egl_files += "/usr/lib/libwayland-egl.so.1*"

libgbm-devel_files = ""
libgbm-devel_files += "mesa.manifest"
libgbm-devel_files += "/usr/include/gbm.h"
libgbm-devel_files += "/usr/lib/libgbm.so"
libgbm-devel_files += "/usr/lib/pkgconfig/gbm.pc"

mesa-libGLESv2_files = ""
mesa-libGLESv2_files += "mesa.manifest"
mesa-libGLESv2_files += "/usr/lib/libGLESv2.so.2*"

mesa-libGLESv3-devel_files = ""
mesa-libGLESv3-devel_files += "mesa.manifest"
mesa-libGLESv3-devel_files += "/usr/include/GLES3"

mesa_files = ""
mesa_files += "mesa.manifest"
mesa_files += "/etc/drirc"
mesa_files += "/usr/lib/dri/"
mesa_files += "/usr/lib/libdricore9*.so.*"

mesa-libGLESv2-devel_files = ""
mesa-libGLESv2-devel_files += "mesa.manifest"
mesa-libGLESv2-devel_files += "/usr/include/GLES2"
mesa-libGLESv2-devel_files += "/usr/lib/libGLESv2.so"
mesa-libGLESv2-devel_files += "/usr/lib/pkgconfig/glesv2.pc"

mesa-devel_files = ""
mesa-devel_files += "mesa.manifest"
mesa-devel_files += "/usr/lib/libglapi.so"
mesa-devel_files += "/usr/lib/libwayland-egl.so"
mesa-devel_files += "/usr/lib/pkgconfig/wayland-egl.pc"
mesa-devel_files += "/usr/lib/pkgconfig/dri.pc"
mesa-devel_files += "/usr/lib/libdricore9*.so"

FILES_${PN}-libEGL = "${mesa-libEGL_files}"
FILES_libgbm = "${libgbm_files}"
FILES_${PN}-libEGL-devel = "${mesa-libEGL-devel_files}"
FILES_${PN}-libGLESv1_CM-devel = "${mesa-libGLESv1_CM-devel_files}"
FILES_${PN}-libGLESv1_CM = "${mesa-libGLESv1_CM_files}"
FILES_${PN}-libglapi = "${mesa-libglapi_files}"
FILES_libwayland-egl = "${libwayland-egl_files}"
FILES_libgbm-devel = "${libgbm-devel_files}"
FILES_${PN}-libGLESv2 = "${mesa-libGLESv2_files}"
FILES_${PN}-libGLESv3-devel = "${mesa-libGLESv3-devel_files}"
FILES_${PN} = "${mesa_files}"
FILES_${PN}-libGLESv2-devel = "${mesa-libGLESv2-devel_files}"
FILES_${PN}-devel = "${mesa-devel_files}"

PKG_mesa-libEGL= "mesa-libEGL"
PKG_libgbm= "libgbm"
PKG_mesa-libEGL-devel= "mesa-libEGL-devel"
PKG_mesa-libGLESv1_CM-devel= "mesa-libGLESv1_CM-devel"
PKG_mesa-libGLESv1_CM= "mesa-libGLESv1_CM"
PKG_mesa-libglapi= "mesa-libglapi"
PKG_libwayland-egl= "libwayland-egl"
PKG_libgbm-devel= "libgbm-devel"
PKG_mesa-libGLESv2= "mesa-libGLESv2"
PKG_mesa-libGLESv3-devel= "mesa-libGLESv3-devel"
PKG_mesa= "mesa"
PKG_mesa-libGLESv2-devel= "mesa-libGLESv2-devel"
PKG_mesa-devel= "mesa-devel"

require mesa-extraconf.inc
