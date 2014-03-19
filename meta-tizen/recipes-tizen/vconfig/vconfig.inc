DESCRIPTION = "Linux 802.1q VLAN configuration utility"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System Environment/Base"
LICENSE = "GPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by vconfig 
PROVIDES += "vconfig"
RPROVIDES_vconfig += "vconfig"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n vlan.1.9
 
 
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
 
 cp ${S}/packaging/vconfig.manifest .
 make clean
 rm -f vconfig
 make CCFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" STRIP=/bin/true vconfig
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${RPM_BUILD_ROOT}
 /bin/install -D -m755 vconfig ${RPM_BUILD_ROOT}/sbin/vconfig
 /bin/install -D -m644 vconfig.8 ${RPM_BUILD_ROOT}/usr/share/man/man8/vconfig.8
 rm -rf contrib/CVS
 
 
}

PACKAGES = ""
PACKAGES += "vconfig"

vconfig_files = ""
vconfig_files += "vconfig.manifest"
vconfig_files += "vconfig.manifest"
vconfig_files += "CHANGELOG contrib README vlan.html vlan_test.pl"
vconfig_files += "/sbin/vconfig"
vconfig_files += "/usr/share/man/man8/vconfig.8*"

FILES_${PN} = "${vconfig_files}"

PKG_vconfig= "vconfig"

require vconfig-extraconf.inc
