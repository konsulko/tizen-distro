DESCRIPTION = "Cross-platform application and UI framework"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-plugin-bearer-connman 
PROVIDES += "qt5-plugin-bearer-connman"
RPROVIDES_qt5-plugin-bearer-connman += "qt5-plugin-bearer-connman"

#PROVIDES by qt5-qtsql 
PROVIDES += "qt5-qtsql"
RPROVIDES_qt5-qtsql += "qt5-qtsql"

#PROVIDES by qt5-qtprintsupport-devel 
PROVIDES += "qt5-qtprintsupport-devel"
RPROVIDES_qt5-qtprintsupport-devel += "qt5-qtprintsupport-devel"
RPROVIDES_qt5-qtprintsupport-devel += "qt5-qtprintsupport-dev"

#PROVIDES by qt5-plugin-imageformat-jpeg 
PROVIDES += "qt5-plugin-imageformat-jpeg"
RPROVIDES_qt5-plugin-imageformat-jpeg += "qt5-plugin-imageformat-jpeg"

#PROVIDES by qt5-qtgui-devel 
PROVIDES += "qt5-qtgui-devel"
RPROVIDES_qt5-qtgui-devel += "qt5-qtgui-devel"
RPROVIDES_qt5-qtgui-devel += "qt5-qtgui-dev"

#PROVIDES by qt5-qtgui 
PROVIDES += "qt5-qtgui"
RPROVIDES_qt5-qtgui += "qt5-qtgui"

#PROVIDES by qt5-plugin-bearer-generic 
PROVIDES += "qt5-plugin-bearer-generic"
RPROVIDES_qt5-plugin-bearer-generic += "qt5-plugin-bearer-generic"

#PROVIDES by qt5-plugin-platform-minimalegl 
PROVIDES += "qt5-plugin-platform-minimalegl"
RPROVIDES_qt5-plugin-platform-minimalegl += "qt5-plugin-platform-minimalegl"

#PROVIDES by qt5-qtprintsupport 
PROVIDES += "qt5-qtprintsupport"
RPROVIDES_qt5-qtprintsupport += "qt5-qtprintsupport"

#PROVIDES by qt5-tools 
PROVIDES += "qt5-tools"
RPROVIDES_qt5-tools += "qt5-tools"

#PROVIDES by qt5-plugin-platform-offscreen 
PROVIDES += "qt5-plugin-platform-offscreen"
RPROVIDES_qt5-plugin-platform-offscreen += "qt5-plugin-platform-offscreen"

#PROVIDES by qt5-qtnetwork-devel 
PROVIDES += "qt5-qtnetwork-devel"
RPROVIDES_qt5-qtnetwork-devel += "qt5-qtnetwork-devel"
RPROVIDES_qt5-qtnetwork-devel += "qt5-qtnetwork-dev"

#PROVIDES by qt5-plugin-platform-eglfs 
PROVIDES += "qt5-plugin-platform-eglfs"
RPROVIDES_qt5-plugin-platform-eglfs += "qt5-plugin-platform-eglfs"

#PROVIDES by qt5-qtbootstrap-devel 
PROVIDES += "qt5-qtbootstrap-devel"
RPROVIDES_qt5-qtbootstrap-devel += "qt5-qtbootstrap-devel"
RPROVIDES_qt5-qtbootstrap-devel += "qt5-qtbootstrap-dev"

#PROVIDES by qt5-qtconcurrent-devel 
PROVIDES += "qt5-qtconcurrent-devel"
RPROVIDES_qt5-qtconcurrent-devel += "qt5-qtconcurrent-devel"
RPROVIDES_qt5-qtconcurrent-devel += "qt5-qtconcurrent-dev"

#PROVIDES by qt5-qtxml-devel 
PROVIDES += "qt5-qtxml-devel"
RPROVIDES_qt5-qtxml-devel += "qt5-qtxml-devel"
RPROVIDES_qt5-qtxml-devel += "qt5-qtxml-dev"

#PROVIDES by qt5-qtcore 
PROVIDES += "qt5-qtcore"
RPROVIDES_qt5-qtcore += "qt5-qtcore"

#PROVIDES by qt5-plugin-platforminputcontext-compose 
PROVIDES += "qt5-plugin-platforminputcontext-compose"
RPROVIDES_qt5-plugin-platforminputcontext-compose += "qt5-plugin-platforminputcontext-compose"

#PROVIDES by qt5-qtcore-devel 
PROVIDES += "qt5-qtcore-devel"
RPROVIDES_qt5-qtcore-devel += "qt5-qtcore-devel"
RPROVIDES_qt5-qtcore-devel += "qt5-qtcore-dev"

#PROVIDES by qt5-plugin-generic-evdev 
PROVIDES += "qt5-plugin-generic-evdev"
RPROVIDES_qt5-plugin-generic-evdev += "qt5-plugin-generic-evdev"

#PROVIDES by qt5-plugin-sqldriver-sqlite 
PROVIDES += "qt5-plugin-sqldriver-sqlite"
RPROVIDES_qt5-plugin-sqldriver-sqlite += "qt5-plugin-sqldriver-sqlite"

#PROVIDES by qt5-qmake 
PROVIDES += "qt5-qmake"
RPROVIDES_qt5-qmake += "qt5-qmake"

#PROVIDES by qt5 
PROVIDES += "qt5"
RPROVIDES_qt5 += "qt5"

#PROVIDES by qt5-plugin-platform-linuxfb 
PROVIDES += "qt5-plugin-platform-linuxfb"
RPROVIDES_qt5-plugin-platform-linuxfb += "qt5-plugin-platform-linuxfb"

#PROVIDES by qt5-qttest 
PROVIDES += "qt5-qttest"
RPROVIDES_qt5-qttest += "qt5-qttest"

#PROVIDES by qt5-qtsql-devel 
PROVIDES += "qt5-qtsql-devel"
RPROVIDES_qt5-qtsql-devel += "qt5-qtsql-devel"
RPROVIDES_qt5-qtsql-devel += "qt5-qtsql-dev"

