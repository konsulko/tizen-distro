DESCRIPTION = "Basic networking tools"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by net-tools-docs  
PROVIDES += "net-tools-docs "
RPROVIDES_net-tools-docs  += "net-tools-docs "

#PROVIDES by net-tools 
PROVIDES += "net-tools"
RPROVIDES_net-tools += "net-tools"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/net-tools.manifest .
 
 cp ${S}/packaging/net-tools-config.h ./config.h
 cp ${S}/packaging/net-tools-config.make ./config.make
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS $CFLAGS -fpie"
 export LDFLAGS="$LDFLAGS -pie -Wl,-z,relro -Wl,-z,now"
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make BASEDIR=${D} mandir=/usr/share/man install
 
 mkdir -p ${D}/usr/sbin
 mkdir -p ${D}/usr/bin
 mv ${D}/bin/ifconfig ${D}/usr/sbin
 mv ${D}/bin/route ${D}/usr/sbin
 mv ${D}/bin/netstat ${D}/usr/bin
 
 
 rm ${D}/sbin/rarp
 
 # remove hostname (has its own package)
 rm ${D}/bin/dnsdomainname
 rm ${D}/bin/domainname
 rm ${D}/bin/hostname
 rm ${D}/bin/nisdomainname
 rm ${D}/bin/ypdomainname
 
 
 
}

PACKAGES = ""
PACKAGES += "net-tools-docs"
PACKAGES += "net-tools"

net-tools-docs_files = ""
net-tools-docs_files += "/usr/share/info"
net-tools-docs_files += "/usr/share/man"

net-tools_files = ""
net-tools_files += "net-tools.manifest"
net-tools_files += "/usr/bin/netstat"
net-tools_files += "/usr/sbin/ifconfig"
net-tools_files += "/usr/sbin/route"
net-tools_files += "/sbin/arp"
net-tools_files += "/sbin/ipmaddr"
net-tools_files += "/sbin/iptunnel"
net-tools_files += "/sbin/nameif"
net-tools_files += "/sbin/plipconfig"
net-tools_files += "/sbin/slattach"
net-tools_files += "/sbin/mii-tool"

FILES_${PN}-docs = "${net-tools-docs_files}"
FILES_${PN} = "${net-tools_files}"

PKG_net-tools-docs= "net-tools-docs"
PKG_net-tools= "net-tools"

require net-tools-extraconf.inc
