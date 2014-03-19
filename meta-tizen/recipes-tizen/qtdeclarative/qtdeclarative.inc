DESCRIPTION = "Qt Declarative library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtdeclarative 
PROVIDES += "qt5-qtdeclarative"
RPROVIDES_qt5-qtdeclarative += "qt5-qtdeclarative"

#PROVIDES by qt5-qtdeclarative-import-folderlistmodel 
PROVIDES += "qt5-qtdeclarative-import-folderlistmodel"
RPROVIDES_qt5-qtdeclarative-import-folderlistmodel += "qt5-qtdeclarative-import-folderlistmodel"

#PROVIDES by qt5-qtdeclarative-devel 
PROVIDES += "qt5-qtdeclarative-devel"
RPROVIDES_qt5-qtdeclarative-devel += "qt5-qtdeclarative-devel"
RPROVIDES_qt5-qtdeclarative-devel += "qt5-qtdeclarative-dev"

#PROVIDES by qt5-qtdeclarative-import-qtquick2plugin 
PROVIDES += "qt5-qtdeclarative-import-qtquick2plugin"
RPROVIDES_qt5-qtdeclarative-import-qtquick2plugin += "qt5-qtdeclarative-import-qtquick2plugin"

#PROVIDES by qt5-qtdeclarative-qtquickparticles 
PROVIDES += "qt5-qtdeclarative-qtquickparticles"
RPROVIDES_qt5-qtdeclarative-qtquickparticles += "qt5-qtdeclarative-qtquickparticles"

#PROVIDES by qt5-qtdeclarative-import-xmllistmodel 
PROVIDES += "qt5-qtdeclarative-import-xmllistmodel"
RPROVIDES_qt5-qtdeclarative-import-xmllistmodel += "qt5-qtdeclarative-import-xmllistmodel"

#PROVIDES by qt5-qtdeclarative-import-settings 
PROVIDES += "qt5-qtdeclarative-import-settings"
RPROVIDES_qt5-qtdeclarative-import-settings += "qt5-qtdeclarative-import-settings"

#PROVIDES by qt5-qtdeclarative-plugin-accessible 
PROVIDES += "qt5-qtdeclarative-plugin-accessible"
RPROVIDES_qt5-qtdeclarative-plugin-accessible += "qt5-qtdeclarative-plugin-accessible"

#PROVIDES by qt5-qtdeclarative-import-dialogs 
PROVIDES += "qt5-qtdeclarative-import-dialogs"
RPROVIDES_qt5-qtdeclarative-import-dialogs += "qt5-qtdeclarative-import-dialogs"

#PROVIDES by qt5-qtdeclarative-qtquick-devel 
PROVIDES += "qt5-qtdeclarative-qtquick-devel"
RPROVIDES_qt5-qtdeclarative-qtquick-devel += "qt5-qtdeclarative-qtquick-devel"
RPROVIDES_qt5-qtdeclarative-qtquick-devel += "qt5-qtdeclarative-qtquick-dev"

#PROVIDES by qt5-qtdeclarative-devel-tools 
PROVIDES += "qt5-qtdeclarative-devel-tools"
RPROVIDES_qt5-qtdeclarative-devel-tools += "qt5-qtdeclarative-devel-tools"
RPROVIDES_qt5-qtdeclarative-devel-tools += "qt5-qtdeclarative-dev"

#PROVIDES by qt5-qtdeclarative-import-window2 
PROVIDES += "qt5-qtdeclarative-import-window2"
RPROVIDES_qt5-qtdeclarative-import-window2 += "qt5-qtdeclarative-import-window2"

#PROVIDES by qt5-qtdeclarative-qtdeclarativetools-devel 
PROVIDES += "qt5-qtdeclarative-qtdeclarativetools-devel"
RPROVIDES_qt5-qtdeclarative-qtdeclarativetools-devel += "qt5-qtdeclarative-qtdeclarativetools-devel"
RPROVIDES_qt5-qtdeclarative-qtdeclarativetools-devel += "qt5-qtdeclarative-qtdeclarativetools-dev"

#PROVIDES by qt5-qtdeclarative-import-models2 
PROVIDES += "qt5-qtdeclarative-import-models2"
RPROVIDES_qt5-qtdeclarative-import-models2 += "qt5-qtdeclarative-import-models2"

#PROVIDES by qt5-qtdeclarative-import-qttest 
PROVIDES += "qt5-qtdeclarative-import-qttest"
RPROVIDES_qt5-qtdeclarative-import-qttest += "qt5-qtdeclarative-import-qttest"

