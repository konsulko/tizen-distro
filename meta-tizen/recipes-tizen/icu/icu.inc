DESCRIPTION = "International Components for Unicode"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "ICU"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libicu 
PROVIDES += "libicu"
RPROVIDES_libicu += "libicu"

#PROVIDES by libicu-devel 
PROVIDES += "libicu-devel"
RPROVIDES_libicu-devel += "libicu-devel"
RPROVIDES_libicu-devel += "libicu-dev"

#PROVIDES by icu 
PROVIDES += "icu"
RPROVIDES_icu += "icu"

RDEPENDS = ""
#RDEPENDS of libicu-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libicu"
RDEPENDS_lib${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of icu 
DEPENDS += "autoconf-native"
DEPENDS += "doxygen"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n icu
 cp ${S}/packaging/icu.manifest .
 
 
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
 
 cd source
 
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
             --disable-renaming \
             --enable-shared \
             --disable-samples
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd source
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 # bugs of rpmdeps
 chmod +x ${D}//usr/lib/lib*.so.*
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/icu 
   rm -rf ${D}/usr/share/doc/icu-4.8.1.1 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
 
}

PACKAGES = ""
PACKAGES += "libicu"
PACKAGES += "libicu-devel"
PACKAGES += "icu"

libicu_files = ""
libicu_files += "icu.manifest"
libicu_files += "/usr/lib/*.so*"
libicu_files += "/usr/bin/derb"
libicu_files += "/usr/bin/genbrk"
libicu_files += "/usr/bin/gencfu"
libicu_files += "/usr/bin/gencnval"
libicu_files += "/usr/bin/genctd"
libicu_files += "/usr/bin/genrb"
libicu_files += "/usr/bin/makeconv"
libicu_files += "/usr/bin/pkgdata"
libicu_files += "/usr/bin/uconv"
libicu_files += "/usr/bin/icuinfo"
libicu_files += "/usr/bin/icu-config"
libicu_files += "/usr/sbin/*"
libicu_files += "/usr/share/icu/4.8.1.1"
libicu_files += "/usr/share/icu/4.8.1.1/config/mh-linux"
libicu_files += "/usr/share/icu/4.8.1.1/install-sh"
libicu_files += "/usr/share/icu/4.8.1.1/license.html"
libicu_files += "/usr/share/icu/4.8.1.1/mkinstalldirs"

libicu-devel_files = ""
libicu-devel_files += "icu.manifest"
libicu-devel_files += "/usr/include/layout"
libicu-devel_files += "/usr/include/unicode"
libicu-devel_files += "/usr/lib/*.so"
libicu-devel_files += "/usr/lib/pkgconfig/icu-*.pc"
libicu-devel_files += "/usr/lib/icu"

icu_files = ""
icu_files += "icu.manifest"

FILES_lib${PN} = "${libicu_files}"
FILES_lib${PN}-devel = "${libicu-devel_files}"
FILES_${PN} = "${icu_files}"

PKG_libicu= "libicu"
PKG_libicu-devel= "libicu-devel"
PKG_icu= "icu"

require icu-extraconf.inc
