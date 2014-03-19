DESCRIPTION = "Tools for Converting from and to the Tiff Format"
HOMEPAGE = "http://www.remotesensing.org/libtiff"
SECTION = "Productivity/Graphics/Convertors"
LICENSE = "HPND"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libtiff 
PROVIDES += "libtiff"
RPROVIDES_libtiff += "libtiff"

#PROVIDES by tiff 
PROVIDES += "tiff"
RPROVIDES_tiff += "tiff"

#PROVIDES by tiff-docs  
PROVIDES += "tiff-docs "
RPROVIDES_tiff-docs  += "tiff-docs "

#PROVIDES by libtiff-devel 
PROVIDES += "libtiff-devel"
RPROVIDES_libtiff-devel += "libtiff-devel"
RPROVIDES_libtiff-devel += "libtiff-dev"

RDEPENDS = ""
#RDEPENDS of libtiff-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "glibc-dev"
RDEPENDS_lib${PN}-devel += "libtiff"
RDEPENDS_lib${PN}-devel += "libstdc++-dev"


DEPENDS = ""
#DEPENDS of tiff 
DEPENDS += "zlib-devel"
DEPENDS += "gcc-cross"
DEPENDS += "lzma-devel"
DEPENDS += "libjpeg-turbo"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/tiff.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/{/usr/share/man/{man1,man3},usr/{bin,lib,include}}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 for f in `find ${D}//usr/share/man -type f -print ` ; do
   if [ `wc -l <$f` -eq 1 ] && grep -q "^\.so " $f ; then
     linkto=`sed -e "s|^\.so ||" $f`
     [ -f "`dirname $f`/$linkto" ] && ln -sf "$linkto" $f
   fi
 done
 
 rm -rf ${D}/usr/share/doc/tiff*
 rm -f ${D}//usr/lib/*.la
 find html -name "Makefile*" | xargs rm
 
 
 
 
}

PACKAGES = ""
PACKAGES += "tiff"
PACKAGES += "tiff-docs"
PACKAGES += "libtiff"
PACKAGES += "libtiff-devel"

tiff_files = ""
tiff_files += "tiff.manifest"
tiff_files += "/usr/bin/*"

tiff-docs_files = ""
tiff-docs_files += "/usr/share/info"
tiff-docs_files += "/usr/share/man"

libtiff_files = ""
libtiff_files += "tiff.manifest"
libtiff_files += "COPYRIGHT"
libtiff_files += "/usr/lib/*.so.*"

libtiff-devel_files = ""
libtiff-devel_files += "tiff.manifest"
libtiff-devel_files += "/usr/include/*"
libtiff-devel_files += "/usr/lib/*.so"
libtiff-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${tiff_files}"
FILES_${PN}-docs = "${tiff-docs_files}"
FILES_lib${PN} = "${libtiff_files}"
FILES_lib${PN}-devel = "${libtiff-devel_files}"

PKG_tiff= "tiff"
PKG_tiff-docs= "tiff-docs"
PKG_libtiff= "libtiff"
PKG_libtiff-devel= "libtiff-devel"

require tiff-extraconf.inc