#PROVIDES by qt5-qtconcurrent 
PROVIDES += "qt5-qtconcurrent"
RPROVIDES_qt5-qtconcurrent += "qt5-qtconcurrent"

#PROVIDES by qt5-qtwidgets-devel 
PROVIDES += "qt5-qtwidgets-devel"
RPROVIDES_qt5-qtwidgets-devel += "qt5-qtwidgets-devel"
RPROVIDES_qt5-qtwidgets-devel += "qt5-qtwidgets-dev"

#PROVIDES by qt5-qtdbus-devel 
PROVIDES += "qt5-qtdbus-devel"
RPROVIDES_qt5-qtdbus-devel += "qt5-qtdbus-devel"
RPROVIDES_qt5-qtdbus-devel += "qt5-qtdbus-dev"

#PROVIDES by qt5-plugin-imageformat-ico 
PROVIDES += "qt5-plugin-imageformat-ico"
RPROVIDES_qt5-plugin-imageformat-ico += "qt5-plugin-imageformat-ico"

#PROVIDES by qt5-qtopengl-devel 
PROVIDES += "qt5-qtopengl-devel"
RPROVIDES_qt5-qtopengl-devel += "qt5-qtopengl-devel"
RPROVIDES_qt5-qtopengl-devel += "qt5-qtopengl-dev"

#PROVIDES by qt5-plugin-bearer-nm 
PROVIDES += "qt5-plugin-bearer-nm"
RPROVIDES_qt5-plugin-bearer-nm += "qt5-plugin-bearer-nm"

#PROVIDES by qt5-plugin-platform-minimal 
PROVIDES += "qt5-plugin-platform-minimal"
RPROVIDES_qt5-plugin-platform-minimal += "qt5-plugin-platform-minimal"

#PROVIDES by qt5-qttest-devel 
PROVIDES += "qt5-qttest-devel"
RPROVIDES_qt5-qttest-devel += "qt5-qttest-devel"
RPROVIDES_qt5-qttest-devel += "qt5-qttest-dev"

#PROVIDES by qt5-qtplatformsupport-devel 
PROVIDES += "qt5-qtplatformsupport-devel"
RPROVIDES_qt5-qtplatformsupport-devel += "qt5-qtplatformsupport-devel"
RPROVIDES_qt5-qtplatformsupport-devel += "qt5-qtplatformsupport-dev"

#PROVIDES by qt5-default 
PROVIDES += "qt5-default"
RPROVIDES_qt5-default += "qt5-default"
# the PROVIDES rules is ignore "qt-default  "
PROVIDES += "qt-default"
RPROVIDES_qt5-default += "qt-default"

#PROVIDES by qt5-plugin-accessible-widgets 
PROVIDES += "qt5-plugin-accessible-widgets"
RPROVIDES_qt5-plugin-accessible-widgets += "qt5-plugin-accessible-widgets"

#PROVIDES by qt5-qtopengl 
PROVIDES += "qt5-qtopengl"
RPROVIDES_qt5-qtopengl += "qt5-qtopengl"

#PROVIDES by qt5-qtxml 
PROVIDES += "qt5-qtxml"
RPROVIDES_qt5-qtxml += "qt5-qtxml"

#PROVIDES by qt5-qtnetwork 
PROVIDES += "qt5-qtnetwork"
RPROVIDES_qt5-qtnetwork += "qt5-qtnetwork"

#PROVIDES by qt5-plugin-imageformat-gif 
PROVIDES += "qt5-plugin-imageformat-gif"
RPROVIDES_qt5-plugin-imageformat-gif += "qt5-plugin-imageformat-gif"

#PROVIDES by qt5-qtwidgets 
PROVIDES += "qt5-qtwidgets"
RPROVIDES_qt5-qtwidgets += "qt5-qtwidgets"

#PROVIDES by qt5-qtdbus 
PROVIDES += "qt5-qtdbus"
RPROVIDES_qt5-qtdbus += "qt5-qtdbus"

#PROVIDES by qt5-plugin-platforminputcontext-ibus 
PROVIDES += "qt5-plugin-platforminputcontext-ibus"
RPROVIDES_qt5-plugin-platforminputcontext-ibus += "qt5-plugin-platforminputcontext-ibus"

#PROVIDES by qt5-plugin-printsupport-cups 
PROVIDES += "qt5-plugin-printsupport-cups"
RPROVIDES_qt5-plugin-printsupport-cups += "qt5-plugin-printsupport-cups"

RDEPENDS = ""
#RDEPENDS of qt5-plugin-bearer-connman (qt5-plugin-bearer-connman)
RDEPENDS_qt5-plugin-bearer-connman += "qt5-qtcore"

#RDEPENDS of qt5-qtsql (qt5-qtsql)
RDEPENDS_qt5-qtsql += "/sbin/ldconfig"

#RDEPENDS of qt5-qtprintsupport-devel (qt5-qtprintsupport-devel)
RDEPENDS_qt5-qtprintsupport-devel += "qt5-qtprintsupport"

#RDEPENDS of qt5-plugin-imageformat-jpeg (qt5-plugin-imageformat-jpeg)
RDEPENDS_qt5-plugin-imageformat-jpeg += "qt5-qtcore"

#RDEPENDS of qt5-qtgui-devel (qt5-qtgui-devel)
RDEPENDS_qt5-qtgui-devel += "qt5-qtopengl-dev"
RDEPENDS_qt5-qtgui-devel += "qt5-qtgui"

#RDEPENDS of qt5-qtgui (qt5-qtgui)
RDEPENDS_qt5-qtgui += "/sbin/ldconfig"

#RDEPENDS of qt5-plugin-bearer-generic (qt5-plugin-bearer-generic)
RDEPENDS_qt5-plugin-bearer-generic += "qt5-qtcore"

#RDEPENDS of qt5-plugin-platform-minimalegl (qt5-plugin-platform-minimalegl)
RDEPENDS_qt5-plugin-platform-minimalegl += "qt5-qtcore"

#RDEPENDS of qt5-qtprintsupport (qt5-qtprintsupport)
RDEPENDS_qt5-qtprintsupport += "/sbin/ldconfig"

