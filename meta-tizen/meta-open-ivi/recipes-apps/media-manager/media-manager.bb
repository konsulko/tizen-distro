DESCRIPTION = "GENIVI Media Manager" 
SECTION = "OpenIVI" 
LICENSE = "MPL-2.0" 
PR = "r0" 

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

DEPENDS = "jansson"
DEPENDS += "glibc"
DEPENDS += "CommonAPI"
DEPENDS += "CommonAPI-DBus"

RDEPENDS = ""
RDEPENDS_${PN} = "lightmediascanner"
RDEPENDS_${PN} = "rygel"
#dLeyna - DLNA-certified open source solution for Linux
RDEPENDS_${PN} = "gupnp-dlna"

SRC_URI = "git://git.projects.genivi.org/media-manager.git;branch=master;tag=45e08ce242a6006aaaefaeda236f51c984eaeeb1"

S = "${WORKDIR}/git"

inherit pkgconfig tizen_cmake

mediamanager_file = ""
mediamanager_file += "${prefix}/etc/udev/rules.d/10-media-manager-usb-mount-rules.rules" 

do_configure() {
 cd ${S}
 git submodule update --init --recursive
 mkdir build
}

do_compile() {
 cd ${S}/build
 LANG=C
 export LANG
 unset DISPLAY
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;

 export LDFLAGS="${LDFLAGS} -Wl,--rpath=${prefix}/lib -Wl,--as-needed -Wl,--hash-style=both"

 cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=${prefix} \
         -DCMAKE_INSTALL_LIBDIR:PATH=${prefix}/lib \
         -DINCLUDE_INSTALL_DIR:PATH=${prefix}/include \
         -DLIB_INSTALL_DIR:PATH=${prefix}/lib \
         -DSYSCONF_INSTALL_DIR:PATH=${sysconfdir} \
         -DSHARE_INSTALL_PREFIX:PATH=${prefix}/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
         ${EXTRA_OECMAKE} ..
 oe_runmake

}

do_install() {
# install -d ${D}${bindir}
# install -m 0755 cameracapture ${D}${bindir}
 export RPM_BUILD_ROOT=${D}/build
 cd ${S}/build
 LANG=C
 export LANG
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
