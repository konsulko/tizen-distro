DESCRIPTION = "Utilities for managing processes on your system"
HOMEPAGE = "http://sourceforge.net/projects/psmisc/"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by psmisc 
PROVIDES += "psmisc"
RPROVIDES_psmisc += "psmisc"
# the PROVIDES rules is ignore "ps:/usr/bin/killall  "
PROVIDES += "ps:/usr/bin/killall"
RPROVIDES_psmisc += "ps:/usr/bin/killall"

#PROVIDES by psmisc-docs  
PROVIDES += "psmisc-docs "
RPROVIDES_psmisc-docs  += "psmisc-docs "

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of psmisc 
DEPENDS += "ncurses"
DEPENDS += "gcc-cross"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "automake-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/psmisc.manifest .
 
 
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
 
 autoreconf -fi
 CFLAGS="-D_GNU_SOURCE ${RPM_OPT_FLAGS} -pipe"
 CXXFLAGS="$CFLAGS"
 CC=gcc
 CXX=g++
 export CFLAGS CXXFLAGS CC CXX
 sh ./configure --prefix=/usr --mandir=/usr/share/man \
 	--disable-rpath		\
 	--with-gnu-ld		\
 	--disable-nls		\
 	--enable-timeout-stat
 make -j16 CFLAGS="$CFLAGS" "CC=$CC"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=$RPM_BUILD_ROOT install
 
 
 
}

PACKAGES = ""
PACKAGES += "psmisc"
PACKAGES += "psmisc-docs"

psmisc_files = ""
psmisc_files += "psmisc.manifest"
psmisc_files += "/usr/bin/fuser"
psmisc_files += "/usr/bin/killall"
psmisc_files += "/usr/bin/peekfd"
psmisc_files += "/usr/bin/prtstat"
psmisc_files += "/usr/bin/pstree"
psmisc_files += "/usr/bin/pstree.x11"

psmisc-docs_files = ""
psmisc-docs_files += "/usr/share/info"
psmisc-docs_files += "/usr/share/man"

FILES_${PN} = "${psmisc_files}"
FILES_${PN}-docs = "${psmisc-docs_files}"

PKG_psmisc= "psmisc"
PKG_psmisc-docs= "psmisc-docs"

require psmisc-extraconf.inc
