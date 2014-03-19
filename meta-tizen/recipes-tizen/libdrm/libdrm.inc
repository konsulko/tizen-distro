DESCRIPTION = "Userspace interface to kernel DRM services"
HOMEPAGE = "http://cgit.freedesktop.org/mesa/drm"
SECTION = "Graphics & UI Framework/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libdrm 
PROVIDES += "libdrm"
RPROVIDES_libdrm += "libdrm"

#PROVIDES by libdrm-intel 
PROVIDES += "libdrm-intel"
RPROVIDES_libdrm-intel += "libdrm-intel"

#PROVIDES by libdrm-devel 
PROVIDES += "libdrm-devel"
RPROVIDES_libdrm-devel += "libdrm-devel"
RPROVIDES_libdrm-devel += "libdrm-dev"

#PROVIDES by libkms 
PROVIDES += "libkms"
RPROVIDES_libkms += "libkms"

RDEPENDS = ""
#RDEPENDS of libdrm-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libdrm"
RDEPENDS_${PN}-devel += "libdrm-intel"
RDEPENDS_${PN}-devel += "libkms"


DEPENDS = ""
#DEPENDS of libdrm 
DEPENDS += "pkgconfig(pthread-stubs)"
DEPENDS += "pkgconfig(pciaccess)"

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
 
 cp ${S}/packaging/libdrm.manifest .
 
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
         --infodir=/usr/share/info \
         --enable-static=yes  \
         --enable-udev \
         --enable-libkms \
         --disable-nouveau-experimental-api \
         --disable-radeon \
         --disable-nouveau \
         --enable-exynos-experimental-api
 
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
 
 
 
}

PACKAGES = ""
PACKAGES += "libdrm"
PACKAGES += "libdrm-intel"
PACKAGES += "libdrm-devel"
PACKAGES += "libkms"

libdrm_files = ""
libdrm_files += "libdrm.manifest"
libdrm_files += "/usr/lib/libdrm.so.*"
libdrm_files += "/usr/lib/libdrm_exynos.so.*"
libdrm_files += "/usr/lib/libdrm_vigs.so.*"

libdrm-intel_files = ""
libdrm-intel_files += "libdrm.manifest"
libdrm-intel_files += "/usr/lib/libdrm_intel.so.*"

libdrm-devel_files = ""
libdrm-devel_files += "libdrm.manifest"
libdrm-devel_files += "/usr/include/libdrm"
libdrm-devel_files += "/usr/include/libdrm/*.h"
libdrm-devel_files += "/usr/include/libkms"
libdrm-devel_files += "/usr/include/libkms/*.h"
libdrm-devel_files += "/usr/include/exynos"
libdrm-devel_files += "/usr/include/exynos/*.h"
libdrm-devel_files += "/usr/include/*.h"
libdrm-devel_files += "/usr/lib/libdrm.so"
libdrm-devel_files += "/usr/lib/libdrm_intel.so"
libdrm-devel_files += "/usr/lib/libkms.so"
libdrm-devel_files += "/usr/lib/libdrm_exynos.so"
libdrm-devel_files += "/usr/lib/libdrm_vigs.so"
libdrm-devel_files += "/usr/lib/pkgconfig/*"

libkms_files = ""
libkms_files += "libdrm.manifest"
libkms_files += "/usr/lib/libkms.so.*"

FILES_${PN} = "${libdrm_files}"
FILES_${PN}-intel = "${libdrm-intel_files}"
FILES_${PN}-devel = "${libdrm-devel_files}"
FILES_libkms = "${libkms_files}"

PKG_libdrm= "libdrm"
PKG_libdrm-intel= "libdrm-intel"
PKG_libdrm-devel= "libdrm-devel"
PKG_libkms= "libkms"

require libdrm-extraconf.inc
