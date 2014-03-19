DESCRIPTION = "A portable foreign function interface library"
HOMEPAGE = "http://sourceware.org/libffi"
SECTION = "Base/Toolchain"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libffi 
PROVIDES += "libffi"
RPROVIDES_libffi += "libffi"

#PROVIDES by libffi-devel 
PROVIDES += "libffi-devel"
RPROVIDES_libffi-devel += "libffi-devel"
RPROVIDES_libffi-devel += "libffi-dev"

RDEPENDS = ""
#RDEPENDS of libffi-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libffi"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""

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
         --infodir=/usr/share/info --disable-static
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
 
 # Determine generic arch target name for multilib wrapper
 basearch=x86_64
 
 # Do header file switcheroo to avoid file conflicts on systems where you
 # can have both a 32- and 64-bit version of the library, and they each need
 # their own correct-but-different versions of the headers to be usable.
 for i in ffi ffitarget; do
   mv ${D}/usr/include/$i.h ${D}/usr/include/$i-${basearch}.h
 done
 install -m644 ${S}/packaging/ffi-multilib.h ${D}/usr/include/ffi.h
 install -m644 ${S}/packaging/ffitarget-multilib.h ${D}/usr/include/ffitarget.h
 
 
 
}

PACKAGES = ""
PACKAGES += "libffi"
PACKAGES += "libffi-devel"

libffi_files = ""
libffi_files += "/usr/lib/*.so.*"

libffi-devel_files = ""
libffi-devel_files += "/usr/lib/pkgconfig/*.pc"
libffi-devel_files += "/usr/include/ffi*.h"
libffi-devel_files += "/usr/lib/*.so"
libffi-devel_files += "/usr/share/man/man3/*.gz"
libffi-devel_files += "/usr/share/info/libffi.info.gz"

FILES_${PN} = "${libffi_files}"
FILES_${PN}-devel = "${libffi-devel_files}"

PKG_libffi= "libffi"
PKG_libffi-devel= "libffi-devel"

require libffi-extraconf.inc
