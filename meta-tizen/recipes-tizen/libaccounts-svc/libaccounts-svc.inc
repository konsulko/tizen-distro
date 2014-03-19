DESCRIPTION = "Account DB library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "TO_BE/FILLED_IN"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libaccounts-svc 
PROVIDES += "libaccounts-svc"
RPROVIDES_libaccounts-svc += "libaccounts-svc"

#PROVIDES by libaccounts-svc-devel 
PROVIDES += "libaccounts-svc-devel"
RPROVIDES_libaccounts-svc-devel += "libaccounts-svc-devel"
RPROVIDES_libaccounts-svc-devel += "libaccounts-svc-dev"

RDEPENDS = ""
#RDEPENDS of libaccounts-svc (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "/usr/bin/sqlite3"

#RDEPENDS of libaccounts-svc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libaccounts-svc"


DEPENDS = ""
#DEPENDS of libaccounts-svc 
DEPENDS += "pkgconfig(capi-appfw-application)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libaccounts-svc.manifest .
 
 
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
 
 export CFLAGS="${CFLAGS} -fPIC -fvisibility=hidden"
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 rm -rf ${D}/usr/lib/accounts-svc
 
 
}

PACKAGES = ""
PACKAGES += "libaccounts-svc"
PACKAGES += "libaccounts-svc-devel"

libaccounts-svc_files = ""
libaccounts-svc_files += "libaccounts-svc.manifest"
libaccounts-svc_files += "/usr/lib/*.so.*"
libaccounts-svc_files += "/usr/bin/account-xml-verify"

libaccounts-svc-devel_files = ""
libaccounts-svc-devel_files += "libaccounts-svc.manifest"
libaccounts-svc-devel_files += "/usr/lib/*.so"
libaccounts-svc-devel_files += "/usr/lib/pkgconfig/accounts-svc.pc"
libaccounts-svc-devel_files += "/usr/include/*.h"
libaccounts-svc-devel_files += "/usr/bin/account-xml-verify"

FILES_${PN} = "${libaccounts-svc_files}"
FILES_${PN}-devel = "${libaccounts-svc-devel_files}"

PKG_libaccounts-svc= "libaccounts-svc"
PKG_libaccounts-svc-devel= "libaccounts-svc-devel"

require libaccounts-svc-extraconf.inc