#PROVIDES by qt5-qtdeclarative-qmlscene 
PROVIDES += "qt5-qtdeclarative-qmlscene"
RPROVIDES_qt5-qtdeclarative-qmlscene += "qt5-qtdeclarative-qmlscene"

#PROVIDES by qt5-qtdeclarative-qtquicktest 
PROVIDES += "qt5-qtdeclarative-qtquicktest"
RPROVIDES_qt5-qtdeclarative-qtquicktest += "qt5-qtdeclarative-qtquicktest"

#PROVIDES by qt5-qtdeclarative-qtquicktest-devel 
PROVIDES += "qt5-qtdeclarative-qtquicktest-devel"
RPROVIDES_qt5-qtdeclarative-qtquicktest-devel += "qt5-qtdeclarative-qtquicktest-devel"
RPROVIDES_qt5-qtdeclarative-qtquicktest-devel += "qt5-qtdeclarative-qtquicktest-dev"

#PROVIDES by qt5-qtdeclarative-qtquick 
PROVIDES += "qt5-qtdeclarative-qtquick"
RPROVIDES_qt5-qtdeclarative-qtquick += "qt5-qtdeclarative-qtquick"

#PROVIDES by qt5-qtdeclarative-import-privatewidgets 
PROVIDES += "qt5-qtdeclarative-import-privatewidgets"
RPROVIDES_qt5-qtdeclarative-import-privatewidgets += "qt5-qtdeclarative-import-privatewidgets"

#PROVIDES by qt5-qtdeclarative-import-particles2 
PROVIDES += "qt5-qtdeclarative-import-particles2"
RPROVIDES_qt5-qtdeclarative-import-particles2 += "qt5-qtdeclarative-import-particles2"

#PROVIDES by qt5-qtdeclarative-plugin-qmlinspector 
PROVIDES += "qt5-qtdeclarative-plugin-qmlinspector"
RPROVIDES_qt5-qtdeclarative-plugin-qmlinspector += "qt5-qtdeclarative-plugin-qmlinspector"

#PROVIDES by qt5-qtdeclarative-qml 
PROVIDES += "qt5-qtdeclarative-qml"
RPROVIDES_qt5-qtdeclarative-qml += "qt5-qtdeclarative-qml"

#PROVIDES by qt5-qtdeclarative-qtquickparticles-devel 
PROVIDES += "qt5-qtdeclarative-qtquickparticles-devel"
RPROVIDES_qt5-qtdeclarative-qtquickparticles-devel += "qt5-qtdeclarative-qtquickparticles-devel"
RPROVIDES_qt5-qtdeclarative-qtquickparticles-devel += "qt5-qtdeclarative-qtquickparticles-dev"

#PROVIDES by qt5-qtdeclarative-import-localstorageplugin 
PROVIDES += "qt5-qtdeclarative-import-localstorageplugin"
RPROVIDES_qt5-qtdeclarative-import-localstorageplugin += "qt5-qtdeclarative-import-localstorageplugin"

