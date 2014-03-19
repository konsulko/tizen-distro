DESCRIPTION = "Telephony Vconf storage plugin"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tel-plugin-vconf 
PROVIDES += "tel-plugin-vconf"
RPROVIDES_tel-plugin-vconf += "tel-plugin-vconf"

RDEPENDS = ""
#RDEPENDS of tel-plugin-vconf (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of tel-plugin-vconf 
DEPENDS += "cmake"
DEPENDS += "libtcore"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(gthread-2.0)"
DEPENDS += "pkgconfig(vconf)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tel-plugin-vconf.manifest .
 
 
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
 
 versionint=$[0 * 1000000 + 1 * 1000 + 32]
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DVERSION=$versionint
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
 mkdir -p ${D}/usr/share/license
 
 
}

PACKAGES = ""
PACKAGES += "tel-plugin-vconf"

tel-plugin-vconf_files = ""
tel-plugin-vconf_files += "tel-plugin-vconf.manifest"
tel-plugin-vconf_files += "/usr/lib/telephony/plugins/vconf-plugin*"
tel-plugin-vconf_files += "/usr/share/license/tel-plugin-vconf"

FILES_${PN} = "${tel-plugin-vconf_files}"

PKG_tel-plugin-vconf= "tel-plugin-vconf"

require tel-plugin-vconf-extraconf.inc
