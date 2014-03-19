DESCRIPTION = "Linux wireless regulatory database"
HOMEPAGE = "http://wireless.kernel.org/en/developers/Regulatory/"
SECTION = "System/Base"
LICENSE = "ISC"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wireless-regdb 
PROVIDES += "wireless-regdb"
RPROVIDES_wireless-regdb += "wireless-regdb"

RDEPENDS = ""
#RDEPENDS of wireless-regdb (${PN})
RDEPENDS_${PN} += "python"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/wireless-regdb.manifest .
 
 
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
 
 install -m 755 -d ${D}//usr/lib/crda
 install -m 644 regulatory.bin ${D}//usr/lib/crda/regulatory.bin
 
}

PACKAGES = ""
PACKAGES += "wireless-regdb"

wireless-regdb_files = ""
wireless-regdb_files += "wireless-regdb.manifest"
wireless-regdb_files += "/usr/lib/crda/regulatory.bin"

FILES_${PN} = "${wireless-regdb_files}"

PKG_wireless-regdb= "wireless-regdb"

require wireless-regdb-extraconf.inc
