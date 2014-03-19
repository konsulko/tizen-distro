DESCRIPTION = "Data compression library with very fast (de)compression"
HOMEPAGE = "http://www.oberhumer.com/opensource/lzo/"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by lzo-minilzo 
PROVIDES += "lzo-minilzo"
RPROVIDES_lzo-minilzo += "lzo-minilzo"

#PROVIDES by lzo-devel 
PROVIDES += "lzo-devel"
RPROVIDES_lzo-devel += "lzo-devel"
RPROVIDES_lzo-devel += "lzo-dev"

#PROVIDES by lzo 
PROVIDES += "lzo"
RPROVIDES_lzo += "lzo"

RDEPENDS = ""
#RDEPENDS of lzo-minilzo (${PN}-mini${PN})
RDEPENDS_${PN}-mini${PN} += "/sbin/ldconfig"
RDEPENDS_${PN}-mini${PN} += "lzo"

#RDEPENDS of lzo-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "lzo"

#RDEPENDS of lzo (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of lzo 
DEPENDS += "zlib-devel"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/lzo.manifest .
 
 
 
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
         --infodir=/usr/share/info --disable-static \
     --disable-dependency-tracking \
     --enable-shared \
     CFLAGS="`echo $CFLAGS | sed 's/-O2//g'`"
 
 make -j16
 
 # build minilzo too (bz 439979)
 gcc -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -O2 -g -fpic -Iinclude/lzo -o minilzo/minilzo.o -c minilzo/minilzo.c
 #gcc -O2 -g -fpic -Iinclude/lzo -o minilzo/minilzo.o -c minilzo/minilzo.c
 gcc -g -shared -o libminilzo.so.0 -Wl,-soname,libminilzo.so.0 minilzo/minilzo.o
 
 
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
 
 install -m 755 libminilzo.so.0 ${D}/usr/lib
 ln -s libminilzo.so.0 ${D}/usr/lib/libminilzo.so
 install -p -m 644 minilzo/minilzo.h ${D}/usr/include/lzo
 
 
 
 
}

PACKAGES = ""
PACKAGES += "lzo-minilzo"
PACKAGES += "lzo-devel"
PACKAGES += "lzo"

lzo-minilzo_files = ""
lzo-minilzo_files += "lzo.manifest"
lzo-minilzo_files += "minilzo/README.LZO"
lzo-minilzo_files += "/usr/lib/libminilzo.so.0"

lzo-devel_files = ""
lzo-devel_files += "lzo.manifest"
lzo-devel_files += "doc/LZOAPI.TXT doc/LZO.FAQ doc/LZO.TXT"
lzo-devel_files += "/usr/include/lzo"
lzo-devel_files += "/usr/lib/lib*lzo*.so"

lzo_files = ""
lzo_files += "lzo.manifest"
lzo_files += "AUTHORS COPYING THANKS NEWS"
lzo_files += "/usr/lib/liblzo2.so.*"

FILES_${PN}-mini${PN} = "${lzo-minilzo_files}"
FILES_${PN}-devel = "${lzo-devel_files}"
FILES_${PN} = "${lzo_files}"

PKG_lzo-minilzo= "lzo-minilzo"
PKG_lzo-devel= "lzo-devel"
PKG_lzo= "lzo"

require lzo-extraconf.inc
