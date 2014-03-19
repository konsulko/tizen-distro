DESCRIPTION = "Crosswalk is an app runtime based on Chromium"
HOMEPAGE = "https://github.com/otcshare/crosswalk"
SECTION = "Web Framework/Web Run Time"
LICENSE = "(BSD-3-Clause and LGPL-2.1+)"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by crosswalk-emulator-support 
PROVIDES += "crosswalk-emulator-support"
RPROVIDES_crosswalk-emulator-support += "crosswalk-emulator-support"

#PROVIDES by crosswalk 
PROVIDES += "crosswalk"
RPROVIDES_crosswalk += "crosswalk"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of crosswalk 
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "audio-session-manager"
DEPENDS += "pkgconfig(freetype2)"
DEPENDS += "pkgconfig(libpulse)"
DEPENDS += "app-core"
DEPENDS += "pkgconfig(wayland-egl)"
DEPENDS += "pkgconfig(nss)"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(xkbcommon)"
DEPENDS += "pkgconfig(libpci)"
DEPENDS += "bzip2"
DEPENDS += "pkgconfig(fontconfig)"
inherit perlnative
DEPENDS += "pkgconfig(icu-i18n)"
DEPENDS += "pkgconfig(pkgmgr-parser)"
DEPENDS += "which"
DEPENDS += "nspr-devel"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libexif)"
DEPENDS += "pkgconfig(pango)"
DEPENDS += "flex"
DEPENDS += "pkgconfig(capi-location-manager)"
DEPENDS += "gperf"
inherit pythonnative
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "pkgconfig(egl)"
DEPENDS += "libcap-devel"
DEPENDS += "python-xml"
DEPENDS += "pkgconfig(sensor)"
DEPENDS += "pkgconfig(wayland-cursor)"
DEPENDS += "pkgconfig(libxslt)"
DEPENDS += "pkgconfig(haptic)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "pkgconfig(cairo)"
DEPENDS += "expat-devel"
DEPENDS += "pkgconfig(libdrm)"
DEPENDS += "bison-native"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(libudev)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n crosswalk
 
 cp ${S}/packaging/xwalk.in .
 cp ${S}/packaging/xwalk.service.in .
 cp ${S}/packaging/crosswalk.manifest .
 cp ${S}/packaging/crosswalk.xml.in .
 cp ${S}/packaging/crosswalk.png .
 sed "s/@VERSION@/5.34.98.0/g" crosswalk.xml.in > crosswalk.xml
 sed "s|@LIB_INSTALL_DIR@|/usr/lib|g" xwalk.in > xwalk
 sed "s|@LIB_INSTALL_DIR@|/usr/lib|g" xwalk.service.in > xwalk.service
 
 cp -a src/AUTHORS AUTHORS.chromium
 cp -a src/LICENSE LICENSE.chromium
 cp -a src/xwalk/LICENSE LICENSE.xwalk
 
 cat ${S}/packaging/crosswalk-do-not-look-for-gtk2-when-using-aura.patch | patch -s  -p0 --fuzz=2
 #patch1
 cat ${S}/packaging/crosswalk-tizen-audio-session-manager.patch | patch -s  -p0 --fuzz=2
 #patch7
 
 
 cat ${S}/packaging/crosswalk-mesa-ozone-typedefs.patch | patch -s  -p0 --fuzz=2
 #patch8
 
 cat ${S}/packaging/Blink-Add-GCC-flag-Wno-narrowing-fix-64bits-build.patch | patch -s  -p0 --fuzz=2
 #patch9
 
 
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
 #
 # The --depth and --generator-output combo is used to put all the Makefiles
 # inside the build directory, and (this is the important part) keep file lists
 # (generatedwith <|() in gyp) in the build directory as well, otherwise they
 # will be in the source directory, erased every time and trigger an almost full
 # Blink rebuild (among other smaller targets).
 # We cannot always pass those flags, though, because gyp's make generator does
 # not work if the --generator-output is the top-level source directory.
 BUILDDIR_NAME=""
 if [ -z "${BUILDDIR_NAME}" ]; then
    BUILDDIR_NAME="."
 else
    GYP_EXTRA_FLAGS="--depth=. --generator-output=${BUILDDIR_NAME}"
 fi
 
 GYP_EXTRA_FLAGS="${GYP_EXTRA_FLAGS} -Duse_ash=1 -Duse_ozone=1"
 
 # Change src/ so that we can pass "." to --depth below, otherwise we would need
 # to pass "src" to it, but this confuses the gyp make generator, that expects
 # to be called from the root source directory.
 cd src
 
 # --no-parallel is added because chroot does not mount a /dev/shm, this will
 # cause python multiprocessing.SemLock error.
 export GYP_GENERATORS='make'
 ./xwalk/gyp_xwalk xwalk/xwalk.gyp \
 --no-parallel \
 ${GYP_EXTRA_FLAGS} \
 -Dchromeos=0 \
 -Ddisable_nacl=1 \
 -Dtizen=1 \
 -Dpython_ver=2.7 \
 -Duse_aura=1 \
 -Duse_cups=0 \
 -Duse_gconf=0 \
 -Duse_kerberos=0 \
 -Duse_system_bzip2=1 \
 -Duse_system_icu=1 \
 -Duse_system_libexif=1 \
 -Duse_system_libxml=1 \
 -Duse_system_nspr=1 \
 -Denable_xi21_mt=1 \
 -Duse_xi2_mt=0 \
 -Denable_hidpi=1
 
 make -j16 -C "${BUILDDIR_NAME}" BUILDTYPE=Release xwalk xwalkctl xwalk_launcher xwalk-pkg-helper
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # Support building in a non-standard directory, possibly outside ${WORKDIR}.
 # Since the build root is erased every time a new build is performed, one way
 # to avoid losing the build directory is to specify a location outside the
 # build root to the BUILDDIR_NAME definition, such as "/var/tmp/xwalk-build"
 # (remember all paths are still inside the chroot):
 #    gbs build --define 'BUILDDIR_NAME /some/path'
 BUILDDIR_NAME=""
 if [ -z "${BUILDDIR_NAME}" ]; then
    BUILDDIR_NAME="."
 fi
 
 # Since BUILDDIR_NAME can be either a relative path or an absolute one, we need
 # to cd into src/ so that it means the same thing in the build and install
 # stages: during the former, a relative location refers to a place inside src/,
 # whereas during the latter a relative location by default would refer to a
 # place one directory above src/. If BUILDDIR_NAME is an absolute path, this is
 # irrelevant anyway.
 cd src
 
 # Binaries.
 install -p -D ../xwalk ${D}/usr/bin/xwalk
 install -p -D ${S}/packaging/org.crosswalkproject.Runtime1.service ${D}/usr/share/dbus-1/services/org.crosswalkproject.Runtime1.service
 install -p -D ../xwalk.service ${D}/usr/lib/systemd/user/xwalk.service
 install -p -D ${BUILDDIR_NAME}/out/Release/xwalk ${D}/usr/lib/xwalk/xwalk
 install -p -D ${BUILDDIR_NAME}/out/Release/xwalkctl ${D}/usr/bin/xwalkctl
 install -p -D ${BUILDDIR_NAME}/out/Release/xwalk-launcher ${D}/usr/bin/xwalk-launcher
 # xwalk-pkg-helper needs to be set-user-ID-root so it can finish the installation process.
 install -m 06755 -p -D ${BUILDDIR_NAME}/out/Release/xwalk-pkg-helper ${D}/usr/bin/xwalk-pkg-helper
 
 # Supporting libraries and resources.
 install -p -D ${BUILDDIR_NAME}/out/Release/icudtl.dat ${D}/usr/lib/xwalk/icudtl.dat
 install -p -D ${BUILDDIR_NAME}/out/Release/libffmpegsumo.so ${D}/usr/lib/xwalk/libffmpegsumo.so
 install -p -D ${BUILDDIR_NAME}/out/Release/libosmesa.so ${D}/usr/lib/xwalk/libosmesa.so
 install -p -D ${BUILDDIR_NAME}/out/Release/xwalk.pak ${D}/usr/lib/xwalk/xwalk.pak
 
 # Register xwalk to the package manager.
 install -p -D ../crosswalk.xml ${D}/usr/share/packages/crosswalk.xml
 install -p -D ../crosswalk.png ${D}/usr/share/icons/default/small/crosswalk.png
 
 
}

