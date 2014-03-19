DESCRIPTION = "Smartcard Service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Network & Connectivity/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by smartcard-service-devel 
PROVIDES += "smartcard-service-devel"
RPROVIDES_smartcard-service-devel += "smartcard-service-devel"
RPROVIDES_smartcard-service-devel += "smartcard-service-dev"

#PROVIDES by smartcard-service 
PROVIDES += "smartcard-service"
RPROVIDES_smartcard-service += "smartcard-service"

#PROVIDES by smartcard-service-common-devel 
PROVIDES += "smartcard-service-common-devel"
RPROVIDES_smartcard-service-common-devel += "smartcard-service-common-devel"
RPROVIDES_smartcard-service-common-devel += "smartcard-service-common-dev"

#PROVIDES by smartcard-service-server 
PROVIDES += "smartcard-service-server"
RPROVIDES_smartcard-service-server += "smartcard-service-server"

#PROVIDES by smartcard-service-common 
PROVIDES += "smartcard-service-common"
RPROVIDES_smartcard-service-common += "smartcard-service-common"

RDEPENDS = ""
#RDEPENDS of smartcard-service-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "smartcard-service"

#RDEPENDS of smartcard-service (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "smartcard-service-common"

#RDEPENDS of smartcard-service-common-devel (${PN}-common-devel)
RDEPENDS_${PN}-common-devel += "smartcard-service-common"

#RDEPENDS of smartcard-service-server (${PN}-server)
RDEPENDS_${PN}-server += "smartcard-service-common"


DEPENDS = ""
#DEPENDS of smartcard-service 
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "cmake"
DEPENDS += "slp-pkgmgr"
inherit pythonnative
DEPENDS += "pkgconfig(aul)"
DEPENDS += "openssl"
DEPENDS += "dlog"
DEPENDS += "pkgmgr-info"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(gio-unix-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/smartcard-service.manifest ${S}/packaging/smartcard-service-devel.manifest ${S}/packaging/smartcard-service-common.manifest ${S}/packaging/smartcard-service-common-devel.manifest ${S}/packaging/smartcard-service-server.manifest .
 
 
 
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
 
 MAJORVER=`echo 0.1.28 | awk 'BEGIN {FS="."}{print $1}'`
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . "-DUSE_AUTOSTART=1"  -DFULLVER=0.1.28 -DMAJORVER=${MAJORVER}
 
 
 
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
PACKAGES += "smartcard-service-devel"
PACKAGES += "smartcard-service"
PACKAGES += "smartcard-service-common-devel"
PACKAGES += "smartcard-service-server"
PACKAGES += "smartcard-service-common"

smartcard-service-devel_files = ""
smartcard-service-devel_files += "smartcard-service-devel.manifest"
smartcard-service-devel_files += "/usr/include/smartcard-service/*"
smartcard-service-devel_files += "/usr/lib/libsmartcard-service.so"
smartcard-service-devel_files += "/usr/lib/pkgconfig/smartcard-service.pc"

smartcard-service_files = ""
smartcard-service_files += "smartcard-service.manifest"
smartcard-service_files += "/usr/lib/libsmartcard-service.so.*"

smartcard-service-common-devel_files = ""
smartcard-service-common-devel_files += "smartcard-service-common-devel.manifest"
smartcard-service-common-devel_files += "/usr/include/smartcard-service-common/*"
smartcard-service-common-devel_files += "/usr/lib/libsmartcard-service-common.so"
smartcard-service-common-devel_files += "/usr/lib/pkgconfig/smartcard-service-common.pc"

smartcard-service-server_files = ""
smartcard-service-server_files += "smartcard-service-server.manifest"
smartcard-service-server_files += "/usr/bin/smartcard-daemon"
smartcard-service-server_files += "/usr/share/packages/smartcard-service-server.xml"
smartcard-service-server_files += "/usr/share/dbus-1/services/org.tizen.smartcard_service.service"

smartcard-service-common_files = ""
smartcard-service-common_files += "smartcard-service-common.manifest"
smartcard-service-common_files += "/usr/lib/libsmartcard-service-common.so.*"

FILES_${PN}-devel = "${smartcard-service-devel_files}"
FILES_${PN} = "${smartcard-service_files}"
FILES_${PN}-common-devel = "${smartcard-service-common-devel_files}"
FILES_${PN}-server = "${smartcard-service-server_files}"
FILES_${PN}-common = "${smartcard-service-common_files}"

PKG_smartcard-service-devel= "smartcard-service-devel"
PKG_smartcard-service= "smartcard-service"
PKG_smartcard-service-common-devel= "smartcard-service-common-devel"
PKG_smartcard-service-server= "smartcard-service-server"
PKG_smartcard-service-common= "smartcard-service-common"

require smartcard-service-extraconf.inc
