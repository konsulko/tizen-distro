DESCRIPTION = "JavaScript interpreter"
HOMEPAGE = "http://www.mozilla.org/js/"
SECTION = "Development/Languages/Other"
LICENSE = "MPL-1.1 or GPL-2.0+ or LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmozjs185 
PROVIDES += "libmozjs185"
RPROVIDES_libmozjs185 += "libmozjs185"

#PROVIDES by js-devel 
PROVIDES += "js-devel"
RPROVIDES_js-devel += "js-devel"
RPROVIDES_js-devel += "js-dev"
# the PROVIDES rules is ignore "libjs-devel = 1.0.0-0"
PROVIDES += "libjs-devel"
RPROVIDES_js-devel += "libjs-devel"
RPROVIDES_js-devel += "libjs-dev"
# the PROVIDES rules is ignore "mozjs185-devel  "
PROVIDES += "mozjs185-devel"
RPROVIDES_js-devel += "mozjs185-devel"
RPROVIDES_js-devel += "mozjs185-dev"

#PROVIDES by js 
PROVIDES += "js"
RPROVIDES_js += "js"
# the PROVIDES rules is ignore "mozjs185  "
PROVIDES += "mozjs185"
RPROVIDES_js += "mozjs185"

RDEPENDS = ""
#RDEPENDS of js-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig"
RDEPENDS_${PN}-devel += "libmozjs185"


DEPENDS = ""
#DEPENDS of js 
DEPENDS += "gcc-cross"
DEPENDS += "zip"
DEPENDS += "autoconf213"
DEPENDS += "pkgconfig-native"
inherit pythonnative
DEPENDS += "nspr-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n js-1.0.0
 
 
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
 
 export MOZILLA_VERSION=1.0.0
 cd js
 pushd src
 
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
         --infodir=/usr/share/info --with-system-nspr --enable-threadsafe
 popd
 export BUILD_OPT=1
 oe_runmake -j16 -C src \
 	JS_THREADSAFE="1" \
 	XCFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -fPIC " \
 	BUILD_OPT="1" \
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd js/src
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 /bin/rm -rf ${D}/usr/lib/libmozjs185-1.0.a
 # SO links are created wrong, fixing them
 /bin/rm -rf ${D}/usr/lib/libmozjs185.so.1.0
 /bin/rm -rf ${D}/usr/lib/libmozjs185.so
 ln -s libmozjs185.so.1.0.0 ${D}/usr/lib/libmozjs185.so.1.0
 ln -s libmozjs185.so.1.0.0 ${D}/usr/lib/libmozjs185.so
 # JS shell
 /bin/install -m 0755 shell/js ${D}/usr/bin/
 # headers are installed with executable permissions
 chmod 644 ${D}/usr/include/js/*
 
 
}

PACKAGES = ""
PACKAGES += "js"
PACKAGES += "js-devel"
PACKAGES += "libmozjs185"

js_files = ""
js_files += "js/src/README.html"
js_files += "/usr/bin/js"

js-devel_files = ""
js-devel_files += "/usr/bin/js-config"
js-devel_files += "/usr/lib/pkgconfig/*.pc"
js-devel_files += "/usr/lib/*.so"
js-devel_files += "/usr/include/js/"

libmozjs185_files = ""
libmozjs185_files += "/usr/lib/*.so.*"

FILES_${PN} = "${js_files}"
FILES_${PN}-devel = "${js-devel_files}"
FILES_libmoz${PN}185 = "${libmozjs185_files}"

PKG_js= "js"
PKG_js-devel= "js-devel"
PKG_libmozjs185= "libmozjs185"

require js-extraconf.inc
