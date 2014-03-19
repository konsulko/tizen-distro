DESCRIPTION = "A Free and Open Source Spell Checker"
HOMEPAGE = "http://aspell.net/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libpspell 
PROVIDES += "libpspell"
RPROVIDES_libpspell += "libpspell"

#PROVIDES by aspell 
PROVIDES += "aspell"
RPROVIDES_aspell += "aspell"

#PROVIDES by aspell-devel 
PROVIDES += "aspell-devel"
RPROVIDES_aspell-devel += "aspell-devel"
RPROVIDES_aspell-devel += "aspell-dev"

#PROVIDES by libaspell 
PROVIDES += "libaspell"
RPROVIDES_libaspell += "libaspell"

#PROVIDES by aspell-ispell 
PROVIDES += "aspell-ispell"
RPROVIDES_aspell-ispell += "aspell-ispell"

#PROVIDES by aspell-spell 
PROVIDES += "aspell-spell"
RPROVIDES_aspell-spell += "aspell-spell"

#PROVIDES by aspell-docs  
PROVIDES += "aspell-docs "
RPROVIDES_aspell-docs  += "aspell-docs "

RDEPENDS = ""
#RDEPENDS of aspell-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libpspell"
RDEPENDS_${PN}-devel += "libaspell"

#RDEPENDS of aspell-ispell (${PN}-ispell)
RDEPENDS_${PN}-ispell += "aspell"

#RDEPENDS of aspell-spell (${PN}-spell)
RDEPENDS_${PN}-spell += "aspell"


DEPENDS = ""
#DEPENDS of aspell 
DEPENDS += "libtool-cross"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "fdupes-native"
DEPENDS += "gcc-c++"
DEPENDS += "ncurses-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/aspell.manifest .
 
 
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
 
 autoreconf -fiv
 export CXXFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables `ncursesw6-config --cflags`"
 #this is an ugly kludge , don't look :-)
 export LDFLAGS="`ncursesw6-config --libs`"
 
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
         --infodir=/usr/share/info \
     --enable-curses="-lncursesw" \
  --disable-rpath
 
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
 # Links for compatibility reasons (ispell and spell)
 ln -s /usr/lib/aspell-0.60/ispell ${D}/usr/bin
 ln -s /usr/lib/aspell-0.60/spell ${D}/usr/bin
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D} | 
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} aspell
 
 
 
 
}

PACKAGES = ""
PACKAGES += "libpspell"
PACKAGES += "aspell"
PACKAGES += "aspell-devel"
PACKAGES += "aspell-docs"
PACKAGES += "libaspell"
PACKAGES += "aspell-ispell"
PACKAGES += "aspell-spell"

libpspell_files = ""
libpspell_files += "aspell.manifest"
libpspell_files += "/usr/lib/libpspell.so.15*"

aspell_files = ""
aspell_files += "aspell.manifest"
aspell_files += "/usr/bin/aspell"
aspell_files += "/usr/bin/aspell-import"
aspell_files += "/usr/bin/pre*"
aspell_files += "/usr/bin/run-with-aspell"
aspell_files += "/usr/bin/word-list-compress"

aspell-devel_files = ""
aspell-devel_files += "aspell.manifest"
aspell-devel_files += "manual/aspell-dev.html/"
aspell-devel_files += "/usr/bin/pspell-config"
aspell-devel_files += "/usr/include/pspell/"
aspell-devel_files += "/usr/include/*.h"
aspell-devel_files += "/usr/lib/libaspell.so"
aspell-devel_files += "/usr/lib/libpspell.so"
aspell-devel_files += "/usr/share/info/aspell-dev.info.gz"
aspell-devel_files += "/usr/share/man/man1/pspell-config.1.gz"

aspell-docs_files = ""
aspell-docs_files += "/usr/share/info"
aspell-docs_files += "/usr/share/man"

libaspell_files = ""
libaspell_files += "aspell.manifest"
libaspell_files += "/usr/lib/aspell-0.60/"
libaspell_files += "/usr/lib/libaspell.so.15*"

aspell-ispell_files = ""
aspell-ispell_files += "aspell.manifest"
aspell-ispell_files += "/usr/bin/ispell"

aspell-spell_files = ""
aspell-spell_files += "aspell.manifest"
aspell-spell_files += "/usr/bin/spell"

FILES_libpspell = "${libpspell_files}"
FILES_${PN} = "${aspell_files}"
FILES_${PN}-devel = "${aspell-devel_files}"
FILES_${PN}-docs = "${aspell-docs_files}"
FILES_lib${PN} = "${libaspell_files}"
FILES_${PN}-ispell = "${aspell-ispell_files}"
FILES_${PN}-spell = "${aspell-spell_files}"

PKG_libpspell= "libpspell"
PKG_aspell= "aspell"
PKG_aspell-devel= "aspell-devel"
PKG_aspell-docs= "aspell-docs"
PKG_libaspell= "libaspell"
PKG_aspell-ispell= "aspell-ispell"
PKG_aspell-spell= "aspell-spell"

require aspell-extraconf.inc
