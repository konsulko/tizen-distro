DESCRIPTION = "Download the contents in background"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "Apache License, Version 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by download-provider 
PROVIDES += "download-provider"
RPROVIDES_download-provider += "download-provider"

#PROVIDES by download-provider-devel 
PROVIDES += "download-provider-devel"
RPROVIDES_download-provider-devel += "download-provider-devel"
RPROVIDES_download-provider-devel += "download-provider-dev"

RDEPENDS = ""
#RDEPENDS of download-provider (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "/usr/bin/sqlite3"

#RDEPENDS of download-provider-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "download-provider"


DEPENDS = ""
#DEPENDS of download-provider 
DEPENDS += "pkgconfig(capi-network-connection)"
DEPENDS += "pkgconfig(capi-appfw-app-manager)"
DEPENDS += "cmake"
DEPENDS += "bundle"
DEPENDS += "pkgconfig(wifi-direct)"
DEPENDS += "app-svc"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(xdgmime)"
DEPENDS += "common"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(notification)"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/org.download-provider.conf .
 cp ${S}/packaging/download-provider.manifest .
 
 
 
 
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
 
 
 	CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables} -fPIC -D_REENTRANT -fvisibility=hidden"; export CFLAGS 
 	FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables} -fPIC -fvisibility=hidden"; export FFLAGS 
 	LDFLAGS+=" -Wl,--as-needed -Wl,--hash-style=both"; export LDFLAGS 
 	cmake \
 		-DCMAKE_INSTALL_PREFIX:PATH=/usr \
 		-DBIN_INSTALL_DIR:PATH=/usr/bin \
 		-DLIB_INSTALL_DIR:PATH=/usr/lib \
 		-DINCLUDE_INSTALL_DIR:PATH=/usr/include \
 		-DPKG_NAME=download-provider \
 		-DPKG_VERSION=1.0.5 \
 		-DPKG_RELEASE=10 \
 		-DIMAGE_DIR:PATH=/usr/share/download-provider \
 		-DDATABASE_FILE:PATH=/opt/usr/dbspace/.download-provider.db \
 		-DDBUS_SERVICE_DIR:PATH=/usr/share/dbus-1/system-services \
 		-DLICENSE_DIR:PATH=/usr/share/license \
 		-DSUPPORT_DBUS_SYSTEM:BOOL=ON \
 		-DSUPPORT_WIFI_DIRECT:BOOL=OFF \
 		-DSUPPORT_LOG_MESSAGE:BOOL=ON \
 		-DSUPPORT_CHECK_IPC:BOOL=ON \
 		-DCMAKE_SKIP_RPATH:BOOL=ON \
 		-DBUILD_SHARED_LIBS:BOOL=ON .
 make -j16
 
 
 
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
 
 install -d -m 755 ${D}/etc/dbus-1/system.d
 install -m 644 ${S}/packaging/org.download-provider.conf ${D}/etc/dbus-1/system.d
 
 mkdir -p ${D}/usr/share/license
 mkdir -p  ${D}/etc/rc.d/rc3.d
 ln -s /etc/rc.d/init.d/download-provider-service  ${D}/etc/rc.d/rc3.d/S70download-provider-service
 mkdir -p  ${D}/etc/rc.d/rc5.d
 ln -s /etc/rc.d/init.d/download-provider-service  ${D}/etc/rc.d/rc5.d/S70download-provider-service
 
 mkdir -p ${D}//lib/systemd/system/graphical.target.wants
 install ${S}/packaging/download-provider.service ${D}//lib/systemd/system/
 ln -s ../download-provider.service ${D}//lib/systemd/system/graphical.target.wants/
 
 mkdir -p ${D}/opt/data/download-provider
 mkdir -p ${D}/opt/usr/dbspace
 if [ ! -f ${D}/opt/usr/dbspace/.download-provider.db ];
 then
 sqlite3 ${D}/opt/usr/dbspace/.download-provider.db 'PRAGMA journal_mode=PERSIST;
 PRAGMA foreign_keys=ON;
 CREATE TABLE logging
 (
 id INTEGER UNIQUE PRIMARY KEY,
 state INTEGER DEFAULT 0,
 errorcode INTEGER DEFAULT 0,
 startcount INTEGER DEFAULT 0,
 packagename TEXT DEFAULT NULL,
 createtime DATE,
 accesstime DATE
 );
 
 CREATE TABLE requestinfo
 (
 id INTEGER UNIQUE PRIMARY KEY,
 auto_download BOOLEAN DEFAULT 0,
 state_event BOOLEAN DEFAULT 0,
 progress_event BOOLEAN DEFAULT 0,
 noti_enable BOOLEAN DEFAULT 0,
 network_type TINYINT DEFAULT 0,
 filename TEXT DEFAULT NULL,
 destination TEXT DEFAULT NULL,
 url TEXT DEFAULT NULL,
 FOREIGN KEY(id) REFERENCES logging(id) ON DELETE CASCADE
 );
 
 CREATE TABLE downloadinfo
 (
 id INTEGER UNIQUE PRIMARY KEY,
 http_status INTEGER DEFAULT 0,
 content_size UNSIGNED BIG INT DEFAULT 0,
 mimetype VARCHAR(64) DEFAULT NULL,
 content_name TEXT DEFAULT NULL,
 saved_path TEXT DEFAULT NULL,
 tmp_saved_path TEXT DEFAULT NULL,
 etag TEXT DEFAULT NULL,
 FOREIGN KEY(id) REFERENCES logging(id) ON DELETE CASCADE
 );
 
 CREATE TABLE httpheaders
 (
 id INTEGER NOT NULL,
 header_field TEXT DEFAULT NULL,
 header_data TEXT DEFAULT NULL,
 FOREIGN KEY(id) REFERENCES logging(id) ON DELETE CASCADE
 );
 
 CREATE TABLE notification
 (
 id INTEGER NOT NULL,
 extra_key TEXT DEFAULT NULL,
 extra_data TEXT DEFAULT NULL,
 FOREIGN KEY(id) REFERENCES logging(id) ON DELETE CASCADE
 );
 
 CREATE UNIQUE INDEX requests_index ON logging (id, state, errorcode, packagename, createtime, accesstime);
 '
 fi
 
 
 
}

