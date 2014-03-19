DESCRIPTION = "Development tools for Qt"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qttools-qdbus 
PROVIDES += "qt5-qttools-qdbus"
RPROVIDES_qt5-qttools-qdbus += "qt5-qttools-qdbus"

#PROVIDES by qt5-qttools-pixeltool 
PROVIDES += "qt5-qttools-pixeltool"
RPROVIDES_qt5-qttools-pixeltool += "qt5-qttools-pixeltool"

#PROVIDES by qt5-qttools 
PROVIDES += "qt5-qttools"
RPROVIDES_qt5-qttools += "qt5-qttools"

#PROVIDES by qt5-qttools-linguist 
PROVIDES += "qt5-qttools-linguist"
RPROVIDES_qt5-qttools-linguist += "qt5-qttools-linguist"

#PROVIDES by qt5-qttools-qtclucene 
PROVIDES += "qt5-qttools-qtclucene"
RPROVIDES_qt5-qttools-qtclucene += "qt5-qttools-qtclucene"

#PROVIDES by qt5-qttools-qtdesigner 
PROVIDES += "qt5-qttools-qtdesigner"
RPROVIDES_qt5-qttools-qtdesigner += "qt5-qttools-qtdesigner"

#PROVIDES by qt5-qttools-qthelp 
PROVIDES += "qt5-qttools-qthelp"
RPROVIDES_qt5-qttools-qthelp += "qt5-qttools-qthelp"

#PROVIDES by qt5-qttools-qthelp-devel 
PROVIDES += "qt5-qttools-qthelp-devel"
RPROVIDES_qt5-qttools-qthelp-devel += "qt5-qttools-qthelp-devel"
RPROVIDES_qt5-qttools-qthelp-devel += "qt5-qttools-qthelp-dev"

#PROVIDES by qt5-qttools-qtuitools 
PROVIDES += "qt5-qttools-qtuitools"
RPROVIDES_qt5-qttools-qtuitools += "qt5-qttools-qtuitools"

#PROVIDES by qt5-qttools-qtuitools-devel 
PROVIDES += "qt5-qttools-qtuitools-devel"
RPROVIDES_qt5-qttools-qtuitools-devel += "qt5-qttools-qtuitools-devel"
RPROVIDES_qt5-qttools-qtuitools-devel += "qt5-qttools-qtuitools-dev"

#PROVIDES by qt5-qttools-qtclucene-devel 
PROVIDES += "qt5-qttools-qtclucene-devel"
RPROVIDES_qt5-qttools-qtclucene-devel += "qt5-qttools-qtclucene-devel"
RPROVIDES_qt5-qttools-qtclucene-devel += "qt5-qttools-qtclucene-dev"

#PROVIDES by qt5-qttools-qtdesigner-devel 
PROVIDES += "qt5-qttools-qtdesigner-devel"
RPROVIDES_qt5-qttools-qtdesigner-devel += "qt5-qttools-qtdesigner-devel"
RPROVIDES_qt5-qttools-qtdesigner-devel += "qt5-qttools-qtdesigner-dev"

RDEPENDS = ""
#RDEPENDS of qt5-qttools-qdbus (qt5-${PN}-qdbus)
RDEPENDS_qt5-${PN}-qdbus += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-qdbus += "qt5-qttools"

#RDEPENDS of qt5-qttools-pixeltool (qt5-${PN}-pixeltool)
RDEPENDS_qt5-${PN}-pixeltool += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-pixeltool += "qt5-qttools"

#RDEPENDS of qt5-qttools-linguist (qt5-${PN}-linguist)
RDEPENDS_qt5-${PN}-linguist += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-linguist += "qt5-qttools"

#RDEPENDS of qt5-qttools-qtclucene (qt5-${PN}-qtclucene)
RDEPENDS_qt5-${PN}-qtclucene += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-qtclucene += "qt5-qttools"

#RDEPENDS of qt5-qttools-qtdesigner (qt5-${PN}-qtdesigner)
RDEPENDS_qt5-${PN}-qtdesigner += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-qtdesigner += "qt5-qttools"

