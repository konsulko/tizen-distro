DESCRIPTION = "System server"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by system-server-system-server 
PROVIDES += "system-server-system-server"
RPROVIDES_system-server-system-server += "system-server-system-server"

#PROVIDES by libdeviced-devel 
PROVIDES += "libdeviced-devel"
RPROVIDES_libdeviced-devel += "libdeviced-devel"
RPROVIDES_libdeviced-devel += "libdeviced-dev"

#PROVIDES by libdeviced 
PROVIDES += "libdeviced"
RPROVIDES_libdeviced += "libdeviced"

#PROVIDES by sysman-devel 
PROVIDES += "sysman-devel"
RPROVIDES_sysman-devel += "sysman-devel"
RPROVIDES_sysman-devel += "sysman-dev"

#PROVIDES by libhaptic 
PROVIDES += "libhaptic"
RPROVIDES_libhaptic += "libhaptic"

#PROVIDES by libslp-pm-devel 
PROVIDES += "libslp-pm-devel"
RPROVIDES_libslp-pm-devel += "libslp-pm-devel"
RPROVIDES_libslp-pm-devel += "libslp-pm-dev"

#PROVIDES by libslp-pm 
PROVIDES += "libslp-pm"
RPROVIDES_libslp-pm += "libslp-pm"

#PROVIDES by system-server 
PROVIDES += "system-server"
RPROVIDES_system-server += "system-server"

#PROVIDES by sysman-internal-devel 
PROVIDES += "sysman-internal-devel"
RPROVIDES_sysman-internal-devel += "sysman-internal-devel"
RPROVIDES_sysman-internal-devel += "sysman-internal-dev"

#PROVIDES by libhaptic-devel 
PROVIDES += "libhaptic-devel"
RPROVIDES_libhaptic-devel += "libhaptic-devel"
RPROVIDES_libhaptic-devel += "libhaptic-dev"

#PROVIDES by libhaptic-plugin-devel 
PROVIDES += "libhaptic-plugin-devel"
RPROVIDES_libhaptic-plugin-devel += "libhaptic-plugin-devel"
RPROVIDES_libhaptic-plugin-devel += "libhaptic-plugin-dev"

#PROVIDES by libdevman-haptic-devel 
PROVIDES += "libdevman-haptic-devel"
RPROVIDES_libdevman-haptic-devel += "libdevman-haptic-devel"
RPROVIDES_libdevman-haptic-devel += "libdevman-haptic-dev"

#PROVIDES by sysman 
PROVIDES += "sysman"
RPROVIDES_sysman += "sysman"

#PROVIDES by libdevman-devel 
PROVIDES += "libdevman-devel"
RPROVIDES_libdevman-devel += "libdevman-devel"
RPROVIDES_libdevman-devel += "libdevman-dev"

#PROVIDES by libdevman 
PROVIDES += "libdevman"
RPROVIDES_libdevman += "libdevman"

RDEPENDS = ""
#RDEPENDS of system-server-system-server (${PN}-${PN})
RDEPENDS_${PN}-${PN} += "system-server"

#RDEPENDS of libhaptic (libhaptic)
RDEPENDS_libhaptic += "system-server"

#RDEPENDS of system-server (${PN})
RDEPENDS_${PN} += "/usr/bin/systemctl"
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "/usr/bin/vconftool"

#RDEPENDS of sysman-devel (sysman-devel)
RDEPENDS_sysman-devel += "system-server"

#RDEPENDS of libslp-pm-devel (libslp-pm-devel)
RDEPENDS_libslp-pm-devel += "libslp-pm"

#RDEPENDS of libslp-pm (libslp-pm)
RDEPENDS_libslp-pm += "system-server"

#RDEPENDS of libdeviced-devel (libdeviced-devel)
RDEPENDS_libdeviced-devel += "libdeviced"

#RDEPENDS of sysman-internal-devel (sysman-internal-devel)
RDEPENDS_sysman-internal-devel += "system-server"

#RDEPENDS of libhaptic-devel (libhaptic-devel)
RDEPENDS_libhaptic-devel += "libhaptic"

#RDEPENDS of libdevman-haptic-devel (libdevman-haptic-devel)
RDEPENDS_libdevman-haptic-devel += "libdevman-dev"

#RDEPENDS of sysman (sysman)
RDEPENDS_sysman += "system-server"

#RDEPENDS of libdevman-devel (libdevman-devel)
RDEPENDS_libdevman-devel += "libdevman"

#RDEPENDS of libdevman (libdevman)
RDEPENDS_libdevman += "system-server"


