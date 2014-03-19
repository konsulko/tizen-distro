DESCRIPTION = "Package Manager API"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/API"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by capi-appfw-package-manager-devel 
PROVIDES += "capi-appfw-package-manager-devel"
RPROVIDES_capi-appfw-package-manager-devel += "capi-appfw-package-manager-devel"
RPROVIDES_capi-appfw-package-manager-devel += "capi-appfw-package-manager-dev"

#PROVIDES by capi-appfw-package-manager 
PROVIDES += "capi-appfw-package-manager"
RPROVIDES_capi-appfw-package-manager += "capi-appfw-package-manager"

RDEPENDS = ""
#RDEPENDS of capi-appfw-package-manager-devel (capi-appfw-${PN}-devel)
RDEPENDS_capi-appfw-${PN}-devel += "capi-appfw-package-manager"


DEPENDS = ""
#DEPENDS of capi-appfw-package-manager 
DEPENDS += "cmake"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(pkgmgr)"
DEPENDS += "ail"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/capi-appfw-package-manager.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.0.29 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DFULLVER=0.0.29 -DMAJORVER=${MAJORVER}
 
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
 
 
}

PACKAGES = ""
PACKAGES += "capi-appfw-package-manager-devel"
PACKAGES += "capi-appfw-package-manager"

capi-appfw-package-manager-devel_files = ""
capi-appfw-package-manager-devel_files += "capi-appfw-package-manager.manifest"
capi-appfw-package-manager-devel_files += "/usr/include/appfw/package_manager.h"
capi-appfw-package-manager-devel_files += "/usr/include/appfw/package_info.h"
capi-appfw-package-manager-devel_files += "/usr/lib/libcapi-appfw-package-manager.so"
capi-appfw-package-manager-devel_files += "/usr/lib/pkgconfig/*.pc"

capi-appfw-package-manager_files = ""
capi-appfw-package-manager_files += "capi-appfw-package-manager.manifest"
capi-appfw-package-manager_files += "/usr/lib/libcapi-appfw-package-manager.so.*"
capi-appfw-package-manager_files += "/usr/bin/pkgmgr_tool"

FILES_${PN}-devel = "${capi-appfw-package-manager-devel_files}"
FILES_${PN} = "${capi-appfw-package-manager_files}"

PKG_capi-appfw-package-manager-devel= "capi-appfw-package-manager-devel"
PKG_capi-appfw-package-manager= "capi-appfw-package-manager"

require package-manager-extraconf.inc
