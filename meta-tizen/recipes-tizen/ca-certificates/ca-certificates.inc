DESCRIPTION = "Utilities for system wide CA certificate installation"
HOMEPAGE = "http://gitorious.org/opensuse/ca-certificates"
SECTION = "Productivity/Networking/Security"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ca-certificates 
PROVIDES += "ca-certificates"
RPROVIDES_ca-certificates += "ca-certificates"

RDEPENDS = ""
#RDEPENDS of ca-certificates (${PN})
RDEPENDS_${PN} += "/usr/bin/rm"
RDEPENDS_${PN} += "openssl-misc"
RDEPENDS_${PN} += "openssl"


DEPENDS = ""
#DEPENDS of ca-certificates 
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -qcT
 cp ${S}/packaging/ca-certificates.manifest .
 install -m 755 ${S}/packaging/update-ca-certificates .
 install -m 644 ${S}/packaging/update-ca-certificates.8 .
 install -m 644 ${S}/packaging/GPL-2.0.txt COPYING
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}//etc/ssl/certs
 mkdir -p ${D}//usr/share/ca-certificates
 mkdir -p ${D}//usr/sbin
 mkdir -p ${D}//usr/share/man/man8
 mkdir -p ${D}/etc/ca-certificates/update.d
 mkdir -p ${D}/usr/lib/ca-certificates/update.d
 install -D -m 644 /dev/null ${D}//var/lib/ca-certificates/ca-bundle.pem
 install -m 644 /dev/null ${D}/etc/ca-certificates.conf
 install -m 755 ${S}/packaging/certbundle.run ${D}/usr/lib/ca-certificates/update.d
 ln -s /var/lib/ca-certificates/ca-bundle.pem ${D}/etc/ssl/ca-bundle.pem
 
 install -m 755 update-ca-certificates ${D}//usr/sbin
 install -m 644 update-ca-certificates.8 ${D}//usr/share/man/man8
 install -m 644 /dev/null ${D}/var/lib/ca-certificates/ca-bundle.pem
 
 
}

PACKAGES = ""
PACKAGES += "ca-certificates"

ca-certificates_files = ""
ca-certificates_files += "ca-certificates.manifest"
ca-certificates_files += "/usr/share/ca-certificates"
ca-certificates_files += "/etc/ssl/certs"
ca-certificates_files += "/etc/ssl/ca-bundle.pem"
ca-certificates_files += "/etc/ca-certificates"
ca-certificates_files += "/etc/ca-certificates/update.d"
ca-certificates_files += "/usr/lib/ca-certificates"
ca-certificates_files += "/usr/lib/ca-certificates/update.d"
ca-certificates_files += "/var/lib/ca-certificates"
ca-certificates_files += "/usr/lib/ca-certificates/update.d/certbundle.run"
ca-certificates_files += "/usr/sbin/update-ca-certificates"
ca-certificates_files += "/usr/share/man/man8/update-ca-certificates.8*"

FILES_${PN} = "${ca-certificates_files}"

PKG_ca-certificates= "ca-certificates"

require ca-certificates-extraconf.inc