#RDEPENDS of qt5-qttools-qthelp (qt5-${PN}-qthelp)
RDEPENDS_qt5-${PN}-qthelp += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-qthelp += "qt5-qttools"

#RDEPENDS of qt5-qttools-qthelp-devel (qt5-${PN}-qthelp-devel)
RDEPENDS_qt5-${PN}-qthelp-devel += "/sbin/ldconfig"

#RDEPENDS of qt5-qttools-qtuitools (qt5-${PN}-qtuitools)
RDEPENDS_qt5-${PN}-qtuitools += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-qtuitools += "qt5-qttools"

#RDEPENDS of qt5-qttools-qtuitools-devel (qt5-${PN}-qtuitools-devel)
RDEPENDS_qt5-${PN}-qtuitools-devel += "/sbin/ldconfig"

#RDEPENDS of qt5-qttools-qtclucene-devel (qt5-${PN}-qtclucene-devel)
RDEPENDS_qt5-${PN}-qtclucene-devel += "/sbin/ldconfig"

#RDEPENDS of qt5-qttools-qtdesigner-devel (qt5-${PN}-qtdesigner-devel)
RDEPENDS_qt5-${PN}-qtdesigner-devel += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of qt5-qttools 
DEPENDS += "fdupes-native"
DEPENDS += "qtdeclarative"
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qttools-5.2.2/qttools
 
 
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
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/lib | 
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
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/share | 
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
PACKAGES += "qt5-qttools-qdbus"
PACKAGES += "qt5-qttools-qtuitools"
PACKAGES += "qt5-qttools"
PACKAGES += "qt5-qttools-linguist"
PACKAGES += "qt5-qttools-qtclucene"
PACKAGES += "qt5-qttools-qtdesigner"
PACKAGES += "qt5-qttools-qthelp"
PACKAGES += "qt5-qttools-qthelp-devel"
PACKAGES += "qt5-qttools-pixeltool"
PACKAGES += "qt5-qttools-qtuitools-devel"
PACKAGES += "qt5-qttools-qtclucene-devel"
PACKAGES += "qt5-qttools-qtdesigner-devel"

qt5-qttools-qdbus_files = ""

qt5-qttools-qtuitools_files = ""

qt5-qttools_files = ""

qt5-qttools-linguist_files = ""
qt5-qttools-linguist_files += "/usr/share/qt5/phrasebooks"
qt5-qttools-linguist_files += "/usr/lib/cmake/Qt5Linguist*"

qt5-qttools-qtclucene_files = ""
qt5-qttools-qtclucene_files += "/usr/lib/libQt5CLucene.so.*"

qt5-qttools-qtdesigner_files = ""
qt5-qttools-qtdesigner_files += "/usr/lib/libQt5Designer*.so.*"

qt5-qttools-qthelp_files = ""
qt5-qttools-qthelp_files += "/usr/lib/libQt5Help.so.*"

qt5-qttools-qthelp-devel_files = ""
qt5-qttools-qthelp-devel_files += "/usr/include/qt5/QtHelp"
qt5-qttools-qthelp-devel_files += "/usr/lib/libQt5Help.prl"
qt5-qttools-qthelp-devel_files += "/usr/lib/libQt5Help.la"
qt5-qttools-qthelp-devel_files += "/usr/lib/libQt5Help.so"
qt5-qttools-qthelp-devel_files += "/usr/lib/pkgconfig/Qt5Help.pc"
qt5-qttools-qthelp-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_help.pri"
qt5-qttools-qthelp-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_help_private.pri"
qt5-qttools-qthelp-devel_files += "/usr/lib/cmake/Qt5Help"

qt5-qttools-pixeltool_files = ""

qt5-qttools-qtuitools-devel_files = ""
qt5-qttools-qtuitools-devel_files += "/usr/include/qt5/QtUiTools"
qt5-qttools-qtuitools-devel_files += "/usr/lib/libQt5UiTools.prl"
qt5-qttools-qtuitools-devel_files += "/usr/lib/libQt5UiTools.a"
qt5-qttools-qtuitools-devel_files += "/usr/lib/libQt5UiTools.la"
qt5-qttools-qtuitools-devel_files += "/usr/lib/pkgconfig/Qt5UiTools.pc"
qt5-qttools-qtuitools-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_uitools.pri"
qt5-qttools-qtuitools-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_uitools_private.pri"
qt5-qttools-qtuitools-devel_files += "/usr/lib/cmake/Qt5UiTools"

