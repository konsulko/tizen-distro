DESCRIPTION = "Chromium Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "App Framework/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by chromium 
PROVIDES += "chromium"
RPROVIDES_chromium += "chromium"

#PROVIDES by chromium-devel 
PROVIDES += "chromium-devel"
RPROVIDES_chromium-devel += "chromium-devel"
RPROVIDES_chromium-devel += "chromium-dev"

RDEPENDS = ""
#RDEPENDS of chromium-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "chromium"


DEPENDS = ""
#DEPENDS of chromium 
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/chromium.manifest .
 
 
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
 
 MAJORVER=`echo 1.0 | awk 'BEGIN {FS="."}{print $1}'`
 CXXFLAGS="$CXXFLAGS -D_OSP_DEBUG_ -D_OSP_ARMEL_" 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .  -DFULLVER=1.0 -DMAJORVER=${MAJORVER}
 # Call make instruction with smp support
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
PACKAGES += "chromium"
PACKAGES += "chromium-devel"

chromium_files = ""
chromium_files += "chromium.manifest"
chromium_files += "/usr/lib/libchromium.so*"

chromium-devel_files = ""
chromium-devel_files += "chromium.manifest"
chromium-devel_files += "/usr/include/chromium/*"
chromium-devel_files += "/usr/lib/pkgconfig/chromium.pc"

FILES_${PN} = "${chromium_files}"
FILES_${PN}-devel = "${chromium-devel_files}"

PKG_chromium= "chromium"
PKG_chromium-devel= "chromium-devel"

require chromium-extraconf.inc
