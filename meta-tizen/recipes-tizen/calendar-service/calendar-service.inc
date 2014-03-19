DESCRIPTION = "DB library for calendar"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by calendar-service 
PROVIDES += "calendar-service"
RPROVIDES_calendar-service += "calendar-service"

#PROVIDES by calendar-service-devel 
PROVIDES += "calendar-service-devel"
RPROVIDES_calendar-service-devel += "calendar-service-devel"
RPROVIDES_calendar-service-devel += "calendar-service-dev"

RDEPENDS = ""
#RDEPENDS of calendar-service (${PN})
RDEPENDS_${PN} += "/bin/chown"
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "/usr/bin/sqlite3"

#RDEPENDS of calendar-service-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "calendar-service"
RDEPENDS_${PN}-devel += "pkgconfig(alarm-service)"


DEPENDS = ""
#DEPENDS of calendar-service 
DEPENDS += "pkgconfig(pims-ipc)"
DEPENDS += "pkgconfig(contacts-service2)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(alarm-service)"
DEPENDS += "pkgconfig(capi-base-common)"
DEPENDS += "app-svc"
DEPENDS += "bundle"
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(db-util)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/calendar-service.manifest .
 
 
 
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
 
 mkdir -p ${D}/etc/rc.d/rc3.d/
 mkdir -p ${D}/etc/rc.d/rc5.d/
 ln -s ../init.d/calendar-serviced.sh ${D}/etc/rc.d/rc3.d/S85calendar-serviced
 ln -s ../init.d/calendar-serviced.sh ${D}/etc/rc.d/rc5.d/S85calendar-serviced
 
 mkdir -p ${D}/lib/systemd/user/tizen-middleware.target.wants
 install ${S}/packaging/calendar.service ${D}/lib/systemd/user/
 ln -s ../calendar.service ${D}/lib/systemd/user/tizen-middleware.target.wants/
 
 
}

PACKAGES = ""
PACKAGES += "calendar-service"
PACKAGES += "calendar-service-devel"

calendar-service_files = ""
calendar-service_files += "calendar-service.manifest"
calendar-service_files += "/usr/bin/calendar-serviced*"
calendar-service_files += "/usr/lib/libcalendar-service2.so.*"
calendar-service_files += "/etc/rc.d/rc3.d/S85calendar-serviced"
calendar-service_files += "/etc/rc.d/rc5.d/S85calendar-serviced"
#Remove rpm attribut "%attr(0775,root,root)"
calendar-service_files += "/opt/usr/data/calendar-svc/"
calendar-service_files += "/opt/usr/data/calendar-svc/.CALENDAR_SVC_CALENDAR_CHANGED"
calendar-service_files += "/opt/usr/data/calendar-svc/.CALENDAR_SVC_EVENT_CHANGED"
calendar-service_files += "/opt/usr/data/calendar-svc/.CALENDAR_SVC_TODO_CHANGED"
calendar-service_files += "/usr/share/calendar-svc/dft-calendar"
calendar-service_files += "/opt/usr/dbspace/.calendar-svc.db*"
calendar-service_files += "/lib/systemd/user/calendar.service"
calendar-service_files += "/lib/systemd/user/tizen-middleware.target.wants/calendar.service"

calendar-service-devel_files = ""
calendar-service-devel_files += "calendar-service.manifest"
calendar-service-devel_files += "/usr/include/calendar-service/*.h"
calendar-service-devel_files += "/usr/include/calendar-service2/*.h"
calendar-service-devel_files += "/usr/lib/*.so"
calendar-service-devel_files += "/usr/lib/pkgconfig/calendar.pc"
calendar-service-devel_files += "/usr/lib/pkgconfig/calendar-service2.pc"
calendar-service-devel_files += "/opt/usr/data/calendar-svc/calendar-svc-initdb"

FILES_${PN} = "${calendar-service_files}"
FILES_${PN}-devel = "${calendar-service-devel_files}"

PKG_calendar-service= "calendar-service"
PKG_calendar-service-devel= "calendar-service-devel"

require calendar-service-extraconf.inc
