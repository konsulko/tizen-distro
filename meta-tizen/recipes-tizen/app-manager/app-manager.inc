DESCRIPTION = "Application Manager API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "API/C API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-appfw-app-manager 
PROVIDES += "capi-appfw-app-manager"
RPROVIDES_capi-appfw-app-manager += "capi-appfw-app-manager"

#PROVIDES by capi-appfw-app-manager-devel 
PROVIDES += "capi-appfw-app-manager-devel"
RPROVIDES_capi-appfw-app-manager-devel += "capi-appfw-app-manager-devel"
RPROVIDES_capi-appfw-app-manager-devel += "capi-appfw-app-manager-dev"

RDEPENDS = ""
#RDEPENDS of capi-appfw-app-manager-devel (capi-appfw-${PN}-devel)
RDEPENDS_capi-appfw-${PN}-devel += "capi-appfw-app-manager"


DEPENDS = ""
#DEPENDS of capi-appfw-app-manager 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(pkgmgr)"
DEPENDS += "ail"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(capi-base-common)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-appfw-app-manager.manifest .
 
 
 
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
 cp LICENSE ${D}/usr/share/license/capi-appfw-app-manager
 
 
}

PACKAGES = ""
PACKAGES += "capi-appfw-app-manager"
PACKAGES += "capi-appfw-app-manager-devel"

capi-appfw-app-manager_files = ""
capi-appfw-app-manager_files += "capi-appfw-app-manager.manifest"
capi-appfw-app-manager_files += "/usr/lib/libcapi-appfw-app-manager.so.*"
capi-appfw-app-manager_files += "capi-appfw-app-manager.manifest"
capi-appfw-app-manager_files += "/usr/share/license/capi-appfw-app-manager"

capi-appfw-app-manager-devel_files = ""
capi-appfw-app-manager-devel_files += "capi-appfw-app-manager.manifest"
capi-appfw-app-manager-devel_files += "/usr/include/appfw/*.h"
capi-appfw-app-manager-devel_files += "/usr/lib/libcapi-appfw-app-manager.so"
capi-appfw-app-manager-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${capi-appfw-app-manager_files}"
FILES_${PN}-devel = "${capi-appfw-app-manager-devel_files}"

PKG_capi-appfw-app-manager= "capi-appfw-app-manager"
PKG_capi-appfw-app-manager-devel= "capi-appfw-app-manager-devel"

require app-manager-extraconf.inc
