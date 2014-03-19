DESCRIPTION = "Data Compression Library"
HOMEPAGE = "http://www.zlib.net/"
SECTION = "Base/Libraries"
LICENSE = "Zlib"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by zlib-devel 
PROVIDES += "zlib-devel"
RPROVIDES_zlib-devel += "zlib-devel"
RPROVIDES_zlib-devel += "zlib-dev"
# the PROVIDES rules is ignore "libz:/usr/include/zlib.h  "
PROVIDES += "libz:/usr/include/zlib.h"
RPROVIDES_zlib-devel += "libz:/usr/include/zlib.h"

#PROVIDES by zlib 
PROVIDES += "zlib"
RPROVIDES_zlib += "zlib"
# the PROVIDES rules is ignore "libz  "
PROVIDES += "libz"
RPROVIDES_zlib += "libz"

#PROVIDES by zlib-devel-static 
PROVIDES += "zlib-devel-static"
RPROVIDES_zlib-devel-static += "zlib-devel-static"
RPROVIDES_zlib-devel-static += "zlib-dev"
# the PROVIDES rules is ignore "zlib-devel:/usr/lib/libz.a  "
PROVIDES += "zlib-devel:/usr/lib/libz.a"
RPROVIDES_zlib-devel-static += "zlib-devel:/usr/lib/libz.a"
RPROVIDES_zlib-devel-static += "zlib-dev"

#PROVIDES by minizip 
PROVIDES += "minizip"
RPROVIDES_minizip += "minizip"

#PROVIDES by minizip-devel 
PROVIDES += "minizip-devel"
RPROVIDES_minizip-devel += "minizip-devel"
RPROVIDES_minizip-devel += "minizip-dev"

RDEPENDS = ""
#RDEPENDS of zlib-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "zlib"

#RDEPENDS of zlib-devel-static (${PN}-devel-static)
RDEPENDS_${PN}-devel-static += "zlib-dev"

#RDEPENDS of minizip (minizip)
RDEPENDS_minizip += "zlib"

#RDEPENDS of minizip-devel (minizip-devel)
RDEPENDS_minizip-devel += "minizip"


DEPENDS = ""
#DEPENDS of zlib 

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/zlib.manifest .
 
 
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
 
 export LDFLAGS="-Wl,-z,relro,-z,now"
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 CC="gcc" ./configure --shared --prefix=/usr --libdir=/lib
 make -j16
 
 cd contrib/minizip
 
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
 
 exit 0
 time make check
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 #mkdir -p ${D}/usr/share/man/man3
 mkdir -p ${D}/usr/lib
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   
 ln -s -v /lib/$(readlink ${D}/lib/libz.so) ${D}/usr/lib/libz.so
 rm -v ${D}/lib/libz.so
 # static lib
 mv ${D}/lib/libz.a ${D}/usr/lib
 # Move .pc file to /usr/lib
 mv ${D}/lib/pkgconfig ${D}/usr/lib
 # manpage
 install -m 644 zlib.3 ${D}/usr/share/man/man3
 install -m 644 zutil.h ${D}/usr/include
 
 pushd contrib/minizip
 make install DESTDIR=$RPM_BUILD_ROOT
 rm -rf ${D}/usr/lib/libminizip.a
 rm -rf ${D}/usr/lib/libminizip.la
 popd
 
 
}

PACKAGES = ""
PACKAGES += "zlib-devel"
PACKAGES += "zlib"
PACKAGES += "zlib-devel-static"
PACKAGES += "minizip"
PACKAGES += "minizip-devel"

zlib-devel_files = ""
zlib-devel_files += "zlib.manifest"
zlib-devel_files += "README"
zlib-devel_files += "/usr/share/man/man3/zlib.3.gz"
zlib-devel_files += "/usr/include/zlib.h"
zlib-devel_files += "/usr/include/zconf.h"
zlib-devel_files += "/usr/include/zutil.h"
zlib-devel_files += "/usr/lib/libz.so"
zlib-devel_files += "/usr/lib/pkgconfig/zlib.pc"

zlib_files = ""
zlib_files += "zlib.manifest"
zlib_files += "/lib/libz.so.1.2.*"
zlib_files += "/lib/libz.so.1"

zlib-devel-static_files = ""
zlib-devel-static_files += "zlib.manifest"
zlib-devel-static_files += "/usr/lib/libz.a"

minizip_files = ""
minizip_files += "zlib.manifest"
minizip_files += "/usr/lib/libminizip.so.*"

minizip-devel_files = ""
minizip-devel_files += "zlib.manifest"
minizip-devel_files += "/usr/include/minizip"
minizip-devel_files += "/usr/include/minizip/*.h"
minizip-devel_files += "/usr/lib/libminizip.so"
minizip-devel_files += "/usr/lib/pkgconfig/minizip.pc"

FILES_${PN}-devel = "${zlib-devel_files}"
FILES_${PN} = "${zlib_files}"
FILES_${PN}-devel-static = "${zlib-devel-static_files}"
FILES_minizip = "${minizip_files}"
FILES_minizip-devel = "${minizip-devel_files}"

PKG_zlib-devel= "zlib-devel"
PKG_zlib= "zlib"
PKG_zlib-devel-static= "zlib-devel-static"
PKG_minizip= "minizip"
PKG_minizip-devel= "minizip-devel"

require zlib-extraconf.inc
