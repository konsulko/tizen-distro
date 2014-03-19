DESCRIPTION = "Qt Imageformats"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtimageformats 
PROVIDES += "qt5-qtimageformats"
RPROVIDES_qt5-qtimageformats += "qt5-qtimageformats"

#PROVIDES by qt5-qtimageformats-plugin-wbmp 
PROVIDES += "qt5-qtimageformats-plugin-wbmp"
RPROVIDES_qt5-qtimageformats-plugin-wbmp += "qt5-qtimageformats-plugin-wbmp"

#PROVIDES by qt5-qtimageformats-plugin-mng 
PROVIDES += "qt5-qtimageformats-plugin-mng"
RPROVIDES_qt5-qtimageformats-plugin-mng += "qt5-qtimageformats-plugin-mng"

#PROVIDES by qt5-qtimageformats-devel 
PROVIDES += "qt5-qtimageformats-devel"
RPROVIDES_qt5-qtimageformats-devel += "qt5-qtimageformats-devel"
RPROVIDES_qt5-qtimageformats-devel += "qt5-qtimageformats-dev"

#PROVIDES by qt5-qtimageformats-plugin-tiff 
PROVIDES += "qt5-qtimageformats-plugin-tiff"
RPROVIDES_qt5-qtimageformats-plugin-tiff += "qt5-qtimageformats-plugin-tiff"

#PROVIDES by qt5-qtimageformats-plugin-tga 
PROVIDES += "qt5-qtimageformats-plugin-tga"
RPROVIDES_qt5-qtimageformats-plugin-tga += "qt5-qtimageformats-plugin-tga"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of qt5-qtimageformats 
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtimageformats-5.2.2/qtimageformats
 
 
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
 
 export QTDIR=/usr/share/qt5
 touch .git # Make sure syncqt is run
 
 qmake -qt=5
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
 %qmake5_install
 
 
}

PACKAGES = ""
PACKAGES += "qt5-qtimageformats-plugin-tiff"
PACKAGES += "qt5-qtimageformats-plugin-mng"
PACKAGES += "qt5-qtimageformats-plugin-wbmp"
PACKAGES += "qt5-qtimageformats-devel"
PACKAGES += "qt5-qtimageformats-plugin-tga"

qt5-qtimageformats-plugin-tiff_files = ""
qt5-qtimageformats-plugin-tiff_files += "/usr/lib/qt5/plugins/imageformats/libqtiff.so"

qt5-qtimageformats-plugin-mng_files = ""
qt5-qtimageformats-plugin-mng_files += "/usr/lib/qt5/plugins/imageformats/libqmng.so"

qt5-qtimageformats-plugin-wbmp_files = ""
qt5-qtimageformats-plugin-wbmp_files += "/usr/lib/qt5/plugins/imageformats/libqwbmp.so"

qt5-qtimageformats-devel_files = ""
qt5-qtimageformats-devel_files += "/usr/lib/cmake"

qt5-qtimageformats-plugin-tga_files = ""
qt5-qtimageformats-plugin-tga_files += "/usr/lib/qt5/plugins/imageformats/libqtga.so"

FILES_${PN}-plugin-tiff = "${qt5-qtimageformats-plugin-tiff_files}"
FILES_${PN}-plugin-mng = "${qt5-qtimageformats-plugin-mng_files}"
FILES_${PN}-plugin-wbmp = "${qt5-qtimageformats-plugin-wbmp_files}"
FILES_${PN}-devel = "${qt5-qtimageformats-devel_files}"
FILES_${PN}-plugin-tga = "${qt5-qtimageformats-plugin-tga_files}"

PKG_qt5-qtimageformats-plugin-tiff= "qt5-qtimageformats-plugin-tiff"
PKG_qt5-qtimageformats-plugin-mng= "qt5-qtimageformats-plugin-mng"
PKG_qt5-qtimageformats-plugin-wbmp= "qt5-qtimageformats-plugin-wbmp"
PKG_qt5-qtimageformats-devel= "qt5-qtimageformats-devel"
PKG_qt5-qtimageformats-plugin-tga= "qt5-qtimageformats-plugin-tga"

require qtimageformats-extraconf.inc
