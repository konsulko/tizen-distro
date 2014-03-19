DESCRIPTION = "App utility library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by aul 
PROVIDES += "aul"
RPROVIDES_aul += "aul"

#PROVIDES by aul-devel 
PROVIDES += "aul-devel"
RPROVIDES_aul-devel += "aul-devel"
RPROVIDES_aul-devel += "aul-dev"

RDEPENDS = ""
#RDEPENDS of aul (aul)
RDEPENDS_aul += "/usr/bin/systemctl"
RDEPENDS_aul += "/sbin/ldconfig"

#RDEPENDS of aul-devel (aul-devel)
RDEPENDS_aul-devel += "aul"


DEPENDS = ""
#DEPENDS of aul 
DEPENDS += "pkgconfig(libprivilege-control)"
DEPENDS += "pkgconfig(rua)"
DEPENDS += "cmake"
DEPENDS += "pkgconfig(ecore)"
DEPENDS += "pkgconfig(ecore-input)"
DEPENDS += "pkgconfig(pkgmgr-info)"
DEPENDS += "pkgconfig(xdgmime)"
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "ail"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "xdgmime-devel"
DEPENDS += "app-checker"
DEPENDS += "pkgconfig(ecore-wayland)"
DEPENDS += "pkgconfig(bundle)"
DEPENDS += "pkgconfig(privacy-manager-client)"
DEPENDS += "pkgconfig(dlog)"
DEPENDS += "pkgconfig(libsmack)"
DEPENDS += "pkgconfig(vconf)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/aul.manifest .
 
 
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
 
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DWITH_WAYLAND=On
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -p ${D}/etc/init.d
 install -m 755 launchpad_run ${D}/etc/init.d
 
 mkdir -p ${D}/etc/rc.d/rc3.d
 mkdir -p ${D}/etc/rc.d/rc4.d
 ln -sf ../../init.d/launchpad_run ${D}//etc/rc.d/rc3.d/S34launchpad_run
 ln -sf ../../init.d/launchpad_run ${D}//etc/rc.d/rc4.d/S80launchpad_run
 
 mkdir -p ${D}/opt/dbspace
 sqlite3 ${D}/opt/dbspace/.mida.db < ${D}/usr/share/aul/mida_db.sql
 rm -rf ${D}/usr/share/aul/mida_db.sql
 
 mkdir -p ${D}/usr/lib/systemd/system/graphical.target.wants
 install -m 0644 ${S}/packaging/launchpad-preload@.service ${D}/usr/lib/systemd/system/launchpad-preload@.service
 install -m 0644 ${S}/packaging/ac.service ${D}/usr/lib/systemd/system/ac.service
 ln -s ../launchpad-preload@.service ${D}/usr/lib/systemd/system/graphical.target.wants/launchpad-preload@app.service
 ln -s ../ac.service ${D}/usr/lib/systemd/system/graphical.target.wants/ac.service
 
 mkdir -p ${D}/opt/etc/smack/accesses.d
 install -m 644 aul.rule ${D}/opt/etc/smack/accesses.d
 
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/aul
 
 
 
}

PACKAGES = ""
PACKAGES += "aul"
PACKAGES += "aul-devel"

aul_files = ""
aul_files += "aul.manifest"
aul_files += "/etc/init.d/launchpad_run"
#Remove rpm attribut "%attr(0644,root,app)"
aul_files += "/opt/dbspace/.mida.db"
#Remove rpm attribut "%attr(0644,root,app)"
aul_files += "/opt/dbspace/.mida.db-journal"
aul_files += "/usr/bin/aul_test"
aul_files += "/usr/bin/launch_app"
aul_files += "/usr/bin/open_app"
aul_files += "/usr/share/aul/miregex/*"
aul_files += "/usr/share/aul/service/*"
aul_files += "/usr/share/aul/preload_list.txt"
aul_files += "/usr/share/aul/preexec_list.txt"
aul_files += "/usr/bin/launchpad_preloading_preinitializing_daemon"
aul_files += "/usr/lib/systemd/system/graphical.target.wants/launchpad-preload@app.service"
aul_files += "/usr/lib/systemd/system/graphical.target.wants/ac.service"
aul_files += "/usr/lib/systemd/system/launchpad-preload@.service"
aul_files += "/usr/lib/systemd/system/ac.service"
aul_files += "/usr/bin/amd"
aul_files += "/usr/bin/daemon-manager-release-agent"
aul_files += "/usr/bin/daemon-manager-launch-agent"
aul_files += "/opt/etc/smack/accesses.d/aul.rule"
aul_files += "/usr/share/license/aul"

aul-devel_files = ""
aul-devel_files += "/usr/include/aul/*.h"
aul-devel_files += "/usr/lib/*.so"
aul-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${aul_files}"
FILES_${PN}-devel = "${aul-devel_files}"

PKG_aul= "aul"
PKG_aul-devel= "aul-devel"

require aul-1-extraconf.inc
