DESCRIPTION = "Library to control privilege of application"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Access Control"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libprivilege-control


#PROVIDES by libprivilege-control-conf


#PROVIDES by libprivilege-control-dev


RDEPENDS = ""
#RDEPENDS of libprivilege-control-conf (${PN}-conf)
RDEPENDS_${PN}-conf += "libprivilege-control"

#RDEPENDS of libprivilege-control-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libprivilege-control"


DEPENDS = ""
#DEPENDS of libprivilege-control
DEPENDS_append_class-native = " cmake-native"
DEPENDS_append_class-target = " cmake-native"
DEPENDS += "tizen-platform-config"
DEPENDS += "dlog"
DEPENDS += "libiri"
DEPENDS += "smack"
DEPENDS += "sqlite3"
DEPENDS += "libcap"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libprivilege-control.manifest .
 
 
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
 
 
 export CFLAGS="${CFLAGS} -Wno-implicit-function-declaration"
 
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
         -DBUILD_SHARED_LIBS:BOOL=ON . -DCMAKE_BUILD_TYPE=RELEASE \
          -DCMAKE_VERBOSE_MAKEFILE=ON \
 	-DTZ_SYS_DB=${prefix}/dbspace \
 	-DTZ_SYS_HOME=/home
 
 VERBOSE=1 make -j16
 
 
 
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
 mkdir -p ${D}/usr/share/privilege-control/
 
 mkdir -p ${D}/usr/lib/systemd/system/multi-user.target.wants
 ln -sf /usr/lib/systemd/system/smack-rules.service ${D}/usr/lib/systemd/system/multi-user.target.wants/smack-rules.service
 mkdir -p ${D}${prefix}/dbspace
 
 sed -i 's|TZ_SYS_DB|${prefix}/dbspace|g' ${S}/packaging/libprivilege-control.manifest
 
 
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig
    /usr/share/privilege-control/db/updater.sh
    chsmack -a 'System' $D${prefix}/dbspace/.rules-db.db3*

}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libprivilege-control "
PACKAGES += " libprivilege-control-conf "
PACKAGES += " libprivilege-control-dev "

libprivilege-control_files = ""
libprivilege-control_files += "libprivilege-control.manifest"
libprivilege-control_files += "${prefix}/lib/*.so.*"
libprivilege-control_files += "${prefix}/lib/librules-db-sql-udf.so"
libprivilege-control_files += "/usr/lib/systemd/system/smack-rules.service"
libprivilege-control_files += "/usr/bin/api_feature_loader"
libprivilege-control_files += "/usr/lib/systemd/system/multi-user.target.wants/smack-rules.service"
libprivilege-control_files += "/usr/share/privilege-control/db/rules-db.sql"
libprivilege-control_files += "/usr/share/privilege-control/db/rules-db-data.sql"
libprivilege-control_files += "/usr/share/privilege-control/db/updater.sh"
libprivilege-control_files += "/usr/share/privilege-control/db/updates/*"
libprivilege-control_files += "/usr/share/privilege-control/db/load-rules-db.sql"
libprivilege-control_files += "/etc/opt/upgrade/220.libprivilege-updater.patch.sh"
libprivilege-control_files += "%dir ${prefix}/dbspace"

libprivilege-control-conf_files = ""
libprivilege-control-conf_files += "libprivilege-control.manifest"
libprivilege-control-conf_files += "${prefix}/dbspace/.privilege_control*.db"

libprivilege-control-dev_files = ""
libprivilege-control-dev_files += "libprivilege-control.manifest"
libprivilege-control-dev_files += "${prefix}/include/*.h"
libprivilege-control-dev_files += "${prefix}/lib/*.so"
libprivilege-control-dev_files += "${prefix}/lib/pkgconfig/*.pc"

FILES_${PN} = "${libprivilege-control_files}"
FILES_${PN}-conf = "${libprivilege-control-conf_files}"
FILES_${PN}-dev = "${libprivilege-control-dev_files}"

PKG_libprivilege-control= "libprivilege-control"
PKG_libprivilege-control-conf= "libprivilege-control-conf"
PKG_libprivilege-control-dev= "libprivilege-control-dev"

require libprivilege-control-extraconf.inc

