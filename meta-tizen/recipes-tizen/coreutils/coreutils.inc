DESCRIPTION = "GNU Core Utilities"
HOMEPAGE = "http://www.gnu.org/software/coreutils/"
SECTION = "Base/Utilities"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by coreutils-locale  
PROVIDES += "coreutils-locale "
RPROVIDES_coreutils-locale  += "coreutils-locale "
# the PROVIDES rules is ignore "coreutils-lang-all = 8.21"
PROVIDES += "coreutils-lang-all"
RPROVIDES_coreutils-locale  += "coreutils-lang-all"

#PROVIDES by coreutils 
PROVIDES += "coreutils"
RPROVIDES_coreutils += "coreutils"
# the PROVIDES rules is ignore "fileutils = 8.21"
PROVIDES += "fileutils"
RPROVIDES_coreutils += "fileutils"
# the PROVIDES rules is ignore "mktemp = 8.21"
PROVIDES += "mktemp"
RPROVIDES_coreutils += "mktemp"
# the PROVIDES rules is ignore "sh-utils = 8.21"
PROVIDES += "sh-utils"
RPROVIDES_coreutils += "sh-utils"
# the PROVIDES rules is ignore "stat = 8.21}"
PROVIDES += "stat"
RPROVIDES_coreutils += "stat"
# the PROVIDES rules is ignore "textutils = 8.21"
PROVIDES += "textutils"
RPROVIDES_coreutils += "textutils"
# the PROVIDES rules is ignore "/bin/basename  "
PROVIDES += "/bin/basename"
RPROVIDES_coreutils += "/bin/basename"
# the PROVIDES rules is ignore "/bin/cat  "
PROVIDES += "/bin/cat"
RPROVIDES_coreutils += "/bin/cat"
# the PROVIDES rules is ignore "/bin/chmod  "
PROVIDES += "/bin/chmod"
RPROVIDES_coreutils += "/bin/chmod"
# the PROVIDES rules is ignore "/bin/chown  "
PROVIDES += "/bin/chown"
RPROVIDES_coreutils += "/bin/chown"
# the PROVIDES rules is ignore "/bin/cp  "
PROVIDES += "/bin/cp"
RPROVIDES_coreutils += "/bin/cp"
# the PROVIDES rules is ignore "/bin/ln  "
PROVIDES += "/bin/ln"
RPROVIDES_coreutils += "/bin/ln"
# the PROVIDES rules is ignore "/bin/ls  "
PROVIDES += "/bin/ls"
RPROVIDES_coreutils += "/bin/ls"
# the PROVIDES rules is ignore "/bin/mkdir  "
PROVIDES += "/bin/mkdir"
RPROVIDES_coreutils += "/bin/mkdir"
# the PROVIDES rules is ignore "/bin/mv  "
PROVIDES += "/bin/mv"
RPROVIDES_coreutils += "/bin/mv"
# the PROVIDES rules is ignore "/bin/pwd  "
PROVIDES += "/bin/pwd"
RPROVIDES_coreutils += "/bin/pwd"
# the PROVIDES rules is ignore "/bin/rm  "
PROVIDES += "/bin/rm"
RPROVIDES_coreutils += "/bin/rm"
# the PROVIDES rules is ignore "/bin/sort  "
PROVIDES += "/bin/sort"
RPROVIDES_coreutils += "/bin/sort"
# the PROVIDES rules is ignore "/bin/touch  "
PROVIDES += "/bin/touch"
RPROVIDES_coreutils += "/bin/touch"

#PROVIDES by coreutils-docs  
PROVIDES += "coreutils-docs "
RPROVIDES_coreutils-docs  += "coreutils-docs "

RDEPENDS = ""
#RDEPENDS of coreutils-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "coreutils"

#RDEPENDS of coreutils (${PN})
RDEPENDS_${PN} += "pam"


DEPENDS = ""
#DEPENDS of coreutils 
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "gmp-devel"
DEPENDS += "gperf"
DEPENDS += "acl"
DEPENDS += "xz"
DEPENDS += "bison-native"
DEPENDS += "makeinfo"
DEPENDS += "libcap-devel"
DEPENDS += "help2man-native"
DEPENDS += "smack-devel"
DEPENDS += "automake-native"
DEPENDS += "pam-devel"

do_patch() {
 #extracte source 4 
 pushd ${S}
 unp ${S}/packaging/gnulib.tar.bz2 
 popd 
 #extracte source 5 
 pushd ${S}
 unp ${S}/packaging/po.tar.bz2 
 popd 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -a 4 -a 5
 cp ${S}/packaging/coreutils.manifest .
 
 
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
 
 ./bootstrap --no-git --gnulib-srcdir=gnulib --skip-po --no-bootstrap-sync
 #AUTOPOINT=true autoreconf -fi
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wall"
 
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
         --infodir=/usr/share/info --libexecdir=/usr/lib --without-included-regex \
   	    --enable-install-program=arch \
 	    --enable-no-install-program=uptime \
 	    --enable-libsmack=yes \
 	    gl_cv_func_printf_directive_n=yes \
 	    gl_cv_func_isnanl_works=yes \
   	    DEFAULT_POSIX2_VERSION=199209
 
 make -C po update-po
 make -j16 V=1
 
 
 
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
   find ${D} -regex ".*\.a$" | xargs rm -f -- pkglibexecdir=/usr/lib/coreutils
 echo '.so man1/test.1' > ${D}//usr/share/man/man1/\[.1
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} coreutils
 
 
 
}

PACKAGES = ""
PACKAGES += "coreutils"
PACKAGES += "coreutils-locale"
PACKAGES += "coreutils-docs"

coreutils_files = ""
coreutils_files += "coreutils.manifest"
coreutils_files += "README NEWS"
coreutils_files += "/usr/bin/*"
coreutils_files += "/usr/lib/coreutils"
coreutils_files += "/usr/share/locale/*/LC_TIME"

coreutils-locale_files = ""

coreutils-docs_files = ""
coreutils-docs_files += "/usr/share/info"
coreutils-docs_files += "/usr/share/man"

FILES_${PN} = "${coreutils_files}"
FILES_${PN}-locale = "${coreutils-locale_files}"
FILES_${PN}-docs = "${coreutils-docs_files}"

PKG_coreutils= "coreutils"
PKG_coreutils-locale= "coreutils-locale"
PKG_coreutils-docs= "coreutils-docs"

require coreutils-extraconf.inc
