DESCRIPTION = "Multimedia Framework Player Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmm-player-devel 
PROVIDES += "libmm-player-devel"
RPROVIDES_libmm-player-devel += "libmm-player-devel"
RPROVIDES_libmm-player-devel += "libmm-player-dev"

#PROVIDES by libmm-player 
PROVIDES += "libmm-player"
RPROVIDES_libmm-player += "libmm-player"

RDEPENDS = ""
#RDEPENDS of libmm-player-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmm-player"


DEPENDS = ""
#DEPENDS of libmm-player 
DEPENDS += "pkgconfig(mm-session)"
DEPENDS += "pkgconfig(gstreamer-app-1.0)"
DEPENDS += "pkgconfig(gstreamer-plugins-base-1.0)"
DEPENDS += "audio-session-manager"
DEPENDS += "libmm-common"
DEPENDS += "pkgconfig(mm-sound)"
DEPENDS += "pkgconfig(mmutil-imgp)"
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "pkgconfig(iniparser)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(gstreamer-1.0)"
DEPENDS += "pkgconfig(mm-ta)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-player.manifest .
 
 
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
 
 
 ##  
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
         --infodir=/usr/share/info.sh
 
 export GSTREAMER_API="-DGST_API_VERSION_1=1"
 export use_gstreamer_1=1
 
 CFLAGS+=" -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" $GSTREAMER_API" ; export CFLAGS
 LDFLAGS+="-Wl,--rpath=/usr/lib -lgstvideo-1.0 -Wl,--hash-style=both -Wl,--as-needed"; export LDFLAGS
 
 
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
         --infodir=/usr/share/info --disable-static
 
 make -j1 
 
 
 
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
PACKAGES += "libmm-player-devel"
PACKAGES += "libmm-player"

libmm-player-devel_files = ""
libmm-player-devel_files += "libmm-player.manifest"
libmm-player-devel_files += "/usr/lib/*.so"
libmm-player-devel_files += "/usr/include/mmf/*.h"
libmm-player-devel_files += "/usr/lib/pkgconfig/*"

libmm-player_files = ""
libmm-player_files += "libmm-player.manifest"
libmm-player_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${libmm-player-devel_files}"
FILES_${PN} = "${libmm-player_files}"

PKG_libmm-player-devel= "libmm-player-devel"
PKG_libmm-player= "libmm-player"

require libmm-player-extraconf.inc
