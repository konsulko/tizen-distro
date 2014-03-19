DESCRIPTION = "Wrt security daemon"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Access Control"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wrt-security 
PROVIDES += "wrt-security"
RPROVIDES_wrt-security += "wrt-security"

#PROVIDES by security-server-certs 
PROVIDES += "security-server-certs"
RPROVIDES_security-server-certs += "security-server-certs"

#PROVIDES by wrt-security-devel 
PROVIDES += "wrt-security-devel"
RPROVIDES_wrt-security-devel += "wrt-security-devel"
RPROVIDES_wrt-security-devel += "wrt-security-dev"

RDEPENDS = ""
#RDEPENDS of wrt-security (${PN})
RDEPENDS_${PN} += "systemd"

#RDEPENDS of security-server-certs (security-server-certs)
RDEPENDS_security-server-certs += "security-server"

#RDEPENDS of wrt-security-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "wrt-security"


DEPENDS = ""
#DEPENDS of wrt-security 
DEPENDS += "pcre"
DEPENDS += "pkgconfig(dpl-utils-efl)"
DEPENDS += "pkgconfig(capi-appfw-app-manager)"
DEPENDS += "cmake"
DEPENDS += "attr"
DEPENDS += "zip"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(xmlsec1)"
DEPENDS += "openssl"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(dpl-wrt-dao-ro)"
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "smack"
DEPENDS += "systemd"
DEPENDS += "privacy-manager"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(dpl-efl)"
DEPENDS += "pkgconfig(capi-appfw-package-manager)"
DEPENDS += "pkgconfig(dpl-dbus-efl)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/wrt-security.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DDPL_LOG="ON" \
         -DVERSION=0.0.67 \
         -DCMAKE_BUILD_TYPE=
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
 cp LICENSE ${D}/usr/share/license/wrt-security
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/lib/systemd/system/multi-user.target.wants
 mkdir -p ${D}/lib/systemd/system/sockets.target.wants
 ln -sf /lib/systemd/system/wrt-security-daemon.service ${D}/lib/systemd/system/multi-user.target.wants/wrt-security-daemon.service
 ln -sf /lib/systemd/system/wrt-security-daemon.socket  ${D}/lib/systemd/system/sockets.target.wants/wrt-security-daemon.socket
 
 
}

PACKAGES = ""
PACKAGES += "wrt-security"
PACKAGES += "wrt-security-devel"

wrt-security_files = ""
wrt-security_files += "wrt-security.manifest"
wrt-security_files += "/usr/lib/libace*.so"
wrt-security_files += "/usr/lib/libace*.so.*"
wrt-security_files += "/usr/lib/libwrt-ocsp.so"
wrt-security_files += "/usr/lib/libwrt-ocsp.so.*"
wrt-security_files += "/usr/share/wrt-engine/*"
wrt-security_files += "/usr/share/license/wrt-security"
wrt-security_files += "/lib/systemd/system/*"

wrt-security-devel_files = ""
wrt-security-devel_files += "wrt-security.manifest"
wrt-security-devel_files += "/usr/include/wrt-security/*"
wrt-security-devel_files += "/usr/include/ace/*"
wrt-security-devel_files += "/usr/include/ace-client/*"
wrt-security-devel_files += "/usr/include/ace-settings/*"
wrt-security-devel_files += "/usr/include/ace-install/*"
wrt-security-devel_files += "/usr/include/ace-common/*"
wrt-security-devel_files += "/usr/include/ace-popup-validation/*"
wrt-security-devel_files += "/usr/include/wrt-ocsp/*"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-client.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-communication-client.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-core.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-dao-ro.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-dao-rw.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-install.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-popup-validation.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-settings.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security-wrt-ocsp.pc"
wrt-security-devel_files += "/usr/lib/pkgconfig/security.pc"

FILES_${PN} = "${wrt-security_files}"
FILES_${PN}-devel = "${wrt-security-devel_files}"

PKG_wrt-security= "wrt-security"
PKG_wrt-security-devel= "wrt-security-devel"

require wrt-security-extraconf.inc
