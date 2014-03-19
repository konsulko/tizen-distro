DESCRIPTION = "LSB support for SLP"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Base"
LICENSE = "GPLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lsb 
PROVIDES += "lsb"
RPROVIDES_lsb += "lsb"
# the PROVIDES rules is ignore "/lib/lsb/init-functions  "
PROVIDES += "/lib/lsb/init-functions"
RPROVIDES_lsb += "/lib/lsb/init-functions"

RDEPENDS = ""

DEPENDS = ""

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
 
 cp ${S}/packaging/lsb.manifest .
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 install -d ${D}/lib/lsb
 cp -p init-functions ${D}/lib/lsb
 
 mkdir -p $RPM_BUILD_ROOT/usr/share/license
 cp ${S}/packaging/lsb $RPM_BUILD_ROOT/usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "lsb"

lsb_files = ""
lsb_files += "lsb.manifest"
lsb_files += "/usr/share/license/lsb"
lsb_files += "/lib/lsb/init-functions"

FILES_${PN} = "${lsb_files}"

PKG_lsb= "lsb"

require lsb-extraconf.inc
