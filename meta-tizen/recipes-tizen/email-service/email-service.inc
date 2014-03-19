DESCRIPTION = "E-mail Framework Middleware package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Messaging/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by email-service 
PROVIDES += "email-service"
RPROVIDES_email-service += "email-service"

#PROVIDES by email-service-devel 
PROVIDES += "email-service-devel"
RPROVIDES_email-service-devel += "email-service-devel"
RPROVIDES_email-service-devel += "email-service-dev"

#PROVIDES by email-service-tests 
PROVIDES += "email-service-tests"
RPROVIDES_email-service-tests += "email-service-tests"

RDEPENDS = ""
#RDEPENDS of email-service (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/sbin/ldconfig"
RDEPENDS_${PN} += "/usr/bin/sqlite3"
RDEPENDS_${PN} += "connman"
RDEPENDS_${PN} += "webkit2-efl"

#RDEPENDS of email-service-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "email-service"

#RDEPENDS of email-service-tests (${PN}-tests)
RDEPENDS_${PN}-tests += "email-service"


DEPENDS = ""
#DEPENDS of email-service 
DEPENDS += "pkgconfig(vconf-internal-keys)"
DEPENDS += "pkgconfig(msg-service)"
DEPENDS += "pkgconfig(openssl)"
DEPENDS += "pkgconfig(libwbxml2)"
DEPENDS += "contacts-service"
DEPENDS += "dbus-glib"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "cmake"
DEPENDS += "drm-client"
DEPENDS += "pkgconfig(accounts-svc)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(gthread-2.0)"
DEPENDS += "pkgconfig(capi-appfw-application)"
DEPENDS += "pkgconfig(libsystemd-daemon)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "badge"
DEPENDS += "pkgconfig(mm-player)"
DEPENDS += "common"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "pkgconfig(uw-imap-toolkit)"
DEPENDS += "pkgconfig(secure-storage)"
DEPENDS += "pkgconfig(mm-session)"
DEPENDS += "pkgconfig(db-util)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(alarm-service)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(feedback)"
DEPENDS += "pkgconfig(cert-svc)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(notification)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/email-service.manifest .
 
 
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
 
 
 export CFLAGS="${CFLAGS} -fPIC -Wall -g -fvisibility=hidden"
 export CXXFLAGS="${CXXFLAGS} -fPIC -Wall -g -fvisibility=hidden"
 
 
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
 
 mkdir -p ${D}/usr/share/license
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/usr/lib/systemd/user/tizen-middleware.target.wants
 install -m 0644 ${S}/packaging/email.service ${D}/usr/lib/systemd/user/
 ln -sf ../email.service ${D}/usr/lib/systemd/user/tizen-middleware.target.wants/
 
 
 
}

PACKAGES = ""
PACKAGES += "email-service"
PACKAGES += "email-service-devel"
PACKAGES += "email-service-tests"

email-service_files = ""
email-service_files += "email-service.manifest"
email-service_files += "/usr/bin/email-service"
email-service_files += "/opt/usr/data/email/res/*"
email-service_files += "/usr/lib/lib*.so.*"
email-service_files += "/usr/lib/systemd/user/email.service"
email-service_files += "/usr/lib/systemd/user/tizen-middleware.target.wants/email.service"
email-service_files += "/usr/share/dbus-1/services/email-service.service"
email-service_files += "/usr/share/license/email-service/LICENSE"
email-service_files += "/opt/etc/smack/accesses.d/email-service.rule"

email-service-devel_files = ""
email-service-devel_files += "email-service.manifest"
email-service-devel_files += "/usr/include/email-service/*.h"
email-service-devel_files += "/usr/lib/lib*.so"
email-service-devel_files += "/usr/lib/pkgconfig/*.pc"

email-service-tests_files = ""
email-service-tests_files += "email-service.manifest"
email-service-tests_files += "/usr/bin/email-test-app"

FILES_${PN} = "${email-service_files}"
FILES_${PN}-devel = "${email-service-devel_files}"
FILES_${PN}-tests = "${email-service-tests_files}"

PKG_email-service= "email-service"
PKG_email-service-devel= "email-service-devel"
PKG_email-service-tests= "email-service-tests"

require email-service-extraconf.inc
