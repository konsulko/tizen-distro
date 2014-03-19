DESCRIPTION = "A small virtual machine engine (in a library) and bytecode compiler"
HOMEPAGE = "http://www.enlightenment.org/"
SECTION = "Graphics/EFL"
LICENSE = "Mixed BSD 2/3-clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by embryo 
PROVIDES += "embryo"
RPROVIDES_embryo += "embryo"
# the PROVIDES rules is ignore "embryo-bin  "
PROVIDES += "embryo-bin"
RPROVIDES_embryo += "embryo-bin"

#PROVIDES by embryo-devel 
PROVIDES += "embryo-devel"
RPROVIDES_embryo-devel += "embryo-devel"
RPROVIDES_embryo-devel += "embryo-dev"

RDEPENDS = ""
#RDEPENDS of embryo-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "embryo"


DEPENDS = ""
#DEPENDS of embryo 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(eina)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/embryo.manifest .
 
 
 
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
         --infodir=/usr/share/info 
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
PACKAGES += "embryo"
PACKAGES += "embryo-devel"

embryo_files = ""
embryo_files += "embryo.manifest"
embryo_files += "/usr/bin/embryo_cc"
embryo_files += "/usr/lib/libembryo.so.*"
embryo_files += "/usr/share/embryo/include/default.inc"

embryo-devel_files = ""
embryo-devel_files += "embryo.manifest"
embryo-devel_files += "/usr/include/embryo-1/*.h"
embryo-devel_files += "/usr/lib/*.so"
embryo-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${embryo_files}"
FILES_${PN}-devel = "${embryo-devel_files}"

PKG_embryo= "embryo"
PKG_embryo-devel= "embryo-devel"

require embryo-extraconf.inc
