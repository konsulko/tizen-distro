DESCRIPTION = "Tizen Platform Configuration"
HOMEPAGE = "http://www.tizen.org"
SECTION = "System/Configuration"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tizen-platform-config 
PROVIDES += "tizen-platform-config"
RPROVIDES_tizen-platform-config += "tizen-platform-config"

#PROVIDES by libtzplatform-config-devel 
PROVIDES += "libtzplatform-config-devel"
RPROVIDES_libtzplatform-config-devel += "libtzplatform-config-devel"
RPROVIDES_libtzplatform-config-devel += "libtzplatform-config-dev"

#PROVIDES by tizen-platform-config-tools 
PROVIDES += "tizen-platform-config-tools"
RPROVIDES_tizen-platform-config-tools += "tizen-platform-config-tools"

#PROVIDES by libtzplatform-config 
PROVIDES += "libtzplatform-config"
RPROVIDES_libtzplatform-config += "libtzplatform-config"

RDEPENDS = ""
#RDEPENDS of tizen-platform-config-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libtzplatform-config"

#RDEPENDS of libtzplatform-config-devel (libtzplatform-config-devel)
RDEPENDS_libtzplatform-config-devel += "libtzplatform-config"

#RDEPENDS of libtzplatform-config (libtzplatform-config)
RDEPENDS_libtzplatform-config += "tizen-platform-config"


DEPENDS = ""
#DEPENDS of tizen-platform-config 
DEPENDS += "tizen-platform-wrapper"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tizen-platform-config.manifest .
 
 
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
         --infodir=/usr/share/info \
 	--disable-static
 
 make -j16
 
 exit 0
 make check
 
 
 
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
PACKAGES += "libtzplatform-config-devel"
PACKAGES += "tizen-platform-config-tools"
PACKAGES += "tizen-platform-config"
PACKAGES += "libtzplatform-config"

libtzplatform-config-devel_files = ""
libtzplatform-config-devel_files += "tizen-platform-config.manifest"
libtzplatform-config-devel_files += "LGPL-2.0 LGPL_2.0"
libtzplatform-config-devel_files += "/usr/lib/*.so"
libtzplatform-config-devel_files += "/usr/lib/pkgconfig/*.pc"
libtzplatform-config-devel_files += "/usr/include/*.h"
libtzplatform-config-devel_files += "/etc/rpm/macros.tizen-platform"

tizen-platform-config-tools_files = ""
tizen-platform-config-tools_files += "tizen-platform-config.manifest"
tizen-platform-config-tools_files += "/usr/bin/*"

tizen-platform-config_files = ""
tizen-platform-config_files += "tizen-platform-config.manifest"
tizen-platform-config_files += "LGPL-2.0 MIT"
tizen-platform-config_files += "/etc/tizen-platform.conf"

libtzplatform-config_files = ""
libtzplatform-config_files += "tizen-platform-config.manifest"
libtzplatform-config_files += "/usr/lib/*.so.*"

FILES_libtzplatform-config-devel = "${libtzplatform-config-devel_files}"
FILES_${PN}-tools = "${tizen-platform-config-tools_files}"
FILES_${PN} = "${tizen-platform-config_files}"
FILES_libtzplatform-config = "${libtzplatform-config_files}"

PKG_libtzplatform-config-devel= "libtzplatform-config-devel"
PKG_tizen-platform-config-tools= "tizen-platform-config-tools"
PKG_tizen-platform-config= "tizen-platform-config"
PKG_libtzplatform-config= "libtzplatform-config"

require tizen-platform-config-extraconf.inc
