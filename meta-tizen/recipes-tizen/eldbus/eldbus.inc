DESCRIPTION = "Easy access to D-Bus from EFL applications"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by eldbus-devel 
PROVIDES += "eldbus-devel"
RPROVIDES_eldbus-devel += "eldbus-devel"
RPROVIDES_eldbus-devel += "eldbus-dev"

#PROVIDES by eldbus 
PROVIDES += "eldbus"
RPROVIDES_eldbus += "eldbus"

RDEPENDS = ""
#RDEPENDS of eldbus-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "eldbus"

#RDEPENDS of eldbus (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of eldbus 
DEPENDS += "ecore"
DEPENDS += "pkgconfig(eina)"
DEPENDS += "dbus-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 export CFLAGS+=" -fvisibility=hidden -fPIC"
 export LDFLAGS+=" -fvisibility=hidden -Wl,--hash-style=both -Wl,--as-needed"
 
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/usr/share/license
 cp ${WORKDIR}/git/COPYING ${D}/usr/share/license/eldbus
 
 
 
}

PACKAGES = ""
PACKAGES += "eldbus-devel"
PACKAGES += "eldbus"

eldbus-devel_files = ""
eldbus-devel_files += "/usr/lib/*.so"
eldbus-devel_files += "/usr/lib/pkgconfig/*.pc"
eldbus-devel_files += "/usr/include/eldbus*/"

eldbus_files = ""
eldbus_files += "/usr/lib/*.so.*"
eldbus_files += "/usr/bin/eldbus*"
eldbus_files += "/usr/share/license/eldbus"

FILES_${PN}-devel = "${eldbus-devel_files}"
FILES_${PN} = "${eldbus_files}"

PKG_eldbus-devel= "eldbus-devel"
PKG_eldbus= "eldbus"

require eldbus-extraconf.inc
