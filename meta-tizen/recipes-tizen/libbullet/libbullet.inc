DESCRIPTION = "Bullet Continuous Collision Detection and Physics Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Zlib"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by bullet-devel 
PROVIDES += "bullet-devel"
RPROVIDES_bullet-devel += "bullet-devel"
RPROVIDES_bullet-devel += "bullet-dev"

#PROVIDES by libbullet 
PROVIDES += "libbullet"
RPROVIDES_libbullet += "libbullet"

#PROVIDES by bullet 
PROVIDES += "bullet"
RPROVIDES_bullet += "bullet"

RDEPENDS = ""
#RDEPENDS of bullet-devel (bullet-devel)
RDEPENDS_bullet-devel += "libbullet"


DEPENDS = ""
#DEPENDS of bullet 
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bullet.manifest .
   
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -G "Unix Makefiles" -DBUILD_SHARED_LIBS=ON -DBUILD_EXTRAS=OFF -DBUILD_DEMOS=OFF -DBUILD_CPU_DEMOS=OFF -DUSE_GRAPHICAL_BENCHMARK=OFF -DCMAKE_INSTALL_PREFIX=/usr -DUSE_GLUT=OFF
 
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
PACKAGES += "bullet-devel"
PACKAGES += "libbullet"

bullet-devel_files = ""
bullet-devel_files += "bullet.manifest"
bullet-devel_files += "/usr/include/*"
bullet-devel_files += "/usr/lib/*.so"
bullet-devel_files += "/usr/lib/pkgconfig/*"

libbullet_files = ""
libbullet_files += "bullet.manifest"
libbullet_files += "/usr/lib/*.so.2.81"
libbullet_files += ""

FILES_${PN}-devel = "${bullet-devel_files}"
FILES_lib${PN} = "${libbullet_files}"

PKG_bullet-devel= "bullet-devel"
PKG_libbullet= "libbullet"

require libbullet-extraconf.inc
