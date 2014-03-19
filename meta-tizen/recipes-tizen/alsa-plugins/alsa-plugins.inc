DESCRIPTION = "Extra Plug-Ins for the ALSA Library"
HOMEPAGE = "http://www.alsa-project.org/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by alsa-plugins 
PROVIDES += "alsa-plugins"
RPROVIDES_alsa-plugins += "alsa-plugins"

#PROVIDES by alsa-plugins-speex 
PROVIDES += "alsa-plugins-speex"
RPROVIDES_alsa-plugins-speex += "alsa-plugins-speex"

#PROVIDES by alsa-plugins-pulse 
PROVIDES += "alsa-plugins-pulse"
RPROVIDES_alsa-plugins-pulse += "alsa-plugins-pulse"

RDEPENDS = ""
#RDEPENDS of alsa-plugins-pulse (${PN}-pulse)
RDEPENDS_${PN}-pulse += "pulseaudio"


DEPENDS = ""
#DEPENDS of alsa-plugins 
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "libpulse-devel"
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "libtool-cross"
DEPENDS += "speex-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/alsa-plugins.manifest .
 
 
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
 
 export AUTOMAKE_JOBS="-j16"
 autoreconf -fi
 
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
         --infodir=/usr/share/info --with-speex=builtin
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
 mkdir -p ${D}/etc/
 /bin/install -m 0644 ${S}/packaging//asound-pulse.conf ${D}/etc/
 /bin/install -m 0644 ${S}/packaging//alsa-pulse.conf ${D}/etc/
 
 
}

PACKAGES = ""
PACKAGES += "alsa-plugins"
PACKAGES += "alsa-plugins-speex"
PACKAGES += "alsa-plugins-pulse"

alsa-plugins_files = ""
alsa-plugins_files += "alsa-plugins.manifest"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_ctl_oss.so"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_pcm_oss.so"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_pcm_upmix.so"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_pcm_vdownmix.so"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_pcm_usb_stream.so"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_rate_speexrate*.so"
alsa-plugins_files += "/usr/lib/alsa-lib/libasound_module_ctl_arcam_av.so"

alsa-plugins-speex_files = ""
alsa-plugins-speex_files += "alsa-plugins.manifest"
alsa-plugins-speex_files += "/usr/lib/alsa-lib/libasound_module_pcm_speex.so"

alsa-plugins-pulse_files = ""
alsa-plugins-pulse_files += "alsa-plugins.manifest"
alsa-plugins-pulse_files += "/usr/lib/alsa-lib/libasound_module_ctl_pulse.so"
alsa-plugins-pulse_files += "/usr/lib/alsa-lib/libasound_module_pcm_pulse.so"
alsa-plugins-pulse_files += "/usr/lib/alsa-lib/libasound_module_conf_pulse.so"
alsa-plugins-pulse_files += "/etc/asound-pulse.conf"
alsa-plugins-pulse_files += "/etc/alsa-pulse.conf"
alsa-plugins-pulse_files += "/usr/share/alsa/alsa.conf.d"

FILES_${PN} = "${alsa-plugins_files}"
FILES_${PN}-speex = "${alsa-plugins-speex_files}"
FILES_${PN}-pulse = "${alsa-plugins-pulse_files}"

PKG_alsa-plugins= "alsa-plugins"
PKG_alsa-plugins-speex= "alsa-plugins-speex"
PKG_alsa-plugins-pulse= "alsa-plugins-pulse"

require alsa-plugins-extraconf.inc
