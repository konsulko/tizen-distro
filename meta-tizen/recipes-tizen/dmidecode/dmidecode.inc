DESCRIPTION = "DMI table decoder"
HOMEPAGE = "http://www.nongnu.org/dmidecode/"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dmidecode 
PROVIDES += "dmidecode"
RPROVIDES_dmidecode += "dmidecode"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup
 cp ${S}/packaging/dmidecode.manifest .
 
 
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
 
 make CFLAGS="$RPM_OPT_FLAGS" -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -dm 755 ${D}/usr/sbin
 install -dm 755 ${D}/usr/share/man/man8
 install -dm 755 ${D}/usr/share/doc/packages/dmidecode
 for i in dmidecode vpddecode ownership biosdecode ; do
 install -m 755 $i ${D}/usr/sbin/
 install -m 644 man/$i.8 ${D}/usr/share/man/man8/
 done
 
 
}

PACKAGES = ""
PACKAGES += "dmidecode"

dmidecode_files = ""
dmidecode_files += "dmidecode.manifest"
dmidecode_files += "/usr/sbin/*"
dmidecode_files += "/usr/share/man/man8/*"

FILES_${PN} = "${dmidecode_files}"

PKG_dmidecode= "dmidecode"

require dmidecode-extraconf.inc
