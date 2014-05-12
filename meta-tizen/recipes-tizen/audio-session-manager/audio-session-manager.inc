DESCRIPTION = "Audio Session Manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by audio-session-manager-dev 


#PROVIDES by audio-session-manager 


#PROVIDES by audio-session-manager-sdk-dev 


RDEPENDS = ""
#RDEPENDS of audio-session-manager-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "audio-session-manager"

#RDEPENDS of audio-session-manager (${PN})
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of audio-session-manager-sdk-dev (${PN}-sdk-dev)
RDEPENDS_${PN}-sdk-dev += "audio-session-manager-dev"


DEPENDS = ""
#DEPENDS of audio-session-manager 
DEPENDS += "avsystem"
DEPENDS += "libmm-common"
DEPENDS += "security-server"
DEPENDS += "glib-2.0"
DEPENDS += "libslp-sysman"
DEPENDS += "vconf"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/audio-session-manager.manifest .
 
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=${infodir} --disable-static --noconfigure
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fvisibility=hidden -DMM_DEBUG_FLAG -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\"" ; export CFLAGS
 
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
         --infodir=${infodir} --disable-static --enable-security
 make -j16
 
 
 
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

PACKAGES += " audio-session-manager-sdk-dev "

audio-session-manager-dev_files = ""
audio-session-manager-dev_files += "audio-session-manager.manifest"
audio-session-manager-dev_files += "${prefix}/include/mmf/audio-session-manager-types.h"
audio-session-manager-dev_files += "${prefix}/include/mmf/audio-session-manager.h"

audio-session-manager_files = ""
audio-session-manager_files += "audio-session-manager.manifest"
audio-session-manager_files += "audio-session-manager.manifest"
audio-session-manager_files += "${prefix}/lib/libaudio-session-mgr.so.*"
audio-session-manager_files += "${prefix}/bin/asm_testsuite"

audio-session-manager-sdk-dev_files = ""
audio-session-manager-sdk-dev_files += "audio-session-manager.manifest"
audio-session-manager-sdk-dev_files += "${prefix}/include/mmf/audio-session-manager-types.h"
audio-session-manager-sdk-dev_files += "${prefix}/include/mmf/audio-session-manager.h"
audio-session-manager-sdk-dev_files += "${prefix}/lib/libaudio-session-mgr.so"
audio-session-manager-sdk-dev_files += "${prefix}/lib/pkgconfig/audio-session-mgr.pc"

FILES_${PN}-dev = "${audio-session-manager-dev_files}"
FILES_${PN} = "${audio-session-manager_files}"
FILES_${PN}-sdk-dev = "${audio-session-manager-sdk-dev_files}"

PKG_audio-session-manager-dev= "audio-session-manager-dev"
PKG_audio-session-manager= "audio-session-manager"
PKG_audio-session-manager-sdk-dev= "audio-session-manager-sdk-dev"

require audio-session-manager-extraconf.inc