#RDEPENDS of qt5-tools (qt5-tools)
RDEPENDS_qt5-tools += "qtchooser"

#RDEPENDS of qt5-plugin-platform-offscreen (qt5-plugin-platform-offscreen)
RDEPENDS_qt5-plugin-platform-offscreen += "qt5-qtcore"

#RDEPENDS of qt5-qtnetwork-devel (qt5-qtnetwork-devel)
RDEPENDS_qt5-qtnetwork-devel += "qt5-qtnetwork"

#RDEPENDS of qt5-plugin-platform-eglfs (qt5-plugin-platform-eglfs)
RDEPENDS_qt5-plugin-platform-eglfs += "qt5-qtcore"

#RDEPENDS of qt5-qtconcurrent-devel (qt5-qtconcurrent-devel)
RDEPENDS_qt5-qtconcurrent-devel += "qt5-qtconcurrent"

#RDEPENDS of qt5-qtxml-devel (qt5-qtxml-devel)
RDEPENDS_qt5-qtxml-devel += "qt5-qtxml"

#RDEPENDS of qt5-qtcore (qt5-qtcore)
RDEPENDS_qt5-qtcore += "/sbin/ldconfig"

#RDEPENDS of qt5-plugin-platforminputcontext-compose (qt5-plugin-platforminputcontext-compose)
RDEPENDS_qt5-plugin-platforminputcontext-compose += "qt5-qtcore"

#RDEPENDS of qt5-qtcore-devel (qt5-qtcore-devel)
RDEPENDS_qt5-qtcore-devel += "qtchooser"
RDEPENDS_qt5-qtcore-devel += "qt5-qmake"
RDEPENDS_qt5-qtcore-devel += "qt5-tools"
RDEPENDS_qt5-qtcore-devel += "fontconfig-dev"
RDEPENDS_qt5-qtcore-devel += "qt5-qtcore"

#RDEPENDS of qt5-plugin-generic-evdev (qt5-plugin-generic-evdev)
RDEPENDS_qt5-plugin-generic-evdev += "qt5-qtcore"

#RDEPENDS of qt5-plugin-sqldriver-sqlite (qt5-plugin-sqldriver-sqlite)
RDEPENDS_qt5-plugin-sqldriver-sqlite += "qt5-qtcore"

#RDEPENDS of qt5-qmake (qt5-qmake)
RDEPENDS_qt5-qmake += "qtchooser"

#RDEPENDS of qt5-plugin-platform-linuxfb (qt5-plugin-platform-linuxfb)
RDEPENDS_qt5-plugin-platform-linuxfb += "qt5-qtcore"

#RDEPENDS of qt5-qttest (qt5-qttest)
RDEPENDS_qt5-qttest += "/sbin/ldconfig"

#RDEPENDS of qt5-qtsql-devel (qt5-qtsql-devel)
RDEPENDS_qt5-qtsql-devel += "qt5-qtsql"

#RDEPENDS of qt5-qtconcurrent (qt5-qtconcurrent)
RDEPENDS_qt5-qtconcurrent += "/sbin/ldconfig"

#RDEPENDS of qt5-qtwidgets-devel (qt5-qtwidgets-devel)
RDEPENDS_qt5-qtwidgets-devel += "qt5-qtwidgets"

#RDEPENDS of qt5-qtdbus-devel (qt5-qtdbus-devel)
RDEPENDS_qt5-qtdbus-devel += "pkgconfig(dbus-1)"
RDEPENDS_qt5-qtdbus-devel += "qt5-qtdbus"

#RDEPENDS of qt5-plugin-imageformat-ico (qt5-plugin-imageformat-ico)
RDEPENDS_qt5-plugin-imageformat-ico += "qt5-qtcore"

#RDEPENDS of qt5-qtopengl-devel (qt5-qtopengl-devel)
RDEPENDS_qt5-qtopengl-devel += "pkgconfig(egl)"
RDEPENDS_qt5-qtopengl-devel += "qt5-qtopengl"

#RDEPENDS of qt5-plugin-bearer-nm (qt5-plugin-bearer-nm)
RDEPENDS_qt5-plugin-bearer-nm += "qt5-qtcore"

#RDEPENDS of qt5-plugin-platform-minimal (qt5-plugin-platform-minimal)
RDEPENDS_qt5-plugin-platform-minimal += "qt5-qtcore"

#RDEPENDS of qt5-qttest-devel (qt5-qttest-devel)
RDEPENDS_qt5-qttest-devel += "qt5-qttest"

#RDEPENDS of qt5-default (qt5-default)
RDEPENDS_qt5-default += "qtchooser"

#RDEPENDS of qt5-plugin-accessible-widgets (qt5-plugin-accessible-widgets)
RDEPENDS_qt5-plugin-accessible-widgets += "qt5-qtcore"

#RDEPENDS of qt5-qtopengl (qt5-qtopengl)
RDEPENDS_qt5-qtopengl += "/sbin/ldconfig"

#RDEPENDS of qt5-qtxml (qt5-qtxml)
RDEPENDS_qt5-qtxml += "/sbin/ldconfig"

#RDEPENDS of qt5-qtnetwork (qt5-qtnetwork)
RDEPENDS_qt5-qtnetwork += "/sbin/ldconfig"

#RDEPENDS of qt5-plugin-imageformat-gif (qt5-plugin-imageformat-gif)
RDEPENDS_qt5-plugin-imageformat-gif += "qt5-qtcore"

#RDEPENDS of qt5-qtwidgets (qt5-qtwidgets)
RDEPENDS_qt5-qtwidgets += "/sbin/ldconfig"

#RDEPENDS of qt5-qtdbus (qt5-qtdbus)
RDEPENDS_qt5-qtdbus += "/sbin/ldconfig"

#RDEPENDS of qt5-plugin-platforminputcontext-ibus (qt5-plugin-platforminputcontext-ibus)
RDEPENDS_qt5-plugin-platforminputcontext-ibus += "qt5-qtcore"

#RDEPENDS of qt5-plugin-printsupport-cups (qt5-plugin-printsupport-cups)
RDEPENDS_qt5-plugin-printsupport-cups += "qt5-qtcore"


