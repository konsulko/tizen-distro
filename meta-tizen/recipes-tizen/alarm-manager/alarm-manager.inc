DESCRIPTION = "Alarm library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND += ""
PROVIDES = ""

#PROVIDES by alarm-manager 


#PROVIDES by libalarm 


#PROVIDES by alarm-server 


#PROVIDES by libalarm-dev 


RDEPENDS = ""
#RDEPENDS of libalarm (libalarm)
RDEPENDS_libalarm += "alarm-server"

#RDEPENDS of alarm-server (alarm-server)
RDEPENDS_alarm-server += "systemd"

#RDEPENDS of libalarm-dev (libalarm-dev)
RDEPENDS_libalarm-dev += "libalarm"


DEPENDS = ""
#DEPENDS of alarm-manager 
DEPENDS += "aul-1"
DEPENDS += "dbus"
DEPENDS += "app-svc"
DEPENDS += "security-server"
DEPENDS += "bundle"
DEPENDS += "glib-2.0"
DEPENDS += "dlog"
DEPENDS += "libslp-pm"
DEPENDS += "heynoti"
DEPENDS += "libtapi-legacy"
DEPENDS += "vconf"
DEPENDS += "libslp-db-util"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/alarm-manager.manifest .
 
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} --disable-static
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
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} --disable-static
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 install -d ${D}/lib/systemd/system/multi-user.target.wants
 install -m0644 ${S}/packaging/alarm-server.service ${D}/lib/systemd/system
 ln -sf ../alarm-server.service ${D}/lib/systemd/system/multi-user.target.wants/alarm-server.service
 
 mkdir -p ${D}/${sysconfdir}/udev/rules.d
 install -m0644  ${S}/packaging/60-alarm-manager-rtc.rules ${D}${sysconfdir}/udev/rules.d/
 
 mkdir -p ${D}/${sysconfdir}/dbus-1/system.d
 install -m0644  ${S}/packaging/alarm-service.conf ${D}${sysconfdir}/dbus-1/system.d/
 
 
}

PACKAGES += " libalarm "
PACKAGES += " alarm-server "
PACKAGES += " libalarm-dev "

libalarm_files = ""
libalarm_files += "alarm-manager.manifest"
libalarm_files += "alarm-lib.manifest"
libalarm_files += "${prefix}/lib/libalarm.so.0.0.0"
libalarm_files += "${prefix}/lib/libalarm.so.0"

alarm-server_files = ""
alarm-server_files += "alarm-manager.manifest"
alarm-server_files += "${prefix}/bin/alarm-server"
alarm-server_files += "/lib/systemd/system/multi-user.target.wants/alarm-server.service"
alarm-server_files += "/lib/systemd/system/alarm-server.service"
alarm-server_files += "${sysconfdir}/dbus-1/system.d/alarm-service.conf"
alarm-server_files += "${sysconfdir}/udev/rules.d/60-alarm-manager-rtc.rules"

libalarm-dev_files = ""
libalarm-dev_files += "alarm-manager.manifest"
libalarm-dev_files += "${prefix}/include/*.h"
libalarm-dev_files += "${prefix}/lib/pkgconfig/*.pc"
libalarm-dev_files += "${prefix}/lib/libalarm.so"

FILES_libalarm = "${libalarm_files}"
FILES_alarm-server = "${alarm-server_files}"
FILES_libalarm-dev = "${libalarm-dev_files}"

PKG_libalarm= "libalarm"
PKG_alarm-server= "alarm-server"
PKG_libalarm-dev= "libalarm-dev"

require alarm-manager-extraconf.inc

