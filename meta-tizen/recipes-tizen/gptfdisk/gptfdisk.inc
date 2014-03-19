DESCRIPTION = "GPT partitioning and MBR repair software"
HOMEPAGE = "http://rodsbooks.com/gdisk"
SECTION = "Base/System"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gptfdisk 
PROVIDES += "gptfdisk"
RPROVIDES_gptfdisk += "gptfdisk"

#PROVIDES by gptfdisk-fixparts 
PROVIDES += "gptfdisk-fixparts"
RPROVIDES_gptfdisk-fixparts += "gptfdisk-fixparts"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of gptfdisk 
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig(popt)"
DEPENDS += "ncurses-devel"
DEPENDS += "xz"
DEPENDS += "pkgconfig(uuid)"
DEPENDS += "pkgconfig(icu-uc)"
DEPENDS += "pkgconfig(icu-io)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/gptfdisk.manifest .
 
 
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
 
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" CXXFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 b="${D}";
 mkdir -p "$b//usr/sbin" "$b//usr/share/man/man8";
 install -pm0755 fixparts {,c,s}gdisk "$b//usr/sbin/";
 install -pm0644 *.8 "$b//usr/share/man/man8/";
 
 
}

PACKAGES = ""
PACKAGES += "gptfdisk"
PACKAGES += "gptfdisk-fixparts"

gptfdisk_files = ""
gptfdisk_files += "gptfdisk.manifest"
gptfdisk_files += "/usr/sbin/gdisk"
gptfdisk_files += "/usr/sbin/sgdisk"
gptfdisk_files += "/usr/sbin/cgdisk"
gptfdisk_files += "/usr/share/man/man8/gdisk.8*"
gptfdisk_files += "/usr/share/man/man8/cgdisk.8*"
gptfdisk_files += "/usr/share/man/man8/sgdisk.8*"

gptfdisk-fixparts_files = ""
gptfdisk-fixparts_files += "gptfdisk.manifest"
gptfdisk-fixparts_files += "/usr/sbin/fixparts"
gptfdisk-fixparts_files += "/usr/share/man/man8/fixparts.8*"

FILES_${PN} = "${gptfdisk_files}"
FILES_${PN}-fixparts = "${gptfdisk-fixparts_files}"

PKG_gptfdisk= "gptfdisk"
PKG_gptfdisk-fixparts= "gptfdisk-fixparts"

require gptfdisk-extraconf.inc