DEPENDS = ""
#DEPENDS of qt5 
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "cups"
DEPENDS += "pkgconfig(sqlite3)"
DEPENDS += "pkgconfig(libpng)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libSM"
DEPENDS += "pam"
DEPENDS += "flex"
DEPENDS += "pkgconfig(fontconfig)"
inherit pythonnative
DEPENDS += "libICE"
DEPENDS += "pkgconfig(mtdev)"
DEPENDS += "mesa"
DEPENDS += "pkgconfig(libxslt)"
DEPENDS += "readline-devel"
DEPENDS += "zlib-devel"
DEPENDS += "freetype2"
DEPENDS += "libxkbcommon"
DEPENDS += "pkgconfig(dbus-1)"
DEPENDS += "libjpeg-turbo"
DEPENDS += "pkgconfig(udev)"
DEPENDS += "openssl"
DEPENDS += "pkgconfig(icu-uc)"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-5.2.2/qtbase
 
 
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
 
 touch .git
 
 MAKEFLAGS=-j16 \
 ./configure --disable-static \
     -confirm-license \
     -developer-build \
     -no-warnings-are-errors \
     -platform devices/linux-g++-tizen \
     -device-option TIZEN_PROFILE=pc \
     -device-option QT_QPA_DEFAULT_PLATFORM=wayland \
     -opengl es2 \
     -prefix "/usr" \
     -bindir "/usr/lib/qt5/bin" \
     -libdir "/usr/lib" \
     -docdir "/usr/share/doc/packages/qt5/" \
     -headerdir "/usr/include/qt5" \
     -datadir "/usr/share/qt5" \
     -plugindir "/usr/lib/qt5/plugins" \
     -importdir "/usr/lib/qt5/imports" \
     -translationdir "/usr/share/qt5/translations" \
     -sysconfdir "/etc/xdg" \
     -examplesdir "/usr/lib/qt5/examples" \
     -archdatadir "/usr/share/qt5" \
     -testsdir "/usr/lib/qt5/tests" \
     -qmldir "/usr/lib/qt5/qml" \
     -libexecdir "/usr/lib/qt5/libexec" \
     -opensource \
     -no-sql-ibase \
     -no-sql-mysql \
     -no-sql-odbc \
     -no-sql-psql \
     -plugin-sql-sqlite \
     -no-sql-sqlite2 \
     -no-sql-tds \
     -system-sqlite \
     -audio-backend \
     -system-zlib \
     -system-libpng \
     -system-libjpeg \
     -no-rpath \
     -optimized-qmake \
     -dbus-linked \
     -no-strip \
     -no-separate-debug-info \
     -verbose \
     -no-gtkstyle \
     -no-openvg \
     -nomake tests \
     -nomake examples \
     -no-xinput2 \
     -no-xcb
 
 
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
 INSTALL_ROOT=${D} oe_runmake install
 
 find ${D}/usr/share/doc/packages/qt5/ -type f -exec chmod ugo-x {} \;
 
 # Make sure these are around
 mkdir -p ${D}/usr/include/qt5/
 mkdir -p ${D}/usr/share/qt5/
 mkdir -p ${D}/usr/lib/qt5/plugins/
 mkdir -p ${D}/usr/lib/qt5/imports/
 mkdir -p ${D}/usr/lib/qt5/translations/
 mkdir -p ${D}/usr/lib/qt5/examples/
 #
 # Install qmake rpm macros
 install -D -p -m 0644 ${S}/packaging//macros.qt5-default \
 ${D}/etc/rpm/macros.qt5-default
 
 # Add a configuration link for qtchooser - the 5.conf is installed by qtchooser
 mkdir -p ${D}/etc/xdg/qtchooser
 ln -s /etc/xdg/qtchooser/5.conf ${D}/etc/xdg/qtchooser/default.conf
 
 #
 
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
PACKAGES += "qt5-plugin-bearer-connman"
PACKAGES += "qt5-qtsql"
PACKAGES += "qt5-qtprintsupport-devel"
PACKAGES += "qt5-plugin-imageformat-jpeg"
PACKAGES += "qt5-qtgui-devel"
PACKAGES += "qt5-plugin-imageformat-gif"
PACKAGES += "qt5-plugin-bearer-generic"
PACKAGES += "qt5-plugin-platform-minimalegl"
PACKAGES += "qt5-qtprintsupport"
PACKAGES += "qt5-tools"
PACKAGES += "qt5-qtsql-devel"
PACKAGES += "qt5-plugin-platform-offscreen"
PACKAGES += "qt5-qtnetwork-devel"
PACKAGES += "qt5-plugin-platform-eglfs"
PACKAGES += "qt5-qtbootstrap-devel"
PACKAGES += "qt5-qtconcurrent-devel"
PACKAGES += "qt5-qtxml-devel"
PACKAGES += "qt5-qtcore"
PACKAGES += "qt5-plugin-platforminputcontext-compose"
PACKAGES += "qt5-qtcore-devel"
PACKAGES += "qt5-plugin-sqldriver-sqlite"
PACKAGES += "qt5-qmake"
PACKAGES += "qt5-plugin-platform-linuxfb"
PACKAGES += "qt5-plugin-generic-evdev"
PACKAGES += "qt5-qttest"
PACKAGES += "qt5-qtconcurrent"
PACKAGES += "qt5-qtwidgets-devel"
PACKAGES += "qt5-qtdbus-devel"
PACKAGES += "qt5-plugin-imageformat-ico"
PACKAGES += "qt5-qtopengl-devel"
PACKAGES += "qt5-plugin-bearer-nm"
PACKAGES += "qt5-plugin-platform-minimal"
PACKAGES += "qt5-qttest-devel"
PACKAGES += "qt5-qtplatformsupport-devel"
PACKAGES += "qt5-default"
PACKAGES += "qt5-plugin-accessible-widgets"
PACKAGES += "qt5-qtopengl"
PACKAGES += "qt5-qtxml"
PACKAGES += "qt5-qtnetwork"
PACKAGES += "qt5-qtgui"
PACKAGES += "qt5-qtwidgets"
PACKAGES += "qt5-qtdbus"
PACKAGES += "qt5-plugin-platforminputcontext-ibus"
PACKAGES += "qt5-plugin-printsupport-cups"

