DESCRIPTION = "A TrueType Font Library"
HOMEPAGE = "http://www.freetype.org"
SECTION = "Graphics/Font Management"
LICENSE = "Freetype or GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libfreetype 
PROVIDES += "libfreetype"
RPROVIDES_libfreetype += "libfreetype"

#PROVIDES by freetype2 
PROVIDES += "freetype2"
RPROVIDES_freetype2 += "freetype2"

#PROVIDES by freetype2-devel 
PROVIDES += "freetype2-devel"
RPROVIDES_freetype2-devel += "freetype2-devel"
RPROVIDES_freetype2-devel += "freetype2-dev"
# the PROVIDES rules is ignore "freetype-devel  "
PROVIDES += "freetype-devel"
RPROVIDES_freetype2-devel += "freetype-devel"
RPROVIDES_freetype2-devel += "freetype-dev"

RDEPENDS = ""
#RDEPENDS of freetype2-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "libfreetype"


DEPENDS = ""
#DEPENDS of freetype2 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n freetype-2.4.9 
 cp ${S}/packaging/freetype2.manifest .
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -std=gnu99 -D_GNU_SOURCE"
 
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
         --infodir=/usr/share/info --without-bzip2 \
            --disable-static
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
 
 rm docs/INSTALL*
 
 
}

PACKAGES = ""
PACKAGES += "libfreetype"
PACKAGES += "freetype2-devel"

libfreetype_files = ""
libfreetype_files += "freetype2.manifest"
libfreetype_files += "/usr/lib/libfreetype.so.*"

freetype2-devel_files = ""
freetype2-devel_files += "freetype2.manifest"
freetype2-devel_files += "/usr/include/*"
freetype2-devel_files += "/usr/lib/libfreetype.so"
freetype2-devel_files += "/usr/lib/pkgconfig/freetype2.pc"
freetype2-devel_files += "/usr/bin/*"
freetype2-devel_files += "/usr/share/aclocal"

FILES_libfreetype = "${libfreetype_files}"
FILES_${PN}-devel = "${freetype2-devel_files}"

PKG_libfreetype= "libfreetype"
PKG_freetype2-devel= "freetype2-devel"

require freetype2-extraconf.inc
