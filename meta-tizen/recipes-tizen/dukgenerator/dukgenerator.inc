DESCRIPTION = "Device Unique Key Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dukgenerator-devel 
PROVIDES += "dukgenerator-devel"
RPROVIDES_dukgenerator-devel += "dukgenerator-devel"
RPROVIDES_dukgenerator-devel += "dukgenerator-dev"

#PROVIDES by dukgenerator 
PROVIDES += "dukgenerator"
RPROVIDES_dukgenerator += "dukgenerator"

RDEPENDS = ""
#RDEPENDS of dukgenerator-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "dukgenerator"


DEPENDS = ""
#DEPENDS of dukgenerator 
DEPENDS += "pkgconfig(cryptsvc)"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "cmake"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/dukgenerator.manifest .
 
 
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
 
 MAJORVER=`echo 1.0.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DLIB_INSTALL_DIR:PATH=/usr/lib -DFULLVER=1.0.0 -DMAJORVER=${MAJORVER} -DDESCRIPTION="Device Unique Key Library" -DBUILD_SHARED_LIBS:BOOL=OFF
 make -j16
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${D} INSTALL_ROOT=${D} install
 rm -f ${D}/usr/share/info/dir
 find ${D} -regex ".*\\.la$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "dukgenerator-devel"
PACKAGES += "dukgenerator"

dukgenerator-devel_files = ""
dukgenerator-devel_files += "dukgenerator.manifest"
dukgenerator-devel_files += "/usr/include/*"
dukgenerator-devel_files += "/usr/lib/pkgconfig/dukgenerator.pc"

dukgenerator_files = ""
dukgenerator_files += "dukgenerator.manifest"
dukgenerator_files += "/usr/lib/*.a"

FILES_${PN}-devel = "${dukgenerator-devel_files}"
FILES_${PN} = "${dukgenerator_files}"

PKG_dukgenerator-devel= "dukgenerator-devel"
PKG_dukgenerator= "dukgenerator"

require dukgenerator-extraconf.inc
