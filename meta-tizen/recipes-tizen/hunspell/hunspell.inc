DESCRIPTION = "Hunspell - a spell checker and morphological analyzer library"
HOMEPAGE = "http://hunspell.sourceforge.net/"
SECTION = "System/Libraries"
LICENSE = "(GPL-2.0+ or LGPL-2.1+ or MPL-1.1+) and LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by hunspell-docs  
PROVIDES += "hunspell-docs "
RPROVIDES_hunspell-docs  += "hunspell-docs "

#PROVIDES by hunspell-devel 
PROVIDES += "hunspell-devel"
RPROVIDES_hunspell-devel += "hunspell-devel"
RPROVIDES_hunspell-devel += "hunspell-dev"

#PROVIDES by hunspell-static 
PROVIDES += "hunspell-static"
RPROVIDES_hunspell-static += "hunspell-static"

#PROVIDES by hunspell 
PROVIDES += "hunspell"
RPROVIDES_hunspell += "hunspell"

#PROVIDES by hunspell-tools 
PROVIDES += "hunspell-tools"
RPROVIDES_hunspell-tools += "hunspell-tools"

RDEPENDS = ""
#RDEPENDS of hunspell-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "pkgconfig"
RDEPENDS_${PN}-devel += "hunspell"
RDEPENDS_${PN}-devel += "libstdc++-dev"

#RDEPENDS of hunspell-static (${PN}-static)
RDEPENDS_${PN}-static += "hunspell-dev"

#RDEPENDS of hunspell-tools (${PN}-tools)
RDEPENDS_${PN}-tools += "hunspell"


DEPENDS = ""
#DEPENDS of hunspell 
DEPENDS += "gcc-cross"
DEPENDS += "readline-devel"
DEPENDS += "ncurses-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "automake-native"
DEPENDS += "libtool-cross"
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/hunspell.manifest .
 
 
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
         --infodir=/usr/share/info \
 	--with-ui \
 	--with-readline
 make -j16
 
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
 rm -f ${D}/usr/bin/example
 install -m 644 src/tools/{,un}munch.h ${D}/usr/include
 rm -rf ${D}/usr/share/man/hu
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} hunspell
 
 
 
}

PACKAGES = ""
PACKAGES += "hunspell-devel"
PACKAGES += "hunspell"
PACKAGES += "hunspell-docs"
PACKAGES += "hunspell-tools"

hunspell-devel_files = ""
hunspell-devel_files += "hunspell.manifest"
hunspell-devel_files += "/usr/include/hunspell"
hunspell-devel_files += "/usr/include/munch.h"
hunspell-devel_files += "/usr/include/unmunch.h"
hunspell-devel_files += "/usr/lib/pkgconfig/hunspell.pc"

hunspell_files = ""
hunspell_files += "hunspell.manifest"
hunspell_files += "COPYING license.hunspell license.myspell"

hunspell-docs_files = ""
hunspell-docs_files += "/usr/share/info"
hunspell-docs_files += "/usr/share/man"

hunspell-tools_files = ""
hunspell-tools_files += "hunspell.manifest"

FILES_${PN}-devel = "${hunspell-devel_files}"
FILES_${PN} = "${hunspell_files}"
FILES_${PN}-docs = "${hunspell-docs_files}"
FILES_${PN}-tools = "${hunspell-tools_files}"

PKG_hunspell-devel= "hunspell-devel"
PKG_hunspell= "hunspell"
PKG_hunspell-docs= "hunspell-docs"
PKG_hunspell-tools= "hunspell-tools"

require hunspell-extraconf.inc
