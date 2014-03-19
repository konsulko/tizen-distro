DESCRIPTION = "Fast, scalable, distributed revision control system"
HOMEPAGE = "http://git-scm.com"
SECTION = "Development/Tools"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by git 
PROVIDES += "git"
RPROVIDES_git += "git"

#PROVIDES by git-daemon 
PROVIDES += "git-daemon"
RPROVIDES_git-daemon += "git-daemon"

#PROVIDES by git-arch 
PROVIDES += "git-arch"
RPROVIDES_git-arch += "git-arch"

#PROVIDES by gitk 
PROVIDES += "gitk"
RPROVIDES_gitk += "gitk"

#PROVIDES by git-gui 
PROVIDES += "git-gui"
RPROVIDES_git-gui += "git-gui"

#PROVIDES by git-svn 
PROVIDES += "git-svn"
RPROVIDES_git-svn += "git-svn"

#PROVIDES by git-remote-helpers 
PROVIDES += "git-remote-helpers"
RPROVIDES_git-remote-helpers += "git-remote-helpers"

#PROVIDES by git-cvs 
PROVIDES += "git-cvs"
RPROVIDES_git-cvs += "git-cvs"

#PROVIDES by git-core 
PROVIDES += "git-core"
RPROVIDES_git-core += "git-core"

#PROVIDES by git-web 
PROVIDES += "git-web"
RPROVIDES_git-web += "git-web"

#PROVIDES by git-email 
PROVIDES += "git-email"
RPROVIDES_git-email += "git-email"

RDEPENDS = ""
#RDEPENDS of git (${PN})
RDEPENDS_${PN} += "git-core"

#RDEPENDS of git-daemon (${PN}-daemon)
RDEPENDS_${PN}-daemon += "/usr/sbin/useradd"
RDEPENDS_${PN}-daemon += "git-core"

#RDEPENDS of git-arch (${PN}-arch)
RDEPENDS_${PN}-arch += "git-core"

#RDEPENDS of gitk (${PN}k)
RDEPENDS_${PN}k += "git-core"

#RDEPENDS of git-gui (${PN}-gui)
RDEPENDS_${PN}-gui += "git-core"

#RDEPENDS of git-svn (${PN}-svn)
RDEPENDS_${PN}-svn += "subversion"
RDEPENDS_${PN}-svn += "git-core"

#RDEPENDS of git-remote-helpers (${PN}-remote-helpers)
RDEPENDS_${PN}-remote-helpers += "python"
RDEPENDS_${PN}-remote-helpers += "git-core"

#RDEPENDS of git-cvs (${PN}-cvs)
RDEPENDS_${PN}-cvs += "git-core"

#RDEPENDS of git-core (${PN}-core)
RDEPENDS_${PN}-core += "openssh"
RDEPENDS_${PN}-core += "rsync"
RDEPENDS_${PN}-core += "perl"
RDEPENDS_${PN}-core += "perl-Error"
RDEPENDS_${PN}-core += "less"

#RDEPENDS of git-web (${PN}-web)
RDEPENDS_${PN}-web += "git-core"

#RDEPENDS of git-email (${PN}-email)
RDEPENDS_${PN}-email += "git-core"


