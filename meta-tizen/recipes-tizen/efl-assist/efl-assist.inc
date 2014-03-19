DESCRIPTION = "EFL assist library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by efl-assist-devel 
PROVIDES += "efl-assist-devel"
RPROVIDES_efl-assist-devel += "efl-assist-devel"
RPROVIDES_efl-assist-devel += "efl-assist-dev"

#PROVIDES by efl-assist 
PROVIDES += "efl-assist"
RPROVIDES_efl-assist += "efl-assist"

RDEPENDS = ""
#RDEPENDS of efl-assist-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "capi-base-common-dev"
RDEPENDS_${PN}-devel += "efl-assist"

#RDEPENDS of efl-assist (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of efl-assist 
DEPENDS += "pkgconfig(ecore-wayland)"
DEPENDS += "pkgconfig(capi-appfw-application)"
DEPENDS += "cmake"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(tts)"
DEPENDS += "common"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "pkgconfig(vconf)"

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
 
 export CFLAGS+=" -fvisibility=hidden"
 export LDFLAGS+=" -fvisibility=hidden"
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . \
     -DCMAKE_INSTALL_PREFIX=/usr \
     -DX11_SUPPORT=Off \
     -DWAYLAND_SUPPORT=On \
     #eol
 
 
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/LICENSE ${D}/usr/share/license/efl-assist
 
 
 
}

PACKAGES = ""
PACKAGES += "efl-assist-devel"
PACKAGES += "efl-assist"

efl-assist-devel_files = ""
efl-assist-devel_files += "/usr/include/efl-assist/*.h"
efl-assist-devel_files += "/usr/lib/*.so"
efl-assist-devel_files += "/usr/lib/pkgconfig/efl-assist.pc"

efl-assist_files = ""
efl-assist_files += "/usr/lib/libefl-assist.so.*"
efl-assist_files += "efl-assist.manifest"

FILES_${PN}-devel = "${efl-assist-devel_files}"
FILES_${PN} = "${efl-assist_files}"

PKG_efl-assist-devel= "efl-assist-devel"
PKG_efl-assist= "efl-assist"

require efl-assist-extraconf.inc
