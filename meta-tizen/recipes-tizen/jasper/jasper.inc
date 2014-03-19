DESCRIPTION = "An Implementation of the JPEG-2000 Standard, Part 1"
HOMEPAGE = "http://www.ece.uvic.ca/~mdadams/jasper/"
SECTION = "Productivity/Graphics/Convertors"
LICENSE = "SUSE-Public-Domain"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libjasper-devel 
PROVIDES += "libjasper-devel"
RPROVIDES_libjasper-devel += "libjasper-devel"
RPROVIDES_libjasper-devel += "libjasper-dev"

#PROVIDES by jasper-docs  
PROVIDES += "jasper-docs "
RPROVIDES_jasper-docs  += "jasper-docs "

#PROVIDES by jasper 
PROVIDES += "jasper"
RPROVIDES_jasper += "jasper"

#PROVIDES by libjasper 
PROVIDES += "libjasper"
RPROVIDES_libjasper += "libjasper"

RDEPENDS = ""
#RDEPENDS of libjasper-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libjpeg-dev"
RDEPENDS_lib${PN}-devel += "libjasper"


DEPENDS = ""
#DEPENDS of jasper 
DEPENDS += "gcc-cross"
DEPENDS += "libtool-cross"
DEPENDS += "libdrm-devel"
DEPENDS += "libjpeg-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/jasper.manifest .
 
 
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
 
 autoreconf -i -f
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wall"
 
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
         --infodir=/usr/share/info --prefix=/usr --enable-shared --disable-static --libdir=/usr/lib
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
 rm ${D}/usr/bin/tmrdemo
 # compatibility link, there was no interface change
 ln -s libjasper.so.1.0.0 ${D}/usr/lib/libjasper-1.701.so.1
 
 
}

PACKAGES = ""
PACKAGES += "libjasper-devel"
PACKAGES += "jasper-docs"
PACKAGES += "jasper"
PACKAGES += "libjasper"

libjasper-devel_files = ""
libjasper-devel_files += "jasper.manifest"
libjasper-devel_files += "/usr/include/jasper"
libjasper-devel_files += "/usr/lib/libjasper.so"

jasper-docs_files = ""
jasper-docs_files += "/usr/share/info"
jasper-docs_files += "/usr/share/man"

jasper_files = ""
jasper_files += "jasper.manifest"
jasper_files += "COPYRIGHT"
jasper_files += "/usr/bin/imgcmp"
jasper_files += "/usr/bin/imginfo"
jasper_files += "/usr/bin/jasper"

libjasper_files = ""
libjasper_files += "jasper.manifest"
libjasper_files += "/usr/lib/libjasper*.so.*"

FILES_lib${PN}-devel = "${libjasper-devel_files}"
FILES_${PN}-docs = "${jasper-docs_files}"
FILES_${PN} = "${jasper_files}"
FILES_lib${PN} = "${libjasper_files}"

PKG_libjasper-devel= "libjasper-devel"
PKG_jasper-docs= "jasper-docs"
PKG_jasper= "jasper"
PKG_libjasper= "libjasper"

require jasper-extraconf.inc
