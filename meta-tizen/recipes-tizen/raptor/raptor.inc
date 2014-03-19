DESCRIPTION = "RDF Parser Toolkit"
HOMEPAGE = "http://www.redland.opensource.ac.uk/raptor/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+ or GPL-2.0+ or Apache-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libraptor 
PROVIDES += "libraptor"
RPROVIDES_libraptor += "libraptor"

#PROVIDES by raptor 
PROVIDES += "raptor"
RPROVIDES_raptor += "raptor"

#PROVIDES by libraptor-devel 
PROVIDES += "libraptor-devel"
RPROVIDES_libraptor-devel += "libraptor-devel"
RPROVIDES_libraptor-devel += "libraptor-dev"
# the PROVIDES rules is ignore "raptor-devel = 2.0.8"
PROVIDES += "raptor-devel"
RPROVIDES_libraptor-devel += "raptor-devel"
RPROVIDES_libraptor-devel += "raptor-dev"

RDEPENDS = ""
#RDEPENDS of libraptor-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libraptor"
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "raptor"


DEPENDS = ""
#DEPENDS of raptor 
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "curl"
DEPENDS += "autoconf-native"
DEPENDS += "pkgconfig(libxslt)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n raptor2-2.0.8
 cp ${S}/packaging/raptor.manifest .
 
 
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
         --infodir=/usr/share/info --disable-gtk-doc --disable-static --with-pic --with-html-dir=/usr/share/doc/packages
 make 
 
 exit 0
 export MALLOC_CHECK_=2
 make check
 unset MALLOC_CHECK_
 
 
 
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
 rm -rf ${D}//usr/share/doc/packages
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/raptor 
   rm -rf ${D}/usr/share/doc/raptor-2.0.8 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "libraptor"
PACKAGES += "raptor"
PACKAGES += "libraptor-devel"

libraptor_files = ""
libraptor_files += "raptor.manifest"
libraptor_files += "/usr/lib/libraptor2.so.0*"

raptor_files = ""
raptor_files += "raptor.manifest"
raptor_files += "/usr/bin/rapper"

libraptor-devel_files = ""
libraptor-devel_files += "raptor.manifest"
libraptor-devel_files += "/usr/lib/lib*.so"
libraptor-devel_files += "/usr/include/*"
libraptor-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_lib${PN} = "${libraptor_files}"
FILES_${PN} = "${raptor_files}"
FILES_lib${PN}-devel = "${libraptor-devel_files}"

PKG_libraptor= "libraptor"
PKG_raptor= "raptor"
PKG_libraptor-devel= "libraptor-devel"

require raptor-extraconf.inc