DEPENDS = ""
#DEPENDS of system-server 
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "cmake"
DEPENDS += "attr"
DEPENDS += "pkgconfig(device-node)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "notification"
DEPENDS += "syspopup"
DEPENDS += "pkgconfig(udev)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(usbutils)"
DEPENDS += "smack"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "libslp-sensor"
DEPENDS += "heynoti"
DEPENDS += "pkgconfig(edbus)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
     -DCMAKE_INSTALL_PREFIX=/usr \
     -DX11_SUPPORT=Off \
     #eol
 
 
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
 
 cp ${S}/packaging/system-server.manifest .
 cp ${S}/packaging/deviced.manifest .
 cp ${S}/packaging/sysman.manifest .
 cp ${S}/packaging/libslp-pm.manifest .
 cp ${S}/packaging/haptic.manifest .
 cp ${S}/packaging/devman.manifest .
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 
 
 
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
 
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../system-server.service  ${D}//lib/systemd/system/multi-user.target.wants/system-server.service  
 
 mkdir -p ${D}//lib/systemd/system/sockets.target.wants 
 ln -s ../system-server.service  ${D}//lib/systemd/system/sockets.target.wants/system-server.service  
 
 
 mkdir -p ${D}//lib/systemd/system/graphical.target.wants 
 ln -s ../regpmon.service  ${D}//lib/systemd/system/graphical.target.wants/regpmon.service  
 install -m 0644 ${S}/packaging/regpmon.service ${D}/lib/systemd/system/regpmon.service
 
 
 mkdir -p ${D}//lib/systemd/system/graphical.target.wants 
 ln -s ../zbooting-done.service  ${D}//lib/systemd/system/graphical.target.wants/zbooting-done.service  
 install -m 0644 ${S}/packaging/zbooting-done.service ${D}/lib/systemd/system/zbooting-done.service
 
 
 
}

PACKAGES = ""
PACKAGES += "libdevman-devel"
PACKAGES += "libhaptic"
PACKAGES += "system-server"
PACKAGES += "sysman-devel"
PACKAGES += "libslp-pm-devel"
PACKAGES += "libdevman"
PACKAGES += "libslp-pm"
PACKAGES += "libdeviced-devel"
PACKAGES += "sysman-internal-devel"
PACKAGES += "libhaptic-devel"
PACKAGES += "libhaptic-plugin-devel"
PACKAGES += "libdevman-haptic-devel"
PACKAGES += "libdeviced"
PACKAGES += "sysman"

libdevman-devel_files = ""
libdevman-devel_files += "/usr/include/devman/devman.h"
libdevman-devel_files += "/usr/include/devman/devman_image.h"
libdevman-devel_files += "/usr/include/devman/devman_managed.h"
libdevman-devel_files += "/usr/include/devman/devman_haptic.h"
libdevman-devel_files += "/usr/include/devman/devman_PG.h"
libdevman-devel_files += "/usr/lib/pkgconfig/devman.pc"
libdevman-devel_files += "/usr/lib/libdevman.so"

libhaptic_files = ""
libhaptic_files += "/usr/lib/libhaptic.so.*"
libhaptic_files += "haptic.manifest"

system-server_files = ""
system-server_files += "system-server.manifest"
system-server_files += "/etc/dbus-1/system.d/system-server.conf"
system-server_files += "/usr/bin/system_server"
system-server_files += "/opt/etc/smack/accesses.d/system-server.rule"
system-server_files += "/usr/lib/system-server/shutdown.sh"
system-server_files += "/usr/bin/restart"
system-server_files += "/usr/bin/movi_format.sh"
system-server_files += "/usr/bin/sys_event"
system-server_files += "/usr/bin/pm_event"
system-server_files += "/usr/bin/regpmon"
system-server_files += "/usr/bin/set_pmon"
system-server_files += "/usr/bin/pmon"
system-server_files += "/usr/bin/sys_pci_noti"
system-server_files += "/usr/bin/mmc-smack-label"
system-server_files += "/usr/bin/device-daemon"
system-server_files += "/usr/bin/fsck_msdosfs"
system-server_files += "/lib/systemd/system/multi-user.target.wants/system-server.service"
system-server_files += "/lib/systemd/system/graphical.target.wants/regpmon.service"
system-server_files += "/lib/systemd/system/sockets.target.wants/system-server.service"
system-server_files += "/lib/systemd/system/system-server.service"
system-server_files += "/lib/systemd/system/system-server.socket"
system-server_files += "/lib/systemd/system/regpmon.service"
system-server_files += "/lib/systemd/system/graphical.target.wants/zbooting-done.service"
system-server_files += "/lib/systemd/system/zbooting-done.service"
system-server_files += "/usr/share/system-server/sys_pci_noti/res/locale/*/LC_MESSAGES/*.mo"
system-server_files += "/etc/dbus-1/system.d/system-server.conf"
system-server_files += "/usr/share/license/fsck_msdosfs"

sysman-devel_files = ""
sysman-devel_files += "/usr/include/sysman/sysman.h"
sysman-devel_files += "/usr/include/sysman/sysman_managed.h"
sysman-devel_files += "/usr/include/sysman/sysman_PG.h"
sysman-devel_files += "/usr/lib/pkgconfig/sysman.pc"
sysman-devel_files += "/usr/lib/libsysman.so"

