DESCRIPTION = "Automated C, C++, and Java Documentation Generator"
HOMEPAGE = "http://www.stack.nl/~dimitri/doxygen/"
SECTION = "Development/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by doxygen-docs  
PROVIDES += "doxygen-docs "
RPROVIDES_doxygen-docs  += "doxygen-docs "

#PROVIDES by doxygen 
PROVIDES += "doxygen"
RPROVIDES_doxygen += "doxygen"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of doxygen 
DEPENDS += "flex"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "bison-native"
DEPENDS += "gcc-c++"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/doxygen.manifest .
 
 
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
 
 unset QTDIR
 ./configure \
    --prefix /usr \
    --shared \
    --release
 make -j16
 
 
 
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
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 
}

PACKAGES = ""
PACKAGES += "doxygen-docs"
PACKAGES += "doxygen"

doxygen-docs_files = ""
doxygen-docs_files += "/usr/share/info"
doxygen-docs_files += "/usr/share/man"

doxygen_files = ""
doxygen_files += "doxygen.manifest"

FILES_${PN}-docs = "${doxygen-docs_files}"
FILES_${PN} = "${doxygen_files}"

PKG_doxygen-docs= "doxygen-docs"
PKG_doxygen= "doxygen"

require doxygen-extraconf.inc