qt5-plugin-bearer-connman_files = ""
qt5-plugin-bearer-connman_files += "/usr/lib/qt5/plugins/bearer/libqconnmanbearer.so"

qt5-qtsql_files = ""
qt5-qtsql_files += "/usr/lib/libQt5Sql.so.*"

qt5-qtprintsupport-devel_files = ""
qt5-qtprintsupport-devel_files += "/usr/include/qt5/QtPrintSupport"
qt5-qtprintsupport-devel_files += "/usr/lib/libQt5PrintSupport.prl"
qt5-qtprintsupport-devel_files += "/usr/lib/libQt5PrintSupport.la"
qt5-qtprintsupport-devel_files += "/usr/lib/libQt5PrintSupport.so"
qt5-qtprintsupport-devel_files += "/usr/lib/pkgconfig/Qt5PrintSupport.pc"
qt5-qtprintsupport-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_printsupport.pri"
qt5-qtprintsupport-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_printsupport_private.pri"

qt5-plugin-imageformat-jpeg_files = ""
qt5-plugin-imageformat-jpeg_files += "/usr/lib/qt5/plugins/imageformats/libqjpeg.so"

qt5-qtgui-devel_files = ""
qt5-qtgui-devel_files += "/usr/include/qt5/QtGui"
qt5-qtgui-devel_files += "/usr/lib/libQt5Gui.prl"
qt5-qtgui-devel_files += "/usr/lib/libQt5Gui.la"
qt5-qtgui-devel_files += "/usr/lib/libQt5Gui.so"
qt5-qtgui-devel_files += "/usr/lib/pkgconfig/Qt5Gui.pc"
qt5-qtgui-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_gui.pri"
qt5-qtgui-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_gui_private.pri"

qt5-plugin-imageformat-gif_files = ""
qt5-plugin-imageformat-gif_files += "/usr/lib/qt5/plugins/imageformats/libqgif.so"

qt5-plugin-bearer-generic_files = ""
qt5-plugin-bearer-generic_files += "/usr/lib/qt5/plugins/bearer/libqgenericbearer.so"

qt5-plugin-platform-minimalegl_files = ""
qt5-plugin-platform-minimalegl_files += "/usr/lib/qt5/plugins/platforms/libqminimalegl.so"

qt5-qtprintsupport_files = ""
qt5-qtprintsupport_files += "/usr/lib/libQt5PrintSupport.so.*"

qt5-tools_files = ""
qt5-tools_files += "/usr/lib/qt5/bin/moc"
qt5-tools_files += "/usr/lib/qt5/bin/rcc"
qt5-tools_files += "/usr/lib/qt5/bin/syncqt.pl"
qt5-tools_files += "/usr/lib/qt5/bin/uic"
qt5-tools_files += "/usr/lib/qt5/bin/qdoc"
qt5-tools_files += "/usr/share/doc/packages/qt5/*"

qt5-qtsql-devel_files = ""
qt5-qtsql-devel_files += "/usr/include/qt5/QtSql"
qt5-qtsql-devel_files += "/usr/lib/libQt5Sql.prl"
qt5-qtsql-devel_files += "/usr/lib/libQt5Sql.la"
qt5-qtsql-devel_files += "/usr/lib/libQt5Sql.so"
qt5-qtsql-devel_files += "/usr/lib/pkgconfig/Qt5Sql.pc"
qt5-qtsql-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_sql.pri"
qt5-qtsql-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_sql_private.pri"

qt5-plugin-platform-offscreen_files = ""
qt5-plugin-platform-offscreen_files += "/usr/lib/qt5/plugins/platforms/libqoffscreen.so"

qt5-qtnetwork-devel_files = ""
qt5-qtnetwork-devel_files += "/usr/include/qt5/QtNetwork"
qt5-qtnetwork-devel_files += "/usr/lib/libQt5Network.prl"
qt5-qtnetwork-devel_files += "/usr/lib/libQt5Network.la"
qt5-qtnetwork-devel_files += "/usr/lib/libQt5Network.so"
qt5-qtnetwork-devel_files += "/usr/lib/pkgconfig/Qt5Network.pc"
qt5-qtnetwork-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_network.pri"
qt5-qtnetwork-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_network_private.pri"

qt5-plugin-platform-eglfs_files = ""
qt5-plugin-platform-eglfs_files += "/usr/lib/qt5/plugins/platforms/libqeglfs.so"

qt5-qtbootstrap-devel_files = ""
qt5-qtbootstrap-devel_files += "/usr/lib/libQt5Bootstrap.prl"
qt5-qtbootstrap-devel_files += "/usr/lib/libQt5Bootstrap.la"
qt5-qtbootstrap-devel_files += "/usr/lib/libQt5Bootstrap.a"
qt5-qtbootstrap-devel_files += "/usr/lib/pkgconfig/Qt5Bootstrap.pc"
qt5-qtbootstrap-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri"

qt5-qtconcurrent-devel_files = ""
qt5-qtconcurrent-devel_files += "/usr/include/qt5/QtConcurrent"
qt5-qtconcurrent-devel_files += "/usr/lib/libQt5Concurrent.prl"
qt5-qtconcurrent-devel_files += "/usr/lib/libQt5Concurrent.la"
qt5-qtconcurrent-devel_files += "/usr/lib/libQt5Concurrent.so"
qt5-qtconcurrent-devel_files += "/usr/lib/pkgconfig/Qt5Concurrent.pc"
qt5-qtconcurrent-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_concurrent.pri"
qt5-qtconcurrent-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_concurrent_private.pri"

