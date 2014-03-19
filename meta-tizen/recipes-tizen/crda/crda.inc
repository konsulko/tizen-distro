DESCRIPTION = "Linux central regulatory domain agent"
HOMEPAGE = "http://wireless.kernel.org/en/developers/Regulatory/"
SECTION = "System/Base"
LICENSE = "ISC"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by crda-docs  
PROVIDES += "crda-docs "
RPROVIDES_crda-docs  += "crda-docs "

#PROVIDES by crda 
PROVIDES += "crda"
RPROVIDES_crda += "crda"

RDEPENDS = ""
#RDEPENDS of crda (${PN})
RDEPENDS_${PN} += "libnl"
RDEPENDS_${PN} += "libgcrypt"


DEPENDS = ""
#DEPENDS of crda 
DEPENDS += "libnl-devel"
DEPENDS += "gcc-cross"
DEPENDS += "python-M2Crypto"
DEPENDS += "libgcrypt-devel"
DEPENDS += "wireless-regdb"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/crda.manifest .
 
 
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
 
 make DESTDIR=${D} UDEV_RULE_DIR=/usr/lib/udev/rules.d SBINDIR=/usr/sbin
 
 
 
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
   find ${D} -regex ".*\.a$" | xargs rm -f -- UDEV_RULE_DIR=/usr/lib/udev/rules.d SBINDIR=/usr/sbin
 
 
 
}

PACKAGES = ""
PACKAGES += "crda"
PACKAGES += "crda-docs"

crda_files = ""
crda_files += "crda.manifest"
crda_files += "/usr/sbin/crda"
crda_files += "/usr/sbin/regdbdump"
crda_files += "/usr/lib/udev/rules.d/85-regulatory.rules"

crda-docs_files = ""
crda-docs_files += "/usr/share/info"
crda-docs_files += "/usr/share/man"

FILES_${PN} = "${crda_files}"
FILES_${PN}-docs = "${crda-docs_files}"

PKG_crda= "crda"
PKG_crda-docs= "crda-docs"

require crda-extraconf.inc
