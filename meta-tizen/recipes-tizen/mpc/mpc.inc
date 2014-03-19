DESCRIPTION = "MPC multiple-precision complex shared library"
HOMEPAGE = "http://www.multiprecision.org/mpc/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "LGPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by mpc 
PROVIDES += "mpc"
RPROVIDES_mpc += "mpc"

#PROVIDES by mpc-devel 
PROVIDES += "mpc-devel"
RPROVIDES_mpc-devel += "mpc-devel"
RPROVIDES_mpc-devel += "mpc-dev"

#PROVIDES by libmpc 
PROVIDES += "libmpc"
RPROVIDES_libmpc += "libmpc"

RDEPENDS = ""
#RDEPENDS of mpc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "mpfr-dev"
RDEPENDS_${PN}-devel += "libmpc"


DEPENDS = ""
#DEPENDS of mpc 
DEPENDS += "gmp"
DEPENDS += "mpfr-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/mpc.manifest .
 
 
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
 
 exit 0
 make check -j16
 
 
 
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
   
 
 
}

PACKAGES = ""
PACKAGES += "mpc-devel"
PACKAGES += "libmpc"

mpc-devel_files = ""
mpc-devel_files += "mpc.manifest"
mpc-devel_files += "AUTHORS NEWS COPYING.LESSER"
mpc-devel_files += "/usr/share/info/mpc.info.gz"
mpc-devel_files += "/usr/lib/libmpc.a"
mpc-devel_files += "/usr/lib/libmpc.so"
mpc-devel_files += "/usr/include/mpc.h"

libmpc_files = ""
libmpc_files += "mpc.manifest"
libmpc_files += "/usr/lib/libmpc.so.3*"

FILES_${PN}-devel = "${mpc-devel_files}"
FILES_lib${PN} = "${libmpc_files}"

PKG_mpc-devel= "mpc-devel"
PKG_libmpc= "libmpc"

require mpc-extraconf.inc
