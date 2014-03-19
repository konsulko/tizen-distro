DESCRIPTION = "Yasm Modular Assembler"
HOMEPAGE = "http://yasm.tortall.net/"
SECTION = "System/Libraries"
LICENSE = "BSD-2-Clause or BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by yasm 
PROVIDES += "yasm"
RPROVIDES_yasm += "yasm"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of yasm 
DEPENDS += "binutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/yasm.manifest .
 
 
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
 
 ./configure --prefix=/usr
 
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
 
 
}

PACKAGES = ""
PACKAGES += "yasm"

yasm_files = ""
yasm_files += "yasm.manifest"
yasm_files += "/usr/bin/yasm"
yasm_files += "/usr/bin/vsyasm"
yasm_files += "/usr/bin/ytasm"
yasm_files += "/usr/include/libyasm-stdint.h"
yasm_files += "/usr/include/libyasm.h"
yasm_files += "/usr/include/libyasm/*"
yasm_files += "/usr/share/man/man1/yasm.1.gz"
yasm_files += "/usr/share/man/man7/yasm_arch.7.gz"
yasm_files += "/usr/share/man/man7/yasm_dbgfmts.7.gz"
yasm_files += "/usr/share/man/man7/yasm_objfmts.7.gz"
yasm_files += "/usr/share/man/man7/yasm_parsers.7.gz"

FILES_${PN} = "${yasm_files}"

PKG_yasm= "yasm"

require yasm-extraconf.inc
