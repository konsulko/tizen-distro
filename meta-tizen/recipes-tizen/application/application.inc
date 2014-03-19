DESCRIPTION = "An Application library in SLP C API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-appfw-application-devel 
PROVIDES += "capi-appfw-application-devel"
RPROVIDES_capi-appfw-application-devel += "capi-appfw-application-devel"
RPROVIDES_capi-appfw-application-devel += "capi-appfw-application-dev"

#PROVIDES by capi-appfw-application 
PROVIDES += "capi-appfw-application"
RPROVIDES_capi-appfw-application += "capi-appfw-application"

RDEPENDS = ""
#RDEPENDS of capi-appfw-application-devel (capi-appfw-${PN}-devel)
RDEPENDS_capi-appfw-${PN}-devel += "capi-appfw-application"


DEPENDS = ""
#DEPENDS of capi-appfw-application 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(alarm-service)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "app-svc"
DEPENDS += "app-core"
DEPENDS += "ail"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(elementary)"
DEPENDS += "pkgconfig(capi-base-common)"
DEPENDS += "pkgconfig(bundle)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(notification)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-appfw-application.manifest .
 
 
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
 
 MAJORVER=`echo 0.1.0 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.1.0 -DMAJORVER=${MAJORVER}
 
 
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
 cp LICENSE ${D}/usr/share/license/capi-appfw-application
 
 
}

PACKAGES = ""
PACKAGES += "capi-appfw-application-devel"
PACKAGES += "capi-appfw-application"

capi-appfw-application-devel_files = ""
capi-appfw-application-devel_files += "capi-appfw-application.manifest"
capi-appfw-application-devel_files += "/usr/include/appfw/*.h"
capi-appfw-application-devel_files += "/usr/lib/pkgconfig/*.pc"
capi-appfw-application-devel_files += "/usr/lib/libcapi-appfw-application.so"

capi-appfw-application_files = ""
capi-appfw-application_files += "capi-appfw-application.manifest"
capi-appfw-application_files += "/usr/lib/libcapi-appfw-application.so.*"
capi-appfw-application_files += "capi-appfw-application.manifest"
capi-appfw-application_files += "/usr/share/license/capi-appfw-application"

FILES_${PN}-devel = "${capi-appfw-application-devel_files}"
FILES_${PN} = "${capi-appfw-application_files}"

PKG_capi-appfw-application-devel= "capi-appfw-application-devel"
PKG_capi-appfw-application= "capi-appfw-application"

require application-extraconf.inc
