DESCRIPTION = "Syspopup package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by syspopup-devel 
PROVIDES += "syspopup-devel"
RPROVIDES_syspopup-devel += "syspopup-devel"
RPROVIDES_syspopup-devel += "syspopup-dev"

#PROVIDES by syspopup 
PROVIDES += "syspopup"
RPROVIDES_syspopup += "syspopup"

#PROVIDES by syspopup-caller-devel 
PROVIDES += "syspopup-caller-devel"
RPROVIDES_syspopup-caller-devel += "syspopup-caller-devel"
RPROVIDES_syspopup-caller-devel += "syspopup-caller-dev"

#PROVIDES by syspopup-caller 
PROVIDES += "syspopup-caller"
RPROVIDES_syspopup-caller += "syspopup-caller"

RDEPENDS = ""
#RDEPENDS of syspopup-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "syspopup"

#RDEPENDS of syspopup-caller-devel (${PN}-caller-devel)
RDEPENDS_${PN}-caller-devel += "syspopup"

#RDEPENDS of syspopup-caller (${PN}-caller)
RDEPENDS_${PN}-caller += "syspopup"
RDEPENDS_${PN}-caller += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of syspopup 
DEPENDS += "sqlite"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(aul)"
DEPENDS += "dlog"
DEPENDS += "app-core"
DEPENDS += "bundle"
DEPENDS += "pkgconfig(libtzplatform-config)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/syspopup.manifest ${S}/packaging/syspopup-devel.manifest ${S}/packaging/syspopup-caller.manifest ${S}/packaging/syspopup-caller-devel.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . \
 -Dwith_wayland=TRUE \
 -DEXTRA_CFLAGS=-fPIC
 
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
 
 mkdir -p ${D}%{TZ_SYS_DB}
 sqlite3 ${D}%{TZ_SYS_DB}/.syspopup.db < ${D}/usr/share/syspopup/syspopup_db.sql
 rm -rf ${D}/usr/share/syspopup/syspopup_db.sql
 
 touch ${D}/usr/share/popup_noti_term
 
 
}

PACKAGES = ""
PACKAGES += "syspopup-devel"
PACKAGES += "syspopup"
PACKAGES += "syspopup-caller-devel"
PACKAGES += "syspopup-caller"

syspopup-devel_files = ""
syspopup-devel_files += "syspopup-devel.manifest"
syspopup-devel_files += "/usr/include/SLP_SYSPOPUP_PG.h"
syspopup-devel_files += "/usr/include/syspopup.h"
syspopup-devel_files += "/usr/lib/libsyspopup.so"
syspopup-devel_files += "/usr/lib/pkgconfig/syspopup.pc"

syspopup_files = ""
syspopup_files += "syspopup.manifest"
syspopup_files += "/usr/share/icons/default/small/org.tizen.syspopup-app.png"
syspopup_files += "/usr/bin/sp_test"
syspopup_files += "/usr/bin/syspopup-app"
syspopup_files += "/usr/lib/libsyspopup.so.0.1.0"
syspopup_files += "/usr/share/popup_noti_term"

syspopup-caller-devel_files = ""
syspopup-caller-devel_files += "syspopup-caller-devel.manifest"
syspopup-caller-devel_files += "/usr/lib/libsyspopup_caller.so"
syspopup-caller-devel_files += "/usr/include/syspopup_caller.h"
syspopup-caller-devel_files += "/usr/lib/pkgconfig/syspopup-caller.pc"

syspopup-caller_files = ""
syspopup-caller_files += "syspopup-caller.manifest"
syspopup-caller_files += "/usr/lib/libsyspopup_caller.so.0.1.0"

FILES_${PN}-devel = "${syspopup-devel_files}"
FILES_${PN} = "${syspopup_files}"
FILES_${PN}-caller-devel = "${syspopup-caller-devel_files}"
FILES_${PN}-caller = "${syspopup-caller_files}"

PKG_syspopup-devel= "syspopup-devel"
PKG_syspopup= "syspopup"
PKG_syspopup-caller-devel= "syspopup-caller-devel"
PKG_syspopup-caller= "syspopup-caller"

require syspopup-extraconf.inc
