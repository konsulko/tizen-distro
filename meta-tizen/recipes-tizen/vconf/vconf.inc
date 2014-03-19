DESCRIPTION = "Configuration system library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by vconf-keys-devel 
PROVIDES += "vconf-keys-devel"
RPROVIDES_vconf-keys-devel += "vconf-keys-devel"
RPROVIDES_vconf-keys-devel += "vconf-keys-dev"

#PROVIDES by vconf 
PROVIDES += "vconf"
RPROVIDES_vconf += "vconf"

#PROVIDES by vconf-devel 
PROVIDES += "vconf-devel"
RPROVIDES_vconf-devel += "vconf-devel"
RPROVIDES_vconf-devel += "vconf-dev"

RDEPENDS = ""
#RDEPENDS of vconf-keys-devel (${PN}-keys-devel)
RDEPENDS_${PN}-keys-devel += "vconf"
RDEPENDS_${PN}-keys-devel += "vconf-internal-keys-dev"

#RDEPENDS of vconf (${PN})
RDEPENDS_${PN} += "systemd"
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of vconf-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(glib-2.0)"
RDEPENDS_${PN}-devel += "vconf-keys-dev"
RDEPENDS_${PN}-devel += "vconf"


DEPENDS = ""
#DEPENDS of vconf 
DEPENDS += "pkgconfig(vconf-internal-keys)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n vconf-0.2.45
 cp ${S}/packaging/vconf.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake .
 
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/opt/var/kdb/db
 mkdir -p ${D}/opt/var/kdb/db/.backup
 mkdir -p ${D}/lib/systemd/system/basic.target.wants
 mkdir -p ${D}/usr/lib/tmpfiles.d
 install -m0644 ${S}/packaging/vconf-setup.service ${D}/lib/systemd/system/
 install -m0644 ${S}/packaging/vconf-setup.conf ${D}/usr/lib/tmpfiles.d/
 ln -sf ../vconf-setup.service ${D}/lib/systemd/system/basic.target.wants/
 
 
}

PACKAGES = ""
PACKAGES += "vconf-keys-devel"
PACKAGES += "vconf"
PACKAGES += "vconf-devel"

vconf-keys-devel_files = ""
vconf-keys-devel_files += "vconf.manifest"
vconf-keys-devel_files += "/usr/include/vconf/vconf-keys.h"

vconf_files = ""
vconf_files += "vconf.manifest"
vconf_files += "/usr/bin/vconftool"
vconf_files += "/usr/bin/vconf-init"
vconf_files += "/usr/lib/*.so.*"
#Remove rpm attribut "%attr(777,root,root)"
vconf_files += "/opt/var/kdb/db"
#Remove rpm attribut "%attr(777,root,root)"
vconf_files += "/opt/var/kdb/db/.backup"
vconf_files += "/lib/systemd/system/basic.target.wants/vconf-setup.service"
vconf_files += "/lib/systemd/system/vconf-setup.service"
vconf_files += "/usr/lib/tmpfiles.d/vconf-setup.conf"

vconf-devel_files = ""
vconf-devel_files += "vconf.manifest"
vconf-devel_files += "/usr/include/vconf/vconf.h"
vconf-devel_files += "/usr/lib/pkgconfig/*.pc"
vconf-devel_files += "/usr/lib/*.so"

FILES_${PN}-keys-devel = "${vconf-keys-devel_files}"
FILES_${PN} = "${vconf_files}"
FILES_${PN}-devel = "${vconf-devel_files}"

PKG_vconf-keys-devel= "vconf-keys-devel"
PKG_vconf= "vconf"
PKG_vconf-devel= "vconf-devel"

require vconf-extraconf.inc
