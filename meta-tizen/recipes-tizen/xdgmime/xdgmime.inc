DESCRIPTION = "Pkg xdgmime"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "LGPLv2, AFLv2"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xdgmime-devel 
PROVIDES += "xdgmime-devel"
RPROVIDES_xdgmime-devel += "xdgmime-devel"
RPROVIDES_xdgmime-devel += "xdgmime-dev"

#PROVIDES by xdgmime 
PROVIDES += "xdgmime"
RPROVIDES_xdgmime += "xdgmime"

RDEPENDS = ""
#RDEPENDS of xdgmime-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "xdgmime"


DEPENDS = ""
#DEPENDS of xdgmime 
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xdgmime.manifest .
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . 
 
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
PACKAGES += "xdgmime-devel"
PACKAGES += "xdgmime"

xdgmime-devel_files = ""
xdgmime-devel_files += "xdgmime.manifest"
xdgmime-devel_files += "/usr/include/xdgmime.h"
xdgmime-devel_files += "/usr/lib/libxdgmime.so"
xdgmime-devel_files += "/usr/lib/pkgconfig/xdgmime.pc"

xdgmime_files = ""
xdgmime_files += "xdgmime.manifest"
xdgmime_files += "/usr/lib/libxdgmime.so.*"
xdgmime_files += "xdgmime.manifest"

FILES_${PN}-devel = "${xdgmime-devel_files}"
FILES_${PN} = "${xdgmime_files}"

PKG_xdgmime-devel= "xdgmime-devel"
PKG_xdgmime= "xdgmime"

require xdgmime-extraconf.inc
