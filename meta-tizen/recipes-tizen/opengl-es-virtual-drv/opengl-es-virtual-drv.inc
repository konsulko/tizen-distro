DESCRIPTION = "The Virtual OpenGL ES library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/X Hardware Support"
LICENSE = "Samsung"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by opengl-es-virtual-drv-devel 
PROVIDES += "opengl-es-virtual-drv-devel"
RPROVIDES_opengl-es-virtual-drv-devel += "opengl-es-virtual-drv-devel"
RPROVIDES_opengl-es-virtual-drv-devel += "opengl-es-virtual-drv-dev"
# the PROVIDES rules is ignore "opengl-es-drv-devel  "
PROVIDES += "opengl-es-drv-devel"
RPROVIDES_opengl-es-virtual-drv-devel += "opengl-es-drv-devel"
RPROVIDES_opengl-es-virtual-drv-devel += "opengl-es-drv-dev"

#PROVIDES by opengl-es-virtual-drv 
PROVIDES += "opengl-es-virtual-drv"
RPROVIDES_opengl-es-virtual-drv += "opengl-es-virtual-drv"
# the PROVIDES rules is ignore "opengl-es-drv  "
PROVIDES += "opengl-es-drv"
RPROVIDES_opengl-es-virtual-drv += "opengl-es-drv"

RDEPENDS = ""
#RDEPENDS of opengl-es-virtual-drv-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "opengl-es-virtual-drv"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n opengl-es-virtual-drv-0.1.5
 
 
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
 
 ./autogen.sh
 
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
         --infodir=/usr/share/info --disable-static --prefix=/usr
 
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
 mkdir -p ${D}/usr/include
 cp -a src/include/KHR ${D}/usr/include
 
 
 
}

PACKAGES = ""
PACKAGES += "opengl-es-virtual-drv-devel"
PACKAGES += "opengl-es-virtual-drv"

opengl-es-virtual-drv-devel_files = ""
opengl-es-virtual-drv-devel_files += "/usr/include/GLES/gl.h"
opengl-es-virtual-drv-devel_files += "/usr/include/GLES/glplatform.h"
opengl-es-virtual-drv-devel_files += "/usr/include/GLES/glext.h"
opengl-es-virtual-drv-devel_files += "/usr/include/EGL/egl.h"
opengl-es-virtual-drv-devel_files += "/usr/include/EGL/eglext.h"
opengl-es-virtual-drv-devel_files += "/usr/include/EGL/eglplatform.h"
opengl-es-virtual-drv-devel_files += "/usr/include/GLES2/gl2.h"
opengl-es-virtual-drv-devel_files += "/usr/include/GLES2/gl2platform.h"
opengl-es-virtual-drv-devel_files += "/usr/include/GLES2/gl2ext.h"
opengl-es-virtual-drv-devel_files += "/usr/include/KHR/khrplatform.h"
opengl-es-virtual-drv-devel_files += "/usr/lib/pkgconfig/gles20.pc"
opengl-es-virtual-drv-devel_files += "/usr/lib/pkgconfig/gles11.pc"

opengl-es-virtual-drv_files = ""
opengl-es-virtual-drv_files += "opengl-es-virtual-drv.manifest"
opengl-es-virtual-drv_files += "/usr/lib/libGLESv1_CM.so"
opengl-es-virtual-drv_files += "/usr/lib/libGLESv2.so"
opengl-es-virtual-drv_files += "/usr/lib/libEGL.so"

FILES_${PN}-devel = "${opengl-es-virtual-drv-devel_files}"
FILES_${PN} = "${opengl-es-virtual-drv_files}"

PKG_opengl-es-virtual-drv-devel= "opengl-es-virtual-drv-devel"
PKG_opengl-es-virtual-drv= "opengl-es-virtual-drv"

require opengl-es-virtual-drv-extraconf.inc
