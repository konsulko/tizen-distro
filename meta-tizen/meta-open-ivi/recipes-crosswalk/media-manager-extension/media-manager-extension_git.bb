SUMMARY = "GENIVI Media Manager Crosswalk Extension"
DESCRIPTION = "Media Manager CrossWalk Tizen Extension. Interfaces with GENIVI MediaManager"
SECTION = "OpenIVI"
PR = "r0"

LICENSE = "MPL-2.0"
LIC_FILES_CHKSUM = "file://extension/api.js;beginline=9;endline=11;md5=7ed4a999c0c67c1efed0b17e0fad99b0"

DEPENDS = "glib-2.0 jansson CommonAPI CommonAPI-DBus"
RDEPENDS_${PN} = "media-manager"

SRCREV_media-manager-extension = "04377af1bed47ca945c2945e8004681c377542b8"
SRCREV_media-manager-interfaces = "f0510129f8ac4fa48e7164dbb81ae9d0a922b9c4"
SRCREV_FORMAT = "media-manager-extension"
SRC_URI = "git://git.projects.genivi.org/media-manager-extension.git;name=media-manager-extension \
           git://git.projects.genivi.org/media-manager-interfaces.git;name=media-manager-interfaces;destsuffix=git/interfaces \
          "

S = "${WORKDIR}/git"

inherit pkgconfig tizen_cmake

do_compile() {
 mkdir -p ${S}/build
 cd ${S}/build
 LANG=C; export LANG;
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED;

 export LDFLAGS="${LDFLAGS} -Wl,--rpath=${prefix}/lib -Wl,--as-needed -Wl,--hash-style=both"

 cmake -DCMAKE_INSTALL_PREFIX:PATH=${prefix} ${EXTRA_OECMAKE} ..

 oe_runmake
}

do_install() {
 export RPM_BUILD_ROOT=${D}/build
 cd ${S}/build
 LANG=C; export LANG;
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}

 oe_runmake install \
         NO_ARLIB=1 \
         DESTDIR=${D} \
         LIBDIR=${prefix}/lib \
         USRLIBDIR=${prefix}/lib \
         BINDIR=${prefix}/bin \
         SBINDIR=${prefix}/sbin
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " media-manager-extension "

media-manager-extension_files = ""
media-manager-extension_files += "${prefix}/lib/tizen-extensions-crosswalk/libmediamanager.so"

FILES_${PN} = "${media-manager-extension_files}"

PKG_media-manager-extension= "media-manager-extension"
