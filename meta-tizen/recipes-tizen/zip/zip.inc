DESCRIPTION = "File compression program"
HOMEPAGE = "http://www.info-zip.org/"
SECTION = "Productivity/Archiving/Compression"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by zip-docs  
PROVIDES += "zip-docs "
RPROVIDES_zip-docs  += "zip-docs "

#PROVIDES by zip 
PROVIDES += "zip"
RPROVIDES_zip += "zip"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n zip30
 cp ${S}/packaging/zip.manifest .
 
 
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
 
 make -j16 -f unix/Makefile prefix=/usr CC="gcc -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -DLARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64" generic_gcc
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 mkdir -p ${D}/usr/share/man/man1
 make install -f unix/Makefile BINDIR=${D}/usr/bin MANDIR=${D}/usr/share/man/man1
 
 
 
}

PACKAGES = ""
PACKAGES += "zip-docs"
PACKAGES += "zip"

zip-docs_files = ""
zip-docs_files += "/usr/share/info"
zip-docs_files += "/usr/share/man"

zip_files = ""
zip_files += "zip.manifest"
zip_files += "LICENSE"
zip_files += "/usr/bin/zip"
zip_files += "/usr/bin/zipcloak"
zip_files += "/usr/bin/zipnote"
zip_files += "/usr/bin/zipsplit"

FILES_${PN}-docs = "${zip-docs_files}"
FILES_${PN} = "${zip_files}"

PKG_zip-docs= "zip-docs"
PKG_zip= "zip"

require zip-extraconf.inc
