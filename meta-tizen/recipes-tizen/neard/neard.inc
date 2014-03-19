DESCRIPTION = "Near Field Communication Manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Connectivity/NFC"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by neard 
PROVIDES += "neard"
RPROVIDES_neard += "neard"

#PROVIDES by neard-devel 
PROVIDES += "neard-devel"
RPROVIDES_neard-devel += "neard-devel"
RPROVIDES_neard-devel += "neard-dev"

#PROVIDES by neard-test 
PROVIDES += "neard-test"
RPROVIDES_neard-test += "neard-test"

RDEPENDS = ""
#RDEPENDS of neard (${PN})
RDEPENDS_${PN} += "libnl3"
RDEPENDS_${PN} += "systemd"

#RDEPENDS of neard-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "neard"

#RDEPENDS of neard-test (${PN}-test)
RDEPENDS_${PN}-test += "pygobject"
RDEPENDS_${PN}-test += "neard"
RDEPENDS_${PN}-test += "dbus-python"


DEPENDS = ""
#DEPENDS of neard 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libnl-3.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/neard.manifest .
 
 
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
 		--enable-debug \
 		--prefix=/usr \
 		--sysconfdir=/etc \
 		--enable-nfctype1=builtin \
 		--enable-nfctype2=builtin \
 		--enable-nfctype3=builtin \
 		--enable-nfctype4=builtin \
 		--enable-p2p=builtin \
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
 
 # Systemd service file
 install -d ${D}/usr/lib/systemd/system/
 install -m 644 ${S}/packaging/neard.service ${D}/usr/lib/systemd/system/neard.service
 install -d ${D}/usr/lib/systemd/system/network.target.wants/
 install -d ${D}/usr/lib/systemd/system/multi-user.target.wants/
 ln -s ../neard.service ${D}/usr/lib/systemd/system/network.target.wants/neard.service
 ln -s ../neard.service ${D}/usr/lib/systemd/system/multi-user.target.wants/neard.service
 
 
 mkdir -p ${D}/etc/neard
 cp src/main.conf ${D}/etc/neard/main.conf
 
 
}

PACKAGES = ""
PACKAGES += "neard"
PACKAGES += "neard-devel"
PACKAGES += "neard-test"

neard_files = ""
neard_files += "neard.manifest"
neard_files += "/usr/share/man/man*/*"
neard_files += "/usr/libexec/nfc/neard"
neard_files += "/etc/neard/main.conf"
neard_files += "/etc/dbus-1/system.d/org.neard.conf"
neard_files += "/usr/lib/systemd/system/neard.service"
neard_files += "/usr/lib/systemd/system/network.target.wants/neard.service"
neard_files += "/usr/lib/systemd/system/multi-user.target.wants/neard.service"

neard-devel_files = ""
neard-devel_files += "neard.manifest"
neard-devel_files += "/usr/include/near/*.h"
neard-devel_files += "/usr/lib/pkgconfig/*.pc"

neard-test_files = ""
neard-test_files += "neard.manifest"
neard-test_files += "/usr/lib/neard/test/*"

FILES_${PN} = "${neard_files}"
FILES_${PN}-devel = "${neard-devel_files}"
FILES_${PN}-test = "${neard-test_files}"

PKG_neard= "neard"
PKG_neard-devel= "neard-devel"
PKG_neard-test= "neard-test"

require neard-extraconf.inc
