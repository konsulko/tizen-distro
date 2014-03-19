DESCRIPTION = "GNU libraries and utilities for producing multi-lingual messages"
HOMEPAGE = "http://www.gnu.org/software/gettext/"
SECTION = "Development/Tools"
LICENSE = "GPL-3.0+ and LGPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gettext-docs  
PROVIDES += "gettext-docs "
RPROVIDES_gettext-docs  += "gettext-docs "

#PROVIDES by gettext-runtime 
PROVIDES += "gettext-runtime"
RPROVIDES_gettext-runtime += "gettext-runtime"
# the PROVIDES rules is ignore "gettext-libs  "
PROVIDES += "gettext-libs"
RPROVIDES_gettext-runtime += "gettext-libs"

#PROVIDES by gettext-tools 
PROVIDES += "gettext-tools"
RPROVIDES_gettext-tools += "gettext-tools"
# the PROVIDES rules is ignore "gettext-devel  "
PROVIDES += "gettext-devel"
RPROVIDES_gettext-tools += "gettext-devel"
RPROVIDES_gettext-tools += "gettext-dev"

#PROVIDES by gettext 
PROVIDES += "gettext"
RPROVIDES_gettext += "gettext"

RDEPENDS = ""
#RDEPENDS of gettext-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "gettext-runtime"


DEPENDS = ""
#DEPENDS of gettext 
DEPENDS += "gcc-cross"
DEPENDS += "libunistring"
DEPENDS += "eglibc-locale"
DEPENDS += "expat"
DEPENDS += "libtool-cross"
DEPENDS += "bison-native"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
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
 
 cp ${S}/packaging/gettext.manifest .
 [ -f  /usr/share/automake/depcomp ] && cp -f /usr/share/automake/{depcomp,ylwrap} .
 
 
 mkdir -p gettext-tools/intl
 
 
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
         --infodir=/usr/share/info --without-included-gettext --enable-nls --disable-static \
     --enable-shared --with-pic-=yes --disable-csharp --without-libpth-prefix --disable-openmp
 make -j16 GCJFLAGS="-findirect-dispatch"
 
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
 
 make install DESTDIR=${D} INSTALL="install -p" \
     lispdir=/usr/share/emacs/site-lisp \
     aclocaldir=/usr/share/aclocal EXAMPLESFILES=""
 
 install -pm 755 ${S}/packaging/msghack.py ${D}/usr/bin/msghack
 
 # make preloadable_libintl.so executable
 chmod 755 ${D}/usr/lib/preloadable_libintl.so
 
 rm -f ${D}/usr/share/info/dir
 
 # doc relocations
 for i in gettext-runtime/man/*.html; do
   rm ${D}/usr/share/doc/gettext/`basename $i`
 done
 rm -r ${D}/usr/share/doc/gettext/javadoc*
 
 rm -rf ${D}/usr/share/doc/gettext/examples
 
 rm -rf htmldoc
 mkdir htmldoc
 mv ${D}/usr/share/doc/gettext/* ${D}/usr/share/doc/libasprintf/* htmldoc
 rm -r ${D}/usr/share/doc/libasprintf
 rm -r ${D}/usr/share/doc/gettext
 
 # remove unpackaged files from the buildroot
 rm -rf ${D}/usr/share/emacs
 rm ${D}/usr/lib/lib*.la
 
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gettext-runtime
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gettext-tools
 cat gettext-*.lang > gettext.lang
 
 
 
}

PACKAGES = ""
PACKAGES += "gettext-runtime"
PACKAGES += "gettext-tools"
PACKAGES += "gettext-docs"

gettext-runtime_files = ""
gettext-runtime_files += "gettext.manifest"
gettext-runtime_files += "LGPL-2.0+ gettext-runtime/intl/COPYING*"
gettext-runtime_files += "/usr/share/gettext/ABOUT-NLS"
gettext-runtime_files += "/usr/bin/gettext"
gettext-runtime_files += "/usr/bin/ngettext"
gettext-runtime_files += "/usr/bin/envsubst"
gettext-runtime_files += "/usr/bin/gettext.sh"
gettext-runtime_files += "/usr/lib/libasprintf.so.*"

gettext-tools_files = ""
gettext-tools_files += "gettext.manifest"
gettext-tools_files += "LGPL-2.0+ COPYING"
gettext-tools_files += "/usr/share/gettext/projects/*"
gettext-tools_files += "/usr/share/gettext/config.rpath"
gettext-tools_files += "/usr/share/gettext/*.h"
gettext-tools_files += "/usr/share/gettext/intl"
gettext-tools_files += "/usr/share/gettext/po"
gettext-tools_files += "/usr/share/gettext/msgunfmt.tcl"
gettext-tools_files += "/usr/share/aclocal/*"
gettext-tools_files += "/usr/include/*"
gettext-tools_files += "/usr/lib/libasprintf.so"
gettext-tools_files += "/usr/lib/libgettextpo.so"
gettext-tools_files += "/usr/lib/libgettextlib*.so"
gettext-tools_files += "/usr/lib/libgettextsrc*.so"
gettext-tools_files += "/usr/lib/preloadable_libintl.so"
gettext-tools_files += "/usr/lib/gettext/hostname"
gettext-tools_files += "/usr/lib/gettext/project-id"
gettext-tools_files += "/usr/lib/gettext/urlget"
gettext-tools_files += "/usr/lib/gettext/user-email"
gettext-tools_files += "/usr/lib/libgettextpo.so.*"
gettext-tools_files += "/usr/share/gettext/javaversion.class"
gettext-tools_files += "/usr/share/gettext/archive*.tar.xz"
gettext-tools_files += "/usr/share/gettext/styles"
gettext-tools_files += "/usr/bin/autopoint"
gettext-tools_files += "/usr/bin/gettextize"
gettext-tools_files += "/usr/bin/msgattrib"
gettext-tools_files += "/usr/bin/msgcat"
gettext-tools_files += "/usr/bin/msgcmp"
gettext-tools_files += "/usr/bin/msgcomm"
gettext-tools_files += "/usr/bin/msgconv"
gettext-tools_files += "/usr/bin/msgen"
gettext-tools_files += "/usr/bin/msgexec"
gettext-tools_files += "/usr/bin/msgfilter"
gettext-tools_files += "/usr/bin/msgfmt"
gettext-tools_files += "/usr/bin/msggrep"
gettext-tools_files += "/usr/bin/msghack"
gettext-tools_files += "/usr/bin/msginit"
gettext-tools_files += "/usr/bin/msgmerge"
gettext-tools_files += "/usr/bin/msgunfmt"
gettext-tools_files += "/usr/bin/msguniq"
gettext-tools_files += "/usr/bin/recode-sr-latin"
gettext-tools_files += "/usr/bin/xgettext"

gettext-docs_files = ""
gettext-docs_files += "/usr/share/info"
gettext-docs_files += "/usr/share/man"

FILES_${PN}-runtime = "${gettext-runtime_files}"
FILES_${PN}-tools = "${gettext-tools_files}"
FILES_${PN}-docs = "${gettext-docs_files}"

PKG_gettext-runtime= "gettext-runtime"
PKG_gettext-tools= "gettext-tools"
PKG_gettext-docs= "gettext-docs"

require gettext-extraconf.inc
