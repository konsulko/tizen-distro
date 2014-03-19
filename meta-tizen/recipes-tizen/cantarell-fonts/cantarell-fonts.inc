DESCRIPTION = "Contemporary Humanist Sans Serif Font"
HOMEPAGE = "http://live.gnome.org/CantarellFonts"
SECTION = "System/X11/Fonts"
LICENSE = "OFL-1.1"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cantarell-fonts 
PROVIDES += "cantarell-fonts"
RPROVIDES_cantarell-fonts += "cantarell-fonts"

RDEPENDS = ""
#RDEPENDS of cantarell-fonts (${PN})
RDEPENDS_${PN} += "/usr/bin/fc-cache"


DEPENDS = ""
#DEPENDS of cantarell-fonts 
DEPENDS += "xz"
DEPENDS += "dos2unix"
DEPENDS += "pkgconfig-native"
DEPENDS += "fontconfig"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/cantarell-fonts.manifest .
 
 
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
         --target=noarch-tizen-linux \
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
 dos2unix COPYING
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} configdir=/usr/share/cantarell-fonts/conf.avail
 mkdir -p ${D}/etc/fonts/conf.d
 ln -s ../../../usr/share/cantarell-fonts/conf.avail/31-cantarell.conf  ${D}/etc/fonts/conf.d
 
 
}

PACKAGES = ""
PACKAGES += "cantarell-fonts"

cantarell-fonts_files = ""
cantarell-fonts_files += "cantarell-fonts.manifest"
cantarell-fonts_files += "/usr/share/cantarell-fonts"
cantarell-fonts_files += "/usr/share/cantarell-fonts/conf.avail"
cantarell-fonts_files += "/usr/share/cantarell-fonts/conf.avail/31-cantarell.conf"
cantarell-fonts_files += "/etc/fonts/conf.d/31-cantarell.conf"
cantarell-fonts_files += "/usr/share/fonts/cantarell"
cantarell-fonts_files += "/usr/share/fonts/cantarell/Cantarell-Bold.otf"
cantarell-fonts_files += "/usr/share/fonts/cantarell/Cantarell-Regular.otf"

FILES_${PN} = "${cantarell-fonts_files}"

PKG_cantarell-fonts= "cantarell-fonts"

require cantarell-fonts-extraconf.inc
