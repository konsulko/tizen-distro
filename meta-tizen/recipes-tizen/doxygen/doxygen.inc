DESCRIPTION = "Automated C, C++, and Java Documentation Generator"
HOMEPAGE = "http://www.stack.nl/~dimitri/doxygen/"
SECTION = "Development/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by doxygen-docs


#PROVIDES by doxygen


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of doxygen
DEPENDS += "flex"
DEPENDS_append_class-native = " bison-native"
DEPENDS_append_class-target = " bison-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/doxygen.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 unset QTDIR
 ./configure \
    --prefix ${prefix} \
    --shared \
    --release
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " doxygen-docs "
PACKAGES += " doxygen "

doxygen-docs_files = ""

doxygen_files = ""
doxygen_files += "doxygen.manifest"
doxygen_files += "${prefix}/bin/*"

FILES_${PN}-docs = "${doxygen-docs_files}"
FILES_${PN} = "${doxygen_files}"

PKG_doxygen-docs= "doxygen-docs"
PKG_doxygen= "doxygen"

require doxygen-extraconf.inc

