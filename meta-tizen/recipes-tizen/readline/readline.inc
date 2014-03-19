DESCRIPTION = "The Readline Library"
HOMEPAGE = "http://www.gnu.org/software/bash/bash.html"
SECTION = "Base/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libreadline 
PROVIDES += "libreadline"
RPROVIDES_libreadline += "libreadline"

#PROVIDES by readline 
PROVIDES += "readline"
RPROVIDES_readline += "readline"
# the PROVIDES rules is ignore "bash://usr/lib/libreadline.so.5  "
PROVIDES += "bash://usr/lib/libreadline.so.5"
RPROVIDES_readline += "bash://usr/lib/libreadline.so.5"

#PROVIDES by readline-devel 
PROVIDES += "readline-devel"
RPROVIDES_readline-devel += "readline-devel"
RPROVIDES_readline-devel += "readline-dev"
# the PROVIDES rules is ignore "bash:/usr/lib/libreadline.a  "
PROVIDES += "bash:/usr/lib/libreadline.a"
RPROVIDES_readline-devel += "bash:/usr/lib/libreadline.a"

RDEPENDS = ""
#RDEPENDS of readline-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libreadline"
RDEPENDS_${PN}-devel += "ncurses-dev"


DEPENDS = ""
#DEPENDS of readline 
DEPENDS += "ncurses"
DEPENDS += "autoconf-native"
DEPENDS += "bison-native"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n readline-5.2
 cp ${S}/packaging/readline.manifest .
 
 
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
 
   autoconf
   cflags ()
   {
       local flag=$1; shift
       case "-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" in
       *${flag}*) return
       esac
       if test -n "$1" && gcc -Werror $flag -S -o /dev/null -xc   /dev/null > /dev/null 2>&1 ; then
 	  local var=$1; shift
 	  eval $var=\${$var:+\$$var\ }$flag
       fi
   }
   echo 'int main () { return !(sizeof(void*) >= 8); }' | gcc -x c -o test64 -
   if ./test64 ; then
       LARGEFILE=""
   else
       LARGEFILE="-D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64"
   fi
   rm -f ./test64
   CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables $LARGEFILE -D_GNU_SOURCE -DRECYCLES_PIDS -Wall -g"
   LDFLAGS=""
   cflags -std=gnu89              CFLAGS
   cflags -Wuninitialized         CFLAGS
   cflags -Wextra                 CFLAGS
   cflags -Wno-unprototyped-calls CFLAGS
   cflags -Wno-switch-enum        CFLAGS
   cflags -ftree-loop-linear      CFLAGS
   cflags -pipe                   CFLAGS
   cflags -Wl,--as-needed         LDFLAGS
   cflags -Wl,-O,2                LDFLAGS
   CC=gcc
   CC_FOR_BUILD="$CC"
   CFLAGS_FOR_BUILD="$CFLAGS"
   LDFLAGS_FOR_BUILD="$LDFLAGS"
   export CC_FOR_BUILD CFLAGS_FOR_BUILD LDFLAGS_FOR_BUILD CFLAGS LDFLAGS CC
   ./configure --build=x86_64-tizen-linux	\
 	--prefix=/usr			\
 	--with-curses			\
 	--mandir=/usr/share/man		\
 	--infodir=/usr/share/info		\
 	--libdir=/usr/lib
   make
   make documentation
   ln -sf shlib/libreadline.so.5.2 libreadline.so
   ln -sf shlib/libreadline.so.5.2 libreadline.so.5
   ln -sf shlib/libhistory.so.5.2 libhistory.so
   ln -sf shlib/libhistory.so.5.2 libhistory.so.5
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
   make install htmldir=/usr/share/doc/packages/readline DESTDIR=${D}
   make install-shared libdir=//usr/lib linkagedir=/usr/lib DESTDIR=${D}
   rm -rf ${D}/usr/share/doc/packages/bash
   rm -rf ${D}/usr/share/doc/packages/readline
   chmod 0755 ${D}//usr/lib/libhistory.so.5.2
   chmod 0755 ${D}//usr/lib/libreadline.so.5.2
   rm -f ${D}//usr/lib/libhistory.so.5.2*old
   rm -f ${D}//usr/lib/libreadline.so.5.2*old
   # remove unpackaged files
   #rm -fv ${D}/usr/lib/libhistory.so.*
   #rm -fv ${D}/usr/lib/libreadline.so.*
   rm -fv ${D}/usr/share/man/man3/history.3*
   rm -fv ${D}/usr/share/info/*.info*
 
 
}

PACKAGES = ""
PACKAGES += "libreadline"
PACKAGES += "readline-devel"

libreadline_files = ""
libreadline_files += "readline.manifest"
libreadline_files += "/usr/lib/libhistory.so.5"
libreadline_files += "/usr/lib/libhistory.so.5.2"
libreadline_files += "/usr/lib/libreadline.so.5"
libreadline_files += "/usr/lib/libreadline.so.5.2"

readline-devel_files = ""
readline-devel_files += "readline.manifest"
readline-devel_files += "/usr/include/readline/"
readline-devel_files += "/usr/lib/libhistory.a"
readline-devel_files += "/usr/lib/libhistory.so"
readline-devel_files += "/usr/lib/libreadline.a"
readline-devel_files += "/usr/lib/libreadline.so"
readline-devel_files += "/usr/share/man/man3/readline.3.gz"

FILES_lib${PN} = "${libreadline_files}"
FILES_${PN}-devel = "${readline-devel_files}"

PKG_libreadline= "libreadline"
PKG_readline-devel= "readline-devel"

require readline-extraconf.inc
