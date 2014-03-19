DESCRIPTION = "Emotion"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "BSD 3-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by emotion 
PROVIDES += "emotion"
RPROVIDES_emotion += "emotion"

#PROVIDES by emotion-devel 
PROVIDES += "emotion-devel"
RPROVIDES_emotion-devel += "emotion-devel"
RPROVIDES_emotion-devel += "emotion-dev"

RDEPENDS = ""
#RDEPENDS of emotion-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "emotion"


DEPENDS = ""
#DEPENDS of emotion 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(evas)"
DEPENDS += "pkgconfig(edje)"
DEPENDS += "pkgconfig(gstreamer-plugins-base-1.0)"
DEPENDS += "pkgconfig(ecore-fb)"
DEPENDS += "pkgconfig(ecore-evas)"
DEPENDS += "pkgconfig(evas-fb)"
DEPENDS += "ecore"
DEPENDS += "pkgconfig(gstreamer-1.0)"
DEPENDS += "pkgconfig(eio)"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/emotion.manifest .
 
 
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
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=/usr \
         --exec-prefix=/usr \
         --bindir=/usr/bin \
         --sbindir=/usr/sbin \
         --sysconfdir=/etc \
         --datadir=/usr/share \
         --includedir=/usr/include \
         --libdir=/usr/lib \
         --libexecdir=/usr/libexec \
         --localstatedir=/var \
         --sharedstatedir=/usr/com \
         --mandir=/usr/share/man \
         --infodir=/usr/share/info --disable-static \
     --enable-gstreamer
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "emotion"
PACKAGES += "emotion-devel"

emotion_files = ""
emotion_files += "emotion.manifest"
emotion_files += "/usr/bin/*"
emotion_files += "/usr/lib/*.so.*"
emotion_files += "/usr/lib/edje/*"
emotion_files += "/usr/lib/emotion/*"
emotion_files += "/usr/share/emotion/*"

emotion-devel_files = ""
emotion-devel_files += "emotion.manifest"
emotion-devel_files += "/usr/include/emotion-1/*"
emotion-devel_files += "/usr/lib/*.so"
emotion-devel_files += "/usr/lib/pkgconfig/*"

FILES_${PN} = "${emotion_files}"
FILES_${PN}-devel = "${emotion-devel_files}"

PKG_emotion= "emotion"
PKG_emotion-devel= "emotion-devel"

require emotion-extraconf.inc
