DESCRIPTION = "Proxy configuration daemon"
HOMEPAGE = "http://connman.net/"
SECTION = "Connectivity/Connection Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pacrunner-test 
PROVIDES += "pacrunner-test"
RPROVIDES_pacrunner-test += "pacrunner-test"

#PROVIDES by pacrunner-proxy-tools 
PROVIDES += "pacrunner-proxy-tools"
RPROVIDES_pacrunner-proxy-tools += "pacrunner-proxy-tools"

#PROVIDES by pacrunner-libproxy-devel 
PROVIDES += "pacrunner-libproxy-devel"
RPROVIDES_pacrunner-libproxy-devel += "pacrunner-libproxy-devel"
RPROVIDES_pacrunner-libproxy-devel += "pacrunner-libproxy-dev"
# the PROVIDES rules is ignore "libproxy-devel <= 0.4.11-2"
PROVIDES += "libproxy-devel"
RPROVIDES_pacrunner-libproxy-devel += "libproxy-devel"
RPROVIDES_pacrunner-libproxy-devel += "libproxy-dev"

#PROVIDES by pacrunner-libproxy 
PROVIDES += "pacrunner-libproxy"
RPROVIDES_pacrunner-libproxy += "pacrunner-libproxy"
# the PROVIDES rules is ignore "libproxy <= 0.4.11-2"
PROVIDES += "libproxy"
RPROVIDES_pacrunner-libproxy += "libproxy"
# the PROVIDES rules is ignore "libproxy-pacrunner-webkit <= 0.4.11-2"
PROVIDES += "libproxy-pacrunner-webkit"
RPROVIDES_pacrunner-libproxy += "libproxy-pacrunner-webkit"

#PROVIDES by pacrunner 
PROVIDES += "pacrunner"
RPROVIDES_pacrunner += "pacrunner"

RDEPENDS = ""
#RDEPENDS of pacrunner-test (${PN}-test)
RDEPENDS_${PN}-test += "pacrunner"

#RDEPENDS of pacrunner-proxy-tools (${PN}-proxy-tools)
RDEPENDS_${PN}-proxy-tools += "pacrunner-libproxy"

#RDEPENDS of pacrunner-libproxy (${PN}-libproxy)
RDEPENDS_${PN}-libproxy += "pacrunner"

#RDEPENDS of pacrunner-libproxy-devel (${PN}-libproxy-devel)
RDEPENDS_${PN}-libproxy-devel += "pacrunner-libproxy"


DEPENDS = ""
#DEPENDS of pacrunner 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "v8-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pacrunner.manifest .
 
 
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
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --enable-v8 \
             --enable-libproxy \
             --enable-curl \
             --enable-test
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
PACKAGES += "pacrunner-test"
PACKAGES += "pacrunner-proxy-tools"
PACKAGES += "pacrunner"
PACKAGES += "pacrunner-libproxy"
PACKAGES += "pacrunner-libproxy-devel"

pacrunner-test_files = ""
pacrunner-test_files += "pacrunner.manifest"
pacrunner-test_files += "/usr/lib/pacrunner/test/create-proxy-config"
pacrunner-test_files += "/usr/lib/pacrunner/test/find-proxy-for-url"
pacrunner-test_files += "/usr/bin/manual-proxy-test"

pacrunner-proxy-tools_files = ""
pacrunner-proxy-tools_files += "pacrunner.manifest"
pacrunner-proxy-tools_files += "/usr/bin/proxy"

pacrunner_files = ""
pacrunner_files += "pacrunner.manifest"
pacrunner_files += "/etc/dbus-1/system.d/pacrunner.conf"
pacrunner_files += "/usr/sbin/pacrunner"
pacrunner_files += "/usr/share/dbus-1/system-services/org.pacrunner.service"

pacrunner-libproxy_files = ""
pacrunner-libproxy_files += "pacrunner.manifest"
pacrunner-libproxy_files += "/usr/lib/libproxy.so.*"

pacrunner-libproxy-devel_files = ""
pacrunner-libproxy-devel_files += "pacrunner.manifest"
pacrunner-libproxy-devel_files += "/usr/include/proxy.h"
pacrunner-libproxy-devel_files += "/usr/lib/libproxy.so"
pacrunner-libproxy-devel_files += "/usr/lib/pkgconfig/libproxy-1.0.pc"

FILES_${PN}-test = "${pacrunner-test_files}"
FILES_${PN}-proxy-tools = "${pacrunner-proxy-tools_files}"
FILES_${PN} = "${pacrunner_files}"
FILES_${PN}-libproxy = "${pacrunner-libproxy_files}"
FILES_${PN}-libproxy-devel = "${pacrunner-libproxy-devel_files}"

PKG_pacrunner-test= "pacrunner-test"
PKG_pacrunner-proxy-tools= "pacrunner-proxy-tools"
PKG_pacrunner= "pacrunner"
PKG_pacrunner-libproxy= "pacrunner-libproxy"
PKG_pacrunner-libproxy-devel= "pacrunner-libproxy-devel"

require pacrunner-extraconf.inc
