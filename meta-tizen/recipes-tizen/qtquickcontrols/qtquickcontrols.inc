DESCRIPTION = "Qt Quick Controls"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtquickcontrols 
PROVIDES += "qt5-qtquickcontrols"
RPROVIDES_qt5-qtquickcontrols += "qt5-qtquickcontrols"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of qt5-qtquickcontrols 
DEPENDS += "fdupes-native"
DEPENDS += "qtdeclarative"
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtquickcontrols-5.2.2
 
 
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
 touch .git # To make sure syncqt is used
 
 %qmake5
 make 
 
 
 
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
 
 #### Pre/Post section
 
 
}

PACKAGES = ""
PACKAGES += "qt5-qtquickcontrols"

qt5-qtquickcontrols_files = ""
qt5-qtquickcontrols_files += "/usr/lib/qt5/qml/QtQuick/Controls"
qt5-qtquickcontrols_files += "/usr/lib/qt5/qml/QtQuick/Layouts"

FILES_${PN} = "${qt5-qtquickcontrols_files}"

PKG_qt5-qtquickcontrols= "qt5-qtquickcontrols"

require qtquickcontrols-extraconf.inc
