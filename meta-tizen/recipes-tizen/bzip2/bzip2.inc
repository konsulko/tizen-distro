DESCRIPTION = "A Program for Compressing Files"
HOMEPAGE = "http://www.bzip.org/"
SECTION = "Base/Tools"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by bzip2-devel 
PROVIDES += "bzip2-devel"
RPROVIDES_bzip2-devel += "bzip2-devel"
RPROVIDES_bzip2-devel += "bzip2-dev"

#PROVIDES by bzip2 
PROVIDES += "bzip2"
RPROVIDES_bzip2 += "bzip2"
# the PROVIDES rules is ignore "bzip  "
PROVIDES += "bzip"
RPROVIDES_bzip2 += "bzip"

#PROVIDES by libbz2 
PROVIDES += "libbz2"
RPROVIDES_libbz2 += "libbz2"
# the PROVIDES rules is ignore "bzip2-libs  "
PROVIDES += "bzip2-libs"
RPROVIDES_libbz2 += "bzip2-libs"

#PROVIDES by bzip2-docs  
PROVIDES += "bzip2-docs "
RPROVIDES_bzip2-docs  += "bzip2-docs "

RDEPENDS = ""
#RDEPENDS of bzip2-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libbz2"


DEPENDS = ""
#DEPENDS of bzip2 
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/bzip2.manifest .
 
 
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
 
 profile_bzip2()
 {
     tmpfile=$(mktemp)
     trap "rm -f $tmpfile $tmpfile.bz2" EXIT
     tar -cjf $tmpfile.bz2 /usr/src || true
    # time ./bzip2 $tmpfile
     time ./bzip2 -d < $tmpfile.bz2 > /dev/null
 }
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
         --infodir=/usr/share/info --with-pic --disable-static
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
 gzip -dc ${S}/packaging/bznew.gz > bznew
 install -D -m 755 bznew $RPM_BUILD_ROOT/usr/bin/bznew
 install -m 644 ${S}/packaging/bznew.1.gz $RPM_BUILD_ROOT/usr/share/man/man1
 
 
}

PACKAGES = ""
PACKAGES += "bzip2-devel"
PACKAGES += "bzip2"
PACKAGES += "libbz2"
PACKAGES += "bzip2-docs"

bzip2-devel_files = ""
bzip2-devel_files += "bzip2.manifest"
bzip2-devel_files += "/usr/include/bzlib.h"
bzip2-devel_files += "/usr/lib/libbz2.so"
bzip2-devel_files += "/usr/lib/pkgconfig/bzip2.pc"

bzip2_files = ""
bzip2_files += "bzip2.manifest"
bzip2_files += "/usr/bin/*"

libbz2_files = ""
libbz2_files += "bzip2.manifest"
libbz2_files += "/usr/lib/libbz2.so.1"
libbz2_files += "/usr/lib/libbz2.so.1.*"

bzip2-docs_files = ""
bzip2-docs_files += "/usr/share/info"
bzip2-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${bzip2-devel_files}"
FILES_${PN} = "${bzip2_files}"
FILES_libbz2 = "${libbz2_files}"
FILES_${PN}-docs = "${bzip2-docs_files}"

PKG_bzip2-devel= "bzip2-devel"
PKG_bzip2= "bzip2"
PKG_libbz2= "libbz2"
PKG_bzip2-docs= "bzip2-docs"

require bzip2-extraconf.inc
