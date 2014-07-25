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

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 CC_host="gcc"; export CC_host
 CXX_host="g++"; export CXX_host

 LD="${CXX}" export LD
 CC="${CC}" export CC
 CXX="${CXX}" export CXX
 
 #CXXFLAGS="$CXXFLAGS -std=c++11" export CXXFLAGS
 
 # For ffmpeg on ia32. The original CFLAGS set by the gyp and config files in
 # src/third_party/ffmpeg already pass -O2 -fomit-frame-pointer, but Tizen's
 # CFLAGS end up appending -fno-omit-frame-pointer. See http://crbug.com/37246
 export CFLAGS=`echo $CFLAGS | sed s,-fno-omit-frame-pointer,,g`

 # Building the RPM in the GBS chroot fails with errors such as
 #   /usr/lib/gcc/i586-tizen-linux/4.7/../../../../i586-tizen-linux/bin/ld:
 #       failed to set dynamic section sizes: Memory exhausted
 # For now, work around it by passing a GNU ld-specific flag that optimizes the
 # linker for memory usage.
 export LDFLAGS="${LDFLAGS} -Wl,--no-keep-memory,--no-fatal-warnings"

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
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Dlinux_use_bundled_binutils=0 -Dlinux_use_bundled_gold=0 -Ddisable_fatal_linker_warnings=1"
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -I${WORKDIR}/oe-defaults.gypi -I${WORKDIR}/include.gypi"

 export GYP_GENERATORS='ninja'
 ./src/xwalk/gyp_xwalk src/xwalk/xwalk.gyp \
 --no-parallel \
 ${GYP_EXTRA_FLAGS} \
 -Dchromeos=0 \
 -Ddisable_nacl=1 \
 -Dtizen=1 \
 -Dpython_ver=2.7 \
 -Duse_aura=1 \
 -Duse_cups=0 \
 -Duse_gconf=0 \
 -Duse_gnome_keyring=0 \
 -Duse_kerberos=0 \
 -Denable_hidpi=1 \
 -Duse_system_bzip2=1 \
 -Duse_proprietary_codecs=0 

 ninja ${PARALLEL_MAKE} -C src/out/Release xwalk xwalkctl xwalk_launcher xwalk-pkg-helper 

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
