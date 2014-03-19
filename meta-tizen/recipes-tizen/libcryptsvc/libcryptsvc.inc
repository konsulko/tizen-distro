DESCRIPTION = "Crypto Service Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Libraries"
LICENSE = "Apache-2.0 and Flora"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcryptsvc-devel 
PROVIDES += "libcryptsvc-devel"
RPROVIDES_libcryptsvc-devel += "libcryptsvc-devel"
RPROVIDES_libcryptsvc-devel += "libcryptsvc-dev"

#PROVIDES by libcryptsvc 
PROVIDES += "libcryptsvc"
RPROVIDES_libcryptsvc += "libcryptsvc"

RDEPENDS = ""
#RDEPENDS of libcryptsvc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libcryptsvc"


DEPENDS = ""
#DEPENDS of libcryptsvc 
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libcryptsvc.manifest .
 
 
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
 
 MAJORVER=`echo 0.0.1 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DARCH=x86 -DFULLVER=0.0.1 -DMAJORVER=${MAJORVER} -DDESCRIPTION="Crypto Service Library (Development)"
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
PACKAGES += "libcryptsvc-devel"
PACKAGES += "libcryptsvc"

libcryptsvc-devel_files = ""
libcryptsvc-devel_files += "libcryptsvc.manifest"
libcryptsvc-devel_files += "/usr/include/*"
libcryptsvc-devel_files += "/usr/lib/pkgconfig/cryptsvc.pc"

libcryptsvc_files = ""
libcryptsvc_files += "libcryptsvc.manifest"
libcryptsvc_files += "/usr/lib/*.so*"

FILES_${PN}-devel = "${libcryptsvc-devel_files}"
FILES_${PN} = "${libcryptsvc_files}"

PKG_libcryptsvc-devel= "libcryptsvc-devel"
PKG_libcryptsvc= "libcryptsvc"

require libcryptsvc-extraconf.inc
