DESCRIPTION = "Tool for enabling and disabling wireless devices"
HOMEPAGE = "http://wireless.kernel.org/download/rfkill/"
SECTION = "Productivity/Networking/Other"
LICENSE = "ISC"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by rfkill-docs  
PROVIDES += "rfkill-docs "
RPROVIDES_rfkill-docs  += "rfkill-docs "

#PROVIDES by rfkill 
PROVIDES += "rfkill"
RPROVIDES_rfkill += "rfkill"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/rfkill.manifest .
 
 
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
 
 install -Dm755 rfkill ${D}/usr/sbin/rfkill
 install -Dm644 rfkill.8 ${D}/usr/share/man/man8/rfkill.8
 
 
 
}

PACKAGES = ""
PACKAGES += "rfkill-docs"
PACKAGES += "rfkill"

rfkill-docs_files = ""
rfkill-docs_files += "/usr/share/info"
rfkill-docs_files += "/usr/share/man"

rfkill_files = ""
rfkill_files += "rfkill.manifest"
rfkill_files += "COPYING"
rfkill_files += "/usr/sbin/rfkill"

FILES_${PN}-docs = "${rfkill-docs_files}"
FILES_${PN} = "${rfkill_files}"

PKG_rfkill-docs= "rfkill-docs"
PKG_rfkill= "rfkill"

require rfkill-extraconf.inc
