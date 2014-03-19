DESCRIPTION = "Audio Video System"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by avsystem 
PROVIDES += "avsystem"
RPROVIDES_avsystem += "avsystem"

#PROVIDES by avsystem-devel 
PROVIDES += "avsystem-devel"
RPROVIDES_avsystem-devel += "avsystem-devel"
RPROVIDES_avsystem-devel += "avsystem-dev"

#PROVIDES by libavsysaudio 
PROVIDES += "libavsysaudio"
RPROVIDES_libavsysaudio += "libavsysaudio"

RDEPENDS = ""
#RDEPENDS of avsystem (${PN})
RDEPENDS_${PN} += "/usr/bin/systemctl"
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of avsystem-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "avsystem"


DEPENDS = ""
#DEPENDS of avsystem 
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(libpulse)"
DEPENDS += "pkgconfig(iniparser)"
DEPENDS += "pkgconfig(mm-log)"
DEPENDS += "alsa-scenario-0.2"
DEPENDS += "pkgconfig(mm-ta)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n avsystem-0.5.5
 cp ${S}/packaging/avsystem.manifest .
 
 
 
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
         --infodir=/usr/share/info \
 	--enable-audiotest
 
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
 
 mkdir -m 755 -p ${D}//etc/rc.d/rc3.d/
 ln -s ../init.d/snd_init ${D}//etc/rc.d/rc3.d/S15snd_init
 mkdir -m 755 -p ${D}//etc/rc.d/rc4.d/
 ln -s ../init.d/snd_init ${D}//etc/rc.d/rc4.d/S15snd_init
 
 mkdir -m 755 -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 install -m 0644 ${S}/packaging/avsystem.service ${D}/usr/lib/systemd/system/avsystem.service
 ln -s ../avsystem.service ${D}/usr/lib/systemd/system/multi-user.target.wants/avsystem.service
 
 
}

PACKAGES = ""
PACKAGES += "avsystem"
PACKAGES += "avsystem-devel"
PACKAGES += "libavsysaudio"

avsystem_files = ""
avsystem_files += "avsystem.manifest"
avsystem_files += "/etc/rc.d/init.d/snd_init"
avsystem_files += "/etc/rc.d/rc3.d/S15snd_init"
avsystem_files += "/etc/rc.d/rc4.d/S15snd_init"
avsystem_files += "/usr/bin/*"
avsystem_files += "/usr/lib/systemd/system/avsystem.service"
avsystem_files += "/usr/lib/systemd/system/multi-user.target.wants/avsystem.service"

avsystem-devel_files = ""
avsystem-devel_files += "avsystem.manifest"
avsystem-devel_files += "/usr/lib/pkgconfig/*.pc"
avsystem-devel_files += "/usr/lib/*.so"
avsystem-devel_files += "/usr/include/avsystem/*.h"

libavsysaudio_files = ""
libavsysaudio_files += "avsystem.manifest"
libavsysaudio_files += "/usr/lib/lib*.so.*"

FILES_${PN} = "${avsystem_files}"
FILES_${PN}-devel = "${avsystem-devel_files}"
FILES_libavsysaudio = "${libavsysaudio_files}"

PKG_avsystem= "avsystem"
PKG_avsystem-devel= "avsystem-devel"
PKG_libavsysaudio= "libavsysaudio"

require avsystem-extraconf.inc
