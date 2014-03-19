DESCRIPTION = "Qt Wayland compositor"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtwayland 
PROVIDES += "qt5-qtwayland"
RPROVIDES_qt5-qtwayland += "qt5-qtwayland"

#PROVIDES by qt5-qtwayland-devel 
PROVIDES += "qt5-qtwayland-devel"
RPROVIDES_qt5-qtwayland-devel += "qt5-qtwayland-devel"
RPROVIDES_qt5-qtwayland-devel += "qt5-qtwayland-dev"

RDEPENDS = ""
#RDEPENDS of qt5-qtwayland-devel (qt5-${PN}-devel)
RDEPENDS_qt5-${PN}-devel += "qt5-qtwayland"


DEPENDS = ""
#DEPENDS of qt5-qtwayland 
DEPENDS += "pkgconfig(wayland-cursor)"
DEPENDS += "libxkbcommon"
DEPENDS += "pkgconfig(wayland-client)"
DEPENDS += "pkgconfig(mtdev)"
DEPENDS += "libffi"
DEPENDS += "mesa"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "qtbase"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtwayland-5.2.2/qtwayland
 
 
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
 export QT_WAYLAND_GL_CONFIG=wayland_egl
 touch .git
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
 %qmake_install
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/include | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
 #### Pre/Post section
 
 
}

PACKAGES = ""
PACKAGES += "qt5-qtwayland"
PACKAGES += "qt5-qtwayland-devel"

qt5-qtwayland_files = ""
qt5-qtwayland_files += "/usr/lib/libQt5WaylandClient.so.5*"
qt5-qtwayland_files += "/usr/lib/qt5/plugins/platforms/libqwayland-generic.so"
qt5-qtwayland_files += "/usr/lib/qt5/plugins/platforms/libqwayland-egl.so"
qt5-qtwayland_files += "/usr/lib/qt5/plugins/wayland-graphics-integration/client/libwayland-egl.so"
qt5-qtwayland_files += "/usr/lib/qt5/plugins/wayland-graphics-integration/client/libdrm-egl-server.so"

qt5-qtwayland-devel_files = ""
qt5-qtwayland-devel_files += "/usr/lib/libQt5WaylandClient.so"
qt5-qtwayland-devel_files += "/usr/include/qt5/*"
qt5-qtwayland-devel_files += "/usr/lib/libQt5WaylandClient.la"
qt5-qtwayland-devel_files += "/usr/lib/libQt5WaylandClient.prl"
qt5-qtwayland-devel_files += "/usr/lib/pkgconfig/Qt5WaylandClient.pc"
qt5-qtwayland-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_waylandclient.pri"
qt5-qtwayland-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri"
qt5-qtwayland-devel_files += "/usr/lib/qt5/bin/qtwaylandscanner"
qt5-qtwayland-devel_files += "/usr/lib/cmake"

FILES_${PN} = "${qt5-qtwayland_files}"
FILES_${PN}-devel = "${qt5-qtwayland-devel_files}"

PKG_qt5-qtwayland= "qt5-qtwayland"
PKG_qt5-qtwayland-devel= "qt5-qtwayland-devel"

require qtwayland-extraconf.inc
