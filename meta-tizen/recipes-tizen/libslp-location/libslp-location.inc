DESCRIPTION = "Location Based Service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Location/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libslp-location-devel 
PROVIDES += "libslp-location-devel"
RPROVIDES_libslp-location-devel += "libslp-location-devel"
RPROVIDES_libslp-location-devel += "libslp-location-dev"

#PROVIDES by libslp-location 
PROVIDES += "libslp-location"
RPROVIDES_libslp-location += "libslp-location"

RDEPENDS = ""
#RDEPENDS of libslp-location-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libslp-location"

#RDEPENDS of libslp-location (${PN})
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of libslp-location 
DEPENDS += "pkgconfig(json-glib-1.0)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(gmodule-2.0)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libslp-location-0.5.3
 cp ${S}/packaging/libslp-location.manifest .
 
 
 
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
 
 
 ./autogen.sh
 
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
         --infodir=/usr/share/info  --enable-dlog --enable-debug
 
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
PACKAGES += "libslp-location-devel"
PACKAGES += "libslp-location"

libslp-location-devel_files = ""
libslp-location-devel_files += "libslp-location.manifest"
libslp-location-devel_files += "/usr/include/location/*.h"
libslp-location-devel_files += "/usr/lib/pkgconfig/*.pc"

libslp-location_files = ""
libslp-location_files += "libslp-location.manifest"
libslp-location_files += "/usr/lib/lib*.so*"

FILES_${PN}-devel = "${libslp-location-devel_files}"
FILES_${PN} = "${libslp-location_files}"

PKG_libslp-location-devel= "libslp-location-devel"
PKG_libslp-location= "libslp-location"

require libslp-location-extraconf.inc
