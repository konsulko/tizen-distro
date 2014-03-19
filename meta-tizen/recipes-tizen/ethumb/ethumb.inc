DESCRIPTION = "Thumbnail Generator Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Graphics/EFL"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by ethumb 
PROVIDES += "ethumb"
RPROVIDES_ethumb += "ethumb"

#PROVIDES by ethumb-devel 
PROVIDES += "ethumb-devel"
RPROVIDES_ethumb-devel += "ethumb-devel"
RPROVIDES_ethumb-devel += "ethumb-dev"

RDEPENDS = ""
#RDEPENDS of ethumb-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "ethumb"


DEPENDS = ""
#DEPENDS of ethumb 
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(edje)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(eet)"
DEPENDS += "pkgconfig(edbus)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/ethumb.manifest .
 
 
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
PACKAGES += "ethumb"
PACKAGES += "ethumb-devel"

ethumb_files = ""
ethumb_files += "ethumb.manifest"
ethumb_files += "/usr/lib/libethumb*.so.*"
ethumb_files += "/usr/share/dbus-1/services/org.enlightenment.Ethumb.service"
ethumb_files += "/usr/share/ethumb/data/frames/default.edj"
ethumb_files += "/usr/bin/ethumb"
ethumb_files += "/usr/bin/ethumbd"
ethumb_files += "/usr/bin/ethumbd_client"
ethumb_files += "/usr/libexec/ethumbd_slave"

ethumb-devel_files = ""
ethumb-devel_files += "ethumb.manifest"
ethumb-devel_files += "/usr/include/ethumb-1/*.h"
ethumb-devel_files += "/usr/lib/libethumb*.so"
ethumb-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${ethumb_files}"
FILES_${PN}-devel = "${ethumb-devel_files}"

PKG_ethumb= "ethumb"
PKG_ethumb-devel= "ethumb-devel"

require ethumb-extraconf.inc