DEPENDS = ""
#DEPENDS of git 
DEPENDS += "libopenssl-devel"
inherit pythonnative
DEPENDS += "expat"
DEPENDS += "asciidoc"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "curl"
DEPENDS += "fdupes-native"
DEPENDS += "perl-Error"
DEPENDS += "xmlto"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/git.manifest .
 
 
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
 
 cat > .make <<'EOF'
 #!/bin/bash
 make -j16 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" \
        GITWEB_CONFIG="/etc/gitweb.conf" \
        GITWEB_PROJECTROOT="/srv/git" \
        WITH_OWN_SUBPROCESS_PY=YesPlease \
        DESTDIR=${D} \
        NO_CROSS_DIRECTORY_HARDLINKS=1 \
        V=1 \
        prefix=/usr mandir=/usr/share/man \
        gitexecdir=/usr/libexec/git \
        htmldir=/usr/share/doc/packages/git-core \
        "$@"
 EOF
 #
 chmod 755 .make
 ./.make all -j16
 ./.make doc
 
 exit 0
 make -j16 test
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 ./.make install install-doc
 ###
 (find ${D}/usr/bin -type f | grep -vE "archimport|svn|cvs|email|gitk|daemon|gui" | sed -e s@^${D}@@)                   > bin-man-doc-files
 (find ${D}/usr/libexec/git -mindepth 1 | grep -vE "archimport|svn|cvs|email|gitk|daemon|gui" | sed -e s@^${D}@@)               >> bin-man-doc-files
 (find ${D}/usr/share/man ${D}/Documentation -type f | grep -vE "archimport|svn|git-cvs|email|gitk|daemon|gui" | sed -e s@^${D}@@ -e 's/$/*/' ) >> bin-man-doc-files
 ( pushd perl
   perl Makefile.PL
   make -f perl.mak DESTDIR=${D}  install_vendor
 )
 rm -rf ${D}/usr/lib/perl5/site_perl
 
   if test -n "$RPM_BUILD_ROOT" -a -d $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto; then 
     find $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto -name .packlist -print0 | xargs -0 -r rm 
     if [ x86_64 == noarch ]; then 
       find $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//auto -depth -type d -print0 | xargs -0 -r rmdir 
     fi 
   fi 
   rm -f $RPM_BUILD_ROOT/usr/lib/perl/5.14.3//perllocal.pod 
   
 find ${D}//usr/share/man -type f -print0 | xargs -0 chmod 644
 find ${D}//usr/lib/python2.7/site-packages/ -type f -name *.pyc -print0 | xargs -0 rm
 install -m 644 -D contrib/completion/git-completion.bash ${D}/etc/bash_completion.d/git.sh
 sed -i  "s#$RPM_BUILD_ROOT##g" ${D}//usr/libexec/git/git-remote-testgit
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} git
 cat git.lang >>bin-man-doc-files
 # use symlinks instead of hardlinks in sub-commands
 
 
 rm -rf ${D}//usr/share/gitweb
 rm -rf ${D}/Documentation/*.html
 rm -rf ${D}/Documentation/*.txt
 
 
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
 
 
 
}

PACKAGES = ""
PACKAGES += "git"
PACKAGES += "git-daemon"
PACKAGES += "git-arch"
PACKAGES += "gitk"
PACKAGES += "git-gui"
PACKAGES += "git-svn"
PACKAGES += "git-remote-helpers"
PACKAGES += "git-cvs"
PACKAGES += "git-core"
PACKAGES += "git-email"

git_files = ""
git_files += "git.manifest"
git_files += "README"

git-daemon_files = ""
git-daemon_files += "git.manifest"
git-daemon_files += "/usr/libexec/git/*daemon*"
git-daemon_files += "/usr/share/man/man1/*daemon*.1*"

git-arch_files = ""
git-arch_files += "git.manifest"
git-arch_files += "/usr/libexec/git/git-archimport"
git-arch_files += "/usr/share/man/man1/git-archimport.1*"

gitk_files = ""
gitk_files += "git.manifest"
gitk_files += "/usr/bin/gitk"
gitk_files += "/usr/share/gitk"
gitk_files += "/usr/share/man/man1/*gitk*.1*"

git-gui_files = ""
git-gui_files += "git.manifest"
git-gui_files += "/usr/libexec/git/git-gui*"
git-gui_files += "/usr/share/git-gui"
git-gui_files += "/usr/share/man/man1/*gui*.1*"

git-svn_files = ""
git-svn_files += "git.manifest"
git-svn_files += "/usr/libexec/git/*svn*"
git-svn_files += "/usr/share/man/man1/*svn*.1*"

git-remote-helpers_files = ""
git-remote-helpers_files += "git.manifest"
git-remote-helpers_files += "/usr/lib/python2.7/site-packages/*"

git-cvs_files = ""
git-cvs_files += "git.manifest"
git-cvs_files += "/usr/bin/git-cvs*"
git-cvs_files += "/usr/libexec/git/*cvs*"
git-cvs_files += "/usr/share/man/man1/*cvs*.1*"

git-core_files = ""
git-core_files += "git.manifest"
git-core_files += "/usr/bin/git"
git-core_files += "/usr/share/git-core/"
git-core_files += "/usr/libexec/git"
git-core_files += "/usr/lib/perl/5.14.3/Git.pm"
git-core_files += "/usr/lib/perl/5.14.3/Git/"
git-core_files += "/usr/lib/perl/5.14.3/Git/*.pm"
git-core_files += "/usr/lib/perl/5.14.3/auto/Git/"

git-email_files = ""
git-email_files += "git.manifest"
git-email_files += "/usr/libexec/git/*email*"
git-email_files += "/usr/share/man/man1/*email*.1*"

FILES_${PN} = "${git_files}"
FILES_${PN}-daemon = "${git-daemon_files}"
FILES_${PN}-arch = "${git-arch_files}"
FILES_${PN}k = "${gitk_files}"
FILES_${PN}-gui = "${git-gui_files}"
FILES_${PN}-svn = "${git-svn_files}"
FILES_${PN}-remote-helpers = "${git-remote-helpers_files}"
FILES_${PN}-cvs = "${git-cvs_files}"
FILES_${PN}-core = "${git-core_files}"
FILES_${PN}-email = "${git-email_files}"

PKG_git= "git"
PKG_git-daemon= "git-daemon"
PKG_git-arch= "git-arch"
PKG_gitk= "gitk"
PKG_git-gui= "git-gui"
PKG_git-svn= "git-svn"
PKG_git-remote-helpers= "git-remote-helpers"
PKG_git-cvs= "git-cvs"
PKG_git-core= "git-core"
PKG_git-email= "git-email"

require git-extraconf.inc
