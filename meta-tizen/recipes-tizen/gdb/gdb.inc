DESCRIPTION = "A GNU source-level debugger for C, C++, Java and other languages"
HOMEPAGE = "http://gnu.org/software/gdb/"
SECTION = "Development/Toolchain"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gdb-devel 
PROVIDES += "gdb-devel"
RPROVIDES_gdb-devel += "gdb-devel"
RPROVIDES_gdb-devel += "gdb-dev"

#PROVIDES by gdb 
PROVIDES += "gdb"
RPROVIDES_gdb += "gdb"

#PROVIDES by gdb-docs  
PROVIDES += "gdb-docs "
RPROVIDES_gdb-docs  += "gdb-docs "

#PROVIDES by gdb-server 
PROVIDES += "gdb-server"
RPROVIDES_gdb-server += "gdb-server"

#PROVIDES by gdb-locale  
PROVIDES += "gdb-locale "
RPROVIDES_gdb-locale  += "gdb-locale "
# the PROVIDES rules is ignore "gdb-lang-all = 7.5.1"
PROVIDES += "gdb-lang-all"
RPROVIDES_gdb-locale  += "gdb-lang-all"

RDEPENDS = ""
#RDEPENDS of gdb-locale  (${PN}-locale )
RDEPENDS_${PN}-locale  += "gdb"


DEPENDS = ""
#DEPENDS of gdb 
DEPENDS += "flex"
DEPENDS += "gcc-cross"
DEPENDS += "python-devel"
DEPENDS += "ncurses-devel"
DEPENDS += "expat"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext
DEPENDS += "rpm-devel"
DEPENDS += "bison-native"
DEPENDS += "makeinfo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/gdb.manifest .
 
 # Remove the info and other generated files added by the FSF release
 # process.
 rm -f libdecnumber/gstdint.h
 rm -f bfd/doc/*.info
 rm -f bfd/doc/*.info-*
 rm -f gdb/doc/*.info
 rm -f gdb/doc/*.info-*
 
 
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
         --infodir=/usr/share/info						\
 	--with-gdb-datadir=/usr/share/gdb		\
 	--enable-gdb-build-warnings=,-Wno-unused	\
 	--disable-werror				\
 	--with-separate-debug-dir=/usr/lib/debug	\
 	--disable-sim					\
 	--disable-rpath					\
 	--with-expat					\
 	--enable-64-bit-bfd				\
 	--enable-static --disable-shared --enable-debug
 
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
 
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} opcodes
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} bfd
 mv opcodes.lang gdb.lang
 cat bfd.lang >> gdb.lang
 
 
 
}

PACKAGES = ""
PACKAGES += "gdb-devel"
PACKAGES += "gdb"
PACKAGES += "gdb-server"
PACKAGES += "gdb-locale"
PACKAGES += "gdb-docs"

gdb-devel_files = ""
gdb-devel_files += "gdb.manifest"
gdb-devel_files += "/usr/include/*.h"
gdb-devel_files += "/usr/include/gdb/*.h"

gdb_files = ""
gdb_files += "gdb.manifest"
gdb_files += "/usr/bin/*"
gdb_files += "/usr/share/gdb"

gdb-server_files = ""
gdb-server_files += "gdb.manifest"
gdb-server_files += "/usr/bin/gdbserver"
gdb-server_files += "/usr/share/man/*/gdbserver.1*"
gdb-server_files += "/usr/lib/libinproctrace.so"

gdb-locale_files = ""

gdb-docs_files = ""
gdb-docs_files += "/usr/share/info"
gdb-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${gdb-devel_files}"
FILES_${PN} = "${gdb_files}"
FILES_${PN}-server = "${gdb-server_files}"
FILES_${PN}-locale = "${gdb-locale_files}"
FILES_${PN}-docs = "${gdb-docs_files}"

PKG_gdb-devel= "gdb-devel"
PKG_gdb= "gdb"
PKG_gdb-server= "gdb-server"
PKG_gdb-locale= "gdb-locale"
PKG_gdb-docs= "gdb-docs"

require gdb-extraconf.inc
