DESCRIPTION = "Udisk automount agent"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by udisks-automount-agent 
PROVIDES += "udisks-automount-agent"
RPROVIDES_udisks-automount-agent += "udisks-automount-agent"

#PROVIDES by udisks-automount-agent-devel 
PROVIDES += "udisks-automount-agent-devel"
RPROVIDES_udisks-automount-agent-devel += "udisks-automount-agent-devel"
RPROVIDES_udisks-automount-agent-devel += "udisks-automount-agent-dev"

RDEPENDS = ""
#RDEPENDS of udisks-automount-agent (${PN})
RDEPENDS_${PN} += "glib2"
RDEPENDS_${PN} += "udisks"

#RDEPENDS of udisks-automount-agent-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "udisks-automount-agent"


DEPENDS = ""
#DEPENDS of udisks-automount-agent 
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "cmake"
DEPENDS += "notification"
DEPENDS += "bundle"
DEPENDS += "udisks-devel"
DEPENDS += "pkgconfig(udisks2)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp -a ${S}/packaging/udisks-automount-agent.manifest .
 cmake . -DCMAKE_INSTALL_PREFIX=/usr -DSYSTEMD_SERVICE_DIR=/lib/systemd/user -DENABLE_NOTIF=0
 
 
 
 
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
 mkdir -p ${D}/lib/systemd/user/core-efl.target.wants/
 ln -s ../udisks-automount-agent.service ${D}/lib/systemd/user/core-efl.target.wants/udisks-automount-agent.service
 
 
 
}

PACKAGES = ""
PACKAGES += "udisks-automount-agent"
PACKAGES += "udisks-automount-agent-devel"

udisks-automount-agent_files = ""
udisks-automount-agent_files += "udisks-automount-agent.manifest"
udisks-automount-agent_files += "/usr/bin/udisks-automount-agent"
udisks-automount-agent_files += "/lib/systemd/user/udisks-automount-agent.service"
udisks-automount-agent_files += "/lib/systemd/user/core-efl.target.wants/udisks-automount-agent.service"
udisks-automount-agent_files += "/etc/polkit-1/localauthority/10-vendor.d/10-udisks.pkla"

udisks-automount-agent-devel_files = ""
udisks-automount-agent-devel_files += "/usr/bin/sample-udisks-agent-notif-listener"
udisks-automount-agent-devel_files += "/usr/bin/sample-udisks-agent-mount-listener"

FILES_${PN} = "${udisks-automount-agent_files}"
FILES_${PN}-devel = "${udisks-automount-agent-devel_files}"

PKG_udisks-automount-agent= "udisks-automount-agent"
PKG_udisks-automount-agent-devel= "udisks-automount-agent-devel"

require udisks-automount-agent-extraconf.inc
