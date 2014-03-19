DESCRIPTION = "VP8 codec library"
HOMEPAGE = "http://www.webmproject.org/"
SECTION = "Multimedia/Libraries"
LICENSE = "BSD-3-Clause and GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libvpx-devel 
PROVIDES += "libvpx-devel"
RPROVIDES_libvpx-devel += "libvpx-devel"
RPROVIDES_libvpx-devel += "libvpx-dev"

#PROVIDES by vpx-tools 
PROVIDES += "vpx-tools"
RPROVIDES_vpx-tools += "vpx-tools"

#PROVIDES by libvpx 
PROVIDES += "libvpx"
RPROVIDES_libvpx += "libvpx"

RDEPENDS = ""
#RDEPENDS of libvpx-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libvpx"


DEPENDS = ""
#DEPENDS of libvpx 
DEPENDS += "yasm"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libvpx-v1.2.0
 cp ${S}/packaging/libvpx.manifest .
 
 
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
 
 cd build
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 # It is only an emulation of autotools configure; the macro does not work
 
 # libvpx default enable NEON support on ARMv7, unfortunately some ARMv7
 # CPU doesn't have NEON, e.g. NVIDIA Tegra 2.
 # So, we still set -mfpu=neon when build libvpx rpm, but also enable
 # runtime-cpu-detect for runtime detect NEON.
 ../configure \
     --prefix=/usr \
     --libdir=/usr/lib \
     --enable-debug \
     --enable-shared \
     --enable-pic
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd build
 
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
PACKAGES += "libvpx-devel"
PACKAGES += "vpx-tools"
PACKAGES += "libvpx"

libvpx-devel_files = ""
libvpx-devel_files += "libvpx.manifest"
libvpx-devel_files += "/usr/include/vpx/"
libvpx-devel_files += "/usr/lib/pkgconfig/vpx.pc"
libvpx-devel_files += "/usr/lib/libvpx.so"

vpx-tools_files = ""
vpx-tools_files += "libvpx.manifest"
vpx-tools_files += "/usr/bin/*"

libvpx_files = ""
libvpx_files += "libvpx.manifest"
libvpx_files += "/usr/lib/libvpx.so.*"

FILES_${PN}-devel = "${libvpx-devel_files}"
FILES_vpx-tools = "${vpx-tools_files}"
FILES_${PN} = "${libvpx_files}"

PKG_libvpx-devel= "libvpx-devel"
PKG_vpx-tools= "vpx-tools"
PKG_libvpx= "libvpx"

require libvpx-extraconf.inc
