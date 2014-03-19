DESCRIPTION = "Meta Package for the OpenGL ES library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Graphics/Library"
LICENSE = "Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by opengl-es-devel 
PROVIDES += "opengl-es-devel"
RPROVIDES_opengl-es-devel += "opengl-es-devel"
RPROVIDES_opengl-es-devel += "opengl-es-dev"

#PROVIDES by opengl-es 
PROVIDES += "opengl-es"
RPROVIDES_opengl-es += "opengl-es"

RDEPENDS = ""
#RDEPENDS of opengl-es-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "opengl-es-drv-dev"
RDEPENDS_${PN}-devel += "opengl-es"

#RDEPENDS of opengl-es (${PN})
RDEPENDS_${PN} += "opengl-es-drv"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/opengl-es.manifest .
 
 
 
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
 
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 mkdir -p ${D}/usr/lib/pkgconfig
 cp -a ./"pkgconfig_arm"/*.pc ${D}/usr/lib/pkgconfig/
 
 
 
}

PACKAGES = ""
PACKAGES += "opengl-es-devel"
PACKAGES += "opengl-es"

opengl-es-devel_files = ""
opengl-es-devel_files += "opengl-es.manifest"
opengl-es-devel_files += "/usr/lib/pkgconfig/opengl-es-11.pc"
opengl-es-devel_files += "/usr/lib/pkgconfig/opengl-es-20.pc"

opengl-es_files = ""
opengl-es_files += "opengl-es.manifest"
opengl-es_files += "opengl-es.manifest"

FILES_${PN}-devel = "${opengl-es-devel_files}"
FILES_${PN} = "${opengl-es_files}"

PKG_opengl-es-devel= "opengl-es-devel"
PKG_opengl-es= "opengl-es"

require opengl-es-extraconf.inc