qt5-qtxml-devel_files = ""
qt5-qtxml-devel_files += "/usr/include/qt5/QtXml"
qt5-qtxml-devel_files += "/usr/lib/libQt5Xml.prl"
qt5-qtxml-devel_files += "/usr/lib/libQt5Xml.la"
qt5-qtxml-devel_files += "/usr/lib/libQt5Xml.so"
qt5-qtxml-devel_files += "/usr/lib/pkgconfig/Qt5Xml.pc"
qt5-qtxml-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_xml.pri"
qt5-qtxml-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_xml_private.pri"

qt5-qtcore_files = ""
qt5-qtcore_files += "/usr/include/qt5/"
qt5-qtcore_files += "/usr/share/qt5/"
qt5-qtcore_files += "/usr/lib/qt5/plugins/"
qt5-qtcore_files += "/usr/lib/qt5/imports/"
qt5-qtcore_files += "/usr/lib/qt5/translations/"
qt5-qtcore_files += "/usr/lib/qt5/examples/"
qt5-qtcore_files += "/usr/lib/libQt5Core.so.*"

qt5-plugin-platforminputcontext-compose_files = ""
qt5-plugin-platforminputcontext-compose_files += "/usr/lib/qt5/plugins/platforminputcontexts/libcomposeplatforminputcontextplugin.so"

qt5-qtcore-devel_files = ""
qt5-qtcore-devel_files += "/usr/include/qt5/QtCore"
qt5-qtcore-devel_files += "/usr/lib/libQt5Core.prl"
qt5-qtcore-devel_files += "/usr/lib/libQt5Core.la"
qt5-qtcore-devel_files += "/usr/lib/libQt5Core.so"
qt5-qtcore-devel_files += "/usr/lib/pkgconfig/Qt5Core.pc"
qt5-qtcore-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_core.pri"
qt5-qtcore-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_core_private.pri"
qt5-qtcore-devel_files += "/usr/lib/cmake"

qt5-plugin-sqldriver-sqlite_files = ""
qt5-plugin-sqldriver-sqlite_files += "/usr/lib/qt5/plugins/sqldrivers/libqsqlite.so"

qt5-qmake_files = ""
qt5-qmake_files += "/usr/lib/qt5/bin/qmake"
qt5-qmake_files += "/usr/share/qt5/mkspecs/aix-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/blackberry*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/common"
qt5-qmake_files += "/usr/share/qt5/mkspecs/cygwin-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/darwin-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/features"
qt5-qmake_files += "/usr/share/qt5/mkspecs/freebsd-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/hpux-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/hpuxi-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/hurd-g++"
qt5-qmake_files += "/usr/share/qt5/mkspecs/irix-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/linux-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/lynxos-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/macx-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/netbsd-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/openbsd-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/qconfig.pri"
qt5-qmake_files += "/usr/share/qt5/mkspecs/qfeatures.pri"
qt5-qmake_files += "/usr/share/qt5/mkspecs/qmodule.pri"
qt5-qmake_files += "/usr/share/qt5/mkspecs/qnx*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/sco-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/solaris-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/tru64-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/unixware-*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/unsupported"
qt5-qmake_files += "/usr/share/qt5/mkspecs/win32-g++"
qt5-qmake_files += "/usr/share/qt5/mkspecs/win32-icc"
qt5-qmake_files += "/usr/share/qt5/mkspecs/win32-msvc20*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/wince*"
qt5-qmake_files += "/usr/share/qt5/mkspecs/devices"
qt5-qmake_files += "/usr/share/qt5/mkspecs/qdevice.pri"
qt5-qmake_files += "/usr/share/qt5/mkspecs/winphone-arm-msvc2012"
qt5-qmake_files += "/usr/share/qt5/mkspecs/winphone-x86-msvc2012"
qt5-qmake_files += "/usr/share/qt5/mkspecs/winrt-arm-msvc2012"
qt5-qmake_files += "/usr/share/qt5/mkspecs/winrt-x64-msvc2012"
qt5-qmake_files += "/usr/share/qt5/mkspecs/winrt-x86-msvc2012"
qt5-qmake_files += "/etc/rpm/macros.qt5-default"

qt5-plugin-platform-linuxfb_files = ""
qt5-plugin-platform-linuxfb_files += "/usr/lib/qt5/plugins/platforms/libqlinuxfb.so"

qt5-plugin-generic-evdev_files = ""
qt5-plugin-generic-evdev_files += "/usr/lib/qt5/plugins/generic/libqevdev*plugin.so"

qt5-qttest_files = ""
qt5-qttest_files += "/usr/lib/libQt5Test.so.*"

qt5-qtconcurrent_files = ""
qt5-qtconcurrent_files += "/usr/lib/libQt5Concurrent.so.*"

qt5-qtwidgets-devel_files = ""
qt5-qtwidgets-devel_files += "/usr/include/qt5/QtWidgets"
qt5-qtwidgets-devel_files += "/usr/lib/libQt5Widgets.prl"
qt5-qtwidgets-devel_files += "/usr/lib/libQt5Widgets.la"
qt5-qtwidgets-devel_files += "/usr/lib/libQt5Widgets.so"
qt5-qtwidgets-devel_files += "/usr/lib/pkgconfig/Qt5Widgets.pc"
qt5-qtwidgets-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_widgets.pri"
qt5-qtwidgets-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_widgets_private.pri"

qt5-qtdbus-devel_files = ""
qt5-qtdbus-devel_files += "/usr/lib/qt5/bin/qdbuscpp2xml"
qt5-qtdbus-devel_files += "/usr/lib/qt5/bin/qdbusxml2cpp"
qt5-qtdbus-devel_files += "/usr/include/qt5/QtDBus"
qt5-qtdbus-devel_files += "/usr/lib/libQt5DBus.so"
qt5-qtdbus-devel_files += "/usr/lib/libQt5DBus.prl"
qt5-qtdbus-devel_files += "/usr/lib/libQt5DBus.la"
qt5-qtdbus-devel_files += "/usr/lib/pkgconfig/Qt5DBus.pc"
qt5-qtdbus-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_dbus.pri"
qt5-qtdbus-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_dbus_private.pri"

qt5-plugin-imageformat-ico_files = ""
qt5-plugin-imageformat-ico_files += "/usr/lib/qt5/plugins/imageformats/libqico.so"

