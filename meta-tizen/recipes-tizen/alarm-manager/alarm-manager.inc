DESCRIPTION = "Alarm library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by alarm-manager 
PROVIDES += "alarm-manager"
RPROVIDES_alarm-manager += "alarm-manager"

#PROVIDES by libalarm 
PROVIDES += "libalarm"
RPROVIDES_libalarm += "libalarm"

#PROVIDES by alarm-server 
PROVIDES += "alarm-server"
RPROVIDES_alarm-server += "alarm-server"

#PROVIDES by libalarm-devel 
PROVIDES += "libalarm-devel"
RPROVIDES_libalarm-devel += "libalarm-devel"
RPROVIDES_libalarm-devel += "libalarm-dev"

RDEPENDS = ""
#RDEPENDS of libalarm (libalarm)
RDEPENDS_libalarm += "alarm-server"

#RDEPENDS of alarm-server (alarm-server)
RDEPENDS_alarm-server += "/usr/bin/systemctl"

#RDEPENDS of libalarm-devel (libalarm-devel)
RDEPENDS_libalarm-devel += "libalarm"


DEPENDS = ""
#DEPENDS of alarm-manager 
DEPENDS += "pkgconfig(pmapi)"
DEPENDS += "pkgconfig(bundle)"
DEPENDS += "pkgconfig(appsvc)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "pkgconfig(heynoti)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/alarm-manager.manifest .
 
 
 
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
         --infodir=/usr/share/info --disable-static
 dbus-binding-tool --mode=glib-server --prefix=alarm_manager ./alarm_mgr.xml > ./include/alarm-skeleton.h
 dbus-binding-tool --mode=glib-client --prefix=alarm_manager ./alarm_mgr.xml > ./include/alarm-stub.h
 dbus-binding-tool --mode=glib-server --prefix=alarm_client ./alarm-expire.xml > ./include/alarm-expire-skeleton.h
 dbus-binding-tool --mode=glib-client --prefix=alarm_client ./alarm-expire.xml > ./include/alarm-expire-stub.h
 
 
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
 
 install -d ${D}/lib/systemd/system/multi-user.target.wants
 install -m0644 ${S}/packaging/alarm-server.service ${D}/lib/systemd/system
 ln -sf ../alarm-server.service ${D}/lib/systemd/system/multi-user.target.wants/alarm-server.service
 
 mkdir -p ${D}//etc/udev/rules.d
 install -m0644  ${S}/packaging/60-alarm-manager-rtc.rules ${D}/etc/udev/rules.d/
 
 mkdir -p ${D}//etc/dbus-1/system.d
 install -m0644  ${S}/packaging/alarm-service.conf ${D}/etc/dbus-1/system.d/
 
 
}

PACKAGES = ""
PACKAGES += "libalarm"
PACKAGES += "alarm-server"
PACKAGES += "libalarm-devel"

libalarm_files = ""
libalarm_files += "alarm-manager.manifest"
libalarm_files += "alarm-lib.manifest"
libalarm_files += "/usr/lib/libalarm.so.0"

alarm-server_files = ""
alarm-server_files += "alarm-manager.manifest"
alarm-server_files += "/lib/systemd/system/multi-user.target.wants/alarm-server.service"
alarm-server_files += "/lib/systemd/system/alarm-server.service"
alarm-server_files += "/etc/dbus-1/system.d/alarm-service.conf"
alarm-server_files += "/etc/udev/rules.d/60-alarm-manager-rtc.rules"

libalarm-devel_files = ""
libalarm-devel_files += "alarm-manager.manifest"
libalarm-devel_files += "/usr/include/*.h"
libalarm-devel_files += "/usr/lib/pkgconfig/*.pc"
libalarm-devel_files += "/usr/lib/libalarm.so"

FILES_libalarm = "${libalarm_files}"
FILES_alarm-server = "${alarm-server_files}"
FILES_libalarm-devel = "${libalarm-devel_files}"

PKG_libalarm= "libalarm"
PKG_alarm-server= "alarm-server"
PKG_libalarm-devel= "libalarm-devel"

require alarm-manager-extraconf.inc
