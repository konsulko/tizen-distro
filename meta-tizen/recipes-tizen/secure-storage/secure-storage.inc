DESCRIPTION = "Secure storage"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Security"
LICENSE = "Apache 2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by secure-storage 
PROVIDES += "secure-storage"
RPROVIDES_secure-storage += "secure-storage"

#PROVIDES by ss-server 
PROVIDES += "ss-server"
RPROVIDES_ss-server += "ss-server"

#PROVIDES by libss-client-devel 
PROVIDES += "libss-client-devel"
RPROVIDES_libss-client-devel += "libss-client-devel"
RPROVIDES_libss-client-devel += "libss-client-dev"

#PROVIDES by libss-client 
PROVIDES += "libss-client"
RPROVIDES_libss-client += "libss-client"
# the PROVIDES rules is ignore "libss-client.so  "
PROVIDES += "libss-client.so"
RPROVIDES_libss-client += "libss-client.so"

RDEPENDS = ""
#RDEPENDS of libss-client (libss-client)
RDEPENDS_libss-client += "dukgenerator"

#RDEPENDS of ss-server (ss-server)
RDEPENDS_ss-server += "/usr/bin/systemctl"
RDEPENDS_ss-server += "libss-client"
RDEPENDS_ss-server += "systemd"

#RDEPENDS of libss-client-devel (libss-client-devel)
RDEPENDS_libss-client-devel += "libss-client"


DEPENDS = ""
#DEPENDS of secure-storage 
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "dukgenerator"
DEPENDS += "cmake"
DEPENDS += "openssl"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(libsystemd-daemon)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libss-client.manifest ${S}/packaging/libss-client-devel.manifest ${S}/packaging/ss-server.manifest .
 
 
 
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
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 mkdir -p ${D}/usr/lib/systemd/system/sockets.target.wants
 ln -s ../secure-storage.service ${D}/usr/lib/systemd/system/multi-user.target.wants/secure-storage.service
 ln -s ../secure-storage.socket ${D}/usr/lib/systemd/system/sockets.target.wants/secure-storage.socket
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE.APLv2 ${D}/usr/share/license/ss-server
 cp LICENSE.APLv2 ${D}/usr/share/license/libss-client
 
 
}

PACKAGES = ""
PACKAGES += "libss-client"
PACKAGES += "ss-server"
PACKAGES += "libss-client-devel"

libss-client_files = ""
libss-client_files += "libss-client.manifest"
libss-client_files += "/usr/lib/libss-client.so.*"
libss-client_files += "/usr/share/license/libss-client"

ss-server_files = ""
ss-server_files += "ss-server.manifest"
ss-server_files += "/usr/bin/ss-server"
ss-server_files += "/usr/lib/systemd/system/secure-storage.service"
ss-server_files += "/usr/lib/systemd/system/multi-user.target.wants/secure-storage.service"
ss-server_files += "/usr/lib/systemd/system/secure-storage.socket"
ss-server_files += "/usr/lib/systemd/system/sockets.target.wants/secure-storage.socket"
ss-server_files += "/usr/share/secure-storage/config"
ss-server_files += "/usr/share/license/ss-server"

libss-client-devel_files = ""
libss-client-devel_files += "libss-client-devel.manifest"
libss-client-devel_files += "/usr/include/ss_manager.h"
libss-client-devel_files += "/usr/lib/pkgconfig/secure-storage.pc"
libss-client-devel_files += "/usr/lib/libss-client.so"

FILES_libss-client = "${libss-client_files}"
FILES_ss-server = "${ss-server_files}"
FILES_libss-client-devel = "${libss-client-devel_files}"

PKG_libss-client= "libss-client"
PKG_ss-server= "ss-server"
PKG_libss-client-devel= "libss-client-devel"

require secure-storage-extraconf.inc
