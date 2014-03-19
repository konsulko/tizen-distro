DESCRIPTION = "Higher-level library to access ELF"
HOMEPAGE = "http://elfutils.fedorahosted.org"
SECTION = "Base/Utilities"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libasm 
PROVIDES += "libasm"
RPROVIDES_libasm += "libasm"

#PROVIDES by libasm-devel 
PROVIDES += "libasm-devel"
RPROVIDES_libasm-devel += "libasm-devel"
RPROVIDES_libasm-devel += "libasm-dev"

#PROVIDES by libdw-devel 
PROVIDES += "libdw-devel"
RPROVIDES_libdw-devel += "libdw-devel"
RPROVIDES_libdw-devel += "libdw-dev"

#PROVIDES by libebl-devel 
PROVIDES += "libebl-devel"
RPROVIDES_libebl-devel += "libebl-devel"
RPROVIDES_libebl-devel += "libebl-dev"

#PROVIDES by libelf-devel 
PROVIDES += "libelf-devel"
RPROVIDES_libelf-devel += "libelf-devel"
RPROVIDES_libelf-devel += "libelf-dev"

#PROVIDES by elfutils 
PROVIDES += "elfutils"
RPROVIDES_elfutils += "elfutils"

#PROVIDES by libdw 
PROVIDES += "libdw"
RPROVIDES_libdw += "libdw"

#PROVIDES by libelf 
PROVIDES += "libelf"
RPROVIDES_libelf += "libelf"

#PROVIDES by libebl 
PROVIDES += "libebl"
RPROVIDES_libebl += "libebl"

RDEPENDS = ""
#RDEPENDS of libebl-devel (libebl-devel)
RDEPENDS_libebl-devel += "glibc-dev"
RDEPENDS_libebl-devel += "libdw-dev"
RDEPENDS_libebl-devel += "libebl"

#RDEPENDS of libdw-devel (libdw-devel)
RDEPENDS_libdw-devel += "glibc-dev"
RDEPENDS_libdw-devel += "libdw"
RDEPENDS_libdw-devel += "libelf-dev"

#RDEPENDS of libelf-devel (libelf-devel)
RDEPENDS_libelf-devel += "glibc-dev"
RDEPENDS_libelf-devel += "libelf"

#RDEPENDS of libasm-devel (libasm-devel)
RDEPENDS_libasm-devel += "libasm"
RDEPENDS_libasm-devel += "glibc-dev"


DEPENDS = ""
#DEPENDS of elfutils 
DEPENDS += "zlib-devel"
DEPENDS += "flex"
DEPENDS += "bzip2"
DEPENDS += "xz-devel"
DEPENDS += "automake-native"
DEPENDS += "bison-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n elfutils-0.155
 cp ${S}/packaging/elfutils.manifest .
 
 
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
 
 #modified="$(sed -n '/^----/n;s/ - .*$//;p;q' "${S}/packaging//elfutils.changes")"
 #DATE="\"$(date -d "${modified}" "+%b %e %Y")\""
 #TIME="\"$(date -d "${modified}" "+%R")\""
 #find . -type f -regex ".*\.c\|.*\.cpp\|.*\.h" -exec sed -i "s/__DATE__/${DATE}/g;s/__TIME__/${TIME}/g" {} +
 autoreconf -fi
 
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
         --infodir=/usr/share/info --program-prefix=eu- --disable-werror
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
   
 # remove unneeded files
 ls -lR ${D}/usr/lib/libelf*
 
 
}

PACKAGES = ""
PACKAGES += "libasm"
PACKAGES += "libasm-devel"
PACKAGES += "libdw-devel"
PACKAGES += "libebl-devel"
PACKAGES += "libelf-devel"
PACKAGES += "elfutils"
PACKAGES += "libdw"
PACKAGES += "libelf"
PACKAGES += "libebl"

libasm_files = ""
libasm_files += "elfutils.manifest"
libasm_files += "LGPL-3.0+ or GPL-2.0 COPYING"
libasm_files += "/usr/lib/libasm.so.*"
libasm_files += "/usr/lib/libasm-0.155.so"

libasm-devel_files = ""
libasm-devel_files += "elfutils.manifest"
libasm-devel_files += "/usr/lib/libasm.so"
libasm-devel_files += "/usr/lib/libasm.a"
libasm-devel_files += "/usr/include/elfutils"
libasm-devel_files += "/usr/include/elfutils/libasm.h"

libdw-devel_files = ""
libdw-devel_files += "elfutils.manifest"
libdw-devel_files += "/usr/lib/libdw.a"
libdw-devel_files += "/usr/lib/libdw.so"
libdw-devel_files += "/usr/include/dwarf.h"
libdw-devel_files += "/usr/include/elfutils"
libdw-devel_files += "/usr/include/elfutils/libdw.h"
libdw-devel_files += "/usr/include/elfutils/libdwfl.h"

libebl-devel_files = ""
libebl-devel_files += "elfutils.manifest"
libebl-devel_files += "/usr/lib/libebl.a"
libebl-devel_files += "/usr/include/elfutils"
libebl-devel_files += "/usr/include/elfutils/libebl.h"

libelf-devel_files = ""
libelf-devel_files += "elfutils.manifest"
libelf-devel_files += "/usr/lib/libelf.so"
libelf-devel_files += "/usr/lib/libelf.a"
libelf-devel_files += "/usr/include/libelf.h"
libelf-devel_files += "/usr/include/gelf.h"
libelf-devel_files += "/usr/include/nlist.h"
libelf-devel_files += "/usr/include/elfutils"
libelf-devel_files += "/usr/include/elfutils/elf-knowledge.h"
libelf-devel_files += "/usr/include/elfutils/version.h"

elfutils_files = ""
elfutils_files += "elfutils.manifest"
elfutils_files += "/usr/bin/*"

libdw_files = ""
libdw_files += "elfutils.manifest"
libdw_files += "LGPL-3.0+ or GPL-2.0 COPYING"
libdw_files += "/usr/lib/libdw.so.*"
libdw_files += "/usr/lib/libdw-0.155.so"

libelf_files = ""
libelf_files += "elfutils.manifest"
libelf_files += "LGPL-3.0+ or GPL-2.0 COPYING"
libelf_files += "/usr/lib/libelf.so.*"
libelf_files += "/usr/lib/libelf-0.155.so"

libebl_files = ""
libebl_files += "elfutils.manifest"
libebl_files += "LGPL-3.0+ or GPL-2.0 COPYING"
libebl_files += "/usr/lib/elfutils"

FILES_libasm = "${libasm_files}"
FILES_libasm-devel = "${libasm-devel_files}"
FILES_libdw-devel = "${libdw-devel_files}"
FILES_libebl-devel = "${libebl-devel_files}"
FILES_libelf-devel = "${libelf-devel_files}"
FILES_${PN} = "${elfutils_files}"
FILES_libdw = "${libdw_files}"
FILES_libelf = "${libelf_files}"
FILES_libebl = "${libebl_files}"

PKG_libasm= "libasm"
PKG_libasm-devel= "libasm-devel"
PKG_libdw-devel= "libdw-devel"
PKG_libebl-devel= "libebl-devel"
PKG_libelf-devel= "libelf-devel"
PKG_elfutils= "elfutils"
PKG_libdw= "libdw"
PKG_libelf= "libelf"
PKG_libebl= "libebl"

require elfutils-extraconf.inc
