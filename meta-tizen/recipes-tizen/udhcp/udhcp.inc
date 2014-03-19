DESCRIPTION = "Micro DHCP client / server"
HOMEPAGE = "http://udhcp.busybox.net"
SECTION = "System/Emulators/PC"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by udhcp 
PROVIDES += "udhcp"
RPROVIDES_udhcp += "udhcp"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cat ${S}/packaging/oracle-rpmbuild-makefile-changes.patch | patch -s  -p1 --fuzz=2
 #patch0 -p1
 cat ${S}/packaging/udhcp_usermac.patch | patch -s  -p1 --fuzz=2
 #patch1 -p1
 cat ${S}/packaging/udhcp-outputpy.patch | patch -s  -p1 --fuzz=2
 #patch2 -p1
 cat ${S}/packaging/udhcp-update-scripts.patch | patch -s  -p1 --fuzz=2
 #patch3 -p1
 
 
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
 
 cp ${S}/packaging/udhcp.manifest .
 oe_runmake
 
 
 
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
   find ${D} -regex ".*\.a$" | xargs rm -f -- SBINDIR=${D}//usr/sbin
 mv ${D}/sbin/udhcpc ${D}//usr/bin
 mv ${D}//usr/sbin/udhcpd ${D}//usr/bin
 
 
}

PACKAGES = ""
PACKAGES += "udhcp"

udhcp_files = ""
udhcp_files += "udhcp.manifest"
udhcp_files += "udhcp.manifest"
udhcp_files += "/usr/bin/*"
udhcp_files += "/usr/share/man/man?/*"
udhcp_files += "/usr/share/udhcpc"
udhcp_files += "/usr/share/udhcpc/*"

FILES_${PN} = "${udhcp_files}"

PKG_udhcp= "udhcp"

require udhcp-extraconf.inc
