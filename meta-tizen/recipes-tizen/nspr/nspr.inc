DESCRIPTION = "Netscape Portable Runtime"
HOMEPAGE = "http://www.mozilla.org/projects/nspr/"
SECTION = "Base/Libraries"
LICENSE = "MPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by nspr-devel 
PROVIDES += "nspr-devel"
RPROVIDES_nspr-devel += "nspr-devel"
RPROVIDES_nspr-devel += "nspr-dev"

#PROVIDES by nspr 
PROVIDES += "nspr"
RPROVIDES_nspr += "nspr"

RDEPENDS = ""
#RDEPENDS of nspr-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "nspr"


DEPENDS = ""
#DEPENDS of nspr 
DEPENDS += "gcc-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -n nspr-4.10.2 -q
 cp ${S}/packaging/nspr.manifest .
 
 
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
 
 # set buildtime to "last-modification-time"
 modified="$(sed -n '/^----/n;s/ - .*$//;p;q' "${S}/packaging//nspr.changes")"
 BUILD_STRING="$(date -u -d "${modified}" "+%F %T")"
 BUILD_TIME="$(date -u -d "${modified}" "+%s000000")"
 #
 cd nspr
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 ./configure --enable-optimize="$CFLAGS" \
             --disable-debug \
 	    --enable-64bit \
 	    --libdir=/usr/lib \
 	    --includedir=/usr/include/nspr4 \
 	    --prefix=/usr
 make SH_DATE="$BUILD_STRING" SH_NOW="$BUILD_TIME" -j16
 exit 0
 # Run test suite
 perl ./pr/tests/runtests.pl 2>&1 | tee output.log
 TEST_FAILURES=`grep -c FAILED ./output.log` || :
 if [ $TEST_FAILURES -ne 0 ]; then
   echo "error: test suite returned failure(s)"
   exit 1
 fi
 echo "test suite completed"
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 mkdir -p ${D}/usr/lib/nspr
 mkdir -p ${D}/usr/lib/pkgconfig
 mkdir -p ${D}/usr/include/nspr4
 cp nspr/config/nspr-config ${D}/usr/bin/
 cp nspr/config/nspr.pc ${D}/usr/lib/pkgconfig
 cp -L nspr/dist/lib/*.so ${D}/usr/lib
 cp -L nspr/dist/lib/*.a  ${D}/usr/lib/nspr/
 cp -rL nspr/dist/include/nspr/* ${D}/usr/include/nspr4/
 # #31667
 chmod -x ${D}/usr/include/nspr4/prvrsion.h
 
 
}

PACKAGES = ""
PACKAGES += "nspr-devel"
PACKAGES += "nspr"

nspr-devel_files = ""
nspr-devel_files += "nspr.manifest"
nspr-devel_files += "/usr/bin/nspr-config"
nspr-devel_files += "/usr/lib/pkgconfig/nspr.pc"
nspr-devel_files += "/usr/include/nspr4/"
nspr-devel_files += "/usr/lib/nspr/"

nspr_files = ""
nspr_files += "nspr.manifest"
nspr_files += "/usr/lib/*.so"

FILES_${PN}-devel = "${nspr-devel_files}"
FILES_${PN} = "${nspr_files}"

PKG_nspr-devel= "nspr-devel"
PKG_nspr= "nspr"

require nspr-extraconf.inc
