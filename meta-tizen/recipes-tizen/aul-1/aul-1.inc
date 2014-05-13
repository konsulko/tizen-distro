DESCRIPTION = "App utility library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

PROVIDES = ""

#PROVIDES by aul 


#PROVIDES by aul-dev 


RDEPENDS = ""
#RDEPENDS of aul (aul)
RDEPENDS_aul += "eglibc"
RDEPENDS_aul += "systemd"

#RDEPENDS of aul-dev (aul-dev)
RDEPENDS_aul-dev += "aul"


DEPENDS = ""
#DEPENDS of aul 
DEPENDS += "pkgmgr-info"
DEPENDS += "librua"
DEPENDS_append_class-native = " cmake-native"
DEPENDS += "attr"
DEPENDS += "dbus"
DEPENDS += "tizen-platform-config"
DEPENDS += "dlog"
DEPENDS += "xdgmime"
DEPENDS += "ail"
DEPENDS += "bundle"
DEPENDS += "sqlite3"
DEPENDS += "ecore"
DEPENDS += "libprivilege-control"
DEPENDS += "app-checker"
DEPENDS += "vconf"
DEPENDS += "privacy-manager"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/aul.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DWITH_WAYLAND=On
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/etc/init.d
 install -m 755 launchpad_run ${D}/etc/init.d
 
 mkdir -p ${D}/etc/rc.d/rc3.d
 mkdir -p ${D}/etc/rc.d/rc4.d
 ln -sf ../../init.d/launchpad_run ${D}/${sysconfdir}/rc.d/rc3.d/S34launchpad_run
 ln -sf ../../init.d/launchpad_run ${D}/${sysconfdir}/rc.d/rc4.d/S80launchpad_run
 
 mkdir -p ${D}%{TZ_SYS_DB}
 sqlite3 ${D}%{TZ_SYS_DB}/.mida.db < ${D}/usr/share/aul/mida_db.sql
 rm -rf ${D}/usr/share/aul/mida_db.sql
 
 mkdir -p ${D}/usr/lib/systemd/system/graphical.target.wants
 install -m 0644 ${S}/packaging/launchpad-preload@.service ${D}/usr/lib/systemd/system/launchpad-preload@.service
 install -m 0644 ${S}/packaging/ac.service ${D}/usr/lib/systemd/system/ac.service
 ln -s ../launchpad-preload@.service ${D}/usr/lib/systemd/system/graphical.target.wants/launchpad-preload@5000.service
 ln -s ../ac.service ${D}/usr/lib/systemd/system/graphical.target.wants/ac.service
 
 mkdir -p ${D}%{TZ_SYS_SMACK}/accesses.d
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/aul
 
 
 
}

PACKAGES += " aul "
PACKAGES += " aul-dev "

aul_files = ""
aul_files += "aul.manifest"
aul_files += "${prefix}/lib/libaul.so.0"
aul_files += "${prefix}/lib/libaul.so.0.1.0"
aul_files += "${sysconfdir}/init.d/launchpad_run"
aul_files += "${prefix}/bin/aul_service.sh"
aul_files += "${prefix}/bin/aul_service_test.sh"
aul_files += "${sysconfdir}/rc.d/rc3.d/S34launchpad_run"
aul_files += "${sysconfdir}/rc.d/rc4.d/S80launchpad_run"
aul_files += "%attr(0644,root,%{TZ_SYS_USER_GROUP}) %{TZ_SYS_DB}/.mida.db"
aul_files += "%attr(0644,root,%{TZ_SYS_USER_GROUP}) %{TZ_SYS_DB}/.mida.db-journal"
aul_files += "${prefix}/bin/aul_mime.sh"
aul_files += "${prefix}/bin/aul_test"
aul_files += "${prefix}/bin/launch_app"
aul_files += "${prefix}/bin/open_app"
aul_files += "/usr/share/aul/miregex/*"
aul_files += "/usr/share/aul/service/*"
aul_files += "/usr/share/aul/preload_list.txt"
aul_files += "/usr/share/aul/preexec_list.txt"
aul_files += "${prefix}/bin/launchpad_preloading_preinitializing_daemon"
aul_files += "/usr/lib/systemd/system/graphical.target.wants/launchpad-preload@5000.service"
aul_files += "/usr/lib/systemd/system/graphical.target.wants/ac.service"
aul_files += "/usr/lib/systemd/system/launchpad-preload@.service"
aul_files += "/usr/lib/systemd/system/ac.service"
aul_files += "/usr/bin/amd"
aul_files += "/usr/bin/daemon-manager-release-agent"
aul_files += "/usr/bin/daemon-manager-launch-agent"
aul_files += "/usr/share/license/aul"

aul-dev_files = ""
aul-dev_files += "/usr/include/aul/*.h"
aul-dev_files += "${prefix}/lib/*.so"
aul-dev_files += "${prefix}/lib/pkgconfig/*.pc"

FILES_${PN} = "${aul_files}"
FILES_${PN}-dev = "${aul-dev_files}"

PKG_aul= "aul"
PKG_aul-dev= "aul-dev"

require aul-1-extraconf.inc

