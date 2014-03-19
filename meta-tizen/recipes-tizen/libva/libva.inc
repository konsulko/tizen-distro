DESCRIPTION = "Video Acceleration (VA) API for Linux"
HOMEPAGE = "http://freedesktop.org/wiki/Software/vaapi"
SECTION = "Multimedia/Video"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libva-devel 
PROVIDES += "libva-devel"
RPROVIDES_libva-devel += "libva-devel"
RPROVIDES_libva-devel += "libva-dev"

#PROVIDES by vaapi-dummy-driver 
PROVIDES += "vaapi-dummy-driver"
RPROVIDES_vaapi-dummy-driver += "vaapi-dummy-driver"

#PROVIDES by vaapi-tools 
PROVIDES += "vaapi-tools"
RPROVIDES_vaapi-tools += "vaapi-tools"

#PROVIDES by libva 
PROVIDES += "libva"
RPROVIDES_libva += "libva"

RDEPENDS = ""
#RDEPENDS of libva-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(libdrm)"
RDEPENDS_${PN}-devel += "pkgconfig(wayland-egl)"
RDEPENDS_${PN}-devel += "pkgconfig(wayland-client)"
RDEPENDS_${PN}-devel += "libva"


DEPENDS = ""
#DEPENDS of libva 
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "pkgconfig-native"
DEPENDS += "xz"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(wayland-egl)"
DEPENDS += "pkgconfig(libudev)"
DEPENDS += "mesa-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 # --enable-x11 set to no explicitly, otherwise it will mislead libva build when other package brings in X11 lib
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
         --infodir=/usr/share/info --enable-dummy-driver \
            --enable-dummy-backend \
            --enable-egl \
            --enable-wayland \
         --enable-x11=no \
            --with-drivers-path=/usr/lib/dri
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
 grep -r include ${D}/usr/include
 
 
}

PACKAGES = ""
PACKAGES += "libva-devel"
PACKAGES += "libva"
PACKAGES += "vaapi-tools"
PACKAGES += "vaapi-dummy-driver"

libva-devel_files = ""
libva-devel_files += "/usr/lib/libva.so"
libva-devel_files += "/usr/lib/libva-tpi.so"
libva-devel_files += "/usr/lib/libva-egl.so"
libva-devel_files += "/usr/lib/libva-wayland.so"
libva-devel_files += "/usr/lib/libva-drm.so"
libva-devel_files += "/usr/include/va"
libva-devel_files += "/usr/lib/pkgconfig/libva*.pc"

libva_files = ""
libva_files += "/usr/lib/libva.so.*"
libva_files += "/usr/lib/libva-tpi.so.*"
libva_files += "/usr/lib/libva-egl.so.*"
libva_files += "/usr/lib/libva-wayland.so.*"
libva_files += "/usr/lib/libva-drm.so.*"

vaapi-tools_files = ""
vaapi-tools_files += "/usr/bin/vainfo"
vaapi-tools_files += "/usr/bin/avcenc"
vaapi-tools_files += "/usr/bin/h264encode"
vaapi-tools_files += "/usr/bin/mpeg2vldemo"
vaapi-tools_files += "/usr/bin/mpeg2vaenc"
vaapi-tools_files += "/usr/bin/loadjpeg"
vaapi-tools_files += "/usr/bin/putsurface_wayland"

vaapi-dummy-driver_files = ""
vaapi-dummy-driver_files += "/usr/lib/dri"
vaapi-dummy-driver_files += "/usr/lib/dri/dummy_drv_video.so"

FILES_${PN}-devel = "${libva-devel_files}"
FILES_${PN} = "${libva_files}"
FILES_vaapi-tools = "${vaapi-tools_files}"
FILES_vaapi-dummy-driver = "${vaapi-dummy-driver_files}"

PKG_libva-devel= "libva-devel"
PKG_libva= "libva"
PKG_vaapi-tools= "vaapi-tools"
PKG_vaapi-dummy-driver= "vaapi-dummy-driver"

require libva-extraconf.inc
