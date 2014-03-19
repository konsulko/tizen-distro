DESCRIPTION = "Font configuration and customization library"
HOMEPAGE = "http://fontconfig.org"
SECTION = "Graphics/Font Management"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by fontconfig-devel 
PROVIDES += "fontconfig-devel"
RPROVIDES_fontconfig-devel += "fontconfig-devel"
RPROVIDES_fontconfig-devel += "fontconfig-dev"

#PROVIDES by fontconfig 
PROVIDES += "fontconfig"
RPROVIDES_fontconfig += "fontconfig"

RDEPENDS = ""
#RDEPENDS of fontconfig-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig"
RDEPENDS_${PN}-devel += "freetype-dev"
RDEPENDS_${PN}-devel += "fontconfig"

#RDEPENDS of fontconfig (${PN})
RDEPENDS_${PN} += "/usr/bin/rm"
RDEPENDS_${PN} += "/usr/bin/fc-cache"
RDEPENDS_${PN} += "/usr/bin/grep"
RDEPENDS_${PN} += "/usr/bin/mkdir"


DEPENDS = ""
#DEPENDS of fontconfig 
DEPENDS += "expat"
DEPENDS += "pkgconfig(freetype2)"
DEPENDS += "gawk"
inherit perlnative

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/fontconfig.manifest .
 
 
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
 
 # We don't want to rebuild the docs, but we want to install the included ones.
 export HASDOCBOOK=no
 
 
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
     --with-expat=/usr \
     --with-expat-include=/usr/include \
     --with-expat-lib=/usr/lib \
     --with-freetype-config=/usr/bin/freetype-config \
     --with-add-fonts=/usr/share/fonts,/usr/share/app_fonts,/usr/share/fallback_fonts \
     --with-cache-dir=/var/cache/fontconfig \
     --with-confdir=/etc/fonts \
     --with-templatedir=/etc/fonts/conf.avail \
     --disable-docs
 
 make -j16
 
 exit 0
 make check
 
 
 
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
 
 mkdir -p ${D}/usr/share/fonts
 
 
}

PACKAGES = ""
PACKAGES += "fontconfig-devel"
PACKAGES += "fontconfig"

fontconfig-devel_files = ""
fontconfig-devel_files += "fontconfig.manifest"
fontconfig-devel_files += "/usr/lib/libfontconfig.so"
fontconfig-devel_files += "/usr/lib/pkgconfig/*"
fontconfig-devel_files += "/usr/include/fontconfig"

fontconfig_files = ""
fontconfig_files += "fontconfig.manifest"
fontconfig_files += "/usr/lib/libfontconfig.so.*"
fontconfig_files += "/usr/bin/fc-*"
fontconfig_files += "/etc/fonts/*"
fontconfig_files += "/usr/share/fonts"
fontconfig_files += "/etc/fonts/conf.d/README"
fontconfig_files += "/etc/fonts/conf.avail/*.conf"
fontconfig_files += "/etc/fonts/conf.d/*.conf"
fontconfig_files += "/var/cache/fontconfig"
fontconfig_files += "/usr/share/xml/fontconfig/fonts.dtd"

FILES_${PN}-devel = "${fontconfig-devel_files}"
FILES_${PN} = "${fontconfig_files}"

PKG_fontconfig-devel= "fontconfig-devel"
PKG_fontconfig= "fontconfig"

require fontconfig-extraconf.inc
