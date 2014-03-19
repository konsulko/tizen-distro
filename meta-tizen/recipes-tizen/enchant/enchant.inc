DESCRIPTION = "Generic Spell Checking Library"
HOMEPAGE = "http://www.abisource.com/"
SECTION = "Productivity/Text/Spell"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by enchant-tools 
PROVIDES += "enchant-tools"
RPROVIDES_enchant-tools += "enchant-tools"

#PROVIDES by enchant-devel 
PROVIDES += "enchant-devel"
RPROVIDES_enchant-devel += "enchant-devel"
RPROVIDES_enchant-devel += "enchant-dev"

#PROVIDES by enchant 
PROVIDES += "enchant"
RPROVIDES_enchant += "enchant"

#PROVIDES by libenchant 
PROVIDES += "libenchant"
RPROVIDES_libenchant += "libenchant"
# the PROVIDES rules is ignore "enchant = 1.6.0"
PROVIDES += "enchant"
RPROVIDES_libenchant += "enchant"

#PROVIDES by enchant-zemberek 
PROVIDES += "enchant-zemberek"
RPROVIDES_enchant-zemberek += "enchant-zemberek"
# the PROVIDES rules is ignore "locale(enchant:az)  "
PROVIDES += "locale(enchant:az)"
RPROVIDES_enchant-zemberek += "locale(enchant:az)"
# the PROVIDES rules is ignore "locale(enchant:tk)  "
PROVIDES += "locale(enchant:tk)"
RPROVIDES_enchant-zemberek += "locale(enchant:tk)"
# the PROVIDES rules is ignore "locale(enchant:tr)  "
PROVIDES += "locale(enchant:tr)"
RPROVIDES_enchant-zemberek += "locale(enchant:tr)"
# the PROVIDES rules is ignore "locale(enchant:tt)  "
PROVIDES += "locale(enchant:tt)"
RPROVIDES_enchant-zemberek += "locale(enchant:tt)"

RDEPENDS = ""
#RDEPENDS of enchant-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig(glib-2.0)"
RDEPENDS_${PN}-devel += "enchant"
RDEPENDS_${PN}-devel += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of enchant 
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "hunspell-devel"
DEPENDS += "aspell"
DEPENDS += "gcc-c++"
DEPENDS += "dbus-glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/enchant.manifest .
 
 
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
         --infodir=/usr/share/info --with-pic \
     --disable-static \
     --enable-zemberek \
     --with-myspell-dir=/usr/share/myspell \
     --disable-voikko
 
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
PACKAGES += "enchant-tools"
PACKAGES += "enchant-devel"
PACKAGES += "libenchant"
PACKAGES += "enchant-zemberek"

enchant-tools_files = ""
enchant-tools_files += "enchant.manifest"
enchant-tools_files += "/usr/bin/enchant"
enchant-tools_files += "/usr/bin/enchant-lsmod"
enchant-tools_files += "/usr/share/man/man1/enchant.1*"

enchant-devel_files = ""
enchant-devel_files += "enchant.manifest"
enchant-devel_files += "/usr/include/*"
enchant-devel_files += "/usr/lib/*.so"
enchant-devel_files += "/usr/lib/pkgconfig/*.pc"

libenchant_files = ""
libenchant_files += "enchant.manifest"
libenchant_files += "COPYING.LIB"
libenchant_files += "/usr/lib/*.so.*"
libenchant_files += "/usr/share/enchant"
libenchant_files += "/usr/lib/enchant"
libenchant_files += "/usr/lib/enchant/libenchant_aspell.so"
libenchant_files += "/usr/lib/enchant/libenchant_ispell.so"
libenchant_files += "/usr/lib/enchant/libenchant_myspell.so"

enchant-zemberek_files = ""
enchant-zemberek_files += "enchant.manifest"
enchant-zemberek_files += "/usr/lib/enchant/libenchant_zemberek.so"

FILES_${PN}-tools = "${enchant-tools_files}"
FILES_${PN}-devel = "${enchant-devel_files}"
FILES_lib${PN} = "${libenchant_files}"
FILES_${PN}-zemberek = "${enchant-zemberek_files}"

PKG_enchant-tools= "enchant-tools"
PKG_enchant-devel= "enchant-devel"
PKG_libenchant= "libenchant"
PKG_enchant-zemberek= "enchant-zemberek"

require enchant-extraconf.inc
