DESCRIPTION = "Messaging Framework Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Samsung"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mms-plugin 
PROVIDES += "mms-plugin"
RPROVIDES_mms-plugin += "mms-plugin"

#PROVIDES by msg-service-tools 
PROVIDES += "msg-service-tools"
RPROVIDES_msg-service-tools += "msg-service-tools"

#PROVIDES by sms-plugin 
PROVIDES += "sms-plugin"
RPROVIDES_sms-plugin += "sms-plugin"

#PROVIDES by msg-service-devel 
PROVIDES += "msg-service-devel"
RPROVIDES_msg-service-devel += "msg-service-devel"
RPROVIDES_msg-service-devel += "msg-service-dev"

#PROVIDES by msg-service 
PROVIDES += "msg-service"
RPROVIDES_msg-service += "msg-service"

RDEPENDS = ""
#RDEPENDS of mms-plugin (mms-plugin)
RDEPENDS_mms-plugin += "/sbin/ldconfig"
RDEPENDS_mms-plugin += "msg-service"

#RDEPENDS of msg-service-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "/sbin/ldconfig"
RDEPENDS_${PN}-tools += "/usr/bin/vconftool"
RDEPENDS_${PN}-tools += "msg-service"
RDEPENDS_${PN}-tools += "/usr/bin/sqlite3"

#RDEPENDS of sms-plugin (sms-plugin)
RDEPENDS_sms-plugin += "/sbin/ldconfig"
RDEPENDS_sms-plugin += "msg-service"

#RDEPENDS of msg-service-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "msg-service"

#RDEPENDS of msg-service (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/usr/bin/sqlite3"


DEPENDS = ""
#DEPENDS of msg-service 
DEPENDS += "pkgconfig(mmutil-imgp)"
DEPENDS += "contacts-service"
DEPENDS += "libslp-sensor"
DEPENDS += "libmm-session"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "cmake"
DEPENDS += "drm-client"
DEPENDS += "dlog"
DEPENDS += "libmm-fileinfo"
DEPENDS += "pkgconfig(capi-appfw-application)"
DEPENDS += "libsvi"
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(mm-player)"
DEPENDS += "libwbxml2"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "libmedia-thumbnail"
DEPENDS += "pkgconfig(mmutil-jpeg)"
DEPENDS += "libslp-db-util"
DEPENDS += "libnet-client"
DEPENDS += "libmm-sound"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(alarm-service)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "libslp-pm"
DEPENDS += "pkgconfig(notification)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/msg-service.manifest ${S}/packaging/msg-service-devel.manifest ${S}/packaging/msg-service-tools.manifest ${S}/packaging/sms-plugin.manifest ${S}/packaging/mms-plugin.manifest .
 
 
 
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
 
 rm -rf ${D}
 mkdir -p ${D}/usr/share/license
 mkdir -p ${D}/etc/config
 
 mkdir -p ${D}/var/log/msgfw
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/lib/systemd/user/tizen-middleware.target.wants
 #install -m 0644 ${S}/packaging/msg-service.service ${D}/lib/systemd/user/
 ln -s ../msg-service.service ${D}/lib/systemd/user/tizen-middleware.target.wants/msg-service.service
 ln -s ../msg-service-log.service ${D}/lib/systemd/user/tizen-middleware.target.wants/msg-service-log.service
 
 mkdir -p  ${D}/etc/rc.d/rc3.d
 ln -s /etc/rc.d/init.d/msg-server  ${D}/etc/rc.d/rc3.d/S70msg-server
 mkdir -p  ${D}/etc/rc.d/rc5.d
 ln -s /etc/rc.d/init.d/msg-server  ${D}/etc/rc.d/rc5.d/S70msg-server
 
 mkdir -p ${D}/opt/usr/data/msg-service
 
 rm ${D}/etc/config/sysinfo-message.emul.xml
 
 
 
}

PACKAGES = ""
PACKAGES += "mms-plugin"
PACKAGES += "msg-service-tools"
PACKAGES += "sms-plugin"
PACKAGES += "msg-service-devel"
PACKAGES += "msg-service"

mms-plugin_files = ""
mms-plugin_files += "mms-plugin.manifest"
mms-plugin_files += "/usr/lib/libmsg_mms_plugin.so"
mms-plugin_files += "/usr/share/license/msg-service/LICENSE.Flora"

msg-service-tools_files = ""
msg-service-tools_files += "msg-service-tools.manifest"
msg-service-tools_files += "/usr/bin/msg-helper"
msg-service-tools_files += "/usr/bin/msg-server"
msg-service-tools_files += "/usr/share/media/Sherbet.wav"
msg-service-tools_files += "/etc/rc.d/init.d/msg-server"
msg-service-tools_files += "/etc/rc.d/rc3.d/S70msg-server"
msg-service-tools_files += "/etc/rc.d/rc5.d/S70msg-server"
msg-service-tools_files += "/lib/systemd/user/msg-service.service"
msg-service-tools_files += "/lib/systemd/user/msg-service-log.service"
msg-service-tools_files += "/lib/systemd/user/tizen-middleware.target.wants/msg-service.service"
msg-service-tools_files += "/lib/systemd/user/tizen-middleware.target.wants/msg-service-log.service"
msg-service-tools_files += "/usr/share/license/msg-service/LICENSE.Flora"
msg-service-tools_files += "/opt/etc/smack/accesses.d/msg-service.rule"
msg-service-tools_files += "/etc/config/sysinfo-message.xml"

sms-plugin_files = ""
sms-plugin_files += "sms-plugin.manifest"
sms-plugin_files += "/usr/lib/libmsg_sms_plugin.so"
sms-plugin_files += "/usr/share/license/msg-service/LICENSE.Flora"

msg-service-devel_files = ""
msg-service-devel_files += "msg-service-devel.manifest"
msg-service-devel_files += "/usr/lib/libmsg_mapi.so"
msg-service-devel_files += "/usr/lib/pkgconfig/msg-service.pc"
msg-service-devel_files += "/usr/include/msg-service/*"

msg-service_files = ""
msg-service_files += "msg-service.manifest"
#Remove rpm attribut "%attr(775,root,db_msg_service)"
msg-service_files += "/opt/usr/data/msg-service"
msg-service_files += "/usr/lib/libmsg_plugin_manager.so"
msg-service_files += "/usr/lib/libmsg_mapi.so.*"
msg-service_files += "/usr/lib/libmsg_framework_handler.so"
msg-service_files += "/usr/lib/libmsg_transaction_manager.so"
msg-service_files += "/usr/lib/libmsg_utils.so"
msg-service_files += "/usr/lib/libmsg_transaction_proxy.so"
msg-service_files += "/usr/lib/libmsg_vobject.so"
msg-service_files += "/usr/share/license/msg-service/LICENSE.Flora"

FILES_mms-plugin = "${mms-plugin_files}"
FILES_${PN}-tools = "${msg-service-tools_files}"
FILES_sms-plugin = "${sms-plugin_files}"
FILES_${PN}-devel = "${msg-service-devel_files}"
FILES_${PN} = "${msg-service_files}"

PKG_mms-plugin= "mms-plugin"
PKG_msg-service-tools= "msg-service-tools"
PKG_sms-plugin= "sms-plugin"
PKG_msg-service-devel= "msg-service-devel"
PKG_msg-service= "msg-service"

require msg-service-extraconf.inc
