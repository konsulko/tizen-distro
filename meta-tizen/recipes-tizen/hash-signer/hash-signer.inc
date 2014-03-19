DESCRIPTION = "Commandline tool for Tizen Signing"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Productivity/Security"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by hash-signer 
PROVIDES += "hash-signer"
RPROVIDES_hash-signer += "hash-signer"

RDEPENDS = ""
#RDEPENDS of hash-signer (${PN})
RDEPENDS_${PN} += "xmlsec1"
RDEPENDS_${PN} += "unzip"
RDEPENDS_${PN} += "xmlstarlet"
RDEPENDS_${PN} += "zip"


DEPENDS = ""
#DEPENDS of hash-signer 
DEPENDS += "xmlsec1"

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
 
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
 mkdir -p ${D}/opt/usr/share/certs/signer
 cp -arf certificates/* ${D}/opt/usr/share/certs/signer/
 mkdir -p ${D}/usr/bin
 cp -arf tools/* ${D}/usr/bin/
 mkdir -p ${D}/etc/rpm
 cp -arf macros/* ${D}/etc/rpm/
 
 
}

PACKAGES = ""
PACKAGES += "hash-signer"

hash-signer_files = ""
hash-signer_files += "/opt/usr/share/certs/signer/*"
hash-signer_files += "/usr/bin/*"
hash-signer_files += "/etc/rpm/*"

FILES_${PN} = "${hash-signer_files}"

PKG_hash-signer= "hash-signer"

require hash-signer-extraconf.inc
