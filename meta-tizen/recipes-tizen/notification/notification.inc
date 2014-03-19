DESCRIPTION = "Notification Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by notification 
PROVIDES += "notification"
RPROVIDES_notification += "notification"

#PROVIDES by notification-devel 
PROVIDES += "notification-devel"
RPROVIDES_notification-devel += "notification-devel"
RPROVIDES_notification-devel += "notification-dev"

RDEPENDS = ""
#RDEPENDS of notification (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "/usr/bin/sqlite3"

#RDEPENDS of notification-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "notification"


DEPENDS = ""
#DEPENDS of notification 
DEPENDS += "cmake"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "ecore"
DEPENDS += "bundle"
DEPENDS += "ail"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(com-core)"
DEPENDS += "heynoti"
DEPENDS += "pkgconfig(eina)"
DEPENDS += "libslp-db-util"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/notification.manifest .
 
 
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
 
 mkdir -p ${D}/usr/share/license
 cp -f LICENSE.APLv2.0 ${D}/usr/share/license/notification
 
 
}

PACKAGES = ""
PACKAGES += "notification"
PACKAGES += "notification-devel"

notification_files = ""
notification_files += "notification.manifest"
notification_files += "/usr/lib/libnotification.so*"
notification_files += "/usr/share/license/notification"

notification-devel_files = ""
notification-devel_files += "/usr/include/notification/*.h"
notification-devel_files += "/usr/lib/pkgconfig/notification.pc"

FILES_${PN} = "${notification_files}"
FILES_${PN}-devel = "${notification-devel_files}"

PKG_notification= "notification"
PKG_notification-devel= "notification-devel"

require notification-extraconf.inc
