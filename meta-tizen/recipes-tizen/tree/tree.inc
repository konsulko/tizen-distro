DESCRIPTION = "File listing as a tree"
HOMEPAGE = "http://mama.indstate.edu/users/ice/tree/"
SECTION = "System/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tree 
PROVIDES += "tree"
RPROVIDES_tree += "tree"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tree.manifest .
 
 
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
 
 make OPTFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" CC="gcc"
 
 
 
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
 install -m 644 doc/tree.1 ${D}/usr/share/man/man1
 install -m 755 tree ${D}/usr/bin
 
 
}

PACKAGES = ""
PACKAGES += "tree"

tree_files = ""
tree_files += "tree.manifest"
tree_files += "/usr/bin/tree"
tree_files += "/usr/share/man/man1/tree.1.gz"

FILES_${PN} = "${tree_files}"

PKG_tree= "tree"

require tree-extraconf.inc
