DESCRIPTION = "Wrt common library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wrt-commons 
PROVIDES += "wrt-commons"
RPROVIDES_wrt-commons += "wrt-commons"

#PROVIDES by wrt-commons-devel 
PROVIDES += "wrt-commons-devel"
RPROVIDES_wrt-commons-devel += "wrt-commons-devel"
RPROVIDES_wrt-commons-devel += "wrt-commons-dev"

RDEPENDS = ""
#RDEPENDS of wrt-commons-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "wrt-commons"


DEPENDS = ""
#DEPENDS of wrt-commons 
DEPENDS += "zlib-devel"
DEPENDS += "pcre"
DEPENDS += "sqlite"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(minizip)"
DEPENDS += "pkgconfig(libiri)"
DEPENDS += "libidn"
DEPENDS += "openssl"
DEPENDS += "dlog"
DEPENDS += "app-core"
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libslp-db-util"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/wrt-commons.manifest .
 
 
 
 
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
 
 
 export LDFLAGS+="-Wl,--rpath=/usr/lib -Wl,--hash-style=both -Wl,--as-needed"
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DVERSION=0.2.160 \
         -DDPL_LOG="OFF"      \
         -DCMAKE_BUILD_TYPE= \
          \
          -DX11_SUPPORT=Off \
         
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
PACKAGES += "wrt-commons"
PACKAGES += "wrt-commons-devel"

wrt-commons_files = ""
wrt-commons_files += "wrt-commons.manifest"
wrt-commons_files += "/usr/lib/*.so.*"
wrt-commons_files += "/usr/share/wrt-engine/*"

wrt-commons-devel_files = ""
wrt-commons-devel_files += "wrt-commons.manifest"
wrt-commons-devel_files += "/usr/lib/*.so"
wrt-commons-devel_files += "/usr/include/dpl-efl/*"
wrt-commons-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${wrt-commons_files}"
FILES_${PN}-devel = "${wrt-commons-devel_files}"

PKG_wrt-commons= "wrt-commons"
PKG_wrt-commons-devel= "wrt-commons-devel"

require wrt-commons-extraconf.inc
