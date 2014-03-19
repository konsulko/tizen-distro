DESCRIPTION = "Vi IMproved"
HOMEPAGE = "http://www.vim.org/"
SECTION = "Base/Utilities"
LICENSE = "Vim"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by vim-data 
PROVIDES += "vim-data"
RPROVIDES_vim-data += "vim-data"

#PROVIDES by vim-base 
PROVIDES += "vim-base"
RPROVIDES_vim-base += "vim-base"

#PROVIDES by vim-enhanced 
PROVIDES += "vim-enhanced"
RPROVIDES_vim-enhanced += "vim-enhanced"
# the PROVIDES rules is ignore "vi  "
PROVIDES += "vi"
RPROVIDES_vim-enhanced += "vi"
# the PROVIDES rules is ignore "vim_client  "
PROVIDES += "vim_client"
RPROVIDES_vim-enhanced += "vim_client"

#PROVIDES by vim-docs  
PROVIDES += "vim-docs "
RPROVIDES_vim-docs  += "vim-docs "

#PROVIDES by vim 
PROVIDES += "vim"
RPROVIDES_vim += "vim"
# the PROVIDES rules is ignore "vi  "
PROVIDES += "vi"
RPROVIDES_vim += "vi"
# the PROVIDES rules is ignore "vim_client  "
PROVIDES += "vim_client"
RPROVIDES_vim += "vim_client"

RDEPENDS = ""
#RDEPENDS of vim-data (${PN}-data)
RDEPENDS_${PN}-data += "vim-base"

#RDEPENDS of vim-base (${PN}-base)
RDEPENDS_${PN}-base += "vim-base"
RDEPENDS_${PN}-base += "update-alternatives"

#RDEPENDS of vim (${PN})
RDEPENDS_${PN} += "vim-base"
RDEPENDS_${PN} += "update-alternatives"

#RDEPENDS of vim-enhanced (${PN}-enhanced)
RDEPENDS_${PN}-enhanced += "vim-data"
RDEPENDS_${PN}-enhanced += "vim-base"
RDEPENDS_${PN}-enhanced += "update-alternatives"
RDEPENDS_${PN}-enhanced += "perl"


DEPENDS = ""
#DEPENDS of vim 
DEPENDS += "systemd"
DEPENDS += "fdupes-native"
DEPENDS += "attr"
DEPENDS += "ncurses"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
inherit perlnative
inherit pythonnative
DEPENDS += "autoconf-native"
DEPENDS += "db4"

