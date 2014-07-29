DESCRIPTION = "Crosswalk is an app runtime based on Chromium"
HOMEPAGE = "https://github.com/otcshare/crosswalk"
SECTION = "Web Framework/Web Run Time"
LICENSE = "(BSD-3-Clause and LGPL-2.1+)"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by crosswalk


RDEPENDS = ""

DEPENDS = ""
#DEPENDS of crosswalk
DEPENDS += "libhaptic"
DEPENDS += "cairo"
DEPENDS += "udev"
DEPENDS += "app-core"
DEPENDS += "libslp-sensor"
DEPENDS += "libxslt"
inherit perlnative
DEPENDS += "pango"
DEPENDS += "bzip2"
DEPENDS += "nss"
DEPENDS += "slp-pkgmgr"
DEPENDS += "alsa-lib"
DEPENDS += "elfutils"
DEPENDS += "fontconfig"
DEPENDS += "wayland"
DEPENDS += "which"
DEPENDS += "libxml2"
DEPENDS += "libcap"
DEPENDS += "icu"
DEPENDS += "flex"
DEPENDS += "freetype"
DEPENDS += "gperf"
inherit pythonnative
DEPENDS += "tizen-platform-config"
DEPENDS += "pkgmgr-info"
DEPENDS += "glib-2.0"
DEPENDS += "libdrm"
DEPENDS += "python-xml"
DEPENDS_append_class-native = " ninja-native"
DEPENDS_append_class-target = " ninja-native"
DEPENDS += "mesa"
DEPENDS += "vconf"
DEPENDS += "nspr"
DEPENDS += "dbus"
DEPENDS += "libxkbcommon"
DEPENDS += "expat-dev"
DEPENDS += "pulseaudio"
DEPENDS += "location-manager"
DEPENDS += "libexif"
DEPENDS_append_class-native = " bison-native"
DEPENDS_append_class-target = " bison-native"
DEPENDS += "pciutils"
DEPENDS += "binutils"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n crosswalk
 
 cp ${S}/packaging/xwalk.in .
 cp ${S}/packaging/xwalk.service.in .
 cp ${S}/packaging/crosswalk.manifest .
 cp ${S}/packaging/crosswalk.xml.in .
 cp ${S}/packaging/crosswalk.png .
 sed "s/@VERSION@/8.36.161.0/g" crosswalk.xml.in > crosswalk.xml
 sed "s|@LIB_INSTALL_DIR@|${prefix}/lib|g" xwalk.in > xwalk
 sed "s|@LIB_INSTALL_DIR@|${prefix}/lib|g" xwalk.service.in > xwalk.service
 
 cp -a src/AUTHORS AUTHORS.chromium
 cp -a src/LICENSE LICENSE.chromium
 cp -a src/xwalk/LICENSE LICENSE.xwalk
 
 cat ${S}/packaging/Blink-Add-GCC-flag-Wno-narrowing-fix-64bits-build.patch | patch -s  -p0 --fuzz=2
 #patch9
 
 # The profiles using Wayland (and thus Ozone) do not need this patch.
 
 ###patch11
 
 
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
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 
 # For ffmpeg on ia32. The original CFLAGS set by the gyp and config files in
 # src/third_party/ffmpeg already pass -O2 -fomit-frame-pointer, but Tizen's
 # CFLAGS end up appending -fno-omit-frame-pointer. See http://crbug.com/37246
 export CFLAGS=`echo $CFLAGS | sed s,-fno-omit-frame-pointer,,g`
 
 
 # Building the RPM in the GBS chroot fails with errors such as
 #   /usr/lib/gcc/i586-tizen-linux/4.7/../../../../i586-tizen-linux/bin/ld:
 #       failed to set dynamic section sizes: Memory exhausted
 # For now, work around it by passing a GNU ld-specific flag that optimizes the
 # linker for memory usage.
 export LDFLAGS="${LDFLAGS} -Wl,--no-keep-memory"
 
 # Support building in a non-standard directory, possibly outside ${WORKDIR}.
 # Since the build root is erased every time a new build is performed, one way
 # to avoid losing the build directory is to specify a location outside the
 # build root to the BUILDDIR_NAME definition, such as "/var/tmp/xwalk-build"
 # (remember all paths are still inside the chroot):
 #    gbs build --define 'BUILDDIR_NAME /some/path'
 BUILDDIR_NAME=""
 if [ -n "${BUILDDIR_NAME}" ]; then
    mkdir -p "${BUILDDIR_NAME}"
    ln -s "${BUILDDIR_NAME}" src/out
 fi
 
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Duse_ozone=1 -Denable_ozone_wayland_vkb=1 -Denable_xdg_shell=1"
 
 # Force gold binary from chroot ld.gold provided by binutils-gold
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Ddisable_nacl=1 -Dlinux_use_bundled_binutils=0 -Dlinux_use_bundled_gold=0 "
 
 # Linking fails in Tizen Common when fatal ld warnings are enabled. XWALK-1379.
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Ddisable_fatal_linker_warnings=1"
 
 # For building for arm in OBS, we need :
 # -> to unset sysroot value.
 # sysroot variable is automatically set for cross compilation to use arm-sysroot provided by Chromium project
 # sysroot usage is not needed, we need to use arm libraries from the virtualized environment.
 #
 # Crosswalk build fails if the fpu selected in the gcc option is different from neon in case of arm7 compilation
 # So force it.
 
 # --no-parallel is added because chroot does not mount a /dev/shm, this will
 # cause python multiprocessing.SemLock error.
 export GYP_GENERATORS='ninja'
 ./src/xwalk/gyp_xwalk src/xwalk/xwalk.gyp \
 --no-parallel \
 ${GYP_EXTRA_FLAGS} \
 -Dchromeos=0 \
 -Dtizen=1 \
 -Dpython_ver=2.7 \
 -Duse_aura=1 \
 -Duse_cups=0 \
 -Duse_gconf=0 \
 -Duse_gnome_keyring=0 \
 -Duse_kerberos=0 \
 -Duse_system_bzip2=1 \
 -Duse_system_libexif=1 \
 -Duse_system_libxml=1 \
 -Duse_system_nspr=1 \
 -Denable_hidpi=1
 
 ninja ${PARALLEL_MAKE} -C src/out/Release xwalk xwalkctl xwalk_launcher xwalk-pkg-helper
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 # Binaries.
 install -p -D xwalk ${D}${prefix}/bin/xwalk
 install -p -D ${S}/packaging/org.crosswalkproject.Runtime1.service ${D}/usr/share/dbus-1/services/org.crosswalkproject.Runtime1.service
 install -p -D xwalk.service ${D}/usr/lib/systemd/user/xwalk.service
 install -p -D src/out/Release/xwalk ${D}${prefix}/lib/xwalk/xwalk
 install -p -D src/out/Release/xwalkctl ${D}${prefix}/bin/xwalkctl
 install -p -D src/out/Release/xwalk-launcher ${D}${prefix}/bin/xwalk-launcher
 # xwalk-pkg-helper needs to be set-user-ID-root so it can finish the installation process.
 install -m 06755 -p -D src/out/Release/xwalk-pkg-helper ${D}${prefix}/bin/xwalk-pkg-helper
 
 # Supporting libraries and resources.
 install -p -D src/out/Release/icudtl.dat ${D}${prefix}/lib/xwalk/icudtl.dat
 install -p -D src/out/Release/libffmpegsumo.so ${D}${prefix}/lib/xwalk/libffmpegsumo.so
 install -p -D src/out/Release/xwalk.pak ${D}${prefix}/lib/xwalk/xwalk.pak
 
 # PNaCl
 
 # Register xwalk to the package manager.
 install -p -D crosswalk.xml ${D}/usr/share/packages/crosswalk.xml
 install -p -D crosswalk.png ${D}/usr/share/icons/default/small/crosswalk.png
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    mkdir -p /opt/share/icons/default/small
    mkdir -p /opt/share/packages

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " crosswalk "

crosswalk_files = ""
crosswalk_files += "${prefix}/bin/xwalk"
crosswalk_files += "${prefix}/bin/xwalkctl"
crosswalk_files += "${prefix}/bin/xwalk-launcher"
crosswalk_files += "${prefix}/bin/xwalk-pkg-helper"
crosswalk_files += "${prefix}/lib/xwalk/icudtl.dat"
crosswalk_files += "${prefix}/lib/xwalk/libffmpegsumo.so"
crosswalk_files += "${prefix}/lib/xwalk/xwalk"
crosswalk_files += "${prefix}/lib/xwalk/xwalk.pak"
crosswalk_files += "/usr/share/packages/crosswalk.xml"
crosswalk_files += "/usr/share/icons/default/small/crosswalk.png"
crosswalk_files += "/usr/share/dbus-1/services/org.crosswalkproject.Runtime1.service"
crosswalk_files += "/usr/lib/systemd/user/xwalk.service"
MANIFESTFILES_${PN} = "crosswalk.manifest"

FILES_${PN} = "${crosswalk_files}"

PKG_crosswalk= "crosswalk"

require crosswalk-extraconf.inc

