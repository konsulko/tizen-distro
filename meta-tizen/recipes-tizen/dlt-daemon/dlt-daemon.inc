DESCRIPTION = "GENIVI Diagnostic Log and Trace"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Automotive/GENIVI"
LICENSE = "MPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by dlt-daemon


#PROVIDES by dlt-bin
PROVIDES += "dlt-bin"


#PROVIDES by dlt-dev
PROVIDES += "dlt-dev"


#PROVIDES by dlt-test
PROVIDES += "dlt-test"


#PROVIDES by dlt
PROVIDES += "dlt"


#PROVIDES by libdlt
PROVIDES += "libdlt"


RDEPENDS = ""
#RDEPENDS of dlt-dev (dlt-dev)
RDEPENDS_dlt-dev += "libdlt"

#RDEPENDS of dlt (dlt)
RDEPENDS_dlt += "eglibc"


DEPENDS = ""
#DEPENDS of dlt
DEPENDS += "systemd"
DEPENDS += "zlib"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n dlt-2.9.1
 
 
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
 
 mkdir build
 cd build
 
 cmake -DWITH_SYSTEMD=ON -DWITH_SYSTEMD_JOURNAL=ON \
       -DWITH_MAN=OFF -DWITH_DLT_EXAMPLES=OFF ..
 make -j 16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf "$RPM_BUILD_ROOT"
 cd build
 make install DESTDIR=$RPM_BUILD_ROOT
 
 
}

pkg_postinst_libdlt() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

pkg_postrm_libdlt() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " dlt-dev "
PACKAGES += " dlt-bin "
PACKAGES += " dlt-daemon "
PACKAGES += " dlt-test "
PACKAGES += " libdlt "

dlt-dev_files = ""
dlt-dev_files += "${prefix}/include/dlt/*"
dlt-dev_files += "${prefix}/lib/*.so"
dlt-dev_files += "${prefix}/lib/pkgconfig/*.pc"

dlt-bin_files = ""
dlt-bin_files += "${prefix}/bin/dlt-adaptor*"
dlt-bin_files += "${prefix}/bin/dlt-convert"
dlt-bin_files += "${prefix}/bin/dlt-receive"
dlt-bin_files += "${prefix}/bin/dlt-system"
dlt-bin_files += "${prefix}/bin/dlt-control"
dlt-bin_files += "${sysconfdir}/dlt-system.conf"
dlt-bin_files += "${prefix}/lib/systemd/system/dlt-adaptor-udp.service"
dlt-bin_files += "${prefix}/lib/systemd/system/dlt-receive.service"
dlt-bin_files += "${prefix}/lib/systemd/system/dlt-system.service"
CONFFILES_dlt-bin = ""
CONFFILES_dlt-bin += "${sysconfdir}/dlt-system.conf"

dlt-daemon_files = ""
dlt-daemon_files += "${prefix}/bin/dlt-daemon"
dlt-daemon_files += "${sysconfdir}/dlt.conf"
dlt-daemon_files += "${prefix}/lib/systemd/system/dlt.service"
CONFFILES_${PN} = ""
CONFFILES_${PN} += "${sysconfdir}/dlt.conf"

dlt-test_files = ""
dlt-test_files += "${prefix}/bin/dlt-test*"
dlt-test_files += "${prefix}/share/dlt-filetransfer/*"

libdlt_files = ""
libdlt_files += "${prefix}/lib/*so.*"

FILES_dlt-dev = "${dlt-dev_files}"
FILES_dlt-bin = "${dlt-bin_files}"
FILES_${PN} = "${dlt-daemon_files}"
FILES_dlt-test = "${dlt-test_files}"
FILES_libdlt = "${libdlt_files}"

PKG_dlt-dev= "dlt-dev"
PKG_dlt-bin= "dlt-bin"
PKG_dlt-daemon= "dlt-daemon"
PKG_dlt-test= "dlt-test"
PKG_libdlt= "libdlt"

require dlt-daemon-extraconf.inc

