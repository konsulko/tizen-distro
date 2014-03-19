DESCRIPTION = "Application installation on external memory"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Application Framework/Package Management"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by app2sd 
PROVIDES += "app2sd"
RPROVIDES_app2sd += "app2sd"

#PROVIDES by app2sd-devel 
PROVIDES += "app2sd-devel"
RPROVIDES_app2sd-devel += "app2sd-devel"
RPROVIDES_app2sd-devel += "app2sd-dev"

RDEPENDS = ""
#RDEPENDS of app2sd-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "app2sd"


DEPENDS = ""
#DEPENDS of app2sd 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "pkgconfig(libssl)"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(db-util)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/app2sd.manifest .
 
 
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
PACKAGES += "app2sd"
PACKAGES += "app2sd-devel"

app2sd_files = ""
app2sd_files += "app2sd.manifest"
app2sd_files += "/usr/lib/libapp2ext.so.*"
app2sd_files += "/usr/lib/libapp2sd.so.*"

app2sd-devel_files = ""
app2sd-devel_files += "app2sd.manifest"
app2sd-devel_files += "/usr/include/app2ext_interface.h"
app2sd-devel_files += "/usr/lib/pkgconfig/app2sd.pc"
app2sd-devel_files += "/usr/lib/libapp2sd.so"
app2sd-devel_files += "/usr/lib/libapp2ext.so"

FILES_${PN} = "${app2sd_files}"
FILES_${PN}-devel = "${app2sd-devel_files}"

PKG_app2sd= "app2sd"
PKG_app2sd-devel= "app2sd-devel"

require app2sd-extraconf.inc
