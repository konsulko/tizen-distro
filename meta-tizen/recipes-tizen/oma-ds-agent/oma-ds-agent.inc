DESCRIPTION = "OMA-DS Agent Daemon for Data Synchronization"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Device Management"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by oma-ds-agent 
PROVIDES += "oma-ds-agent"
RPROVIDES_oma-ds-agent += "oma-ds-agent"

#PROVIDES by ds-public-plugins 
PROVIDES += "ds-public-plugins"
RPROVIDES_ds-public-plugins += "ds-public-plugins"

RDEPENDS = ""
#RDEPENDS of oma-ds-agent (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of oma-ds-agent 
DEPENDS += "cmake"
DEPENDS += "libslp-memo"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "expat"
DEPENDS += "pkgconfig(check)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sync-agent)"
DEPENDS += "contacts-service"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 cmake . -DCMAKE_INSTALL_PREFIX=/usr
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
 
 if [ ! -d ${D}/opt/dbspace ]
 then
 	mkdir -p ${D}/opt/dbspace
 fi
 
 sqlite3 ${D}/opt/dbspace/.omasyncagent.db "PRAGMA journal_mode = PERSIST; create table a(a); drop table a;" > /dev/null
 
 
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
PACKAGES += "oma-ds-agent"
PACKAGES += "ds-public-plugins"

oma-ds-agent_files = ""
oma-ds-agent_files += "oma-ds-agent.manifest"
oma-ds-agent_files += "/usr/share/dbus-1/system-services/com.samsung.omadsagent.service"
oma-ds-agent_files += "/usr/bin/oma-ds-agent"
oma-ds-agent_files += "/usr/share/oma-ds-cfg/*"
oma-ds-agent_files += "/usr/lib/systemd/system/oma-ds-agent.service"
oma-ds-agent_files += "/usr/lib/systemd/system/graphical.target.wants/oma-ds-agent.service"
oma-ds-agent_files += "/etc/dbus-1/system.d/com.samsung.omadsagent.conf"

ds-public-plugins_files = ""
ds-public-plugins_files += "ds-public-plugins.manifest"
ds-public-plugins_files += "/usr/lib/sync-agent/ds-public/*"

FILES_${PN} = "${oma-ds-agent_files}"
FILES_ds-public-plugins = "${ds-public-plugins_files}"

PKG_oma-ds-agent= "oma-ds-agent"
PKG_ds-public-plugins= "ds-public-plugins"

require oma-ds-agent-extraconf.inc
