DESCRIPTION = "A Client for Cisco VPN concentrator"
HOMEPAGE = "http://svn.unix-ag.uni-kl.de/vpnc/branches/vpnc-nortel"
SECTION = "Networking/Security"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by vpnc 
PROVIDES += "vpnc"
RPROVIDES_vpnc += "vpnc"

RDEPENDS = ""
#RDEPENDS of vpnc (${PN})
RDEPENDS_${PN} += "/usr/sbin/ip"
RDEPENDS_${PN} += "/usr/bin/sed"


DEPENDS = ""
#DEPENDS of vpnc 
DEPENDS += "gnutls"
DEPENDS += "libgcrypt"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n vpnc
 cp ${S}/packaging/vpnc.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 make PREFIX=/usr
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${RPM_BUILD_ROOT}//var/run/vpnc
 oe_runmake install \
 	DESTDIR=${RPM_BUILD_ROOT} \
 	PREFIX=/usr
 rm -rfv ${RPM_BUILD_ROOT}/usr/share/doc/vpnc
 mkdir -p ${RPM_BUILD_ROOT}//etc/tmpfiles.d
 install -m 0644 ${S}/packaging/vpnc.conf ${RPM_BUILD_ROOT}//etc/tmpfiles.d/
 
 
}

PACKAGES = ""
PACKAGES += "vpnc"

vpnc_files = ""
vpnc_files += "vpnc.manifest"
vpnc_files += "/etc/tmpfiles.d"
vpnc_files += "/etc/tmpfiles.d/vpnc.conf"
vpnc_files += "/etc/vpnc"
vpnc_files += "/etc/vpnc/vpnc-script"
vpnc_files += "/usr/sbin/vpnc"
vpnc_files += "/usr/sbin/vpnc-disconnect"
vpnc_files += "/usr/bin/cisco-decrypt"
vpnc_files += "/usr/bin/pcf2vpnc"
vpnc_files += "/usr/share/man/man1/cisco-decrypt.1.*"
vpnc_files += "/usr/share/man/man1/pcf2vpnc.1.*"
vpnc_files += "/usr/share/man/man8/vpnc.8.*"

FILES_${PN} = "${vpnc_files}"

PKG_vpnc= "vpnc"

require vpnc-extraconf.inc
