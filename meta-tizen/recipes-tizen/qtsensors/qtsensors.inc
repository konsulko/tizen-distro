DESCRIPTION = "Qt Sensors module"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtsensors-devel 
PROVIDES += "qt5-qtsensors-devel"
RPROVIDES_qt5-qtsensors-devel += "qt5-qtsensors-devel"
RPROVIDES_qt5-qtsensors-devel += "qt5-qtsensors-dev"

#PROVIDES by qt5-qtsensors-plugin-gestures-sensor 
PROVIDES += "qt5-qtsensors-plugin-gestures-sensor"
RPROVIDES_qt5-qtsensors-plugin-gestures-sensor += "qt5-qtsensors-plugin-gestures-sensor"

#PROVIDES by qt5-qtsensors-plugin-gestures-shake 
PROVIDES += "qt5-qtsensors-plugin-gestures-shake"
RPROVIDES_qt5-qtsensors-plugin-gestures-shake += "qt5-qtsensors-plugin-gestures-shake"

#PROVIDES by qt5-qtdeclarative-import-sensors 
PROVIDES += "qt5-qtdeclarative-import-sensors"
RPROVIDES_qt5-qtdeclarative-import-sensors += "qt5-qtdeclarative-import-sensors"

#PROVIDES by qt5-qtsensors-plugin-tizen 
PROVIDES += "qt5-qtsensors-plugin-tizen"
RPROVIDES_qt5-qtsensors-plugin-tizen += "qt5-qtsensors-plugin-tizen"

#PROVIDES by qt5-qtsensors 
PROVIDES += "qt5-qtsensors"
RPROVIDES_qt5-qtsensors += "qt5-qtsensors"

#PROVIDES by qt5-qtsensors-plugin-generic 
PROVIDES += "qt5-qtsensors-plugin-generic"
RPROVIDES_qt5-qtsensors-plugin-generic += "qt5-qtsensors-plugin-generic"

RDEPENDS = ""
#RDEPENDS of qt5-qtsensors-devel (qt5-${PN}-devel)
RDEPENDS_qt5-${PN}-devel += "qt5-qtsensors"

#RDEPENDS of qt5-qtsensors-plugin-gestures-sensor (qt5-${PN}-plugin-gestures-sensor)
RDEPENDS_qt5-${PN}-plugin-gestures-sensor += "qt5-qtsensors"

#RDEPENDS of qt5-qtsensors-plugin-gestures-shake (qt5-${PN}-plugin-gestures-shake)
RDEPENDS_qt5-${PN}-plugin-gestures-shake += "qt5-qtsensors"

#RDEPENDS of qt5-qtdeclarative-import-sensors (qt5-qtdeclarative-import-sensors)
RDEPENDS_qt5-qtdeclarative-import-sensors += "qt5-qtsensors"
RDEPENDS_qt5-qtdeclarative-import-sensors += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtsensors-plugin-tizen (qt5-${PN}-plugin-tizen)
RDEPENDS_qt5-${PN}-plugin-tizen += "qt5-qtsensors"

#RDEPENDS of qt5-qtsensors-plugin-generic (qt5-${PN}-plugin-generic)
RDEPENDS_qt5-${PN}-plugin-generic += "qt5-qtsensors"


DEPENDS = ""
#DEPENDS of qt5-qtsensors 
DEPENDS += "pkgconfig(capi-system-sensor)"
DEPENDS += "fdupes-native"
DEPENDS += "qtdeclarative"
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtsensors-5.2.2/qtsensors
 
 
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
 touch .git
 qmake -qt=5 
 #CONFIG+=sensorfw
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
 # Remove unneeded .la files
 rm -f ${D}//usr/lib/*.la
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}//usr/include | 
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
PACKAGES += "qt5-qtsensors-devel"
PACKAGES += "qt5-qtsensors-plugin-generic"
PACKAGES += "qt5-qtsensors-plugin-gestures-shake"
PACKAGES += "qt5-qtdeclarative-import-sensors"
PACKAGES += "qt5-qtsensors-plugin-tizen"
PACKAGES += "qt5-qtsensors"
PACKAGES += "qt5-qtsensors-plugin-gestures-sensor"

qt5-qtsensors-devel_files = ""
qt5-qtsensors-devel_files += "/usr/lib/libQt5Sensors.so"
qt5-qtsensors-devel_files += "/usr/lib/libQt5Sensors.prl"
qt5-qtsensors-devel_files += "/usr/lib/pkgconfig/*"
qt5-qtsensors-devel_files += "/usr/include/qt5/*"
qt5-qtsensors-devel_files += "/usr/share/qt5/mkspecs"
qt5-qtsensors-devel_files += "/usr/lib/cmake"

qt5-qtsensors-plugin-generic_files = ""
qt5-qtsensors-plugin-generic_files += "/usr/lib/qt5/plugins/sensors/libqtsensors_generic.so"

qt5-qtsensors-plugin-gestures-shake_files = ""
qt5-qtsensors-plugin-gestures-shake_files += "/usr/lib/qt5/plugins/sensorgestures/libqtsensorgestures_shakeplugin.so"

qt5-qtdeclarative-import-sensors_files = ""
qt5-qtdeclarative-import-sensors_files += "/usr/lib/qt5/qml/QtSensors"

qt5-qtsensors-plugin-tizen_files = ""
qt5-qtsensors-plugin-tizen_files += "/usr/lib/qt5/plugins/sensors/libqtsensors_tizen.so"

qt5-qtsensors_files = ""
qt5-qtsensors_files += "/usr/lib/libQt5Sensors.so.5"
qt5-qtsensors_files += "/usr/lib/libQt5Sensors.so.5.*"

qt5-qtsensors-plugin-gestures-sensor_files = ""
qt5-qtsensors-plugin-gestures-sensor_files += "/usr/lib/qt5/plugins/sensorgestures/libqtsensorgestures_plugin.so"

FILES_${PN}-devel = "${qt5-qtsensors-devel_files}"
FILES_${PN}-plugin-generic = "${qt5-qtsensors-plugin-generic_files}"
FILES_${PN}-plugin-gestures-shake = "${qt5-qtsensors-plugin-gestures-shake_files}"
FILES_qt5-qtdeclarative-import-sensors = "${qt5-qtdeclarative-import-sensors_files}"
FILES_${PN}-plugin-tizen = "${qt5-qtsensors-plugin-tizen_files}"
FILES_${PN} = "${qt5-qtsensors_files}"
FILES_${PN}-plugin-gestures-sensor = "${qt5-qtsensors-plugin-gestures-sensor_files}"

PKG_qt5-qtsensors-devel= "qt5-qtsensors-devel"
PKG_qt5-qtsensors-plugin-generic= "qt5-qtsensors-plugin-generic"
PKG_qt5-qtsensors-plugin-gestures-shake= "qt5-qtsensors-plugin-gestures-shake"
PKG_qt5-qtdeclarative-import-sensors= "qt5-qtdeclarative-import-sensors"
PKG_qt5-qtsensors-plugin-tizen= "qt5-qtsensors-plugin-tizen"
PKG_qt5-qtsensors= "qt5-qtsensors"
PKG_qt5-qtsensors-plugin-gestures-sensor= "qt5-qtsensors-plugin-gestures-sensor"

require qtsensors-extraconf.inc
