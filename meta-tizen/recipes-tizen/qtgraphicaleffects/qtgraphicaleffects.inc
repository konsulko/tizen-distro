DESCRIPTION = "Qt Graphical Effects"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtgraphicaleffects 
PROVIDES += "qt5-qtgraphicaleffects"
RPROVIDES_qt5-qtgraphicaleffects += "qt5-qtgraphicaleffects"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of qt5-qtgraphicaleffects 
DEPENDS += "fdupes-native"
DEPENDS += "qtdeclarative"
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtgraphicaleffects-5.2.2/qtgraphicaleffects
 
 
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
 
 %qmake5 CONFIG+=package
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
 
 #### Pre/Post section
 
 
}

PACKAGES = ""
PACKAGES += "qt5-qtgraphicaleffects"

qt5-qtgraphicaleffects_files = ""
qt5-qtgraphicaleffects_files += "/usr/lib/qt5/qml/QtGraphicalEffects/*"

FILES_${PN} = "${qt5-qtgraphicaleffects_files}"

PKG_qt5-qtgraphicaleffects= "qt5-qtgraphicaleffects"

require qtgraphicaleffects-extraconf.inc
