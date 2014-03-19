DESCRIPTION = "Tools for configuring the console (keyboard, virtual terminals, etc"
HOMEPAGE = "http://ftp.altlinux.org/pub/people/legion/kbd"
SECTION = "Base/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by kbd-docs  
PROVIDES += "kbd-docs "
RPROVIDES_kbd-docs  += "kbd-docs "

#PROVIDES by kbd-misc 
PROVIDES += "kbd-misc"
RPROVIDES_kbd-misc += "kbd-misc"

#PROVIDES by kbd 
PROVIDES += "kbd"
RPROVIDES_kbd += "kbd"

RDEPENDS = ""
#RDEPENDS of kbd (${PN})
RDEPENDS_${PN} += "kbd-misc"


DEPENDS = ""
#DEPENDS of kbd 
DEPENDS += "flex"
DEPENDS += "bison-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 #extracte source 2 
 pushd ${S}
 unp ${S}/packaging/kbd-latsun-fonts.tar.bz2 
 popd 
 #extracte source 3 
 pushd ${S}
 unp ${S}/packaging/kbd-latarcyrheb-16-fixed.tar.bz2 
 popd 
 #extracte source 4 
 pushd ${S}
 unp ${S}/packaging/fr-dvorak.tar.bz2 
 popd 
 #extracte source 5 
 pushd ${S}
 unp ${S}/packaging/kbd-latarcyrheb-32.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -a 2 -a 3 -a 4 -a 5
 cp ${S}/packaging/kbd.manifest .
 
 # 7-bit maps are obsolete; so are non-euro maps
 pushd data/keymaps/i386
 mv qwerty/fi.map qwerty/fi-old.map
 cp qwerty/fi-latin9.map qwerty/fi.map
 cp qwerty/pt-latin9.map qwerty/pt.map
 cp qwerty/sv-latin1.map qwerty/se-latin1.map
 
 mv azerty/fr.map azerty/fr-old.map
 cp azerty/fr-latin9.map azerty/fr.map
 
 cp azerty/fr-latin9.map azerty/fr-latin0.map # legacy alias
 
 # Rename conflicting keymaps
 mv dvorak/no.map dvorak/no-dvorak.map
 mv fgGIod/trf.map fgGIod/trf-fgGIod.map
 mv olpc/es.map olpc/es-olpc.map
 mv olpc/pt.map olpc/pt-olpc.map
 mv qwerty/cz.map qwerty/cz-qwerty.map
 popd
 
 # remove obsolete "gr" translation
 pushd po
 rm -f gr.po gr.gmo
 popd
 
 
 
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
         --infodir=/usr/share/info --prefix=/usr --datadir=/usr/lib/kbd --mandir=/usr/share/man --localedir=/usr/share/locale --disable-nls
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
 
 # ro_win.map.gz is useless
 rm -f ${D}//usr/lib/kbd/keymaps/i386/qwerty/ro_win.map.gz
 
 # Create additional name for Serbian latin keyboard
 ln -s sr-cy.map.gz ${D}//usr/lib/kbd/keymaps/i386/qwerty/sr-latin.map.gz
 
 # The rhpl keyboard layout table is indexed by kbd layout names, so we need a
 # Korean keyboard
 ln -s us.map.gz ${D}//usr/lib/kbd/keymaps/i386/qwerty/ko.map.gz
 
 # Some microoptimization
 sed -i -e 's,\<kbd_mode\>,/usr/bin/kbd_mode,g;s,\<setfont\>,/usr/bin/setfont,g' \
         ${D}//usr/bin/unicode_start
 
 # Link open to openvt
 ln -s openvt ${D}/usr/bin/open
 
 ## Move locale files to correct place
 #cp -r ${D}/lib/kbd/locale/ ${D}/usr/share/locale
 #rm -rf ${D}/lib/kbd/locale
 
 
 
}

PACKAGES = ""
PACKAGES += "kbd-misc"
PACKAGES += "kbd-docs"
PACKAGES += "kbd"

kbd-misc_files = ""
kbd-misc_files += "kbd.manifest"
kbd-misc_files += "/usr/lib/kbd"

kbd-docs_files = ""
kbd-docs_files += "/usr/share/info"
kbd-docs_files += "/usr/share/man"

kbd_files = ""
kbd_files += "kbd.manifest"
kbd_files += "/usr/bin/*"

FILES_${PN}-misc = "${kbd-misc_files}"
FILES_${PN}-docs = "${kbd-docs_files}"
FILES_${PN} = "${kbd_files}"

PKG_kbd-misc= "kbd-misc"
PKG_kbd-docs= "kbd-docs"
PKG_kbd= "kbd"

require kbd-extraconf.inc
