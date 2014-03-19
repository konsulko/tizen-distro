DESCRIPTION = "Suite of DLNA middleware components"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by dleyna-devel 
PROVIDES += "dleyna-devel"
RPROVIDES_dleyna-devel += "dleyna-devel"
RPROVIDES_dleyna-devel += "dleyna-dev"

#PROVIDES by dleyna 
PROVIDES += "dleyna"
RPROVIDES_dleyna += "dleyna"

RDEPENDS = ""
#RDEPENDS of dleyna-devel (dleyna-devel)
RDEPENDS_dleyna-devel += "dleyna"

#RDEPENDS of dleyna (dleyna)
RDEPENDS_dleyna += "dbus"
RDEPENDS_dleyna += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of dleyna 
DEPENDS += "GSSDP"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "GUPnP-DLNA"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "GUPnP"
DEPENDS += "GUPnP-AV"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n dleyna-0.4.0
 
 
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
         --infodir=/usr/share/info --enable-master-build --disable-static --enable-debug --disable-never-quit --with-log-level=8 --with-log-type=1
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
PACKAGES += "dleyna-devel"
PACKAGES += "dleyna"

dleyna-devel_files = ""
dleyna-devel_files += "/usr/include/dleyna-1.0/libdleyna"
dleyna-devel_files += "/usr/lib/libdleyna-core-1.0.so"
dleyna-devel_files += "/usr/lib/dleyna-server/libdleyna-server-1.0.so"
dleyna-devel_files += "/usr/lib/dleyna-renderer/libdleyna-renderer-1.0.so"
dleyna-devel_files += "/usr/lib/pkgconfig/dleyna-connector-dbus-1.0.pc"
dleyna-devel_files += "/usr/lib/pkgconfig/dleyna-core-1.0.pc"
dleyna-devel_files += "/usr/lib/pkgconfig/dleyna-server-1.0.pc"
dleyna-devel_files += "/usr/lib/pkgconfig/dleyna-renderer-1.0.pc"
dleyna-devel_files += "/usr/lib/pkgconfig/dleyna-server-service-1.0.pc"
dleyna-devel_files += "/usr/lib/pkgconfig/dleyna-renderer-service-1.0.pc"

dleyna_files = ""
dleyna_files += "AUTHORS"
dleyna_files += "/usr/libexec/dleyna-server-service"
dleyna_files += "/usr/libexec/dleyna-renderer-service"
dleyna_files += "/usr/lib/libdleyna-core-1.0.so.*"
dleyna_files += "/usr/lib/dleyna-server/libdleyna-server-1.0.so.*"
dleyna_files += "/usr/lib/dleyna-renderer/libdleyna-renderer-1.0.so.*"
dleyna_files += "/usr/lib/dleyna-1.0/connectors/libdleyna-connector-dbus.so"
dleyna_files += "/etc/dleyna-server-service.conf"
dleyna_files += "/etc/dleyna-renderer-service.conf"
dleyna_files += "/usr/share/dbus-1/services/*"

FILES_${PN}-devel = "${dleyna-devel_files}"
FILES_${PN} = "${dleyna_files}"

PKG_dleyna-devel= "dleyna-devel"
PKG_dleyna= "dleyna"

require dLeyna-extraconf.inc
