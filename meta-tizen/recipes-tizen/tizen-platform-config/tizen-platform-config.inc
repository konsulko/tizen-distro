DESCRIPTION = "Tizen Platform Configuration"
HOMEPAGE = "http://www.tizen.org"
SECTION = "System/Configuration"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by tizen-platform-config 


#PROVIDES by libtzplatform-config-dev 


#PROVIDES by tizen-platform-config-tools 


#PROVIDES by libtzplatform-config 


RDEPENDS = ""
#RDEPENDS of tizen-platform-config-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "libtzplatform-config"

#RDEPENDS of libtzplatform-config-dev (libtzplatform-config-dev)
RDEPENDS_libtzplatform-config-dev += "libtzplatform-config"

#RDEPENDS of libtzplatform-config (libtzplatform-config)
RDEPENDS_libtzplatform-config += "tizen-platform-config"


DEPENDS = ""
#DEPENDS of tizen-platform-config 
DEPENDS += "tizen-platform-wrapper"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tizen-platform-config.manifest .
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
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
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir} --disable-static
 oe_runmake -j16
 
 exit 0
 oe_runmake check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES += " libtzplatform-config-dev "
PACKAGES += " tizen-platform-config-tools "
PACKAGES += " libtzplatform-config "

libtzplatform-config-dev_files = ""
libtzplatform-config-dev_files += "tizen-platform-config.manifest"
libtzplatform-config-dev_files += "LGPL-2.0 LGPL_2.0"
libtzplatform-config-dev_files += "${prefix}/lib/*.so"
libtzplatform-config-dev_files += "${prefix}/lib/pkgconfig/*.pc"
libtzplatform-config-dev_files += "${prefix}/include/*.h"
libtzplatform-config-dev_files += "${sysconfdir}/rpm/macros.tizen-platform"

tizen-platform-config-tools_files = ""
tizen-platform-config-tools_files += "tizen-platform-config.manifest"
tizen-platform-config-tools_files += "${prefix}/bin/*"

tizen-platform-config_files = ""
tizen-platform-config_files += "tizen-platform-config.manifest"
tizen-platform-config_files += "LGPL-2.0 MIT"
tizen-platform-config_files += "${sysconfdir}/tizen-platform.conf"

libtzplatform-config_files = ""
libtzplatform-config_files += "tizen-platform-config.manifest"
libtzplatform-config_files += "${prefix}/lib/*.so.*"

FILES_libtzplatform-config-dev = "${libtzplatform-config-dev_files}"
FILES_${PN}-tools = "${tizen-platform-config-tools_files}"
FILES_${PN} = "${tizen-platform-config_files}"
FILES_libtzplatform-config = "${libtzplatform-config_files}"

PKG_libtzplatform-config-dev= "libtzplatform-config-dev"
PKG_tizen-platform-config-tools= "tizen-platform-config-tools"
PKG_tizen-platform-config= "tizen-platform-config"
PKG_libtzplatform-config= "libtzplatform-config"

require tizen-platform-config-extraconf.inc

