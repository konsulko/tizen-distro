DESCRIPTION = "Security server and utilities"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by security-server-certs 
PROVIDES += "security-server-certs"
RPROVIDES_security-server-certs += "security-server-certs"

#PROVIDES by security-server-devel 
PROVIDES += "security-server-devel"
RPROVIDES_security-server-devel += "security-server-devel"
RPROVIDES_security-server-devel += "security-server-dev"

#PROVIDES by security-server 
PROVIDES += "security-server"
RPROVIDES_security-server += "security-server"

#PROVIDES by libsecurity-server-client 
PROVIDES += "libsecurity-server-client"
RPROVIDES_libsecurity-server-client += "libsecurity-server-client"

#PROVIDES by libsecurity-server-client-devel 
PROVIDES += "libsecurity-server-client-devel"
RPROVIDES_libsecurity-server-client-devel += "libsecurity-server-client-devel"
RPROVIDES_libsecurity-server-client-devel += "libsecurity-server-client-dev"

RDEPENDS = ""
#RDEPENDS of security-server-certs (${PN}-certs)
RDEPENDS_${PN}-certs += "security-server"

#RDEPENDS of security-server-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "security-server"

#RDEPENDS of libsecurity-server-client-devel (lib${PN}-client-devel)
RDEPENDS_lib${PN}-client-devel += "libsecurity-server-client"

#RDEPENDS of libsecurity-server-client (lib${PN}-client)
RDEPENDS_lib${PN}-client += "/sbin/ldconfig"
RDEPENDS_lib${PN}-client += "security-server"

#RDEPENDS of security-server (${PN})
RDEPENDS_${PN} += "systemd"


DEPENDS = ""
#DEPENDS of security-server 
DEPENDS += "cmake"
DEPENDS += "attr"
DEPENDS += "zip"
DEPENDS += "pkgconfig(libsmack)"
DEPENDS += "openssl"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(libprivilege-control)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/security-server.manifest .
 
 
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
 
 export LDFLAGS+="-Wl,--rpath=/usr/lib"
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DVERSION=0.0.73 \
         -DCMAKE_BUILD_TYPE= \
         -DSMACK=Off
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
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/security-server
 cp LICENSE ${D}/usr/share/license/libsecurity-server-client
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m 0644 ${S}/packaging/security-server.service ${D}/usr/lib/systemd/system/security-server.service
 ln -s ../security-server.service ${D}/usr/lib/systemd/system/multi-user.target.wants/security-server.service
 
 
 
}

PACKAGES = ""
PACKAGES += "security-server"
PACKAGES += "libsecurity-server-client"
PACKAGES += "libsecurity-server-client-devel"

security-server_files = ""
security-server_files += "security-server.manifest"
security-server_files += "/usr/lib/systemd/system/multi-user.target.wants/security-server.service"
security-server_files += "/usr/lib/systemd/system/security-server.service"
security-server_files += "/usr/share/license/security-server"

libsecurity-server-client_files = ""
libsecurity-server-client_files += "security-server.manifest"
libsecurity-server-client_files += "/usr/lib/libsecurity-server-client.so.*"
libsecurity-server-client_files += "/usr/share/license/libsecurity-server-client"

libsecurity-server-client-devel_files = ""
libsecurity-server-client-devel_files += "security-server.manifest"
libsecurity-server-client-devel_files += "/usr/lib/libsecurity-server-client.so"
libsecurity-server-client-devel_files += "/usr/include/security-server/security-server.h"
libsecurity-server-client-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${security-server_files}"
FILES_lib${PN}-client = "${libsecurity-server-client_files}"
FILES_lib${PN}-client-devel = "${libsecurity-server-client-devel_files}"

PKG_security-server= "security-server"
PKG_libsecurity-server-client= "libsecurity-server-client"
PKG_libsecurity-server-client-devel= "libsecurity-server-client-devel"

require security-server-extraconf.inc
