DESCRIPTION = "Connection Manager"
HOMEPAGE = "http://connman.net"
SECTION = "Network & Connectivity/Connection Management"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by connman 
PROVIDES += "connman"
RPROVIDES_connman += "connman"

#PROVIDES by connman-devel 
PROVIDES += "connman-devel"
RPROVIDES_connman-devel += "connman-devel"
RPROVIDES_connman-devel += "connman-dev"

#PROVIDES by connman-test 
PROVIDES += "connman-test"
RPROVIDES_connman-test += "connman-test"

#PROVIDES by connman-docs  
PROVIDES += "connman-docs "
RPROVIDES_connman-docs  += "connman-docs "

RDEPENDS = ""
#RDEPENDS of connman (${PN})
RDEPENDS_${PN} += "iptables"
RDEPENDS_${PN} += "systemd"

#RDEPENDS of connman-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "connman"

#RDEPENDS of connman-test (${PN}-test)
RDEPENDS_${PN}-test += "pygobject"
RDEPENDS_${PN}-test += "connman"
RDEPENDS_${PN}-test += "python-xml"
RDEPENDS_${PN}-test += "dbus-python"


DEPENDS = ""
#DEPENDS of connman 
DEPENDS += "systemd"
DEPENDS += "readline-devel"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(gnutls)"
DEPENDS += "pkgconfig(xtables)"
DEPENDS += "pkgconfig(libiptc)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/connman.manifest .
 
 
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
 
 CFLAGS+=" -DTIZEN_EXT"
 
 ./bootstrap
 
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
         --infodir=/usr/share/info \
             --enable-threads \
             --enable-client \
             --enable-pacrunner \
             --enable-wifi=builtin \
             --enable-test \
             --enable-loopback \
             --enable-ethernet \
             --disable-linklocaladdr \
             --disable-rfkill \
             --with-systemdunitdir=/lib/systemd/system
 
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
 
 
 mkdir -p ${D}/etc/connman
 cp src/main.conf ${D}/etc/connman/main.conf
 
 
 mkdir -p ${D}//lib/systemd/system/network.target.wants 
 ln -s ../connman.service  ${D}//lib/systemd/system/network.target.wants/connman.service  
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../connman.service  ${D}//lib/systemd/system/multi-user.target.wants/connman.service  
 
 
}

PACKAGES = ""
PACKAGES += "connman"
PACKAGES += "connman-docs"
PACKAGES += "connman-test"
PACKAGES += "connman-devel"

connman_files = ""
connman_files += "connman.manifest"
connman_files += "connman.manifest"
connman_files += "/usr/sbin/*"
connman_files += "/usr/lib/connman/plugins/*.so"
connman_files += "/usr/share/man/*"
connman_files += "/etc/connman/main.conf"
connman_files += "/etc/dbus-1/system.d/*"
connman_files += "/lib/systemd/system/connman.service"
connman_files += "/lib/systemd/system/network.target.wants/connman.service"
connman_files += "/lib/systemd/system/multi-user.target.wants/connman.service"

connman-docs_files = ""
connman-docs_files += "/usr/share/info"
connman-docs_files += "/usr/share/man"

connman-test_files = ""
connman-test_files += "connman.manifest"
connman-test_files += "/usr/lib/connman/test/*"

connman-devel_files = ""
connman-devel_files += "connman.manifest"
connman-devel_files += "/usr/include/connman/*.h"
connman-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${connman_files}"
FILES_${PN}-docs = "${connman-docs_files}"
FILES_${PN}-test = "${connman-test_files}"
FILES_${PN}-devel = "${connman-devel_files}"

PKG_connman= "connman"
PKG_connman-docs= "connman-docs"
PKG_connman-test= "connman-test"
PKG_connman-devel= "connman-devel"

require connman-extraconf.inc