qt5-qttools-qtclucene-devel_files = ""
qt5-qttools-qtclucene-devel_files += "/usr/include/qt5/QtCLucene"
qt5-qttools-qtclucene-devel_files += "/usr/lib/libQt5CLucene.prl"
qt5-qttools-qtclucene-devel_files += "/usr/lib/libQt5CLucene.la"
qt5-qttools-qtclucene-devel_files += "/usr/lib/libQt5CLucene.so"
qt5-qttools-qtclucene-devel_files += "/usr/lib/pkgconfig/Qt5CLucene.pc"
qt5-qttools-qtclucene-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_clucene_private.pri"
qt5-qttools-qtclucene-devel_files += ""

qt5-qttools-qtdesigner-devel_files = ""
qt5-qttools-qtdesigner-devel_files += "/usr/include/qt5/QtDesigner"
qt5-qttools-qtdesigner-devel_files += "/usr/include/qt5/QtDesignerComponents"
qt5-qttools-qtdesigner-devel_files += "/usr/lib/libQt5Designer*.so"
qt5-qttools-qtdesigner-devel_files += "/usr/lib/libQt5Designer*.prl"
qt5-qttools-qtdesigner-devel_files += "/usr/lib/libQt5Designer*.la"
qt5-qttools-qtdesigner-devel_files += "/usr/lib/libQt5Designer*.prl"
qt5-qttools-qtdesigner-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_designer*.pri"
qt5-qttools-qtdesigner-devel_files += "/usr/lib/pkgconfig/Qt5Designer*.pc"
qt5-qttools-qtdesigner-devel_files += "/usr/lib/cmake/Qt5Designer"

FILES_${PN}-qdbus = "${qt5-qttools-qdbus_files}"
FILES_${PN}-qtuitools = "${qt5-qttools-qtuitools_files}"
FILES_${PN} = "${qt5-qttools_files}"
FILES_${PN}-linguist = "${qt5-qttools-linguist_files}"
FILES_${PN}-qtclucene = "${qt5-qttools-qtclucene_files}"
FILES_${PN}-qtdesigner = "${qt5-qttools-qtdesigner_files}"
FILES_${PN}-qthelp = "${qt5-qttools-qthelp_files}"
FILES_${PN}-qthelp-devel = "${qt5-qttools-qthelp-devel_files}"
FILES_${PN}-pixeltool = "${qt5-qttools-pixeltool_files}"
FILES_${PN}-qtuitools-devel = "${qt5-qttools-qtuitools-devel_files}"
FILES_${PN}-qtclucene-devel = "${qt5-qttools-qtclucene-devel_files}"
FILES_${PN}-qtdesigner-devel = "${qt5-qttools-qtdesigner-devel_files}"

PKG_qt5-qttools-qdbus= "qt5-qttools-qdbus"
PKG_qt5-qttools-qtuitools= "qt5-qttools-qtuitools"
PKG_qt5-qttools= "qt5-qttools"
PKG_qt5-qttools-linguist= "qt5-qttools-linguist"
PKG_qt5-qttools-qtclucene= "qt5-qttools-qtclucene"
PKG_qt5-qttools-qtdesigner= "qt5-qttools-qtdesigner"
PKG_qt5-qttools-qthelp= "qt5-qttools-qthelp"
PKG_qt5-qttools-qthelp-devel= "qt5-qttools-qthelp-devel"
PKG_qt5-qttools-pixeltool= "qt5-qttools-pixeltool"
PKG_qt5-qttools-qtuitools-devel= "qt5-qttools-qtuitools-devel"
PKG_qt5-qttools-qtclucene-devel= "qt5-qttools-qtclucene-devel"
PKG_qt5-qttools-qtdesigner-devel= "qt5-qttools-qtdesigner-devel"

require qttools-extraconf.inc
