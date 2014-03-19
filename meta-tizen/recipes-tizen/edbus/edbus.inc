DESCRIPTION = "EFL Wrapper for DBus"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 2-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by edbus-devel 
PROVIDES += "edbus-devel"
RPROVIDES_edbus-devel += "edbus-devel"
RPROVIDES_edbus-devel += "edbus-dev"

#PROVIDES by edbus 
PROVIDES += "edbus"
RPROVIDES_edbus += "edbus"

RDEPENDS = ""
#RDEPENDS of edbus-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "edbus"


DEPENDS = ""
#DEPENDS of edbus 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "ecore"
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(eina)"
DEPENDS += "pkgconfig(evas)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n e_dbus-1.7.8
 cp ${S}/packaging/edbus.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static
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
PACKAGES += "edbus-devel"
PACKAGES += "edbus"

edbus-devel_files = ""
edbus-devel_files += "edbus.manifest"
edbus-devel_files += "/usr/include/e_dbus-1/*.h"
edbus-devel_files += "/usr/lib/*.so"
edbus-devel_files += "/usr/lib/pkgconfig/*.pc"
edbus-devel_files += "/usr/include/e_dbus-1/connman0_7x/E_Connman.h"
edbus-devel_files += "/usr/bin/e-notify-send"

edbus_files = ""
edbus_files += "edbus.manifest"
edbus_files += "/usr/bin/e_dbus_*"
edbus_files += "/usr/bin/e-notify-send"
edbus_files += "/usr/lib/libe*.so.*"
edbus_files += "/usr/share/e_dbus/logo.png"

FILES_${PN}-devel = "${edbus-devel_files}"
FILES_${PN} = "${edbus_files}"

PKG_edbus-devel= "edbus-devel"
PKG_edbus= "edbus"

require edbus-extraconf.inc