PACKAGES = ""
PACKAGES += "download-provider"
PACKAGES += "download-provider-devel"

download-provider_files = ""
download-provider_files += "download-provider.manifest"
#Remove rpm attribut "%attr(0775,root,app)"
download-provider_files += "/opt/data/download-provider"
download-provider_files += "/usr/share/download-provider/*.png"
download-provider_files += "/usr/lib/libdownloadagent2.so.0.0.1"
download-provider_files += "/usr/lib/libdownloadagent2.so"
download-provider_files += "/lib/systemd/system/download-provider.service"
download-provider_files += "/lib/systemd/system/graphical.target.wants/download-provider.service"
download-provider_files += "/usr/lib/libdownload-provider-interface.so.1.0.5"
download-provider_files += "/usr/lib/libdownload-provider-interface.so.0"
download-provider_files += "/usr/bin/download-provider"
download-provider_files += "/etc/rc.d/init.d/download-provider-service"
download-provider_files += "/etc/rc.d/rc3.d/S70download-provider-service"
download-provider_files += "/etc/rc.d/rc5.d/S70download-provider-service"
download-provider_files += "/usr/share/license/download-provider"
download-provider_files += "/usr/share/dbus-1/system-services/org.download-provider.service"
download-provider_files += "/etc/dbus-1/system.d/org.download-provider.conf"

download-provider-devel_files = ""
download-provider-devel_files += "download-provider.manifest"
download-provider-devel_files += "/usr/lib/libdownloadagent2.so"
download-provider-devel_files += "/usr/lib/libdownload-provider-interface.so"
download-provider-devel_files += "/usr/include/download-provider/download-provider-defs.h"
download-provider-devel_files += "/usr/include/download-provider/download-provider-interface.h"
download-provider-devel_files += "/usr/bin/download-provider"
download-provider-devel_files += "/usr/lib/pkgconfig/download-provider.pc"
download-provider-devel_files += "/usr/lib/pkgconfig/download-provider-interface.pc"

FILES_${PN} = "${download-provider_files}"
FILES_${PN}-devel = "${download-provider-devel_files}"

PKG_download-provider= "download-provider"
PKG_download-provider-devel= "download-provider-devel"

require download-provider-extraconf.inc
