DESCRIPTION = "Bluetooth file share Agent"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Bluetooth"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libbluetooth-share-devel 
PROVIDES += "libbluetooth-share-devel"
RPROVIDES_libbluetooth-share-devel += "libbluetooth-share-devel"
RPROVIDES_libbluetooth-share-devel += "libbluetooth-share-dev"

#PROVIDES by libbluetooth-share 
PROVIDES += "libbluetooth-share"
RPROVIDES_libbluetooth-share += "libbluetooth-share"

#PROVIDES by bluetooth-share 
PROVIDES += "bluetooth-share"
RPROVIDES_bluetooth-share += "bluetooth-share"

RDEPENDS = ""
#RDEPENDS of libbluetooth-share-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "bluetooth-share"

#RDEPENDS of libbluetooth-share (lib${PN})
RDEPENDS_lib${PN} += "bluetooth-share"

#RDEPENDS of bluetooth-share (${PN})
RDEPENDS_${PN} += "coreutils"
RDEPENDS_${PN} += "sqlite"
RDEPENDS_${PN} += "smack"
RDEPENDS_${PN} += "vconf"


DEPENDS = ""
#DEPENDS of bluetooth-share 
DEPENDS += "pkgconfig(libprivilege-control)"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "app-svc"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(sysman)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(syspopup-caller)"
DEPENDS += "pkgconfig(contacts-service2)"
DEPENDS += "app-core"
DEPENDS += "pkgconfig(pmapi)"
DEPENDS += "pkgconfig(capi-content-media-content)"
DEPENDS += "pkgconfig(calendar-service2)"
DEPENDS += "pkgconfig(libtzplatform-config)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(notification)"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "bluetooth-frwk"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bluetooth-share.manifest ${S}/packaging/libbluetooth-share.manifest ${S}/packaging/libbluetooth-share-devel.manifest .
 
 
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
 
 export CFLAGS+=" -fpie -fvisibility=hidden"
 export LDFLAGS+=" -Wl,--rpath=/usr//usr/lib -Wl,--as-needed -Wl,--unresolved-symbols=ignore-in-shared-libs -pie"
 
 
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
 make
 
 
 
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
 mkdir -p  ${D}%{TZ_SYS_SHARE}/bt-ftp
 install -D -m 0755 ${S}/packaging/init_db.sh ${D}%{TZ_SYS_SHARE}/bluetooth-share/ressources/init_db.sh
 
 
}

PACKAGES = ""
PACKAGES += "libbluetooth-share-devel"
PACKAGES += "libbluetooth-share"
PACKAGES += "bluetooth-share"

libbluetooth-share-devel_files = ""
libbluetooth-share-devel_files += "libbluetooth-share-devel.manifest"
libbluetooth-share-devel_files += "/usr/include/bluetooth-share-api/bluetooth-share-api.h"
libbluetooth-share-devel_files += "/usr/lib/libbluetooth-share-api.so"
libbluetooth-share-devel_files += "/usr/lib/pkgconfig/bluetooth-share-api.pc"

libbluetooth-share_files = ""
libbluetooth-share_files += "libbluetooth-share.manifest"
libbluetooth-share_files += "/usr/lib/libbluetooth-share-api.so.0.*"

bluetooth-share_files = ""
bluetooth-share_files += "bluetooth-share.manifest"
bluetooth-share_files += "/usr/bin/bluetooth-share"
bluetooth-share_files += "/usr/share/dbus-1/system-services/org.bluetooth.share.service"

FILES_lib${PN}-devel = "${libbluetooth-share-devel_files}"
FILES_lib${PN} = "${libbluetooth-share_files}"
FILES_${PN} = "${bluetooth-share_files}"

PKG_libbluetooth-share-devel= "libbluetooth-share-devel"
PKG_libbluetooth-share= "libbluetooth-share"
PKG_bluetooth-share= "bluetooth-share"

require bluetooth-share-extraconf.inc
