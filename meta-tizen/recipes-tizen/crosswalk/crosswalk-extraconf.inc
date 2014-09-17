inherit gettext

FILESEXTRAPATHS_prepend := "${THISDIR}/crosswalk"

SRC_URI += "\
            file://include.gypi \
            file://oe-defaults.gypi \
            "

# This comes from the chromium recipe:
# http://layers.openembedded.org/layerindex/recipe/4969/
# It allows architecture specific configuration
COMPATIBLE_MACHINE = "(-)"
COMPATIBLE_MACHINE_i586 = "(.*)"
COMPATIBLE_MACHINE_x86-64 = "(.*)"
COMPATIBLE_MACHINE_armv6 = "(.*)"
COMPATIBLE_MACHINE_armv7a = "(.*)"
COMPATIBLE_MACHINE_romley-ivb = "(.*)"
COMPATIBLE_MACHINE_valleyisland-64 = "(.*)"

RDEPENDS_${PN} += "libpulsecommon"

do_compile_prepend() {

 CC_host="gcc"; export CC_host
 CXX_host="g++"; export CXX_host

 LD="${CXX}" export LD
 CC="${CC}" export CC
 CXX="${CXX}" export CXX_host
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -I${WORKDIR}/oe-defaults.gypi -I${WORKDIR}/include.gypi"
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -I${WORKDIR}/oe-defaults.gypi -I${WORKDIR}/include.gypi"
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
 
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Duse_ozone=1 -Denable_ozone_wayland_vkb=1 -Denable_xdg_shell=0"
 
 # Force gold binary from chroot ld.gold provided by binutils-gold
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Ddisable_nacl=1 -Dlinux_use_bundled_binutils=0 -Dlinux_use_bundled_gold=0 "
 
 # Linking fails in Tizen Common when fatal ld warnings are enabled. XWALK-1379.
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Ddisable_fatal_linker_warnings=1"
 
 # Temporarily disable Alsa support while snd_seq_* support is not enabled on
 # Tizen. See https://codereview.chromium.org/264973012 and
 # https://review.tizen.org/gerrit/#/c/24336/
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Duse_alsa=0"
 
 # Temporarily disable WebRTC support because its build currently hardcodes
 # dependencies on X11 and OpenSSL. We are still trying to get some
 # clarifications as to whether this is really necessary. See XWALK-2160.
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Denable_webrtc=0"
 
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
 -Duse_system_nspr=1 \
 -Dshared_process_mode=1 \
 -Denable_hidpi=1
 
 ninja -j16 -C src/out/Release xwalk xwalkctl xwalk_launcher xwalk-pkg-helper
 
 
 
}

crosswalk-dbg_files += "/usr/lib/xwalk/.debug"
crosswalk-dbg_files += "/usr/lib/xwalk/.debug/libffmpegsumo.so"
crosswalk-dbg_files += "/usr/lib/xwalk/.debug/xwalk"

FILES_${PN}-dbg += "${crosswalk-dbg_files}"

pkg_postinst_${PN}() {
    #!/bin/sh -e

    mkdir -p $D/opt/share/icons/default/small
    mkdir -p $D/opt/share/packages

}
