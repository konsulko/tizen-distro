DESCRIPTION = "Qt XML Patterns library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1 or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtxmlpatterns 
PROVIDES += "qt5-qtxmlpatterns"
RPROVIDES_qt5-qtxmlpatterns += "qt5-qtxmlpatterns"

#PROVIDES by qt5-qtxmlpatterns-devel 
PROVIDES += "qt5-qtxmlpatterns-devel"
RPROVIDES_qt5-qtxmlpatterns-devel += "qt5-qtxmlpatterns-devel"
RPROVIDES_qt5-qtxmlpatterns-devel += "qt5-qtxmlpatterns-dev"

RDEPENDS = ""
#RDEPENDS of qt5-qtxmlpatterns-devel (qt5-${PN}-devel)
RDEPENDS_qt5-${PN}-devel += "qt5-qtxmlpatterns"


DEPENDS = ""
#DEPENDS of qt5-qtxmlpatterns 
DEPENDS += "fdupes-native"
DEPENDS += "qtbase"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtxmlpatterns-5.2.2/qtxmlpatterns
 
 # The original source assumes build happens within a monolithic tree.
 # The tool used is syncqt, which complains a lot but really only wants
 # to know where the mkspecs may be found. Hence the environment variable
 # name is a little misleading.
 #
 # XXX: FOR THE LOVE OF ALL THAT MAY BE HOLY - DO NOT USE RPMBUILD AND
 # ITS INTERNAL qmake MACRO. IT BREAKS THE BUILD!
 
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
 # Remove unneeded .la files
 rm -f ${D}//usr/lib/*.la
 # Fix wrong path in prl files
 find ${D}/usr/lib -type f -name '*.prl' \
 -exec sed -i -e "/^QMAKE_PRL_BUILD_DIR/d;s/\(QMAKE_PRL_LIBS =\).*/\1/" {} \;
 
 # We don't need qt5/Qt/
 rm -rf ${D}/usr/include/qt5/Qt
 
 #
 
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
PACKAGES += "qt5-qtxmlpatterns"
PACKAGES += "qt5-qtxmlpatterns-devel"

qt5-qtxmlpatterns_files = ""
qt5-qtxmlpatterns_files += "/usr/lib/libQt5XmlPatterns.so.*"

qt5-qtxmlpatterns-devel_files = ""
qt5-qtxmlpatterns-devel_files += "/usr/lib/libQt5XmlPatterns.so"
qt5-qtxmlpatterns-devel_files += "/usr/lib/libQt5XmlPatterns.prl"
qt5-qtxmlpatterns-devel_files += "/usr/lib/pkgconfig/*"
qt5-qtxmlpatterns-devel_files += "/usr/include/qt5"
qt5-qtxmlpatterns-devel_files += "/usr/share/qt5/mkspecs"
qt5-qtxmlpatterns-devel_files += "/usr/lib/cmake"

FILES_${PN} = "${qt5-qtxmlpatterns_files}"
FILES_${PN}-devel = "${qt5-qtxmlpatterns-devel_files}"

PKG_qt5-qtxmlpatterns= "qt5-qtxmlpatterns"
PKG_qt5-qtxmlpatterns-devel= "qt5-qtxmlpatterns-devel"

require qtxmlpatterns-extraconf.inc
