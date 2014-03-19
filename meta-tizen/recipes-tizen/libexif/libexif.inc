DESCRIPTION = "An EXIF Tag Parsing Library for Digital Cameras"
HOMEPAGE = "http://libexif.sourceforge.net"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libexif 
PROVIDES += "libexif"
RPROVIDES_libexif += "libexif"

#PROVIDES by libexif-devel 
PROVIDES += "libexif-devel"
RPROVIDES_libexif-devel += "libexif-devel"
RPROVIDES_libexif-devel += "libexif-dev"

RDEPENDS = ""
#RDEPENDS of libexif-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libexif"
RDEPENDS_${PN}-devel += "glibc-dev"


DEPENDS = ""
#DEPENDS of libexif 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig-native"
#Replace "DEPENDS" on gettext by "inherit gettext"
inherit gettext

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libexif.manifest .
 
 
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
         --infodir=/usr/share/info --with-pic \
 	--disable-static \
 	--with-doc-dir=/usr/share/doc/packages/libexif
 make 
 ### -j16
 
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
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} libexif-12
 
 
}

PACKAGES = ""
PACKAGES += "libexif"
PACKAGES += "libexif-devel"

libexif_files = ""
libexif_files += "libexif.manifest"
libexif_files += "/usr/lib/*.so.*"

libexif-devel_files = ""
libexif-devel_files += "libexif.manifest"
libexif-devel_files += "/usr/share/doc/packages/libexif"
libexif-devel_files += "/usr/lib/*.so"
libexif-devel_files += "/usr/lib/pkgconfig/*.pc"
libexif-devel_files += "/usr/include/*"

FILES_${PN} = "${libexif_files}"
FILES_${PN}-devel = "${libexif-devel_files}"

PKG_libexif= "libexif"
PKG_libexif-devel= "libexif-devel"

require libexif-extraconf.inc
