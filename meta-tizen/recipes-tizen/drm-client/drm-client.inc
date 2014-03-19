DESCRIPTION = "DRM client Package"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Security/Libraries"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by drm-client-devel 
PROVIDES += "drm-client-devel"
RPROVIDES_drm-client-devel += "drm-client-devel"
RPROVIDES_drm-client-devel += "drm-client-dev"

#PROVIDES by drm-client 
PROVIDES += "drm-client"
RPROVIDES_drm-client += "drm-client"

RDEPENDS = ""
#RDEPENDS of drm-client-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "drm-client"


DEPENDS = ""
#DEPENDS of drm-client 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "cmake"
DEPENDS += "common"
DEPENDS += "dlog"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/drm-client.manifest .
 
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "drm-client-devel"
PACKAGES += "drm-client"

drm-client-devel_files = ""
drm-client-devel_files += "drm-client.manifest"
drm-client-devel_files += "/usr/include/drm-client/*"
drm-client-devel_files += "/usr/lib/*.so"
drm-client-devel_files += "/usr/lib/pkgconfig/drm-client.pc"

drm-client_files = ""
drm-client_files += "drm-client.manifest"
drm-client_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${drm-client-devel_files}"
FILES_${PN} = "${drm-client_files}"

PKG_drm-client-devel= "drm-client-devel"
PKG_drm-client= "drm-client"

require drm-client-extraconf.inc
