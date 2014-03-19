DESCRIPTION = "An ELF Object File Access Library"
HOMEPAGE = "http://www.mr511.de/software/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libelf0-devel 
PROVIDES += "libelf0-devel"
RPROVIDES_libelf0-devel += "libelf0-devel"
RPROVIDES_libelf0-devel += "libelf0-dev"

#PROVIDES by libelf0 
PROVIDES += "libelf0"
RPROVIDES_libelf0 += "libelf0"

RDEPENDS = ""
#RDEPENDS of libelf0-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libelf0"


DEPENDS = ""
#DEPENDS of libelf0 
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libelf-0.8.13
 cp ${S}/packaging/libelf0.manifest .
 
 
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
         --infodir=/usr/share/info --disable-nls
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install instroot=${D}
 # remove the wrapper includes
 rm -f ${D}/usr/include/*.h
 # remove unneeded *.la and *.a files
 rm -f ${D}/usr/lib/*.la
 
 
}

PACKAGES = ""
PACKAGES += "libelf0-devel"
PACKAGES += "libelf0"

libelf0-devel_files = ""
libelf0-devel_files += "libelf0.manifest"
libelf0-devel_files += "/usr/lib/libelf.so"
libelf0-devel_files += "/usr/lib/libelf.a"
libelf0-devel_files += "/usr/lib/pkgconfig/libelf.pc"
libelf0-devel_files += "/usr/include/libelf"

libelf0_files = ""
libelf0_files += "libelf0.manifest"
libelf0_files += "/usr/lib/libelf.so.*"

FILES_${PN}-devel = "${libelf0-devel_files}"
FILES_${PN} = "${libelf0_files}"

PKG_libelf0-devel= "libelf0-devel"
PKG_libelf0= "libelf0"

require libelf0-extraconf.inc
