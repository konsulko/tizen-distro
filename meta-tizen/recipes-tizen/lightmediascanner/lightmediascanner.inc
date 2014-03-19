DESCRIPTION = "Light media scanner is a media indexer for embedded devices"
HOMEPAGE = "https://github.com/profusion/lightmediascanner"
SECTION = "Multimedia/Libraries"
LICENSE = "LGPL-2.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lightmediascanner 
PROVIDES += "lightmediascanner"
RPROVIDES_lightmediascanner += "lightmediascanner"

#PROVIDES by lightmediascanner-devel 
PROVIDES += "lightmediascanner-devel"
RPROVIDES_lightmediascanner-devel += "lightmediascanner-devel"
RPROVIDES_lightmediascanner-devel += "lightmediascanner-dev"

#PROVIDES by lightmediascanner-test 
PROVIDES += "lightmediascanner-test"
RPROVIDES_lightmediascanner-test += "lightmediascanner-test"

RDEPENDS = ""
#RDEPENDS of lightmediascanner (${PN})
RDEPENDS_${PN} += "libmp4v2"
RDEPENDS_${PN} += "libtheora"

#RDEPENDS of lightmediascanner-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "lightmediascanner"

#RDEPENDS of lightmediascanner-test (${PN}-test)
RDEPENDS_${PN}-test += "lightmediascanner"


DEPENDS = ""
#DEPENDS of lightmediascanner 
DEPENDS += "sqlite-devel"
DEPENDS += "libmp4v2"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "pkgconfig(vorbis)"
DEPENDS += "pkgconfig(flac)"
DEPENDS += "libav"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libtheora"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n lightmediascanner-0.4.5
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 # Temporarily install test binaries
 mkdir -p ${D}//usr/bin
 libtool --mode=install install -m 0755 ${WORKDIR}/lightmediascanner-0.4.5/src/bin/test ${D}//usr/bin/lms-test
 libtool --mode=install install -m 0755 ${WORKDIR}/lightmediascanner-0.4.5/src/bin/list-parsers ${D}//usr/bin/lms-list-parsers
 
 
}

PACKAGES = ""
PACKAGES += "lightmediascanner"
PACKAGES += "lightmediascanner-devel"
PACKAGES += "lightmediascanner-test"

lightmediascanner_files = ""
lightmediascanner_files += "AUTHORS README"
lightmediascanner_files += "/usr/lib/*.so.*"
lightmediascanner_files += "/usr/lib/lightmediascanner/plugins/*"
lightmediascanner_files += "/usr/share/dbus-1/services/*.service"

lightmediascanner-devel_files = ""
lightmediascanner-devel_files += "/usr/include/*"
lightmediascanner-devel_files += "/usr/lib/*.so"
lightmediascanner-devel_files += "/usr/lib/pkgconfig/*"

lightmediascanner-test_files = ""
lightmediascanner-test_files += "/usr/bin/*"

FILES_${PN} = "${lightmediascanner_files}"
FILES_${PN}-devel = "${lightmediascanner-devel_files}"
FILES_${PN}-test = "${lightmediascanner-test_files}"

PKG_lightmediascanner= "lightmediascanner"
PKG_lightmediascanner-devel= "lightmediascanner-devel"
PKG_lightmediascanner-test= "lightmediascanner-test"

require lightmediascanner-extraconf.inc
