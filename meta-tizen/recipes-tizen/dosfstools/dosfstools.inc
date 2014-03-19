DESCRIPTION = "Utilities for Making and Checking MS-DOS FAT File Systems on Linux"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/File Systems"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dosfstools-docs  
PROVIDES += "dosfstools-docs "
RPROVIDES_dosfstools-docs  += "dosfstools-docs "

#PROVIDES by dosfstools 
PROVIDES += "dosfstools"
RPROVIDES_dosfstools += "dosfstools"

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
 
 cp ${S}/packaging/dosfstools.manifest .
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} PREFIX=/usr
 
 rm -rf ${D}/usr/share/doc/dosfstools
 
 
 
 
}

PACKAGES = ""
PACKAGES += "dosfstools"
PACKAGES += "dosfstools-docs"

dosfstools_files = ""
dosfstools_files += "dosfstools.manifest"
dosfstools_files += "dosfstools.manifest"
dosfstools_files += "/usr/sbin/dosfsck"
dosfstools_files += "/usr/sbin/dosfslabel"
dosfstools_files += "/usr/sbin/fsck.msdos"
dosfstools_files += "/usr/sbin/fsck.vfat"
dosfstools_files += "/usr/sbin/mkdosfs"
dosfstools_files += "/usr/sbin/mkfs.msdos"
dosfstools_files += "/usr/sbin/mkfs.vfat"

dosfstools-docs_files = ""
dosfstools-docs_files += "/usr/share/info"
dosfstools-docs_files += "/usr/share/man"

FILES_${PN} = "${dosfstools_files}"
FILES_${PN}-docs = "${dosfstools-docs_files}"

PKG_dosfstools= "dosfstools"
PKG_dosfstools-docs= "dosfstools-docs"

require dosfstools-extraconf.inc