PACKAGES = ""
PACKAGES += "crosswalk-emulator-support"
PACKAGES += "crosswalk"

crosswalk-emulator-support_files = ""
crosswalk-emulator-support_files += "/usr/lib/xwalk/libosmesa.so"

crosswalk_files = ""
crosswalk_files += "crosswalk.manifest"
crosswalk_files += "/usr/bin/xwalk"
crosswalk_files += "/usr/bin/xwalkctl"
crosswalk_files += "/usr/bin/xwalk-launcher"
crosswalk_files += "/usr/bin/xwalk-pkg-helper"
crosswalk_files += "/usr/lib/xwalk/icudtl.dat"
crosswalk_files += "/usr/lib/xwalk/libffmpegsumo.so"
crosswalk_files += "/usr/lib/xwalk/xwalk"
crosswalk_files += "/usr/lib/xwalk/xwalk.pak"
crosswalk_files += "/usr/share/packages/crosswalk.xml"
crosswalk_files += "/usr/share/icons/default/small/crosswalk.png"
crosswalk_files += "/usr/share/dbus-1/services/org.crosswalkproject.Runtime1.service"
crosswalk_files += "/usr/lib/systemd/user/xwalk.service"

FILES_${PN}-emulator-support = "${crosswalk-emulator-support_files}"
FILES_${PN} = "${crosswalk_files}"

PKG_crosswalk-emulator-support= "crosswalk-emulator-support"
PKG_crosswalk= "crosswalk"

require crosswalk.git-extraconf.inc
