DESCRIPTION = "Wayland Compositor Infrastructure"
HOMEPAGE = "http://weston.freedesktop.org/"
SECTION = "Graphics & UI Framework/Wayland Window System"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by weston 
PROVIDES += "weston"
RPROVIDES_weston += "weston"

#PROVIDES by weston-devel 
PROVIDES += "weston-devel"
RPROVIDES_weston-devel += "weston-devel"
RPROVIDES_weston-devel += "weston-dev"

#PROVIDES by weston-docs  
PROVIDES += "weston-docs "
RPROVIDES_weston-docs  += "weston-docs "

#PROVIDES by weston-clients 
PROVIDES += "weston-clients"
RPROVIDES_weston-clients += "weston-clients"

RDEPENDS = ""
#RDEPENDS of weston (${PN})
RDEPENDS_${PN} += "weston-startup"
RDEPENDS_${PN} += "/usr/sbin/groupadd"


DEPENDS = ""
#DEPENDS of weston 
DEPENDS += "expat"
DEPENDS += "libvpx"
DEPENDS += "xz"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "pkgconfig(cairo-egl)"
DEPENDS += "systemd"
DEPENDS += "pkgconfig(wayland-server)"
DEPENDS += "poppler"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pam"
DEPENDS += "pixman"
DEPENDS += "pkgconfig(libffi)"
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(mtdev)"
DEPENDS += "mesa"
DEPENDS += "libxkbcommon"
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "libjpeg-turbo"
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "autoconf-native"
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/weston.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --disable-setuid-install  --enable-simple-clients --enable-clients --disable-libunwind --disable-xwayland --disable-xwayland-test --disable-x11-compositor --disable-rpi-compositor 
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
 
 # install example clients
 install -m 755 clients/weston-simple-touch ${D}/usr/bin
 install -m 755 clients/weston-simple-shm ${D}/usr/bin
 install -m 755 clients/weston-simple-egl ${D}/usr/bin
 install -m 755 clients/weston-flower ${D}/usr/bin
 install -m 755 clients/weston-image ${D}/usr/bin
 install -m 755 clients/weston-cliptest ${D}/usr/bin
 install -m 755 clients/weston-dnd ${D}/usr/bin
 install -m 755 clients/weston-smoke ${D}/usr/bin
 install -m 755 clients/weston-resizor ${D}/usr/bin
 install -m 755 clients/weston-eventdemo ${D}/usr/bin
 install -m 755 clients/weston-clickdot ${D}/usr/bin
 install -m 755 clients/weston-transformed ${D}/usr/bin
 install -m 755 clients/weston-fullscreen ${D}/usr/bin
 install -m 755 clients/weston-calibrator ${D}/usr/bin
 
 install -d ${D}/usr/lib/systemd/user
 install -m 644 ${S}/packaging/weston.target ${D}/usr/lib/systemd/user/weston.target
 # The weston.service unit file must be provided by the weston-startup
 # virtual package, i.e. "Provide: weston-startup".  The weston-startup
 # virtual package requirement is intended to force Tizen profile
 # maintainers to add the necessary start-up script or systemd unit
 # file to start weston. Otherwise it becomes possible to install
 # weston without an automated means to start weston at boot, which may
 # lead to confusion.  This approach allows startup related files to be
 # maintained outside of this weston package.
 
 
}

PACKAGES = ""
PACKAGES += "weston"
PACKAGES += "weston-clients"
PACKAGES += "weston-docs"
PACKAGES += "weston-devel"

weston_files = ""
weston_files += "weston.manifest"
weston_files += "/usr/bin/wcap-*"
weston_files += "/usr/bin/weston"
weston_files += "/usr/bin/weston-info"
weston_files += "/usr/bin/weston-terminal"
weston_files += "/usr/libexec/weston-*"
weston_files += "/usr/lib/weston"
weston_files += "/usr/share/weston"
weston_files += "/usr/lib/systemd/user/weston.target"

weston-clients_files = ""
weston-clients_files += "weston.manifest"
weston-clients_files += "/usr/bin/weston-simple-touch"
weston-clients_files += "/usr/bin/weston-simple-shm"
weston-clients_files += "/usr/bin/weston-simple-egl"
weston-clients_files += "/usr/bin/weston-flower"
weston-clients_files += "/usr/bin/weston-image"
weston-clients_files += "/usr/bin/weston-cliptest"
weston-clients_files += "/usr/bin/weston-dnd"
weston-clients_files += "/usr/bin/weston-smoke"
weston-clients_files += "/usr/bin/weston-resizor"
weston-clients_files += "/usr/bin/weston-eventdemo"
weston-clients_files += "/usr/bin/weston-clickdot"
weston-clients_files += "/usr/bin/weston-transformed"
weston-clients_files += "/usr/bin/weston-fullscreen"
weston-clients_files += "/usr/bin/weston-calibrator"

weston-docs_files = ""
weston-docs_files += "/usr/share/info"
weston-docs_files += "/usr/share/man"

weston-devel_files = ""
weston-devel_files += "weston.manifest"
weston-devel_files += "/usr/include/weston/*.h"
weston-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${weston_files}"
FILES_${PN}-clients = "${weston-clients_files}"
FILES_${PN}-docs = "${weston-docs_files}"
FILES_${PN}-devel = "${weston-devel_files}"

PKG_weston= "weston"
PKG_weston-clients= "weston-clients"
PKG_weston-docs= "weston-docs"
PKG_weston-devel= "weston-devel"

require weston-extraconf.inc
