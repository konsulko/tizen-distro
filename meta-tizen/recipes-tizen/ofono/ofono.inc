DESCRIPTION = "Open Source Telephony"
HOMEPAGE = "http://ofono.org"
SECTION = "Telephony/Cellular"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ofono-docs  
PROVIDES += "ofono-docs "
RPROVIDES_ofono-docs  += "ofono-docs "

#PROVIDES by ofono-test 
PROVIDES += "ofono-test"
RPROVIDES_ofono-test += "ofono-test"

#PROVIDES by ofono-devel 
PROVIDES += "ofono-devel"
RPROVIDES_ofono-devel += "ofono-devel"
RPROVIDES_ofono-devel += "ofono-dev"

#PROVIDES by ofono 
PROVIDES += "ofono"
RPROVIDES_ofono += "ofono"

RDEPENDS = ""
#RDEPENDS of ofono-test (${PN}-test)
RDEPENDS_${PN}-test += "python-xml"
RDEPENDS_${PN}-test += "python-gobject"
RDEPENDS_${PN}-test += "dbus-python"
RDEPENDS_${PN}-test += "ofono"

#RDEPENDS of ofono-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ofono"

#RDEPENDS of ofono (${PN})
RDEPENDS_${PN} += "dbus"
RDEPENDS_${PN} += "systemd"


DEPENDS = ""
#DEPENDS of ofono 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(mobile-broadband-provider-info)"
DEPENDS += "automake-native"
DEPENDS += "bluez"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(libudev)"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 cp ${S}/packaging/ofono.manifest .
 
 
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
 
 autoreconf --force --install
 
 
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
         --infodir=/usr/share/info --disable-static \
     --enable-test \
     --disable-bluez4 \
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
 
 mkdir -p ${D}/usr/lib/systemd/system/network.target.wants
 ln -s ../ofono.service ${D}/usr/lib/systemd/system/network.target.wants/ofono.service
 
 
 mkdir -p ${D}//lib/systemd/system/multi-user.target.wants 
 ln -s ../ofono.service  ${D}//lib/systemd/system/multi-user.target.wants/ofono.service  
 
 
 
}

PACKAGES = ""
PACKAGES += "ofono-test"
PACKAGES += "ofono-docs"
PACKAGES += "ofono-devel"
PACKAGES += "ofono"

ofono-test_files = ""
ofono-test_files += "ofono.manifest"
ofono-test_files += "/usr/lib/ofono/test/*"

ofono-docs_files = ""
ofono-docs_files += "/usr/share/info"
ofono-docs_files += "/usr/share/man"

ofono-devel_files = ""
ofono-devel_files += "ofono.manifest"
ofono-devel_files += "/usr/include/ofono/*.h"
ofono-devel_files += "/usr/lib/pkgconfig/ofono.pc"

ofono_files = ""
ofono_files += "ofono.manifest"
ofono_files += "ofono.manifest"
ofono_files += "/etc/dbus-1/system.d/*.conf"
ofono_files += "/usr/sbin/*"
ofono_files += "/lib/systemd/system/network.target.wants/ofono.service"
ofono_files += "/lib/systemd/system/ofono.service"
ofono_files += "/lib/systemd/system/multi-user.target.wants/ofono.service"
ofono_files += "/etc/ofono/phonesim.conf"

FILES_${PN}-test = "${ofono-test_files}"
FILES_${PN}-docs = "${ofono-docs_files}"
FILES_${PN}-devel = "${ofono-devel_files}"
FILES_${PN} = "${ofono_files}"

PKG_ofono-test= "ofono-test"
PKG_ofono-docs= "ofono-docs"
PKG_ofono-devel= "ofono-devel"
PKG_ofono= "ofono"

require ofono-extraconf.inc
