DESCRIPTION = "Configuration system library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by vconf-keys-dev


#PROVIDES by vconf


#PROVIDES by vconf-dev


RDEPENDS = ""
#RDEPENDS of vconf-keys-dev (${PN}-keys-dev)
RDEPENDS_${PN}-keys-dev += "vconf"
RDEPENDS_${PN}-keys-dev += "vconf-internal-keys-dev"

#RDEPENDS of vconf (${PN})
RDEPENDS_${PN} += "eglibc"
RDEPENDS_${PN} += "systemd"

#RDEPENDS of vconf-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "vconf"
RDEPENDS_${PN}-dev += "glib-2.0"


DEPENDS = ""
#DEPENDS of vconf
DEPENDS += "vconf-internal-keys"
DEPENDS += "tizen-platform-config"
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "dlog"
DEPENDS += "glib-2.0"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n vconf-0.2.51
 cp ${S}/packaging/vconf.manifest .
 
 
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
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
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
         ${EXTRA_OECMAKE} . \
 	-DTZ_SYS_CONFIG=${prefix}/kdb
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}${prefix}/kdb/db
 mkdir -p ${D}${prefix}/kdb/db/.backup
 mkdir -p ${D}/lib/systemd/system/basic.target.wants
 mkdir -p ${D}${prefix}/lib/tmpfiles.d
 install -m0644 ${S}/packaging/vconf-setup.service ${D}/lib/systemd/system/
 install -m0644 ${S}/packaging/vconf-setup.conf ${D}${prefix}/lib/tmpfiles.d/
 ln -sf ../vconf-setup.service ${D}/lib/systemd/system/basic.target.wants/
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    systemctl daemon-reload
    chsmack -a 'User' $D${prefix}/kdb
    chsmack -a 'User' $D${prefix}/kdb/db
    chsmack -a 'User' $D${prefix}/kdb/db/.backup

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    systemctl daemon-reload

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " vconf-keys-dev "
PACKAGES += " vconf "
PACKAGES += " vconf-dev "

vconf-keys-dev_files = ""
vconf-keys-dev_files += "vconf.manifest"
vconf-keys-dev_files += "${prefix}/include/vconf/vconf-keys.h"

vconf_files = ""
vconf_files += "vconf.manifest"
vconf_files += "${sysconfdir}/preconf.d/vconf-setup"
vconf_files += "${prefix}/bin/vconftool"
vconf_files += "${prefix}/bin/vconf-init"
vconf_files += "${prefix}/kdb/kdb_first_boot"
vconf_files += "${prefix}/lib/*.so.*"
vconf_files += "%attr(777,root,users) ${prefix}/kdb/db"
vconf_files += "%attr(777,root,root) ${prefix}/kdb/db/.backup"
vconf_files += "/lib/systemd/system/basic.target.wants/vconf-setup.service"
vconf_files += "/lib/systemd/system/vconf-setup.service"
vconf_files += "${prefix}/lib/tmpfiles.d/vconf-setup.conf"

vconf-dev_files = ""
vconf-dev_files += "vconf.manifest"
vconf-dev_files += "${prefix}/include/vconf/vconf.h"
vconf-dev_files += "${prefix}/lib/pkgconfig/*.pc"
vconf-dev_files += "${prefix}/lib/*.so"

FILES_${PN}-keys-dev = "${vconf-keys-dev_files}"
FILES_${PN} = "${vconf_files}"
FILES_${PN}-dev = "${vconf-dev_files}"

PKG_vconf-keys-dev= "vconf-keys-dev"
PKG_vconf= "vconf"
PKG_vconf-dev= "vconf-dev"

require vconf-extraconf.inc