libslp-pm-devel_files = ""
libslp-pm-devel_files += "/usr/include/pmapi/pmapi.h"
libslp-pm-devel_files += "/usr/include/pmapi/pmapi_managed.h"
libslp-pm-devel_files += "/usr/include/pmapi/pm_PG.h"
libslp-pm-devel_files += "/usr/lib/pkgconfig/pmapi.pc"
libslp-pm-devel_files += "/usr/lib/libpmapi.so"

libdevman_files = ""
libdevman_files += "/usr/bin/display_wd"
libdevman_files += "/usr/lib/libdevman.so.*"
libdevman_files += "devman.manifest"

libslp-pm_files = ""
libslp-pm_files += "libslp-pm.manifest"
libslp-pm_files += "/usr/lib/libpmapi.so.*"

libdeviced-devel_files = ""
libdeviced-devel_files += "/usr/include/deviced/dd-battery.h"
libdeviced-devel_files += "/usr/include/deviced/dd-control.h"
libdeviced-devel_files += "/usr/include/deviced/dd-deviced.h"
libdeviced-devel_files += "/usr/include/deviced/dd-deviced-managed.h"
libdeviced-devel_files += "/usr/include/deviced/dd-display.h"
libdeviced-devel_files += "/usr/include/deviced/dd-haptic.h"
libdeviced-devel_files += "/usr/include/deviced/dd-led.h"
libdeviced-devel_files += "/usr/include/deviced/haptic-module.h"
libdeviced-devel_files += "/usr/include/deviced/haptic-plugin-intf.h"
libdeviced-devel_files += "/usr/lib/libdeviced.so"
libdeviced-devel_files += "/usr/lib/pkgconfig/deviced.pc"

sysman-internal-devel_files = ""
sysman-internal-devel_files += "/usr/include/sysman/sysman-internal.h"

libhaptic-devel_files = ""
libhaptic-devel_files += "/usr/include/haptic/haptic.h"
libhaptic-devel_files += "/usr/lib/libhaptic.so"
libhaptic-devel_files += "/usr/lib/pkgconfig/haptic.pc"

libhaptic-plugin-devel_files = ""
libhaptic-plugin-devel_files += "/usr/include/haptic/haptic_module.h"
libhaptic-plugin-devel_files += "/usr/include/haptic/haptic_plugin_intf.h"
libhaptic-plugin-devel_files += "/usr/include/haptic/haptic_PG.h"
libhaptic-plugin-devel_files += "/usr/lib/pkgconfig/haptic-plugin.pc"

libdevman-haptic-devel_files = ""
libdevman-haptic-devel_files += "/usr/include/devman/devman_haptic_ext.h"
libdevman-haptic-devel_files += "/usr/include/devman/devman_haptic_ext_core.h"
libdevman-haptic-devel_files += "/usr/lib/pkgconfig/devman_haptic.pc"

libdeviced_files = ""
libdeviced_files += "/usr/lib/libdeviced.so.*"
libdeviced_files += "deviced.manifest"

sysman_files = ""
sysman_files += "sysman.manifest"
sysman_files += "/usr/lib/libsysman.so.*"
sysman_files += "/usr/bin/regpmon"
sysman_files += "/usr/bin/set_pmon"

FILES_libdevman-devel = "${libdevman-devel_files}"
FILES_libhaptic = "${libhaptic_files}"
FILES_${PN} = "${system-server_files}"
FILES_sysman-devel = "${sysman-devel_files}"
FILES_libslp-pm-devel = "${libslp-pm-devel_files}"
FILES_libdevman = "${libdevman_files}"
FILES_libslp-pm = "${libslp-pm_files}"
FILES_libdeviced-devel = "${libdeviced-devel_files}"
FILES_sysman-internal-devel = "${sysman-internal-devel_files}"
FILES_libhaptic-devel = "${libhaptic-devel_files}"
FILES_libhaptic-plugin-devel = "${libhaptic-plugin-devel_files}"
FILES_libdevman-haptic-devel = "${libdevman-haptic-devel_files}"
FILES_libdeviced = "${libdeviced_files}"
FILES_sysman = "${sysman_files}"

PKG_libdevman-devel= "libdevman-devel"
PKG_libhaptic= "libhaptic"
PKG_system-server= "system-server"
PKG_sysman-devel= "sysman-devel"
PKG_libslp-pm-devel= "libslp-pm-devel"
PKG_libdevman= "libdevman"
PKG_libslp-pm= "libslp-pm"
PKG_libdeviced-devel= "libdeviced-devel"
PKG_sysman-internal-devel= "sysman-internal-devel"
PKG_libhaptic-devel= "libhaptic-devel"
PKG_libhaptic-plugin-devel= "libhaptic-plugin-devel"
PKG_libdevman-haptic-devel= "libdevman-haptic-devel"
PKG_libdeviced= "libdeviced"
PKG_sysman= "sysman"

require system-server-extraconf.inc