qt5-qtopengl-devel_files = ""
qt5-qtopengl-devel_files += "/usr/include/qt5/QtOpenGL"
qt5-qtopengl-devel_files += "/usr/include/qt5/QtOpenGLExtensions"
qt5-qtopengl-devel_files += "/usr/lib/libQt5OpenGL.prl"
qt5-qtopengl-devel_files += "/usr/lib/libQt5OpenGL.la"
qt5-qtopengl-devel_files += "/usr/lib/libQt5OpenGLExtensions.prl"
qt5-qtopengl-devel_files += "/usr/lib/libQt5OpenGLExtensions.la"
qt5-qtopengl-devel_files += "/usr/lib/libQt5OpenGL.so"
qt5-qtopengl-devel_files += "/usr/lib/libQt5OpenGLExtensions.a"
qt5-qtopengl-devel_files += "/usr/lib/pkgconfig/Qt5OpenGL.pc"
qt5-qtopengl-devel_files += "/usr/lib/pkgconfig/Qt5OpenGLExtensions.pc"
qt5-qtopengl-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_opengl.pri"
qt5-qtopengl-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_opengl_private.pri"
qt5-qtopengl-devel_files += "/usr/share/qt5/mkspecs/android-g++/qmake.conf"
qt5-qtopengl-devel_files += "/usr/share/qt5/mkspecs/android-g++/qplatformdefs.h"
qt5-qtopengl-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_openglextensions.pri"
qt5-qtopengl-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri"

qt5-plugin-bearer-nm_files = ""
qt5-plugin-bearer-nm_files += "/usr/lib/qt5/plugins/bearer/libqnmbearer.so"

qt5-plugin-platform-minimal_files = ""
qt5-plugin-platform-minimal_files += "/usr/lib/qt5/plugins/platforms/libqminimal.so"

qt5-qttest-devel_files = ""
qt5-qttest-devel_files += "/usr/include/qt5/QtTest"
qt5-qttest-devel_files += "/usr/lib/libQt5Test.prl"
qt5-qttest-devel_files += "/usr/lib/libQt5Test.la"
qt5-qttest-devel_files += "/usr/lib/libQt5Test.so"
qt5-qttest-devel_files += "/usr/lib/pkgconfig/Qt5Test.pc"
qt5-qttest-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_testlib.pri"
qt5-qttest-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_testlib_private.pri"

qt5-qtplatformsupport-devel_files = ""
qt5-qtplatformsupport-devel_files += "/usr/include/qt5/QtPlatformSupport"
qt5-qtplatformsupport-devel_files += "/usr/lib/libQt5PlatformSupport.prl"
qt5-qtplatformsupport-devel_files += "/usr/lib/libQt5PlatformSupport.la"
qt5-qtplatformsupport-devel_files += "/usr/lib/libQt5PlatformSupport.a"
qt5-qtplatformsupport-devel_files += "/usr/lib/pkgconfig/Qt5PlatformSupport.pc"
qt5-qtplatformsupport-devel_files += "/usr/share/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri"

qt5-default_files = ""
qt5-default_files += "/etc/xdg/qtchooser/default.conf"

qt5-plugin-accessible-widgets_files = ""
qt5-plugin-accessible-widgets_files += "/usr/lib/qt5/plugins/accessible/libqtaccessiblewidgets.so"

qt5-qtopengl_files = ""
qt5-qtopengl_files += "/usr/lib/libQt5OpenGL.so.*"

qt5-qtxml_files = ""
qt5-qtxml_files += "/usr/lib/libQt5Xml.so.*"

qt5-qtnetwork_files = ""
qt5-qtnetwork_files += "/usr/lib/libQt5Network.so.*"

qt5-qtgui_files = ""
qt5-qtgui_files += "/usr/lib/libQt5Gui.so.*"

qt5-qtwidgets_files = ""
qt5-qtwidgets_files += "/usr/lib/libQt5Widgets.so.*"

qt5-qtdbus_files = ""
qt5-qtdbus_files += "/usr/lib/libQt5DBus.so.*"

qt5-plugin-platforminputcontext-ibus_files = ""
qt5-plugin-platforminputcontext-ibus_files += "/usr/lib/qt5/plugins/platforminputcontexts/libibusplatforminputcontextplugin.so"

qt5-plugin-printsupport-cups_files = ""
qt5-plugin-printsupport-cups_files += "/usr/lib/qt5/plugins/printsupport/libcupsprintersupport.so"

