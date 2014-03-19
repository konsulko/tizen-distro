DESCRIPTION = "Telephony Packet Service library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tel-plugin-packetservice 
PROVIDES += "tel-plugin-packetservice"
RPROVIDES_tel-plugin-packetservice += "tel-plugin-packetservice"

RDEPENDS = ""
#RDEPENDS of tel-plugin-packetservice (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of tel-plugin-packetservice 
DEPENDS += "cmake"
DEPENDS += "libtcore"
DEPENDS += "pkgconfig(libtzplatform-config)"
DEPENDS += "dlog"
DEPENDS += "pkgconfig(iniparser)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tel-plugin-packetservice.manifest .
 
 
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
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake . -DSYSCONFDIR=/etc
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
 cp LICENSE ${D}/usr/share/license/tel-plugin-packetservice
 
 
}

PACKAGES = ""
PACKAGES += "tel-plugin-packetservice"

tel-plugin-packetservice_files = ""
tel-plugin-packetservice_files += "tel-plugin-packetservice.manifest"
tel-plugin-packetservice_files += "/usr/share/ps-plugin/dnet_db.sql"
tel-plugin-packetservice_files += "/usr/share/ps-plugin/dnet_db_data.sql"
tel-plugin-packetservice_files += "/etc/dbus-1/system.d/*"
tel-plugin-packetservice_files += "/usr/lib/telephony/plugins/ps-plugin*"
tel-plugin-packetservice_files += "/usr/share/license/tel-plugin-packetservice"

FILES_${PN} = "${tel-plugin-packetservice_files}"

PKG_tel-plugin-packetservice= "tel-plugin-packetservice"

require tel-plugin-packetservice-extraconf.inc