RDEPENDS = ""
#RDEPENDS of qt5-qtdeclarative-import-folderlistmodel (qt5-${PN}-import-folderlistmodel)
RDEPENDS_qt5-${PN}-import-folderlistmodel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-devel (qt5-${PN}-devel)
RDEPENDS_qt5-${PN}-devel += "qt5-qtsql-dev"
RDEPENDS_qt5-${PN}-devel += "qt5-qtnetwork-dev"
RDEPENDS_qt5-${PN}-devel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-qtquick2plugin (qt5-${PN}-import-qtquick2plugin)
RDEPENDS_qt5-${PN}-import-qtquick2plugin += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtquickparticles (qt5-${PN}-qtquickparticles)
RDEPENDS_qt5-${PN}-qtquickparticles += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-xmllistmodel (qt5-${PN}-import-xmllistmodel)
RDEPENDS_qt5-${PN}-import-xmllistmodel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-settings (qt5-${PN}-import-settings)
RDEPENDS_qt5-${PN}-import-settings += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-plugin-accessible (qt5-${PN}-plugin-accessible)
RDEPENDS_qt5-${PN}-plugin-accessible += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-dialogs (qt5-${PN}-import-dialogs)
RDEPENDS_qt5-${PN}-import-dialogs += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtquick-devel (qt5-${PN}-qtquick-devel)
RDEPENDS_qt5-${PN}-qtquick-devel += "qt5-qtdeclarative-qtquick"
RDEPENDS_qt5-${PN}-qtquick-devel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-devel-tools (qt5-${PN}-devel-tools)
RDEPENDS_qt5-${PN}-devel-tools += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-window2 (qt5-${PN}-import-window2)
RDEPENDS_qt5-${PN}-import-window2 += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtdeclarativetools-devel (qt5-${PN}-${PN}tools-devel)
RDEPENDS_qt5-${PN}-${PN}tools-devel += "qt5-qtdeclarative-dev"
RDEPENDS_qt5-${PN}-${PN}tools-devel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-models2 (qt5-${PN}-import-models2)
RDEPENDS_qt5-${PN}-import-models2 += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-qttest (qt5-${PN}-import-qttest)
RDEPENDS_qt5-${PN}-import-qttest += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qmlscene (qt5-${PN}-qmlscene)
RDEPENDS_qt5-${PN}-qmlscene += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtquicktest (qt5-${PN}-qtquicktest)
RDEPENDS_qt5-${PN}-qtquicktest += "/sbin/ldconfig"
RDEPENDS_qt5-${PN}-qtquicktest += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtquicktest-devel (qt5-${PN}-qtquicktest-devel)
RDEPENDS_qt5-${PN}-qtquicktest-devel += "qt5-qtdeclarative-dev"
RDEPENDS_qt5-${PN}-qtquicktest-devel += "qt5-qtdeclarative-qtquicktest"
RDEPENDS_qt5-${PN}-qtquicktest-devel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtquick (qt5-${PN}-qtquick)
RDEPENDS_qt5-${PN}-qtquick += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-privatewidgets (qt5-${PN}-import-privatewidgets)
RDEPENDS_qt5-${PN}-import-privatewidgets += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-particles2 (qt5-${PN}-import-particles2)
RDEPENDS_qt5-${PN}-import-particles2 += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-plugin-qmlinspector (qt5-${PN}-plugin-qmlinspector)
RDEPENDS_qt5-${PN}-plugin-qmlinspector += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qml (qt5-${PN}-qml)
RDEPENDS_qt5-${PN}-qml += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-qtquickparticles-devel (qt5-${PN}-qtquickparticles-devel)
RDEPENDS_qt5-${PN}-qtquickparticles-devel += "qt5-qtdeclarative-qtquickparticles"
RDEPENDS_qt5-${PN}-qtquickparticles-devel += "qt5-qtdeclarative"

#RDEPENDS of qt5-qtdeclarative-import-localstorageplugin (qt5-${PN}-import-localstorageplugin)
RDEPENDS_qt5-${PN}-import-localstorageplugin += "qt5-qtdeclarative"


