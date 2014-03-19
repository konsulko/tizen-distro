DESCRIPTION = "Sync agent FW Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by sync-agent-devel 
PROVIDES += "sync-agent-devel"
RPROVIDES_sync-agent-devel += "sync-agent-devel"
RPROVIDES_sync-agent-devel += "sync-agent-dev"

#PROVIDES by common-public-plugins 
PROVIDES += "common-public-plugins"
RPROVIDES_common-public-plugins += "common-public-plugins"

#PROVIDES by sync-agent 
PROVIDES += "sync-agent"
RPROVIDES_sync-agent += "sync-agent"

RDEPENDS = ""
#RDEPENDS of sync-agent-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "sync-agent"

#RDEPENDS of sync-agent (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of sync-agent 
DEPENDS += "sqlite"
DEPENDS += "pkgconfig(capi-system-info)"
DEPENDS += "contacts-service"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "cmake"
DEPENDS += "app-svc"
DEPENDS += "pkgconfig(syspopup-caller)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sysman)"
DEPENDS += "dbus-glib"
DEPENDS += "msg-service"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "common"
DEPENDS += "pkgconfig(location)"
DEPENDS += "libaccounts-svc"
DEPENDS += "libwbxml2"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "bundle"
DEPENDS += "pkgconfig(uuid)"
DEPENDS += "libgcrypt"
DEPENDS += "libslp-db-util"
DEPENDS += "pkgconfig(capi-network-connection)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(alarm-service)"
DEPENDS += "libslp-memo"
DEPENDS += "calendar-service"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "libslp-pm"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/sync-agent.manifest .
 
 
 
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
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 
}

PACKAGES = ""
PACKAGES += "sync-agent-devel"
PACKAGES += "common-public-plugins"
PACKAGES += "sync-agent"

sync-agent-devel_files = ""
sync-agent-devel_files += "sync-agent.manifest"
sync-agent-devel_files += "/usr/include/sync_agent.h"
sync-agent-devel_files += "/usr/include/sync-agent/*"
sync-agent-devel_files += "/usr/lib/pkgconfig/sync-agent.pc"

common-public-plugins_files = ""
common-public-plugins_files += "sync-agent.manifest"
common-public-plugins_files += "/usr/lib/sync-agent/common-public/*"

sync-agent_files = ""
sync-agent_files += "sync-agent.manifest"
sync-agent_files += "/usr/lib/*.so"
sync-agent_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${sync-agent-devel_files}"
FILES_common-public-plugins = "${common-public-plugins_files}"
FILES_${PN} = "${sync-agent_files}"

PKG_sync-agent-devel= "sync-agent-devel"
PKG_common-public-plugins= "common-public-plugins"
PKG_sync-agent= "sync-agent"

require sync-agent-extraconf.inc
