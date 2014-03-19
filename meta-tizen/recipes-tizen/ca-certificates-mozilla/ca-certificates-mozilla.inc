DESCRIPTION = "CA certificates for OpenSSL"
HOMEPAGE = "http://www.mozilla.org"
SECTION = "Productivity/Networking/Security"
LICENSE = "MPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ca-certificates-mozilla
PROVIDES += "ca-certificates-mozilla"
RPROVIDES_ca-certificates-mozilla += "ca-certificates-mozilla"
# the PROVIDES rules is ignore "openssl-certs = 0.9.9"
PROVIDES += "openssl-certs"
RPROVIDES_ca-certificates-mozilla += "openssl-certs"

RDEPENDS = ""
#RDEPENDS of ca-certificates-mozilla (${PN})
RDEPENDS_${PN} += "ca-certificates"


DEPENDS = ""
#DEPENDS of ca-certificates-mozilla
DEPENDS += "openssl"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -qcT
 cp ${S}/packaging/ca-certificates-mozilla.manifest .
 /bin/cp ${S}/packaging/certdata.txt .
 install -m 644 ${S}/packaging/extractcerts.pl COPYING


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

 perl ${S}/packaging/extractcerts.pl --trustbits < certdata.txt



}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 mkdir -p ${D}//usr/share/ca-certificates/mozilla
 set +x
 for i in *.pem; do
   args=()
   trust=`sed -n '/^# openssl-trust=/{s/^.*=//;p;q;}' "$i"`
   alias=`sed -n '/^# alias=/{s/^.*=//;p;q;}' "$i"`
   case "$trust" in
     *serverAuth*) ;;
     *) echo "skipping $i, not trusted for serverAuth"; continue ;;
   esac
   echo "$i"
   {
     grep '^#' "$i"
     openssl x509 -in "$i" "${args[@]}"
   } > "${D}//usr/share/ca-certificates/mozilla/$i"
 done
 set -x
}

PACKAGES = ""
PACKAGES += "ca-certificates-mozilla"

ca-certificates-mozilla_files = ""
ca-certificates-mozilla_files += "ca-certificates-mozilla.manifest"
ca-certificates-mozilla_files += "COPYING"
ca-certificates-mozilla_files += "/usr/share/ca-certificates/mozilla"

FILES_${PN} = "${ca-certificates-mozilla_files}"

PKG_ca-certificates-mozilla= "ca-certificates-mozilla"

require ca-certificates-mozilla-extraconf.inc
