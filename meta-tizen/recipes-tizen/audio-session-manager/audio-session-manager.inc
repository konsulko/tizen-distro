DESCRIPTION = "Audio Session Manager"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Multimedia/Service"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by audio-session-manager-devel 
PROVIDES += "audio-session-manager-devel"
RPROVIDES_audio-session-manager-devel += "audio-session-manager-devel"
RPROVIDES_audio-session-manager-devel += "audio-session-manager-dev"

#PROVIDES by audio-session-manager 
PROVIDES += "audio-session-manager"
RPROVIDES_audio-session-manager += "audio-session-manager"

#PROVIDES by audio-session-manager-sdk-devel 
PROVIDES += "audio-session-manager-sdk-devel"
RPROVIDES_audio-session-manager-sdk-devel += "audio-session-manager-sdk-devel"
RPROVIDES_audio-session-manager-sdk-devel += "audio-session-manager-sdk-dev"

RDEPENDS = ""
#RDEPENDS of audio-session-manager-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "audio-session-manager"

#RDEPENDS of audio-session-manager (${PN})
RDEPENDS_${PN} += "/usr/bin/vconftool"
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of audio-session-manager-sdk-devel (${PN}-sdk-devel)
RDEPENDS_${PN}-sdk-devel += "audio-session-manager-dev"


DEPENDS = ""
#DEPENDS of audio-session-manager 
DEPENDS += "pkgconfig(security-server)"
DEPENDS += "pkgconfig(avsysaudio)"
DEPENDS += "pkgconfig(sysman)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(mm-common)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/audio-session-manager.manifest .
 
 
 
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
         --infodir=/usr/share/info --disable-static --noconfigure
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fvisibility=hidden -DMM_DEBUG_FLAG -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\"" ; export CFLAGS
 
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
         --infodir=/usr/share/info --disable-static --enable-security
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
PACKAGES += "audio-session-manager-devel"
PACKAGES += "audio-session-manager"
PACKAGES += "audio-session-manager-sdk-devel"

audio-session-manager-devel_files = ""
audio-session-manager-devel_files += "audio-session-manager.manifest"
audio-session-manager-devel_files += "/usr/include/mmf/audio-session-manager-types.h"
audio-session-manager-devel_files += "/usr/include/mmf/audio-session-manager.h"

audio-session-manager_files = ""
audio-session-manager_files += "audio-session-manager.manifest"
audio-session-manager_files += "audio-session-manager.manifest"
audio-session-manager_files += "/usr/lib/libaudio-session-mgr.so.*"
audio-session-manager_files += "/usr/bin/asm_testsuite"

audio-session-manager-sdk-devel_files = ""
audio-session-manager-sdk-devel_files += "audio-session-manager.manifest"
audio-session-manager-sdk-devel_files += "/usr/include/mmf/audio-session-manager-types.h"
audio-session-manager-sdk-devel_files += "/usr/include/mmf/audio-session-manager.h"
audio-session-manager-sdk-devel_files += "/usr/lib/libaudio-session-mgr.so"
audio-session-manager-sdk-devel_files += "/usr/lib/pkgconfig/audio-session-mgr.pc"

FILES_${PN}-devel = "${audio-session-manager-devel_files}"
FILES_${PN} = "${audio-session-manager_files}"
FILES_${PN}-sdk-devel = "${audio-session-manager-sdk-devel_files}"

PKG_audio-session-manager-devel= "audio-session-manager-devel"
PKG_audio-session-manager= "audio-session-manager"
PKG_audio-session-manager-sdk-devel= "audio-session-manager-sdk-devel"

require audio-session-manager-extraconf.inc
