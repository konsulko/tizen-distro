DESCRIPTION = "A utility for unpacking zip files"
HOMEPAGE = "http://www.info-zip.org/pub/infozip/UnZip.html"
SECTION = "Applications/Archiving"
LICENSE = "BSD"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by unzip 
PROVIDES += "unzip"
RPROVIDES_unzip += "unzip"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n unzip60
 cp ${S}/packaging/unzip.manifest .
 
 
 
 ln -s unix/Makefile Makefile
 
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
 
 make CFLAGS="-D_LARGEFILE64_SOURCE" linux_noasm LF2="" -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 make prefix=${D}/usr MANDIR=${D}//usr/share/man/man1 INSTALL="cp -p" install LF2=""
 
 
}

PACKAGES = ""
PACKAGES += "unzip"

unzip_files = ""
unzip_files += "unzip.manifest"
unzip_files += "LICENSE"
unzip_files += "/usr/bin/*"
unzip_files += "/usr/share/man/*/*"

FILES_${PN} = "${unzip_files}"

PKG_unzip= "unzip"

require unzip-extraconf.inc