FILES_${PN}-plugin-bearer-connman = "${qt5-plugin-bearer-connman_files}"
FILES_${PN}-qtsql = "${qt5-qtsql_files}"
FILES_${PN}-qtprintsupport-devel = "${qt5-qtprintsupport-devel_files}"
FILES_${PN}-plugin-imageformat-jpeg = "${qt5-plugin-imageformat-jpeg_files}"
FILES_${PN}-qtgui-devel = "${qt5-qtgui-devel_files}"
FILES_${PN}-plugin-imageformat-gif = "${qt5-plugin-imageformat-gif_files}"
FILES_${PN}-plugin-bearer-generic = "${qt5-plugin-bearer-generic_files}"
FILES_${PN}-plugin-platform-minimalegl = "${qt5-plugin-platform-minimalegl_files}"
FILES_${PN}-qtprintsupport = "${qt5-qtprintsupport_files}"
FILES_${PN}-tools = "${qt5-tools_files}"
FILES_${PN}-qtsql-devel = "${qt5-qtsql-devel_files}"
FILES_${PN}-plugin-platform-offscreen = "${qt5-plugin-platform-offscreen_files}"
FILES_${PN}-qtnetwork-devel = "${qt5-qtnetwork-devel_files}"
FILES_${PN}-plugin-platform-eglfs = "${qt5-plugin-platform-eglfs_files}"
FILES_${PN}-qtbootstrap-devel = "${qt5-qtbootstrap-devel_files}"
FILES_${PN}-qtconcurrent-devel = "${qt5-qtconcurrent-devel_files}"
FILES_${PN}-qtxml-devel = "${qt5-qtxml-devel_files}"
FILES_${PN}-qtcore = "${qt5-qtcore_files}"
FILES_${PN}-plugin-platforminputcontext-compose = "${qt5-plugin-platforminputcontext-compose_files}"
FILES_${PN}-qtcore-devel = "${qt5-qtcore-devel_files}"
FILES_${PN}-plugin-sqldriver-sqlite = "${qt5-plugin-sqldriver-sqlite_files}"
FILES_${PN}-qmake = "${qt5-qmake_files}"
FILES_${PN}-plugin-platform-linuxfb = "${qt5-plugin-platform-linuxfb_files}"
FILES_${PN}-plugin-generic-evdev = "${qt5-plugin-generic-evdev_files}"
FILES_${PN}-qttest = "${qt5-qttest_files}"
FILES_${PN}-qtconcurrent = "${qt5-qtconcurrent_files}"
FILES_${PN}-qtwidgets-devel = "${qt5-qtwidgets-devel_files}"
FILES_${PN}-qtdbus-devel = "${qt5-qtdbus-devel_files}"
FILES_${PN}-plugin-imageformat-ico = "${qt5-plugin-imageformat-ico_files}"
FILES_${PN}-qtopengl-devel = "${qt5-qtopengl-devel_files}"
FILES_${PN}-plugin-bearer-nm = "${qt5-plugin-bearer-nm_files}"
FILES_${PN}-plugin-platform-minimal = "${qt5-plugin-platform-minimal_files}"
FILES_${PN}-qttest-devel = "${qt5-qttest-devel_files}"
FILES_${PN}-qtplatformsupport-devel = "${qt5-qtplatformsupport-devel_files}"
FILES_${PN}-default = "${qt5-default_files}"
FILES_${PN}-plugin-accessible-widgets = "${qt5-plugin-accessible-widgets_files}"
FILES_${PN}-qtopengl = "${qt5-qtopengl_files}"
FILES_${PN}-qtxml = "${qt5-qtxml_files}"
FILES_${PN}-qtnetwork = "${qt5-qtnetwork_files}"
FILES_${PN}-qtgui = "${qt5-qtgui_files}"
FILES_${PN}-qtwidgets = "${qt5-qtwidgets_files}"
FILES_${PN}-qtdbus = "${qt5-qtdbus_files}"
FILES_${PN}-plugin-platforminputcontext-ibus = "${qt5-plugin-platforminputcontext-ibus_files}"
FILES_${PN}-plugin-printsupport-cups = "${qt5-plugin-printsupport-cups_files}"

PKG_qt5-plugin-bearer-connman= "qt5-plugin-bearer-connman"
PKG_qt5-qtsql= "qt5-qtsql"
PKG_qt5-qtprintsupport-devel= "qt5-qtprintsupport-devel"
PKG_qt5-plugin-imageformat-jpeg= "qt5-plugin-imageformat-jpeg"
PKG_qt5-qtgui-devel= "qt5-qtgui-devel"
PKG_qt5-plugin-imageformat-gif= "qt5-plugin-imageformat-gif"
PKG_qt5-plugin-bearer-generic= "qt5-plugin-bearer-generic"
PKG_qt5-plugin-platform-minimalegl= "qt5-plugin-platform-minimalegl"
PKG_qt5-qtprintsupport= "qt5-qtprintsupport"
PKG_qt5-tools= "qt5-tools"
PKG_qt5-qtsql-devel= "qt5-qtsql-devel"
PKG_qt5-plugin-platform-offscreen= "qt5-plugin-platform-offscreen"
PKG_qt5-qtnetwork-devel= "qt5-qtnetwork-devel"
PKG_qt5-plugin-platform-eglfs= "qt5-plugin-platform-eglfs"
PKG_qt5-qtbootstrap-devel= "qt5-qtbootstrap-devel"
PKG_qt5-qtconcurrent-devel= "qt5-qtconcurrent-devel"
PKG_qt5-qtxml-devel= "qt5-qtxml-devel"
PKG_qt5-qtcore= "qt5-qtcore"
PKG_qt5-plugin-platforminputcontext-compose= "qt5-plugin-platforminputcontext-compose"
PKG_qt5-qtcore-devel= "qt5-qtcore-devel"
PKG_qt5-plugin-sqldriver-sqlite= "qt5-plugin-sqldriver-sqlite"
PKG_qt5-qmake= "qt5-qmake"
PKG_qt5-plugin-platform-linuxfb= "qt5-plugin-platform-linuxfb"
PKG_qt5-plugin-generic-evdev= "qt5-plugin-generic-evdev"
PKG_qt5-qttest= "qt5-qttest"
PKG_qt5-qtconcurrent= "qt5-qtconcurrent"
PKG_qt5-qtwidgets-devel= "qt5-qtwidgets-devel"
PKG_qt5-qtdbus-devel= "qt5-qtdbus-devel"
PKG_qt5-plugin-imageformat-ico= "qt5-plugin-imageformat-ico"
PKG_qt5-qtopengl-devel= "qt5-qtopengl-devel"
PKG_qt5-plugin-bearer-nm= "qt5-plugin-bearer-nm"
PKG_qt5-plugin-platform-minimal= "qt5-plugin-platform-minimal"
PKG_qt5-qttest-devel= "qt5-qttest-devel"
PKG_qt5-qtplatformsupport-devel= "qt5-qtplatformsupport-devel"
PKG_qt5-default= "qt5-default"
PKG_qt5-plugin-accessible-widgets= "qt5-plugin-accessible-widgets"
PKG_qt5-qtopengl= "qt5-qtopengl"
PKG_qt5-qtxml= "qt5-qtxml"
PKG_qt5-qtnetwork= "qt5-qtnetwork"
PKG_qt5-qtgui= "qt5-qtgui"
PKG_qt5-qtwidgets= "qt5-qtwidgets"
PKG_qt5-qtdbus= "qt5-qtdbus"
PKG_qt5-plugin-platforminputcontext-ibus= "qt5-plugin-platforminputcontext-ibus"
PKG_qt5-plugin-printsupport-cups= "qt5-plugin-printsupport-cups"

require qtbase-extraconf.inc
