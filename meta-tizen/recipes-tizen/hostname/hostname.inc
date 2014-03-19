DESCRIPTION = "Utility to set/show the host name or domain name"
HOMEPAGE = "http://packages.qa.debian.org/h/hostname.html"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by hostname 
PROVIDES += "hostname"
RPROVIDES_hostname += "hostname"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n hostname
 cp ${S}/packaging/hostname.manifest .
 
 
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
 
 make CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables $CFLAGS"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make BASEDIR=${D} install
 # english is enough
 rm -rf ${D}/usr/share/man/fr
 
 
}

PACKAGES = ""
PACKAGES += "hostname"

hostname_files = ""
hostname_files += "hostname.manifest"
hostname_files += "/bin/*"
hostname_files += "/usr/share/man/man1/*"

FILES_${PN} = "${hostname_files}"

PKG_hostname= "hostname"

require hostname-extraconf.inc
