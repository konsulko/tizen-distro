DESCRIPTION = "XML Parser Toolkit"
HOMEPAGE = "http://expat.sourceforge.net/"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libexpat 
PROVIDES += "libexpat"
RPROVIDES_libexpat += "libexpat"

#PROVIDES by expat 
PROVIDES += "expat"
RPROVIDES_expat += "expat"

#PROVIDES by libexpat-devel 
PROVIDES += "libexpat-devel"
RPROVIDES_libexpat-devel += "libexpat-devel"
RPROVIDES_libexpat-devel += "libexpat-dev"
# the PROVIDES rules is ignore "expat-devel  "
PROVIDES += "expat-devel"
RPROVIDES_libexpat-devel += "expat-devel"
RPROVIDES_libexpat-devel += "expat-dev"

RDEPENDS = ""
#RDEPENDS of libexpat-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "libexpat"


DEPENDS = ""
#DEPENDS of expat 
DEPENDS += "libtool-cross"
DEPENDS += "gcc-c++"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q 
 cp ${S}/packaging/expat.manifest .
 
 rm -f examples/*.dsp
 
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
         --infodir=/usr/share/info --disable-static --with-pic
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
 rm doc/xmlwf.1
 
 
}

PACKAGES = ""
PACKAGES += "libexpat"
PACKAGES += "expat"
PACKAGES += "libexpat-devel"

libexpat_files = ""
libexpat_files += "expat.manifest"
libexpat_files += "/usr/lib/libexpat.so.*"

expat_files = ""
expat_files += "expat.manifest"
expat_files += "/usr/share/man/man?/*"
expat_files += "/usr/bin/xmlwf"

libexpat-devel_files = ""
libexpat-devel_files += "expat.manifest"
libexpat-devel_files += "/usr/include/*"
libexpat-devel_files += "/usr/lib/libexpat.so"
libexpat-devel_files += "/usr/lib/pkgconfig/expat.pc"

FILES_lib${PN} = "${libexpat_files}"
FILES_${PN} = "${expat_files}"
FILES_lib${PN}-devel = "${libexpat-devel_files}"

PKG_libexpat= "libexpat"
PKG_expat= "expat"
PKG_libexpat-devel= "libexpat-devel"

require expat-extraconf.inc