do_patch() {
 #extracte source 98 
 pushd ${S}/../
 unp ${S}/packaging/vim-7.4-patches.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n vim74 -b 98
 cp ${S}/packaging/vim.manifest .
 for p in ../vim-7.4-patches/7.4*; do
     test -e $p || break
     test ${p#*/7.4.} -le 155 || exit 1
     echo Patch $p
     patch -s -p0 < $p
 done
 unset p
 cp ${S}/packaging/tizen.vimrc  .
 
 # newer perl? ugly hack to fix build anyway.
 sed -i -e 's/^XS(XS_/XS_INTERNAL(XS_/' src/if_perl.xs
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wall -pipe -fno-strict-aliasing"
 export CFLAGS=${CFLAGS/-D_FORTIFY_SOURCE=2/-D_FORTIFY_SOURCE=1}
 
 export COMMON_OPTIONS="\
 	--disable-selinux \
 	--enable-smack \
     --with-vim-name=vim \
     --with-ex-name=ex \
     --with-view-name=view \
     --enable-cscope \
     --enable-multibyte \
     --enable-sniff \
     --with-features=huge \
     --with-compiledby='http://www.tizen.org/' \
     --with-tlib=tinfo \
     --with-global-runtime=/usr/share/vim/site"
 export SCRIPT_OPTIONS="\
     --enable-perlinterp \
     --enable-pythoninterp \
     --with-python-config-dir=/usr/lib/python2.7/config"
 
 pushd src
 autoconf
 popd
 #
 # build small default binary
 
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
     ${COMMON_OPTIONS} --disable-gui --without-x --disable-gpm \
     --disable-perlinterp --disable-pythoninterp \
     --disable-rubyinterp --disable-tclinterp
 sed -i -e 's|define HAVE_DATE_TIME 1|undef HAVE_DATE_TIME|' src/auto/config.h
 make VIMRCLOC=/etc VIMRUNTIMEDIR=/usr/share/vim/current MAKE="make -e" -j16
 cp src/vim vim-normal
 make distclean
 #
 # build enhanced binary
 
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
         --infodir=/usr/share/info ${COMMON_OPTIONS} ${SCRIPT_OPTIONS} --disable-gui
 sed -i -e 's|define HAVE_DATE_TIME 1|undef HAVE_DATE_TIME|' src/auto/config.h
 make VIMRCLOC=/etc VIMRUNTIMEDIR=/usr/share/vim/current MAKE="make -e" -j16
 cp src/vim vim-enhanced
 #make distclean
 #
 #
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 # create icon directory to have the icon from the tarball installed
 install -d -m 0755 ${D}/usr/share/icons/hicolor/48x48/apps
 
 cd src
 make install DESTDIR=${D} BINDIR=/usr/bin VIMRCLOC=/etc VIMRUNTIMEDIR=/usr/share/vim/site
 cd ..
 
 # install the other binaries
 install -D -m 0755 vim-normal    ${D}//usr/bin/vim-normal
 install -D -m 0755 vim-enhanced  ${D}/usr/bin/vim-enhanced
 
 # compat symlinks
 # we need a dummy target for /etc/alternatives/vim
 mkdir -p ${D}/etc/alternatives
 touch ${D}/etc/alternatives/vim
 ln -s -f /etc/alternatives/vim ${D}//usr/bin/vim
 
 ln -s -f vim   ${D}/usr/bin/vi
 ln -s -f vim        ${D}/usr/bin/edit
 ln -s -f vim       ${D}//usr/bin/ex
 
 # man pages
 mkdir -p ${D}/usr/share/man/man1
 ln -s -f vim.1.gz ${D}/usr/share/man/man1/vi.1.gz
 ln -s -f vim.1.gz ${D}/usr/share/man/man1/ex.1.gz
 
 
 # make the vim settings more generic
 ln -s -f vim74 ${D}/usr/share/vim/current
 
 # additional files
 install -D -m 0644 ${S}/packaging/tizen.vimrc ${D}/etc/vimrc
 
 # create site wide runtime directory
 mkdir -p -m 0755 ${D}/usr/share/vim/site/after
 mkdir -m 0755 ${D}/usr/share/vim/site/autoload
 mkdir -m 0755 ${D}/usr/share/vim/site/colors
 mkdir -m 0755 ${D}/usr/share/vim/site/doc
 mkdir -m 0755 ${D}/usr/share/vim/site/plugin
 mkdir -m 0755 ${D}/usr/share/vim/site/syntax
 mkdir -m 0755 ${D}/usr/share/vim/site/ftdetect
 mkdir -m 0755 ${D}/usr/share/vim/site/after/syntax
 mkdir -m 0755 ${D}/usr/share/vim/current/skeletons
 mkdir -m 0755 ${D}/etc/skel
 
 
 #
 # documentation
 install -d -m 0755 ${D}/usr/share/doc/packages/{,g}vim/
 cp runtime/doc/uganda.txt LICENSE
 install -D -m 0644 \
     tizen.vimrc \
     README.txt README_src.txt README_unix.txt \
   ${D}/usr/share/doc/packages/vim/
 #
 # remove unecessary duplicate manpages
 rm -rf ${D}/usr/share/man/fr.ISO8859-1/
 rm -rf ${D}/usr/share/man/fr.UTF-8/
 rm -rf ${D}/usr/share/man/pl.ISO8859-2/
 rm -rf ${D}/usr/share/man/pl.UTF-8/
 rm -rf ${D}/usr/share/man/ru.KOI8-R/
 rm -rf ${D}/usr/share/man/it.ISO8859-1/
 rm -rf ${D}/usr/share/man/it.UTF-8/
 rm -rf ${D}/usr/share/man/ru.UTF-8
 # and move russian manpages to a place where they can be found
 rm -rf ${D}/usr/share/man/{fr,it,pl,ru,ja}
 
 
 # remove some c source files
 rm -f ${D}/usr/share/vim/vim74/tools/*.c
 rm -f ${D}/usr/share/vim/vim74/macros/maze/*.c
 #
 # Create ghost files (see vim.conf)
 mkdir -p ${D}/var/run/vi.recover
 rm -rf ${D}/usr/share/icons/hicolor/48x48/apps
 
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}/usr/share/vim/vim74/lang | 
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
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}/usr/share/vim/vim74/tutor | 
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
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}/usr/share/vim/vim74/ftplugin | 
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
 
 
}

PACKAGES = ""
PACKAGES += "vim-data"
PACKAGES += "vim-base"
PACKAGES += "vim"
PACKAGES += "vim-docs"
PACKAGES += "vim-enhanced"

vim-data_files = ""
vim-data_files += "vim.manifest"
vim-data_files += "/usr/share/vim/vim74/autoload/*"
vim-data_files += "/usr/share/vim/vim74/colors/*"
vim-data_files += "/usr/share/vim/vim74/compiler/*"
vim-data_files += "/usr/share/vim/vim74/doc/*"
vim-data_files += "/usr/share/vim/vim74/ftplugin/*"
vim-data_files += "/usr/share/vim/vim74/indent/*"
vim-data_files += "/usr/share/vim/vim74/keymap/*"
vim-data_files += "/usr/share/vim/vim74/lang/*"
vim-data_files += "/usr/share/vim/vim74/macros/*"
vim-data_files += "/usr/share/vim/vim74/plugin/*"
vim-data_files += "/usr/share/vim/vim74/print/*"
vim-data_files += "/usr/share/vim/vim74/spell/*"
vim-data_files += "/usr/share/vim/vim74/syntax/*"
vim-data_files += "/usr/share/vim/vim74/tools/ccfilter.1"
vim-data_files += "/usr/share/vim/vim74/tools/ccfilter_README.txt"
vim-data_files += "/usr/share/vim/vim74/tools/efm_filter.pl"
vim-data_files += "/usr/share/vim/vim74/tools/efm_filter.txt"
vim-data_files += "/usr/share/vim/vim74/tools/efm_perl.pl"
vim-data_files += "/usr/share/vim/vim74/tools/mve.awk"
vim-data_files += "/usr/share/vim/vim74/tools/mve.txt"
vim-data_files += "/usr/share/vim/vim74/tools/pltags.pl"
vim-data_files += "/usr/share/vim/vim74/tools/README.txt"
vim-data_files += "/usr/share/vim/vim74/tools/ref"
vim-data_files += "/usr/share/vim/vim74/tools/shtags.1"
vim-data_files += "/usr/share/vim/vim74/tools/shtags.pl"
vim-data_files += "/usr/share/vim/vim74/tools/unicode.vim"
vim-data_files += "/usr/share/vim/vim74/tools/vimm"
vim-data_files += "/usr/share/vim/vim74/tools/vimspell.sh"
vim-data_files += "/usr/share/vim/vim74/tools/vimspell.txt"
vim-data_files += "/usr/share/vim/vim74/tools/vim_vs_net.cmd"
vim-data_files += "/usr/share/vim/vim74/tutor/*"
vim-data_files += "/usr/share/vim/vim74/delmenu.vim"
vim-data_files += "/usr/share/vim/vim74/menu.vim"
vim-data_files += "/usr/share/vim/vim74/mswin.vim"
vim-data_files += "/usr/share/vim/vim74/synmenu.vim"
vim-data_files += "/usr/share/vim/vim74/gvimrc_example.vim"
vim-data_files += "/usr/share/vim/vim74/vimrc_example.vim"

vim-base_files = ""
vim-base_files += "vim.manifest"
vim-base_files += "/etc/vimrc"
vim-base_files += "/usr/bin/edit"
vim-base_files += "/usr/bin/ex"
vim-base_files += "/usr/bin/rview"
vim-base_files += "/usr/bin/rvim"
vim-base_files += "/usr/bin/vi"
vim-base_files += "/usr/bin/vim"
vim-base_files += "/usr/bin/view"
vim-base_files += "/usr/bin/vimdiff"
vim-base_files += "/usr/bin/vimtutor"
vim-base_files += "/usr/bin/xxd"
vim-base_files += "/usr/share/doc/packages/vim"
vim-base_files += "/usr/share/vim/current"
vim-base_files += "/usr/share/vim/"
vim-base_files += "/usr/share/vim/vim74/"
vim-base_files += "/usr/share/vim/vim74/autoload/"
vim-base_files += "/usr/share/vim/vim74/colors/"
vim-base_files += "/usr/share/vim/vim74/compiler/"
vim-base_files += "/usr/share/vim/vim74/doc/"
vim-base_files += "/usr/share/vim/vim74/ftplugin/"
vim-base_files += "/usr/share/vim/vim74/indent/"
vim-base_files += "/usr/share/vim/vim74/keymap/"
vim-base_files += "/usr/share/vim/vim74/lang/"
vim-base_files += "/usr/share/vim/vim74/macros/"
vim-base_files += "/usr/share/vim/vim74/plugin/"
vim-base_files += "/usr/share/vim/vim74/print/"
vim-base_files += "/usr/share/vim/vim74/spell/"
vim-base_files += "/usr/share/vim/vim74/syntax/"
vim-base_files += "/usr/share/vim/vim74/tools/"
vim-base_files += "/usr/share/vim/vim74/tutor/"
vim-base_files += "/usr/share/vim/vim74/skeletons/"
vim-base_files += "/usr/share/vim/site"
vim-base_files += "/usr/share/vim/site/autoload/"
vim-base_files += "/usr/share/vim/site/colors/"
vim-base_files += "/usr/share/vim/site/doc/"
vim-base_files += "/usr/share/vim/site/plugin/"
vim-base_files += "/usr/share/vim/site/syntax/"
vim-base_files += "/usr/share/vim/site/ftdetect/"
vim-base_files += "/usr/share/vim/site/after/"
vim-base_files += "/usr/share/vim/site/after/syntax/"
vim-base_files += "/usr/share/vim/vim74/bugreport.vim"
vim-base_files += "/usr/share/vim/vim74/evim.vim"
vim-base_files += "/usr/share/vim/vim74/filetype.vim"
vim-base_files += "/usr/share/vim/vim74/ftoff.vim"
vim-base_files += "/usr/share/vim/vim74/ftplugin.vim"
vim-base_files += "/usr/share/vim/vim74/ftplugof.vim"
vim-base_files += "/usr/share/vim/vim74/indent.vim"
vim-base_files += "/usr/share/vim/vim74/indoff.vim"
vim-base_files += "/usr/share/vim/vim74/optwin.vim"
vim-base_files += "/usr/share/vim/vim74/scripts.vim"
vim-base_files += "/usr/share/vim/vim74/syntax/syntax.vim"

vim_files = ""
vim_files += "vim.manifest"
vim_files += "/usr/bin/vim-normal"

vim-docs_files = ""
vim-docs_files += "/usr/share/info"
vim-docs_files += "/usr/share/man"

vim-enhanced_files = ""
vim-enhanced_files += "vim.manifest"
vim-enhanced_files += "/usr/bin/vim-enhanced"

FILES_${PN}-data = "${vim-data_files}"
FILES_${PN}-base = "${vim-base_files}"
FILES_${PN} = "${vim_files}"
FILES_${PN}-docs = "${vim-docs_files}"
FILES_${PN}-enhanced = "${vim-enhanced_files}"

PKG_vim-data= "vim-data"
PKG_vim-base= "vim-base"
PKG_vim= "vim"
PKG_vim-docs= "vim-docs"
PKG_vim-enhanced= "vim-enhanced"

require vim-extraconf.inc
