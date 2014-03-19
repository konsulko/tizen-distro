DESCRIPTION = "Unwind Library"
HOMEPAGE = "http://savannah.nongnu.org/projects/libunwind/"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libunwind 
PROVIDES += "libunwind"
RPROVIDES_libunwind += "libunwind"

#PROVIDES by libunwind-devel 
PROVIDES += "libunwind-devel"
RPROVIDES_libunwind-devel += "libunwind-devel"
RPROVIDES_libunwind-devel += "libunwind-dev"
# the PROVIDES rules is ignore "libunwind:/usr/lib/libunwind.so  "
PROVIDES += "libunwind:/usr/lib/libunwind.so"
RPROVIDES_libunwind-devel += "libunwind:/usr/lib/libunwind.so"

RDEPENDS = ""
#RDEPENDS of libunwind-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libunwind"


DEPENDS = ""
#DEPENDS of libunwind 
DEPENDS += "gcc-cross"
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libunwind.manifest .
 
 
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
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -U_FORTIFY_SOURCE"
 
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
   
 mkdir -p $RPM_BUILD_ROOT/lib
 ln -sf //usr/lib/libunwind.so.8 $RPM_BUILD_ROOT/usr/lib/libunwind.so
 # Check that ln did not create a dangling link
 stat "${D}"/$(readlink -f "${D}//usr/lib/libunwind.so");
 
 
}

PACKAGES = ""
PACKAGES += "libunwind"
PACKAGES += "libunwind-devel"

libunwind_files = ""
libunwind_files += "libunwind.manifest"
libunwind_files += "/usr/lib/lib*"
libunwind_files += "/usr/lib/lib*.so.*"
libunwind_files += "/usr/lib/libunwind.so"

libunwind-devel_files = ""
libunwind-devel_files += "libunwind.manifest"
libunwind-devel_files += "/usr/include/*"
libunwind-devel_files += "/usr/lib/lib*.a"
libunwind-devel_files += "/usr/lib/libunwind-*.so"
libunwind-devel_files += "/usr/lib/pkgconfig/libunwind-generic.pc"
libunwind-devel_files += "/usr/lib/pkgconfig/libunwind-ptrace.pc"
libunwind-devel_files += "/usr/lib/pkgconfig/libunwind-setjmp.pc"
libunwind-devel_files += "/usr/lib/pkgconfig/libunwind.pc"
libunwind-devel_files += "/usr/lib/pkgconfig/libunwind-coredump.pc"
libunwind-devel_files += "/usr/share/man/man?/*"

FILES_${PN} = "${libunwind_files}"
FILES_${PN}-devel = "${libunwind-devel_files}"

PKG_libunwind= "libunwind"
PKG_libunwind-devel= "libunwind-devel"

require libunwind-extraconf.inc
