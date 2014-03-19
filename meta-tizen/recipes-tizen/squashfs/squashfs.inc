DESCRIPTION = "A Read-Only File System with Efficient Compression"
HOMEPAGE = "http://squashfs.sourceforge.net/"
SECTION = "System/Filesystems"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by squashfs 
PROVIDES += "squashfs"
RPROVIDES_squashfs += "squashfs"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of squashfs 
DEPENDS += "zlib-devel"
DEPENDS += "lzma-devel"
DEPENDS += "attr"
DEPENDS += "lzo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n squashfs4.2
 cp ${S}/packaging/squashfs.manifest .
 
 
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
 
 sed -i -e "s#-O2#-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables#g" squashfs-tools/Makefile
 make -j16 -C squashfs-tools XZ_SUPPORT=1 LZO_SUPPORT=1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 install -m 755 squashfs-tools/{un,mk}squashfs ${D}/usr/bin
 
 
}

PACKAGES = ""
PACKAGES += "squashfs"

squashfs_files = ""
squashfs_files += "squashfs.manifest"
squashfs_files += "/usr/bin/*squashfs"

FILES_${PN} = "${squashfs_files}"

PKG_squashfs= "squashfs"

require squashfs-extraconf.inc
