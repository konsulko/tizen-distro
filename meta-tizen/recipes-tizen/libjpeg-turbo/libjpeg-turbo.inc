DESCRIPTION = "A MMX/SSE2 accelerated library for manipulating JPEG image files"
HOMEPAGE = "http://sourceforge.net/projects/libjpeg-turbo"
SECTION = "Graphics & UI Framework/Libraries"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libjpeg 
PROVIDES += "libjpeg"
RPROVIDES_libjpeg += "libjpeg"
# the PROVIDES rules is ignore "libjpeg = 8.0.2"
PROVIDES += "libjpeg"
RPROVIDES_libjpeg += "libjpeg"
# the PROVIDES rules is ignore "libjpeg8  "
PROVIDES += "libjpeg8"
RPROVIDES_libjpeg += "libjpeg8"

#PROVIDES by libjpeg-turbo 
PROVIDES += "libjpeg-turbo"
RPROVIDES_libjpeg-turbo += "libjpeg-turbo"

#PROVIDES by libjpeg-devel 
PROVIDES += "libjpeg-devel"
RPROVIDES_libjpeg-devel += "libjpeg-devel"
RPROVIDES_libjpeg-devel += "libjpeg-dev"
# the PROVIDES rules is ignore "libjpeg-turbo-devel  "
PROVIDES += "libjpeg-turbo-devel"
RPROVIDES_libjpeg-devel += "libjpeg-turbo-devel"
RPROVIDES_libjpeg-devel += "libjpeg-turbo-dev"
# the PROVIDES rules is ignore "libjpeg-devel = 8.0.2"
PROVIDES += "libjpeg-devel"
RPROVIDES_libjpeg-devel += "libjpeg-devel"
RPROVIDES_libjpeg-devel += "libjpeg-dev"
# the PROVIDES rules is ignore "libjpeg8-devel  "
PROVIDES += "libjpeg8-devel"
RPROVIDES_libjpeg-devel += "libjpeg8-devel"
RPROVIDES_libjpeg-devel += "libjpeg8-dev"

#PROVIDES by libjpeg-turbo-docs  
PROVIDES += "libjpeg-turbo-docs "
RPROVIDES_libjpeg-turbo-docs  += "libjpeg-turbo-docs "

RDEPENDS = ""
#RDEPENDS of libjpeg-devel (libjpeg-devel)
RDEPENDS_libjpeg-devel += "libjpeg"


DEPENDS = ""
#DEPENDS of libjpeg-turbo 
DEPENDS += "gcc-cross"
DEPENDS += "libtool-cross"
DEPENDS += "yasm"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libjpeg-turbo.manifest .
 
 
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
 
 autoreconf -fiv
 
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
         --infodir=/usr/share/info --disable-static \
            --with-jpeg8
 make -j16
 
 exit 0
 make test libdir=/usr/lib
 
 
 
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
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 
 # Fix perms
 chmod -x README-turbo.txt release/copyright
 
 # Remove unwanted files
 rm -f ${D}/usr/lib/lib{,turbo}jpeg.la
 
 rm ${D}/usr/bin/tjbench
 
 # Remove docs, we'll select docs manually
 rm -rf ${D}/usr/share/doc/
 
 
}

PACKAGES = ""
PACKAGES += "libjpeg"
PACKAGES += "libjpeg-turbo"
PACKAGES += "libjpeg-turbo-docs"
PACKAGES += "libjpeg-devel"

libjpeg_files = ""
libjpeg_files += "libjpeg-turbo.manifest"
libjpeg_files += "/usr/lib/libturbojpeg.so"
libjpeg_files += "/usr/lib/libjpeg.so.8.0.2"
libjpeg_files += "/usr/lib/libjpeg.so.8"

libjpeg-turbo_files = ""
libjpeg-turbo_files += "libjpeg-turbo.manifest"
libjpeg-turbo_files += "/usr/bin/*"

libjpeg-turbo-docs_files = ""
libjpeg-turbo-docs_files += "/usr/share/info"
libjpeg-turbo-docs_files += "/usr/share/man"

libjpeg-devel_files = ""
libjpeg-devel_files += "libjpeg-turbo.manifest"
libjpeg-devel_files += "/usr/include/*.h"
libjpeg-devel_files += "/usr/lib/libjpeg.so"
libjpeg-devel_files += "coderules.txt jconfig.txt libjpeg.txt structure.txt example.c"

FILES_libjpeg = "${libjpeg_files}"
FILES_${PN} = "${libjpeg-turbo_files}"
FILES_${PN}-docs = "${libjpeg-turbo-docs_files}"
FILES_libjpeg-devel = "${libjpeg-devel_files}"

PKG_libjpeg= "libjpeg"
PKG_libjpeg-turbo= "libjpeg-turbo"
PKG_libjpeg-turbo-docs= "libjpeg-turbo-docs"
PKG_libjpeg-devel= "libjpeg-devel"

require libjpeg-turbo-extraconf.inc
