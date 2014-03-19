DESCRIPTION = "Contacts Service"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Social & Contents/Contacts"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by contacts-service2 
PROVIDES += "contacts-service2"
RPROVIDES_contacts-service2 += "contacts-service2"

#PROVIDES by contacts-service 
PROVIDES += "contacts-service"
RPROVIDES_contacts-service += "contacts-service"

#PROVIDES by contacts-service2-devel 
PROVIDES += "contacts-service2-devel"
RPROVIDES_contacts-service2-devel += "contacts-service2-devel"
RPROVIDES_contacts-service2-devel += "contacts-service2-dev"

RDEPENDS = ""
#RDEPENDS of contacts-service2 (${PN}2)
RDEPENDS_${PN}2 += "libprivilege-control-conf"

#RDEPENDS of contacts-service (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "/bin/chown"
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/bin/chmod"
RDEPENDS_${PN} += "/usr/bin/sqlite3"

#RDEPENDS of contacts-service2-devel (${PN}2-devel)
RDEPENDS_${PN}2-devel += "contacts-service2"


DEPENDS = ""
#DEPENDS of contacts-service 
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "pkgconfig(pims-ipc)"
DEPENDS += "vconf-keys-devel"
DEPENDS += "pkgconfig(capi-media-image-util)"
DEPENDS += "pkgconfig(accounts-svc)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "badge"
DEPENDS += "pkgconfig(tapi)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(libsmack)"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "common"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/contacts-service2.manifest .
 
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
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
 
 mkdir -p ${D}/usr/lib/systemd/user/tizen-middleware.target.wants
 install -m 0644 ${S}/packaging/contacts-service.service ${D}/usr/lib/systemd/user/contacts-service.service
 ln -s ../contacts-service.service ${D}/usr/lib/systemd/user/tizen-middleware.target.wants/contacts-service.service
 
 mkdir -p ${D}/usr/lib/systemd/user/sockets.target.wants
 install -m 0644 ${S}/packaging/contacts-service.socket ${D}/usr/lib/systemd/user/contacts-service.socket
 ln -s ../contacts-service.socket ${D}/usr/lib/systemd/user/sockets.target.wants/contacts-service.socket
 
 
 
}

PACKAGES = ""
PACKAGES += "contacts-service2"
PACKAGES += "contacts-service2-devel"

contacts-service2_files = ""
contacts-service2_files += "contacts-service2.manifest"
contacts-service2_files += "/usr/lib/libcontacts-service2.so.*"
contacts-service2_files += "/usr/bin/contacts-service-ipcd*"
contacts-service2_files += "/opt/usr/data/contacts-svc/.CONTACTS_SVC_*"
contacts-service2_files += "/opt/usr/data/contacts-svc/img/*"
contacts-service2_files += "/usr/lib/systemd/user/contacts-service.service"
contacts-service2_files += "/usr/lib/systemd/user/tizen-middleware.target.wants/contacts-service.service"
contacts-service2_files += "/usr/lib/systemd/user/sockets.target.wants/contacts-service.socket"
contacts-service2_files += "/usr/lib/systemd/user/contacts-service.socket"
contacts-service2_files += "/opt/usr/dbspace/.contacts-svc.db*"
contacts-service2_files += "/opt/etc/smack/accesses.d/contacts-service2.rule"

contacts-service2-devel_files = ""
contacts-service2-devel_files += "/usr/lib/libcontacts-service2.so"
contacts-service2-devel_files += "/usr/lib/pkgconfig/contacts-service2.pc"
contacts-service2-devel_files += "/usr/include/contacts-svc/contacts.h"
contacts-service2-devel_files += "/usr/include/contacts-svc/contacts_*.h"

FILES_${PN}2 = "${contacts-service2_files}"
FILES_${PN}2-devel = "${contacts-service2-devel_files}"

PKG_contacts-service2= "contacts-service2"
PKG_contacts-service2-devel= "contacts-service2-devel"

require contacts-service-extraconf.inc
