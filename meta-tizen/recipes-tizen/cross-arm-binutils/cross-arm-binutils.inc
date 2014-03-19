DESCRIPTION = "GNU Binutils"
HOMEPAGE = "http://www.gnu.org/software/binutils/"
SECTION = "Development/Tools/Building"
LICENSE = "GFDL-1.3 and GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cross-arm-binutils-devel 
PROVIDES += "cross-arm-binutils-devel"
RPROVIDES_cross-arm-binutils-devel += "cross-arm-binutils-devel"
RPROVIDES_cross-arm-binutils-devel += "cross-arm-binutils-dev"
# the PROVIDES rules is ignore "binutils:/usr/include/bfd.h  "
PROVIDES += "binutils:/usr/include/bfd.h"
RPROVIDES_cross-arm-binutils-devel += "binutils:/usr/include/bfd.h"

#PROVIDES by cross-arm-binutils-gold 
PROVIDES += "cross-arm-binutils-gold"
RPROVIDES_cross-arm-binutils-gold += "cross-arm-binutils-gold"

#PROVIDES by cross-arm-binutils 
PROVIDES += "cross-arm-binutils"
RPROVIDES_cross-arm-binutils += "cross-arm-binutils"

RDEPENDS = ""
#RDEPENDS of cross-arm-binutils-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "binutils"

#RDEPENDS of cross-arm-binutils-gold (${PN}-gold)
RDEPENDS_${PN}-gold += "binutils"

#RDEPENDS of cross-arm-binutils (${PN})
RDEPENDS_${PN} += "update-alternatives"


DEPENDS = ""
#DEPENDS of cross-arm-binutils 
DEPENDS += "flex"
DEPENDS += "zlib-devel-static"
DEPENDS += "glibc-devel-static"
DEPENDS += "bc"
DEPENDS += "bison-native"
DEPENDS += "gcc-c++"
DEPENDS += "makeinfo"

do_patch() {
 echo "make check will return with true in case of testsuite failures."
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n binutils-2.23.1
 
 sed -i -e '/BFD_VERSION_DATE/s/$/-0/' bfd/version.h
 
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
 
 RPM_OPT_FLAGS="$RPM_OPT_FLAGS -Wno-error"
 RPM_OPT_FLAGS=`echo $RPM_OPT_FLAGS |sed -e 's/atom/i686/g'`
 # building cross-TARGET-binutils
 echo "Building cross binutils." 
 mkdir build-dir
 cd build-dir
 EXTRA_TARGETS=
 EXTRA_TARGETS="$EXTRA_TARGETS,arm-tizen-linux-gnueabi"
 TARGET_OS=arm-tizen-linux-gnueabi
 ../configure CFLAGS="${RPM_OPT_FLAGS}" \
   --prefix=/usr \
   --with-bugurl=http://bugs.opensuse.org/ \
   --with-pkgversion="GNU Binutils; %distribution" \
   --disable-nls \
   --build=x86_64-tizen-linux --target=$TARGET_OS \
   --with-sysroot=/usr/$TARGET_OS/sys-root \
   ${EXTRA_TARGETS:+--enable-targets="${EXTRA_TARGETS#,}"}
 make -j16 all-bfd TARGET-bfd=headers
 # force reconfiguring
 rm bfd/Makefile
 make -j16
 
 exit 0
 unset LD_AS_NEEDED
 cd build-dir
 make -k check CFLAGS="-O2 -g" CXXFLAGS="-O2 -g" || true
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd build-dir
 # installing cross-TARGET-binutils and TARGET-binutils
 make DESTDIR=$RPM_BUILD_ROOT install
 # Replace hard links by symlinks, so that rpmlint doesn't complain
 T=$(basename ${D}/usr/arm*)
 for f in ${D}/usr/$T/bin/* ; do
    ln -sf /usr/bin/$T-$(basename $f) $f
 done
 rm -rf $RPM_BUILD_ROOT/usr/share/man
 rm -rf $RPM_BUILD_ROOT/usr/share/info
 rm -rf $RPM_BUILD_ROOT/usr/lib*
 rm -rf $RPM_BUILD_ROOT/usr/include
 rm -f $RPM_BUILD_ROOT/usr/bin/*-c++filt
 > ../binutils.lang
 cd $RPM_BUILD_DIR/binutils-2.23.1
 
 
 
 
}

PACKAGES = ""
PACKAGES += "cross-arm-binutils"

cross-arm-binutils_files = ""
cross-arm-binutils_files += "/usr/arm*"
cross-arm-binutils_files += "/usr/bin/*"

FILES_${PN} = "${cross-arm-binutils_files}"

PKG_cross-arm-binutils= "cross-arm-binutils"

require cross-arm-binutils-extraconf.inc
