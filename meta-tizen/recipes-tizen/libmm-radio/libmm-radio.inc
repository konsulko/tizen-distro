DESCRIPTION = "Multimedia Framework Radio Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmm-radio-test 
PROVIDES += "libmm-radio-test"
RPROVIDES_libmm-radio-test += "libmm-radio-test"

#PROVIDES by libmm-radio-devel 
PROVIDES += "libmm-radio-devel"
RPROVIDES_libmm-radio-devel += "libmm-radio-devel"
RPROVIDES_libmm-radio-devel += "libmm-radio-dev"

#PROVIDES by libmm-radio 
PROVIDES += "libmm-radio"
RPROVIDES_libmm-radio += "libmm-radio"

RDEPENDS = ""
#RDEPENDS of libmm-radio-test (${PN}-test)
RDEPENDS_${PN}-test += "libmm-radio"

#RDEPENDS of libmm-radio-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmm-radio"


DEPENDS = ""
#DEPENDS of libmm-radio 
DEPENDS += "libmm-common"
DEPENDS += "pkgconfig(gstreamer-1.0)"
DEPENDS += "pkgconfig(gstreamer-plugins-base-1.0)"
DEPENDS += "audio-session-manager"
DEPENDS += "libmm-log"
DEPENDS += "pkgconfig(mm-sound)"
DEPENDS += "pkgconfig(mm-session)"
DEPENDS += "pkgconfig(mm-ta)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-radio.manifest .
 
 
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
 
 export GSTREAMER_API="-DGST_API_VERSION_1=1"
 export use_gstreamer_1=1
 
 CFLAGS=" -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables  -DGST_EXT_TIME_ANALYSIS -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" $GSTREAMER_API"; export CFLAGS;
 
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
PACKAGES += "libmm-radio-test"
PACKAGES += "libmm-radio-devel"
PACKAGES += "libmm-radio"

libmm-radio-test_files = ""
libmm-radio-test_files += "libmm-radio.manifest"
libmm-radio-test_files += "/usr/bin/mm_radio_testsuite"

libmm-radio-devel_files = ""
libmm-radio-devel_files += "libmm-radio.manifest"
libmm-radio-devel_files += "/usr/lib/libmmfradio.so"
libmm-radio-devel_files += "/usr/lib/pkgconfig/mm-radio.pc"
libmm-radio-devel_files += "/usr/include/mmf/mm_radio.h"

libmm-radio_files = ""
libmm-radio_files += "libmm-radio.manifest"
libmm-radio_files += "/usr/lib/libmmfradio.so.*"

FILES_${PN}-test = "${libmm-radio-test_files}"
FILES_${PN}-devel = "${libmm-radio-devel_files}"
FILES_${PN} = "${libmm-radio_files}"

PKG_libmm-radio-test= "libmm-radio-test"
PKG_libmm-radio-devel= "libmm-radio-devel"
PKG_libmm-radio= "libmm-radio"

require libmm-radio-extraconf.inc
