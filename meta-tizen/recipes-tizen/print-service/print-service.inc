DESCRIPTION = "print service library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Flora Software License"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by print-service-devel 
PROVIDES += "print-service-devel"
RPROVIDES_print-service-devel += "print-service-devel"
RPROVIDES_print-service-devel += "print-service-dev"

#PROVIDES by print-service 
PROVIDES += "print-service"
RPROVIDES_print-service += "print-service"

#PROVIDES by print-driver-data 
PROVIDES += "print-driver-data"
RPROVIDES_print-driver-data += "print-driver-data"

#PROVIDES by print-service-tests 
PROVIDES += "print-service-tests"
RPROVIDES_print-service-tests += "print-service-tests"

RDEPENDS = ""
#RDEPENDS of print-service-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "print-service"

#RDEPENDS of print-service (${PN})
RDEPENDS_${PN} += "cups"
RDEPENDS_${PN} += "glib2"
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of print-driver-data (print-driver-data)
RDEPENDS_print-driver-data += "print-service"

#RDEPENDS of print-service-tests (${PN}-tests)
RDEPENDS_${PN}-tests += "print-service"


DEPENDS = ""
#DEPENDS of print-service 
DEPENDS += "glib"
DEPENDS += "cmake"
DEPENDS += "libxml2"
DEPENDS += "dlog"
DEPENDS += "application"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "ecore"
DEPENDS += "cups"
DEPENDS += "pkgconfig(eina)"
DEPENDS += "binutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 cp ${S}/packaging/print-service.manifest .
 cp ${S}/packaging/print-driver-data.manifest .
 cp ${S}/packaging/print-service-tests.manifest .
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DENABLE_OM_TESTS=On
 
 
 
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
 cp ${WORKDIR}/git/LICENSE.Flora ${D}/usr/share/license/print-service
 cp ${WORKDIR}/git/LICENSE.Flora ${D}/usr/share/license/print-driver-data
 
 
}

PACKAGES = ""
PACKAGES += "print-driver-data"
PACKAGES += "print-service"
PACKAGES += "print-service-tests"
PACKAGES += "print-service-devel"

print-driver-data_files = ""
print-driver-data_files += "print-driver-data.manifest"
print-driver-data_files += "/usr/share/license/print-driver-data"
print-driver-data_files += "/usr/share/cups/ppd/"
print-driver-data_files += "/usr/share/cups/ppd/*"

print-service_files = ""
print-service_files += "print-service.manifest"
print-service_files += "/usr/share/license/print-service"
print-service_files += "/usr/lib/*.so*"

print-service-tests_files = ""
print-service-tests_files += "print-service-tests.manifest"
print-service-tests_files += "/usr/bin/getppdvalue"
print-service-tests_files += "/usr/lib/libopmap.so*"

print-service-devel_files = ""
print-service-devel_files += "/usr/include/print-service/*.h"
print-service-devel_files += "/usr/lib/pkgconfig/*"

FILES_print-driver-data = "${print-driver-data_files}"
FILES_${PN} = "${print-service_files}"
FILES_${PN}-tests = "${print-service-tests_files}"
FILES_${PN}-devel = "${print-service-devel_files}"

PKG_print-driver-data= "print-driver-data"
PKG_print-service= "print-service"
PKG_print-service-tests= "print-service-tests"
PKG_print-service-devel= "print-service-devel"

require print-service-extraconf.inc
