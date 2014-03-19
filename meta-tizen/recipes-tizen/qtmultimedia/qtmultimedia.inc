DESCRIPTION = "Qt Multimedia module"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Base/Libraries"
LICENSE = "LGPL-2.1+ or GPL-3.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder 
PROVIDES += "qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder"
RPROVIDES_qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder += "qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder"

#PROVIDES by qt5-qtmultimedia 
PROVIDES += "qt5-qtmultimedia"
RPROVIDES_qt5-qtmultimedia += "qt5-qtmultimedia"

#PROVIDES by qt5-qtmultimedia-plugin-mediaservice-gstmediacapture 
PROVIDES += "qt5-qtmultimedia-plugin-mediaservice-gstmediacapture"
RPROVIDES_qt5-qtmultimedia-plugin-mediaservice-gstmediacapture += "qt5-qtmultimedia-plugin-mediaservice-gstmediacapture"

#PROVIDES by qt5-qtdeclarative-import-multimedia 
PROVIDES += "qt5-qtdeclarative-import-multimedia"
RPROVIDES_qt5-qtdeclarative-import-multimedia += "qt5-qtdeclarative-import-multimedia"

#PROVIDES by qt5-qtmultimedia-gsttools 
PROVIDES += "qt5-qtmultimedia-gsttools"
RPROVIDES_qt5-qtmultimedia-gsttools += "qt5-qtmultimedia-gsttools"

#PROVIDES by qt5-qtmultimedia-plugin-playlistformats-m3u 
PROVIDES += "qt5-qtmultimedia-plugin-playlistformats-m3u"
RPROVIDES_qt5-qtmultimedia-plugin-playlistformats-m3u += "qt5-qtmultimedia-plugin-playlistformats-m3u"

#PROVIDES by qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer 
PROVIDES += "qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer"
RPROVIDES_qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer += "qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer"

#PROVIDES by qt5-qtmultimedia-devel 
PROVIDES += "qt5-qtmultimedia-devel"
RPROVIDES_qt5-qtmultimedia-devel += "qt5-qtmultimedia-devel"
RPROVIDES_qt5-qtmultimedia-devel += "qt5-qtmultimedia-dev"

#PROVIDES by qt5-qtmultimedia-plugin-mediaservice-gstcamerabin 
PROVIDES += "qt5-qtmultimedia-plugin-mediaservice-gstcamerabin"
RPROVIDES_qt5-qtmultimedia-plugin-mediaservice-gstcamerabin += "qt5-qtmultimedia-plugin-mediaservice-gstcamerabin"

RDEPENDS = ""
#RDEPENDS of qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder (qt5-${PN}-plugin-mediaservice-gstaudiodecoder)
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstaudiodecoder += "qt5-qtmultimedia-gsttools"
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstaudiodecoder += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtmultimedia-plugin-mediaservice-gstmediacapture (qt5-${PN}-plugin-mediaservice-gstmediacapture)
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstmediacapture += "qt5-qtmultimedia-gsttools"
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstmediacapture += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtdeclarative-import-multimedia (qt5-qtdeclarative-import-multimedia)
RDEPENDS_qt5-qtdeclarative-import-multimedia += "qt5-qtdeclarative"
RDEPENDS_qt5-qtdeclarative-import-multimedia += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtmultimedia-gsttools (qt5-${PN}-gsttools)
RDEPENDS_qt5-${PN}-gsttools += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtmultimedia-plugin-playlistformats-m3u (qt5-${PN}-plugin-playlistformats-m3u)
RDEPENDS_qt5-${PN}-plugin-playlistformats-m3u += "qt5-qtmultimedia-gsttools"
RDEPENDS_qt5-${PN}-plugin-playlistformats-m3u += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer (qt5-${PN}-plugin-mediaservice-gstmediaplayer)
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstmediaplayer += "qt5-qtmultimedia-gsttools"
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstmediaplayer += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtmultimedia-devel (qt5-${PN}-devel)
RDEPENDS_qt5-${PN}-devel += "qt5-qtmultimedia"

#RDEPENDS of qt5-qtmultimedia-plugin-mediaservice-gstcamerabin (qt5-${PN}-plugin-mediaservice-gstcamerabin)
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstcamerabin += "qt5-qtmultimedia-gsttools"
RDEPENDS_qt5-${PN}-plugin-mediaservice-gstcamerabin += "qt5-qtmultimedia"


DEPENDS = ""
#DEPENDS of qt5-qtmultimedia 
DEPENDS += "pkgconfig(gstreamer-interfaces-0.10)"
DEPENDS += "pkgconfig(alsa)"
DEPENDS += "pkgconfig(gstreamer-base-0.10)"
DEPENDS += "pkgconfig(gstreamer-app-0.10)"
DEPENDS += "pkgconfig(gstreamer-audio-0.10)"
DEPENDS += "pkgconfig(gstreamer-video-0.10)"
DEPENDS += "qtdeclarative"
DEPENDS += "pkgconfig(gstreamer-pbutils-0.10)"
DEPENDS += "pkgconfig(gstreamer-0.10)"
DEPENDS += "fdupes-native"
DEPENDS += "qtbase"
DEPENDS += "pkgconfig(gstreamer-plugins-bad-0.10)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n qt5-qtmultimedia-5.2.2/qtmultimedia
 
 
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
PACKAGES += "qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder"
PACKAGES += "qt5-qtmultimedia"
PACKAGES += "qt5-qtmultimedia-plugin-mediaservice-gstmediacapture"
PACKAGES += "qt5-qtdeclarative-import-multimedia"
PACKAGES += "qt5-qtmultimedia-gsttools"
PACKAGES += "qt5-qtmultimedia-plugin-playlistformats-m3u"
PACKAGES += "qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer"
PACKAGES += "qt5-qtmultimedia-devel"
PACKAGES += "qt5-qtmultimedia-plugin-mediaservice-gstcamerabin"

qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder_files = ""
qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder_files += "/usr/lib/qt5/plugins/mediaservice/libgstaudiodecoder.so"

qt5-qtmultimedia_files = ""
qt5-qtmultimedia_files += "/usr/lib/libQt5Multimedia.so.5"
qt5-qtmultimedia_files += "/usr/lib/libQt5Multimedia.so.5.*"
qt5-qtmultimedia_files += "/usr/lib/libQt5MultimediaWidgets.so.5"
qt5-qtmultimedia_files += "/usr/lib/libQt5MultimediaWidgets.so.5.*"
qt5-qtmultimedia_files += "/usr/lib/libQt5MultimediaQuick_p.so.5"
qt5-qtmultimedia_files += "/usr/lib/libQt5MultimediaQuick_p.so.5.*"

qt5-qtmultimedia-plugin-mediaservice-gstmediacapture_files = ""
qt5-qtmultimedia-plugin-mediaservice-gstmediacapture_files += "/usr/lib/qt5/plugins/mediaservice/libgstmediacapture.so"

qt5-qtdeclarative-import-multimedia_files = ""
qt5-qtdeclarative-import-multimedia_files += "/usr/lib/qt5/qml/QtMultimedia/"

qt5-qtmultimedia-gsttools_files = ""
qt5-qtmultimedia-gsttools_files += "/usr/lib/libqgsttools_p.so.1"
qt5-qtmultimedia-gsttools_files += "/usr/lib/libqgsttools_p.so.1.*"

qt5-qtmultimedia-plugin-playlistformats-m3u_files = ""
qt5-qtmultimedia-plugin-playlistformats-m3u_files += "/usr/lib/qt5/plugins/playlistformats/libqtmultimedia_m3u.so"

qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer_files = ""
qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer_files += "/usr/lib/qt5/plugins/mediaservice/libgstmediaplayer.so"

qt5-qtmultimedia-devel_files = ""
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5Multimedia.so"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5MultimediaWidgets.so"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5MultimediaQuick_p.so"
qt5-qtmultimedia-devel_files += "/usr/lib/libqgsttools_p.so"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5Multimedia.prl"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5Multimedia.la"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5MultimediaWidgets.prl"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5MultimediaWidgets.la"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5MultimediaQuick_p.prl"
qt5-qtmultimedia-devel_files += "/usr/lib/libQt5MultimediaQuick_p.la"
qt5-qtmultimedia-devel_files += "/usr/lib/libqgsttools_p.prl"
qt5-qtmultimedia-devel_files += "/usr/lib/pkgconfig/*"
qt5-qtmultimedia-devel_files += "/usr/include/qt5/*"
qt5-qtmultimedia-devel_files += "/usr/share/qt5/mkspecs/"
qt5-qtmultimedia-devel_files += "/usr/lib/cmake/"

qt5-qtmultimedia-plugin-mediaservice-gstcamerabin_files = ""
qt5-qtmultimedia-plugin-mediaservice-gstcamerabin_files += "/usr/lib/qt5/plugins/mediaservice/libgstcamerabin.so"

FILES_${PN}-plugin-mediaservice-gstaudiodecoder = "${qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder_files}"
FILES_${PN} = "${qt5-qtmultimedia_files}"
FILES_${PN}-plugin-mediaservice-gstmediacapture = "${qt5-qtmultimedia-plugin-mediaservice-gstmediacapture_files}"
FILES_qt5-qtdeclarative-import-multimedia = "${qt5-qtdeclarative-import-multimedia_files}"
FILES_${PN}-gsttools = "${qt5-qtmultimedia-gsttools_files}"
FILES_${PN}-plugin-playlistformats-m3u = "${qt5-qtmultimedia-plugin-playlistformats-m3u_files}"
FILES_${PN}-plugin-mediaservice-gstmediaplayer = "${qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer_files}"
FILES_${PN}-devel = "${qt5-qtmultimedia-devel_files}"
FILES_${PN}-plugin-mediaservice-gstcamerabin = "${qt5-qtmultimedia-plugin-mediaservice-gstcamerabin_files}"

PKG_qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder= "qt5-qtmultimedia-plugin-mediaservice-gstaudiodecoder"
PKG_qt5-qtmultimedia= "qt5-qtmultimedia"
PKG_qt5-qtmultimedia-plugin-mediaservice-gstmediacapture= "qt5-qtmultimedia-plugin-mediaservice-gstmediacapture"
PKG_qt5-qtdeclarative-import-multimedia= "qt5-qtdeclarative-import-multimedia"
PKG_qt5-qtmultimedia-gsttools= "qt5-qtmultimedia-gsttools"
PKG_qt5-qtmultimedia-plugin-playlistformats-m3u= "qt5-qtmultimedia-plugin-playlistformats-m3u"
PKG_qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer= "qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer"
PKG_qt5-qtmultimedia-devel= "qt5-qtmultimedia-devel"
PKG_qt5-qtmultimedia-plugin-mediaservice-gstcamerabin= "qt5-qtmultimedia-plugin-mediaservice-gstcamerabin"

require qtmultimedia-extraconf.inc
