DESCRIPTION = "Bluetooth framework for BlueZ and Obexd"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Bluetooth"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by bluetooth-frwk-core 
PROVIDES += "bluetooth-frwk-core"
RPROVIDES_bluetooth-frwk-core += "bluetooth-frwk-core"

#PROVIDES by bluetooth-frwk-devel 
PROVIDES += "bluetooth-frwk-devel"
RPROVIDES_bluetooth-frwk-devel += "bluetooth-frwk-devel"
RPROVIDES_bluetooth-frwk-devel += "bluetooth-frwk-dev"

#PROVIDES by bluetooth-frwk-service 
PROVIDES += "bluetooth-frwk-service"
RPROVIDES_bluetooth-frwk-service += "bluetooth-frwk-service"

#PROVIDES by bluetooth-frwk 
PROVIDES += "bluetooth-frwk"
RPROVIDES_bluetooth-frwk += "bluetooth-frwk"

RDEPENDS = ""
#RDEPENDS of bluetooth-frwk-core (${PN}-core)
RDEPENDS_${PN}-core += "bluetooth-frwk"

#RDEPENDS of bluetooth-frwk-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "bluetooth-frwk"

#RDEPENDS of bluetooth-frwk-service (${PN}-service)
RDEPENDS_${PN}-service += "bluetooth-frwk"

#RDEPENDS of bluetooth-frwk (${PN})
RDEPENDS_${PN} += "bluetooth-tools"
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "syspopup"
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "vconf"


DEPENDS = ""
#DEPENDS of bluetooth-frwk 
DEPENDS += "pkgconfig(libprivilege-control)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(alarm-service)"
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(syspopup-caller)"
DEPENDS += "pkgconfig(capi-network-tethering)"
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(notification)"
DEPENDS += "pkgconfig(status)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bluetooth-frwk.manifest .
 
 
 
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
 
 
 export CFLAGS+="   -Wall -g -fvisibility=hidden -fPIC"
 export LDFLAGS+=" -Wl,--rpath=/usr/lib -Wl,--as-needed -Wl,--unresolved-symbols=ignore-in-shared-libs"
 
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
 	-DMULTI_USER_SUPPORT=Off \
  -DLIBNOTIFY_SUPPORT=Off \
  -DLIBNOTIFICATION_SUPPORT=Off
 
 make
 
 
 
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
 	mkdir -p ${D}/etc/rc.d/rc3.d/
 	mkdir -p ${D}/etc/rc.d/rc5.d/
 	ln -s /etc/rc.d/init.d/bluetooth-frwk-service ${D}/etc/rc.d/rc3.d/S80bluetooth-frwk-service
 	ln -s /etc/rc.d/init.d/bluetooth-frwk-service ${D}/etc/rc.d/rc5.d/S80bluetooth-frwk-service
 
 mkdir -p ${D}/lib/systemd/user
 mkdir -p ${D}/lib/systemd/user/tizen-middleware.target.wants
 install -m 0644 bt-service/bluetooth-frwk-service.service ${D}/lib/systemd/user
 ln -s ../bluetooth-frwk-service.service ${D}/lib/systemd/user/tizen-middleware.target.wants/bluetooth-frwk-service.service
 
 
 
}

PACKAGES = ""
PACKAGES += "bluetooth-frwk-devel"
PACKAGES += "bluetooth-frwk-core"
PACKAGES += "bluetooth-frwk-service"
PACKAGES += "bluetooth-frwk"

bluetooth-frwk-devel_files = ""
bluetooth-frwk-devel_files += "bluetooth-frwk.manifest"
bluetooth-frwk-devel_files += "/usr/include/bt-service/bluetooth-api.h"
bluetooth-frwk-devel_files += "/usr/include/bt-service/bluetooth-hid-api.h"
bluetooth-frwk-devel_files += "/usr/include/bt-service/bluetooth-audio-api.h"
bluetooth-frwk-devel_files += "/usr/include/bt-service/bluetooth-telephony-api.h"
bluetooth-frwk-devel_files += "/usr/include/bt-service/bluetooth-media-control.h"
bluetooth-frwk-devel_files += "/usr/lib/pkgconfig/bluetooth-api.pc"
bluetooth-frwk-devel_files += "/usr/lib/libbluetooth-api.so"

bluetooth-frwk-core_files = ""
bluetooth-frwk-core_files += "bluetooth-frwk.manifest"
bluetooth-frwk-core_files += "/usr/share/dbus-1/system-services/org.projectx.bt_core.service"
bluetooth-frwk-core_files += "/usr/bin/bt-core"
bluetooth-frwk-core_files += "/etc/dbus-1/system.d/bluetooth-frwk-core.conf"

bluetooth-frwk-service_files = ""
bluetooth-frwk-service_files += "bluetooth-frwk.manifest"
bluetooth-frwk-service_files += "/usr/share/dbus-1/system-services/org.projectx.bt.service"
bluetooth-frwk-service_files += "/etc/rc.d/init.d/bluetooth-frwk-service"
bluetooth-frwk-service_files += "/etc/rc.d/rc3.d/S80bluetooth-frwk-service"
bluetooth-frwk-service_files += "/etc/rc.d/rc5.d/S80bluetooth-frwk-service"
bluetooth-frwk-service_files += "/usr/bin/bt-service"
bluetooth-frwk-service_files += "/lib/systemd/user/tizen-middleware.target.wants/bluetooth-frwk-service.service"
bluetooth-frwk-service_files += "/lib/systemd/user/bluetooth-frwk-service.service"
bluetooth-frwk-service_files += "/etc/dbus-1/system.d/bluetooth-frwk-service.conf"

bluetooth-frwk_files = ""
bluetooth-frwk_files += "bluetooth-frwk.manifest"
bluetooth-frwk_files += "/usr/lib/libbluetooth-api.so.*"

FILES_${PN}-devel = "${bluetooth-frwk-devel_files}"
FILES_${PN}-core = "${bluetooth-frwk-core_files}"
FILES_${PN}-service = "${bluetooth-frwk-service_files}"
FILES_${PN} = "${bluetooth-frwk_files}"

PKG_bluetooth-frwk-devel= "bluetooth-frwk-devel"
PKG_bluetooth-frwk-core= "bluetooth-frwk-core"
PKG_bluetooth-frwk-service= "bluetooth-frwk-service"
PKG_bluetooth-frwk= "bluetooth-frwk"

require bluetooth-frwk-extraconf.inc
