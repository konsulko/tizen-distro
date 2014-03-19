DESCRIPTION = "File manager service server."
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmedia-utils-devel 
PROVIDES += "libmedia-utils-devel"
RPROVIDES_libmedia-utils-devel += "libmedia-utils-devel"
RPROVIDES_libmedia-utils-devel += "libmedia-utils-dev"

#PROVIDES by media-server 
PROVIDES += "media-server"
RPROVIDES_media-server += "media-server"

#PROVIDES by libmedia-utils 
PROVIDES += "libmedia-utils"
RPROVIDES_libmedia-utils += "libmedia-utils"

RDEPENDS = ""
#RDEPENDS of libmedia-utils-devel (libmedia-utils-devel)
RDEPENDS_libmedia-utils-devel += "libmedia-utils"

#RDEPENDS of media-server (${PN})
RDEPENDS_${PN} += "/usr/bin/vconftool"


DEPENDS = ""
#DEPENDS of media-server 
DEPENDS += "drm-client"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "libslp-db-util"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "heynoti"
DEPENDS += "libslp-pm"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(notification)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/media-server.manifest ${S}/packaging/libmedia-utils.manifest ${S}/packaging/libmedia-utils-devel.manifest .
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
         --infodir=/usr/share/info --prefix=/usr --disable-static
 
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
 install -m 644 ${S}/packaging/media-server.service ${D}/usr/lib/systemd/system/media-server.service
 ln -s ../media-server.service ${D}/usr/lib/systemd/system/multi-user.target.wants/media-server.service
 
 
}

PACKAGES = ""
PACKAGES += "libmedia-utils-devel"
PACKAGES += "media-server"
PACKAGES += "libmedia-utils"

libmedia-utils-devel_files = ""
libmedia-utils-devel_files += "libmedia-utils-devel.manifest"
libmedia-utils-devel_files += "/usr/lib/libmedia-utils.so"
libmedia-utils-devel_files += "/usr/lib/pkgconfig/libmedia-utils.pc"
libmedia-utils-devel_files += "/usr/include/media-utils/*.h"

media-server_files = ""
media-server_files += "media-server.manifest"
media-server_files += "/usr/bin/media-server"
media-server_files += "/usr/bin/media-scanner"
media-server_files += "/usr/bin/mediadb-update"
media-server_files += "/usr/lib/systemd/system/media-server.service"
media-server_files += "/usr/lib/systemd/system/multi-user.target.wants/media-server.service"

libmedia-utils_files = ""
libmedia-utils_files += "libmedia-utils.manifest"
libmedia-utils_files += "/usr/lib/libmedia-utils.so.0"
libmedia-utils_files += "/usr/lib/libmedia-utils.so.0.0.0"

FILES_libmedia-utils-devel = "${libmedia-utils-devel_files}"
FILES_${PN} = "${media-server_files}"
FILES_libmedia-utils = "${libmedia-utils_files}"

PKG_libmedia-utils-devel= "libmedia-utils-devel"
PKG_media-server= "media-server"
PKG_libmedia-utils= "libmedia-utils"

require media-server-extraconf.inc
