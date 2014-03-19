DESCRIPTION = "The GNU Bourne Again shell"
HOMEPAGE = "http://www.gnu.org/software/bash"
SECTION = "Base/Tools"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by bash-docs  
PROVIDES += "bash-docs "
RPROVIDES_bash-docs  += "bash-docs "

#PROVIDES by bash 
PROVIDES += "bash"
RPROVIDES_bash += "bash"
# the PROVIDES rules is ignore "/bin/bash  "
PROVIDES += "/bin/bash"
RPROVIDES_bash += "/bin/bash"
# the PROVIDES rules is ignore "/bin/sh  "
PROVIDES += "/bin/sh"
RPROVIDES_bash += "/bin/sh"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of bash 
DEPENDS += "autoconf-native"
DEPENDS += "bison-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bash.manifest .
 
 
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
         --infodir=/usr/share/info --enable-largefile \
             --without-bash-malloc \
             --disable-nls \
             --enable-alias \
             --enable-readline  \
             --enable-history
 
 # Recycles pids is neccessary. When bash's last fork's pid was X
 # and new fork's pid is also X, bash has to wait for this same pid.
 # Without Recycles pids bash will not wait.
 make "CPPFLAGS=-D_GNU_SOURCE -DDEFAULT_PATH_VALUE='\"/usr/local/bin:/usr/bin\"' -DRECYCLES_PIDS `getconf LFS_CFLAGS`"
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
 
 mkdir -p ${D}/etc/bash_completion.d
 
 # make manpages for bash builtins as per suggestion in DOC/README
 pushd doc
 sed -e '
 /^\.SH NAME/, /\\- bash built-in commands, see \\fBbash\\fR(1)$/{
 /^\.SH NAME/d
 s/^bash, //
 s/\\- bash built-in commands, see \\fBbash\\fR(1)$//
 s/,//g
 b
 }
 d
 ' builtins.1 > man.pages
 # '
 for i in echo pwd test kill; do
   perl -pi -e "s,$i,,g" man.pages
   perl -pi -e "s,  , ,g" man.pages
 done
 
 install -c -m 644 builtins.1 ${D}/usr/share/man/man1/builtins.1
 install -c -m 644 bash.1 ${D}/usr/share/man/man1/bash.1
 
 for i in `cat man.pages` ; do
   echo .so man1/builtins.1 > ${D}/usr/share/man/man1/$i.1
   chmod 0644 ${D}/usr/share/man/man1/$i.1
 done
 popd
 
 # Link bash man page to sh so that man sh works.
 ln -s bash.1 ${D}/usr/share/man/man1/sh.1
 
 # Not for printf, true and false (conflict with coreutils)
 rm -f ${D}//usr/share/man/man1/printf.1
 rm -f ${D}//usr/share/man/man1/true.1
 rm -f ${D}//usr/share/man/man1/false.1
 
 pushd ${D}
 ln -sf bash ./usr/bin/sh
 rm -f ./usr/share/info/dir
 popd
 mkdir -p ${D}/etc/skel
 install -c -m644 ${S}/packaging/dot.bashrc ${D}/etc/skel/.bashrc
 install -c -m644 ${S}/packaging/dot.profile ${D}/etc/skel/.bash_profile
 LONG_BIT=$(getconf LONG_BIT)
 mv ${D}/usr/bin/bashbug \
    ${D}/usr/bin/bashbug-"${LONG_BIT}"
 
 # Fix missing sh-bangs in example scripts (bug #225609).
 for script in \
   examples/scripts/krand.bash \
   examples/scripts/bcsh.sh \
   examples/scripts/precedence \
   examples/scripts/shprompt
 do
   cp "$script" "$script"-orig
   echo '#!/bin/bash' > "$script"
   cat "$script"-orig >> "$script"
   rm -f "$script"-orig
 done
 
 rm -rf ${D}/usr/bin/bashbug-*
 chmod a-x doc/*.sh
 
 
 
}

PACKAGES = ""
PACKAGES += "bash-docs"
PACKAGES += "bash"

bash-docs_files = ""
bash-docs_files += "/usr/share/info"
bash-docs_files += "/usr/share/man"

bash_files = ""
bash_files += "bash.manifest"
bash_files += "/usr/bin/sh"
bash_files += "/usr/bin/bash"
bash_files += "/etc/skel"
bash_files += "/etc/bash_completion.d"

FILES_${PN}-docs = "${bash-docs_files}"
FILES_${PN} = "${bash_files}"

PKG_bash-docs= "bash-docs"
PKG_bash= "bash"

require bash-extraconf.inc