DEPENDS = ""
#DEPENDS of qt5-qtdeclarative 
inherit pythonnative
DEPENDS += "gdb"
DEPENDS += "fdupes-native"
DEPENDS += "qt5-qtxmlpatterns-devel"
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtdeclarative-5.2.2/qtdeclarative
 
 
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
 # Fix wrong path in pkgconfig files
 find ${D}/usr/lib/pkgconfig -type f -name '*.pc' \
 -exec perl -pi -e "s, -L${WORKDIR}/?\S+,,g" {} \;
 # Fix wrong path in prl files
 find ${D}/usr/lib -type f -name '*.prl' \
 -exec sed -i -e "/^QMAKE_PRL_BUILD_DIR/d;s/\(QMAKE_PRL_LIBS =\).*/\1/" {} \;
 # Remove unneeded .la files
 rm -f ${D}/usr/lib/*.la
 
 # We don't need qt5/Qt/
 rm -rf ${D}/usr/include/qt5/Qt
 
 # Manually copy qmldevtools static library
 cp lib/libQt5QmlDevTools.a ${D}/usr/lib
 
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
 
 
 
 
 #### Pre/Post section
 
 
}

PACKAGES = ""
PACKAGES += "qt5-qtdeclarative"
PACKAGES += "qt5-qtdeclarative-import-folderlistmodel"
PACKAGES += "qt5-qtdeclarative-qtquickparticles"
PACKAGES += "qt5-qtdeclarative-import-qtquick2plugin"
PACKAGES += "qt5-qtdeclarative-devel"
PACKAGES += "qt5-qtdeclarative-import-xmllistmodel"
PACKAGES += "qt5-qtdeclarative-import-settings"
PACKAGES += "qt5-qtdeclarative-plugin-accessible"
PACKAGES += "qt5-qtdeclarative-import-dialogs"
PACKAGES += "qt5-qtdeclarative-qtquick-devel"
PACKAGES += "qt5-qtdeclarative-devel-tools"
PACKAGES += "qt5-qtdeclarative-import-window2"
PACKAGES += "qt5-qtdeclarative-qtdeclarativetools-devel"
PACKAGES += "qt5-qtdeclarative-import-models2"
PACKAGES += "qt5-qtdeclarative-import-qttest"
PACKAGES += "qt5-qtdeclarative-qmlscene"
PACKAGES += "qt5-qtdeclarative-qtquicktest"
PACKAGES += "qt5-qtdeclarative-qtquicktest-devel"
PACKAGES += "qt5-qtdeclarative-qtquick"
PACKAGES += "qt5-qtdeclarative-import-privatewidgets"
PACKAGES += "qt5-qtdeclarative-import-particles2"
PACKAGES += "qt5-qtdeclarative-plugin-qmlinspector"
PACKAGES += "qt5-qtdeclarative-qml"
PACKAGES += "qt5-qtdeclarative-qtquickparticles-devel"
PACKAGES += "qt5-qtdeclarative-import-localstorageplugin"

qt5-qtdeclarative_files = ""
qt5-qtdeclarative_files += "/usr/lib/libQt5Qml.so.5"
qt5-qtdeclarative_files += "/usr/lib/libQt5Qml.so.5.*"

qt5-qtdeclarative-import-folderlistmodel_files = ""
qt5-qtdeclarative-import-folderlistmodel_files += "/usr/lib/qt5/qml/Qt/labs/folderlistmodel/*"

qt5-qtdeclarative-qtquickparticles_files = ""
qt5-qtdeclarative-qtquickparticles_files += "/usr/lib/libQt5QuickParticles.so.5"
qt5-qtdeclarative-qtquickparticles_files += "/usr/lib/libQt5QuickParticles.so.5.*"

qt5-qtdeclarative-import-qtquick2plugin_files = ""
qt5-qtdeclarative-import-qtquick2plugin_files += "/usr/lib/qt5/qml/QtQuick.2"

qt5-qtdeclarative-devel_files = ""
qt5-qtdeclarative-devel_files += "/usr/lib/libQt5Qml.so"
qt5-qtdeclarative-devel_files += "/usr/lib/libQt5Qml.prl"
qt5-qtdeclarative-devel_files += "/usr/lib/pkgconfig/Qt5Qml.pc"
qt5-qtdeclarative-devel_files += "/usr/include/qt5/QtQml"
qt5-qtdeclarative-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_qml.pri"
qt5-qtdeclarative-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_qml_private.pri"
qt5-qtdeclarative-devel_files += "/usr/lib/cmake"

qt5-qtdeclarative-import-xmllistmodel_files = ""
qt5-qtdeclarative-import-xmllistmodel_files += "/usr/lib/qt5/qml/QtQuick/XmlListModel"

qt5-qtdeclarative-import-settings_files = ""
qt5-qtdeclarative-import-settings_files += "/usr/lib/qt5/qml/Qt/labs/settings"

qt5-qtdeclarative-plugin-accessible_files = ""
qt5-qtdeclarative-plugin-accessible_files += "/usr/lib/qt5/plugins/accessible/libqtaccessiblequick.so"

qt5-qtdeclarative-import-dialogs_files = ""
qt5-qtdeclarative-import-dialogs_files += "/usr/lib/qt5/qml/QtQuick/Dialogs"

qt5-qtdeclarative-qtquick-devel_files = ""
qt5-qtdeclarative-qtquick-devel_files += "/usr/lib/libQt5Quick.so"
qt5-qtdeclarative-qtquick-devel_files += "/usr/lib/libQt5Quick.prl"
qt5-qtdeclarative-qtquick-devel_files += "/usr/lib/pkgconfig/Qt5Quick.pc"
qt5-qtdeclarative-qtquick-devel_files += "/usr/include/qt5/QtQuick"
qt5-qtdeclarative-qtquick-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_quick.pri"
qt5-qtdeclarative-qtquick-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_quick_private.pri"

qt5-qtdeclarative-devel-tools_files = ""

qt5-qtdeclarative-import-window2_files = ""
qt5-qtdeclarative-import-window2_files += "/usr/lib/qt5/qml/QtQuick/Window.2"

qt5-qtdeclarative-qtdeclarativetools-devel_files = ""
qt5-qtdeclarative-qtdeclarativetools-devel_files += "/usr/lib/libQt5QmlDevTools.a"
qt5-qtdeclarative-qtdeclarativetools-devel_files += "/usr/lib/libQt5QmlDevTools.prl"
qt5-qtdeclarative-qtdeclarativetools-devel_files += "/usr/lib/pkgconfig/Qt5QmlDevTools.pc"
qt5-qtdeclarative-qtdeclarativetools-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri"

qt5-qtdeclarative-import-models2_files = ""
qt5-qtdeclarative-import-models2_files += "/usr/lib/qt5/qml/QtQml/Models.2"

qt5-qtdeclarative-import-qttest_files = ""
qt5-qtdeclarative-import-qttest_files += "/usr/lib/qt5/qml/QtTest"

qt5-qtdeclarative-qmlscene_files = ""

qt5-qtdeclarative-qtquicktest_files = ""
qt5-qtdeclarative-qtquicktest_files += "/usr/lib/libQt5QuickTest.so.5"
qt5-qtdeclarative-qtquicktest_files += "/usr/lib/libQt5QuickTest.so.5.*"

qt5-qtdeclarative-qtquicktest-devel_files = ""
qt5-qtdeclarative-qtquicktest-devel_files += "/usr/include/qt5/QtQuickTest"
qt5-qtdeclarative-qtquicktest-devel_files += "/usr/lib/libQt5QuickTest.so"
qt5-qtdeclarative-qtquicktest-devel_files += "/usr/lib/libQt5QuickTest.prl"
qt5-qtdeclarative-qtquicktest-devel_files += "/usr/lib/pkgconfig/Qt5QuickTest.pc"
qt5-qtdeclarative-qtquicktest-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_qmltest.pri"
qt5-qtdeclarative-qtquicktest-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_qmltest_private.pri"

qt5-qtdeclarative-qtquick_files = ""
qt5-qtdeclarative-qtquick_files += "/usr/lib/libQt5Quick.so.5"
qt5-qtdeclarative-qtquick_files += "/usr/lib/libQt5Quick.so.5.*"

qt5-qtdeclarative-import-privatewidgets_files = ""
qt5-qtdeclarative-import-privatewidgets_files += "/usr/lib/qt5/qml/QtQuick/PrivateWidgets"

qt5-qtdeclarative-import-particles2_files = ""
qt5-qtdeclarative-import-particles2_files += "/usr/lib/qt5/qml/QtQuick/Particles.2"

qt5-qtdeclarative-plugin-qmlinspector_files = ""
qt5-qtdeclarative-plugin-qmlinspector_files += "/usr/lib/qt5/plugins/qmltooling/*"

qt5-qtdeclarative-qml_files = ""

qt5-qtdeclarative-qtquickparticles-devel_files = ""
qt5-qtdeclarative-qtquickparticles-devel_files += "/usr/include/qt5/QtQuickParticles"
qt5-qtdeclarative-qtquickparticles-devel_files += "/usr/lib/libQt5QuickParticles.so"
qt5-qtdeclarative-qtquickparticles-devel_files += "/usr/lib/libQt5QuickParticles.prl"
qt5-qtdeclarative-qtquickparticles-devel_files += "/usr/lib/pkgconfig/Qt5QuickParticles.pc"
qt5-qtdeclarative-qtquickparticles-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri"

qt5-qtdeclarative-import-localstorageplugin_files = ""
qt5-qtdeclarative-import-localstorageplugin_files += "/usr/lib/qt5/qml/QtQuick/LocalStorage"

FILES_${PN} = "${qt5-qtdeclarative_files}"
FILES_${PN}-import-folderlistmodel = "${qt5-qtdeclarative-import-folderlistmodel_files}"
FILES_${PN}-qtquickparticles = "${qt5-qtdeclarative-qtquickparticles_files}"
FILES_${PN}-import-qtquick2plugin = "${qt5-qtdeclarative-import-qtquick2plugin_files}"
FILES_${PN}-devel = "${qt5-qtdeclarative-devel_files}"
FILES_${PN}-import-xmllistmodel = "${qt5-qtdeclarative-import-xmllistmodel_files}"
FILES_${PN}-import-settings = "${qt5-qtdeclarative-import-settings_files}"
FILES_${PN}-plugin-accessible = "${qt5-qtdeclarative-plugin-accessible_files}"
FILES_${PN}-import-dialogs = "${qt5-qtdeclarative-import-dialogs_files}"
FILES_${PN}-qtquick-devel = "${qt5-qtdeclarative-qtquick-devel_files}"
FILES_${PN}-devel-tools = "${qt5-qtdeclarative-devel-tools_files}"
FILES_${PN}-import-window2 = "${qt5-qtdeclarative-import-window2_files}"
FILES_${PN}-qtdeclarativetools-devel = "${qt5-qtdeclarative-qtdeclarativetools-devel_files}"
FILES_${PN}-import-models2 = "${qt5-qtdeclarative-import-models2_files}"
FILES_${PN}-import-qttest = "${qt5-qtdeclarative-import-qttest_files}"
FILES_${PN}-qmlscene = "${qt5-qtdeclarative-qmlscene_files}"
FILES_${PN}-qtquicktest = "${qt5-qtdeclarative-qtquicktest_files}"
FILES_${PN}-qtquicktest-devel = "${qt5-qtdeclarative-qtquicktest-devel_files}"
FILES_${PN}-qtquick = "${qt5-qtdeclarative-qtquick_files}"
FILES_${PN}-import-privatewidgets = "${qt5-qtdeclarative-import-privatewidgets_files}"
FILES_${PN}-import-particles2 = "${qt5-qtdeclarative-import-particles2_files}"
FILES_${PN}-plugin-qmlinspector = "${qt5-qtdeclarative-plugin-qmlinspector_files}"
FILES_${PN}-qml = "${qt5-qtdeclarative-qml_files}"
FILES_${PN}-qtquickparticles-devel = "${qt5-qtdeclarative-qtquickparticles-devel_files}"
FILES_${PN}-import-localstorageplugin = "${qt5-qtdeclarative-import-localstorageplugin_files}"

PKG_qt5-qtdeclarative= "qt5-qtdeclarative"
PKG_qt5-qtdeclarative-import-folderlistmodel= "qt5-qtdeclarative-import-folderlistmodel"
PKG_qt5-qtdeclarative-qtquickparticles= "qt5-qtdeclarative-qtquickparticles"
PKG_qt5-qtdeclarative-import-qtquick2plugin= "qt5-qtdeclarative-import-qtquick2plugin"
PKG_qt5-qtdeclarative-devel= "qt5-qtdeclarative-devel"
PKG_qt5-qtdeclarative-import-xmllistmodel= "qt5-qtdeclarative-import-xmllistmodel"
PKG_qt5-qtdeclarative-import-settings= "qt5-qtdeclarative-import-settings"
PKG_qt5-qtdeclarative-plugin-accessible= "qt5-qtdeclarative-plugin-accessible"
PKG_qt5-qtdeclarative-import-dialogs= "qt5-qtdeclarative-import-dialogs"
PKG_qt5-qtdeclarative-qtquick-devel= "qt5-qtdeclarative-qtquick-devel"
PKG_qt5-qtdeclarative-devel-tools= "qt5-qtdeclarative-devel-tools"
PKG_qt5-qtdeclarative-import-window2= "qt5-qtdeclarative-import-window2"
PKG_qt5-qtdeclarative-qtdeclarativetools-devel= "qt5-qtdeclarative-qtdeclarativetools-devel"
PKG_qt5-qtdeclarative-import-models2= "qt5-qtdeclarative-import-models2"
PKG_qt5-qtdeclarative-import-qttest= "qt5-qtdeclarative-import-qttest"
PKG_qt5-qtdeclarative-qmlscene= "qt5-qtdeclarative-qmlscene"
PKG_qt5-qtdeclarative-qtquicktest= "qt5-qtdeclarative-qtquicktest"
PKG_qt5-qtdeclarative-qtquicktest-devel= "qt5-qtdeclarative-qtquicktest-devel"
PKG_qt5-qtdeclarative-qtquick= "qt5-qtdeclarative-qtquick"
PKG_qt5-qtdeclarative-import-privatewidgets= "qt5-qtdeclarative-import-privatewidgets"
PKG_qt5-qtdeclarative-import-particles2= "qt5-qtdeclarative-import-particles2"
PKG_qt5-qtdeclarative-plugin-qmlinspector= "qt5-qtdeclarative-plugin-qmlinspector"
PKG_qt5-qtdeclarative-qml= "qt5-qtdeclarative-qml"
PKG_qt5-qtdeclarative-qtquickparticles-devel= "qt5-qtdeclarative-qtquickparticles-devel"
PKG_qt5-qtdeclarative-import-localstorageplugin= "qt5-qtdeclarative-import-localstorageplugin"

require qtdeclarative-extraconf.inc
