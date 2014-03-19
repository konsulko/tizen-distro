DESCRIPTION = "The GNU C Compiler and Support Files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Toolchain"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gcc48-info 
PROVIDES += "gcc48-info"
RPROVIDES_gcc48-info += "gcc48-info"

#PROVIDES by libquadmath-64bit 
PROVIDES += "libquadmath-64bit"
RPROVIDES_libquadmath-64bit += "libquadmath-64bit"
# the PROVIDES rules is ignore "libquadmath-64bit = 4.8.2-1"
PROVIDES += "libquadmath-64bit"
RPROVIDES_libquadmath-64bit += "libquadmath-64bit"

#PROVIDES by libstdc++48-devel 
PROVIDES += "libstdc++48-devel"
RPROVIDES_libstdc++48-devel += "libstdc++48-devel"
RPROVIDES_libstdc++48-devel += "libstdc++48-dev"

#PROVIDES by libffi-32bit 
PROVIDES += "libffi-32bit"
RPROVIDES_libffi-32bit += "libffi-32bit"

#PROVIDES by libatomic-32bit 
PROVIDES += "libatomic-32bit"
RPROVIDES_libatomic-32bit += "libatomic-32bit"

#PROVIDES by libasan-32bit 
PROVIDES += "libasan-32bit"
RPROVIDES_libasan-32bit += "libasan-32bit"

#PROVIDES by libffi-64bit 
PROVIDES += "libffi-64bit"
RPROVIDES_libffi-64bit += "libffi-64bit"

#PROVIDES by libatomic 
PROVIDES += "libatomic"
RPROVIDES_libatomic += "libatomic"

#PROVIDES by gcc48-locale 
PROVIDES += "gcc48-locale"
RPROVIDES_gcc48-locale += "gcc48-locale"

#PROVIDES by libgcc_s1-64bit 
PROVIDES += "libgcc_s1-64bit"
RPROVIDES_libgcc_s1-64bit += "libgcc_s1-64bit"
# the PROVIDES rules is ignore "libgcc_s1-64bit = 4.8.2-1"
PROVIDES += "libgcc_s1-64bit"
RPROVIDES_libgcc_s1-64bit += "libgcc_s1-64bit"

#PROVIDES by libstdc++ 
PROVIDES += "libstdc++"
RPROVIDES_libstdc++ += "libstdc++"
# the PROVIDES rules is ignore "libstdc++ = 4.8.2-1"
PROVIDES += "libstdc++"
RPROVIDES_libstdc++ += "libstdc++"

#PROVIDES by gcc48-java 
PROVIDES += "gcc48-java"
RPROVIDES_gcc48-java += "gcc48-java"

#PROVIDES by gcc48-ada 
PROVIDES += "gcc48-ada"
RPROVIDES_gcc48-ada += "gcc48-ada"

#PROVIDES by libgomp-64bit 
PROVIDES += "libgomp-64bit"
RPROVIDES_libgomp-64bit += "libgomp-64bit"
# the PROVIDES rules is ignore "libgomp-64bit = 4.8.2-1"
PROVIDES += "libgomp-64bit"
RPROVIDES_libgomp-64bit += "libgomp-64bit"

#PROVIDES by libstdc++48-doc 
PROVIDES += "libstdc++48-doc"
RPROVIDES_libstdc++48-doc += "libstdc++48-doc"

#PROVIDES by libitm 
PROVIDES += "libitm"
RPROVIDES_libitm += "libitm"

#PROVIDES by libffi48-devel-64bit 
PROVIDES += "libffi48-devel-64bit"
RPROVIDES_libffi48-devel-64bit += "libffi48-devel-64bit"
RPROVIDES_libffi48-devel-64bit += "libffi48-dev"

#PROVIDES by libmudflap48 
PROVIDES += "libmudflap48"
RPROVIDES_libmudflap48 += "libmudflap48"

#PROVIDES by libgcj48 
PROVIDES += "libgcj48"
RPROVIDES_libgcj48 += "libgcj48"

#PROVIDES by libgfortran 
PROVIDES += "libgfortran"
RPROVIDES_libgfortran += "libgfortran"
# the PROVIDES rules is ignore "libgfortran = 4.8.2-1"
PROVIDES += "libgfortran"
RPROVIDES_libgfortran += "libgfortran"

#PROVIDES by libobjc-32bit 
PROVIDES += "libobjc-32bit"
RPROVIDES_libobjc-32bit += "libobjc-32bit"
# the PROVIDES rules is ignore "libobjc-32bit = 4.8.2-1"
PROVIDES += "libobjc-32bit"
RPROVIDES_libobjc-32bit += "libobjc-32bit"

#PROVIDES by libada48-32bit 
PROVIDES += "libada48-32bit"
RPROVIDES_libada48-32bit += "libada48-32bit"

#PROVIDES by libquadmath-32bit 
PROVIDES += "libquadmath-32bit"
RPROVIDES_libquadmath-32bit += "libquadmath-32bit"
# the PROVIDES rules is ignore "libquadmath-32bit = 4.8.2-1"
PROVIDES += "libquadmath-32bit"
RPROVIDES_libquadmath-32bit += "libquadmath-32bit"

#PROVIDES by libmudflap48-32bit 
PROVIDES += "libmudflap48-32bit"
RPROVIDES_libmudflap48-32bit += "libmudflap48-32bit"

#PROVIDES by gcc48-c++ 
PROVIDES += "gcc48-c++"
RPROVIDES_gcc48-c++ += "gcc48-c++"

#PROVIDES by libitm-32bit 
PROVIDES += "libitm-32bit"
RPROVIDES_libitm-32bit += "libitm-32bit"

#PROVIDES by gcc48-fortran-32bit 
PROVIDES += "gcc48-fortran-32bit"
RPROVIDES_gcc48-fortran-32bit += "gcc48-fortran-32bit"

#PROVIDES by gcc48-fortran-64bit 
PROVIDES += "gcc48-fortran-64bit"
RPROVIDES_gcc48-fortran-64bit += "gcc48-fortran-64bit"

#PROVIDES by cpp48 
PROVIDES += "cpp48"
RPROVIDES_cpp48 += "cpp48"

#PROVIDES by gcc48-ada-64bit 
PROVIDES += "gcc48-ada-64bit"
RPROVIDES_gcc48-ada-64bit += "gcc48-ada-64bit"

#PROVIDES by libmudflap48-64bit 
PROVIDES += "libmudflap48-64bit"
RPROVIDES_libmudflap48-64bit += "libmudflap48-64bit"

#PROVIDES by libstdc++-64bit 
PROVIDES += "libstdc++-64bit"
RPROVIDES_libstdc++-64bit += "libstdc++-64bit"
# the PROVIDES rules is ignore "libstdc++-64bit = 4.8.2-1"
PROVIDES += "libstdc++-64bit"
RPROVIDES_libstdc++-64bit += "libstdc++-64bit"

#PROVIDES by libatomic-64bit 
PROVIDES += "libatomic-64bit"
RPROVIDES_libatomic-64bit += "libatomic-64bit"

#PROVIDES by gcc48 
PROVIDES += "gcc48"
RPROVIDES_gcc48 += "gcc48"

#PROVIDES by libgcj48-jar 
PROVIDES += "libgcj48-jar"
RPROVIDES_libgcj48-jar += "libgcj48-jar"

#PROVIDES by libgcj48-devel 
PROVIDES += "libgcj48-devel"
RPROVIDES_libgcj48-devel += "libgcj48-devel"
RPROVIDES_libgcj48-devel += "libgcj48-dev"

#PROVIDES by libobjc-64bit 
PROVIDES += "libobjc-64bit"
RPROVIDES_libobjc-64bit += "libobjc-64bit"
# the PROVIDES rules is ignore "libobjc-64bit = 4.8.2-1"
PROVIDES += "libobjc-64bit"
RPROVIDES_libobjc-64bit += "libobjc-64bit"

#PROVIDES by gcc48-obj-c++ 
PROVIDES += "gcc48-obj-c++"
RPROVIDES_gcc48-obj-c++ += "gcc48-obj-c++"

#PROVIDES by gcc48-32bit 
PROVIDES += "gcc48-32bit"
RPROVIDES_gcc48-32bit += "gcc48-32bit"

#PROVIDES by libobjc 
PROVIDES += "libobjc"
RPROVIDES_libobjc += "libobjc"
# the PROVIDES rules is ignore "libobjc = 4.8.2-1"
PROVIDES += "libobjc"
RPROVIDES_libobjc += "libobjc"

#PROVIDES by libgcc_s1 
PROVIDES += "libgcc_s1"
RPROVIDES_libgcc_s1 += "libgcc_s1"
# the PROVIDES rules is ignore "libgcc_s1 = 4.8.2-1"
PROVIDES += "libgcc_s1"
RPROVIDES_libgcc_s1 += "libgcc_s1"

#PROVIDES by libstdc++48-devel-64bit 
PROVIDES += "libstdc++48-devel-64bit"
RPROVIDES_libstdc++48-devel-64bit += "libstdc++48-devel-64bit"
RPROVIDES_libstdc++48-devel-64bit += "libstdc++48-dev"

#PROVIDES by libgcc_s1-32bit 
PROVIDES += "libgcc_s1-32bit"
RPROVIDES_libgcc_s1-32bit += "libgcc_s1-32bit"
# the PROVIDES rules is ignore "libgcc_s1-32bit = 4.8.2-1"
PROVIDES += "libgcc_s1-32bit"
RPROVIDES_libgcc_s1-32bit += "libgcc_s1-32bit"

#PROVIDES by libtsan-64bit 
PROVIDES += "libtsan-64bit"
RPROVIDES_libtsan-64bit += "libtsan-64bit"

#PROVIDES by libstdc++-locale 
PROVIDES += "libstdc++-locale"
RPROVIDES_libstdc++-locale += "libstdc++-locale"
# the PROVIDES rules is ignore "libstdc++-locale = 4.8.2-1"
PROVIDES += "libstdc++-locale"
RPROVIDES_libstdc++-locale += "libstdc++-locale"

#PROVIDES by gcc48-testresults 
PROVIDES += "gcc48-testresults"
RPROVIDES_gcc48-testresults += "gcc48-testresults"

#PROVIDES by libffi48-devel 
PROVIDES += "libffi48-devel"
RPROVIDES_libffi48-devel += "libffi48-devel"
RPROVIDES_libffi48-devel += "libffi48-dev"

#PROVIDES by libada48 
PROVIDES += "libada48"
RPROVIDES_libada48 += "libada48"

#PROVIDES by libada48-64bit 
PROVIDES += "libada48-64bit"
RPROVIDES_libada48-64bit += "libada48-64bit"

#PROVIDES by gcc48-objc-64bit 
PROVIDES += "gcc48-objc-64bit"
RPROVIDES_gcc48-objc-64bit += "gcc48-objc-64bit"

#PROVIDES by gcc48-objc 
PROVIDES += "gcc48-objc"
RPROVIDES_gcc48-objc += "gcc48-objc"

#PROVIDES by libitm-64bit 
PROVIDES += "libitm-64bit"
RPROVIDES_libitm-64bit += "libitm-64bit"

#PROVIDES by libffi48-devel-32bit 
PROVIDES += "libffi48-devel-32bit"
RPROVIDES_libffi48-devel-32bit += "libffi48-devel-32bit"
RPROVIDES_libffi48-devel-32bit += "libffi48-dev"

#PROVIDES by gcc48-gij 
PROVIDES += "gcc48-gij"
RPROVIDES_gcc48-gij += "gcc48-gij"

#PROVIDES by libasan 
PROVIDES += "libasan"
RPROVIDES_libasan += "libasan"

#PROVIDES by libffi 
PROVIDES += "libffi"
RPROVIDES_libffi += "libffi"

#PROVIDES by libtsan-32bit 
PROVIDES += "libtsan-32bit"
RPROVIDES_libtsan-32bit += "libtsan-32bit"

#PROVIDES by gcc48-64bit 
PROVIDES += "gcc48-64bit"
RPROVIDES_gcc48-64bit += "gcc48-64bit"

#PROVIDES by gcc48-objc-32bit 
PROVIDES += "gcc48-objc-32bit"
RPROVIDES_gcc48-objc-32bit += "gcc48-objc-32bit"

#PROVIDES by libgomp-32bit 
PROVIDES += "libgomp-32bit"
RPROVIDES_libgomp-32bit += "libgomp-32bit"
# the PROVIDES rules is ignore "libgomp-32bit = 4.8.2-1"
PROVIDES += "libgomp-32bit"
RPROVIDES_libgomp-32bit += "libgomp-32bit"

#PROVIDES by libquadmath 
PROVIDES += "libquadmath"
RPROVIDES_libquadmath += "libquadmath"
# the PROVIDES rules is ignore "libquadmath = 4.8.2-1"
PROVIDES += "libquadmath"
RPROVIDES_libquadmath += "libquadmath"

#PROVIDES by libgfortran-32bit 
PROVIDES += "libgfortran-32bit"
RPROVIDES_libgfortran-32bit += "libgfortran-32bit"
# the PROVIDES rules is ignore "libgfortran-32bit = 4.8.2-1"
PROVIDES += "libgfortran-32bit"
RPROVIDES_libgfortran-32bit += "libgfortran-32bit"

#PROVIDES by libtsan 
PROVIDES += "libtsan"
RPROVIDES_libtsan += "libtsan"

#PROVIDES by libgfortran-64bit 
PROVIDES += "libgfortran-64bit"
RPROVIDES_libgfortran-64bit += "libgfortran-64bit"
# the PROVIDES rules is ignore "libgfortran-64bit = 4.8.2-1"
PROVIDES += "libgfortran-64bit"
RPROVIDES_libgfortran-64bit += "libgfortran-64bit"

#PROVIDES by libstdc++48-devel-32bit 
PROVIDES += "libstdc++48-devel-32bit"
RPROVIDES_libstdc++48-devel-32bit += "libstdc++48-devel-32bit"
RPROVIDES_libstdc++48-devel-32bit += "libstdc++48-dev"

#PROVIDES by libasan-64bit 
PROVIDES += "libasan-64bit"
RPROVIDES_libasan-64bit += "libasan-64bit"

#PROVIDES by libgomp 
PROVIDES += "libgomp"
RPROVIDES_libgomp += "libgomp"
# the PROVIDES rules is ignore "libgomp = 4.8.2-1"
PROVIDES += "libgomp"
RPROVIDES_libgomp += "libgomp"

#PROVIDES by libgcj_bc 
PROVIDES += "libgcj_bc"
RPROVIDES_libgcj_bc += "libgcj_bc"
# the PROVIDES rules is ignore "libgcj_bc.so.()(64bit)  "
PROVIDES += "libgcj_bc.so.()(64bit)"
RPROVIDES_libgcj_bc += "libgcj_bc.so.()(64bit)"

#PROVIDES by gcc48-fortran 
PROVIDES += "gcc48-fortran"
RPROVIDES_gcc48-fortran += "gcc48-fortran"

#PROVIDES by gcc48-ada-32bit 
PROVIDES += "gcc48-ada-32bit"
RPROVIDES_gcc48-ada-32bit += "gcc48-ada-32bit"

#PROVIDES by libstdc++-32bit 
PROVIDES += "libstdc++-32bit"
RPROVIDES_libstdc++-32bit += "libstdc++-32bit"
# the PROVIDES rules is ignore "libstdc++-32bit = 4.8.2-1"
PROVIDES += "libstdc++-32bit"
RPROVIDES_libstdc++-32bit += "libstdc++-32bit"

RDEPENDS = ""
#RDEPENDS of gcc48-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "gcc48"

#RDEPENDS of gcc48-java (${PN}-java)
RDEPENDS_${PN}-java += "gcc48"
RDEPENDS_${PN}-java += "libgcj48-dev"

#RDEPENDS of gcc48-ada (${PN}-ada)
RDEPENDS_${PN}-ada += "gcc48"
RDEPENDS_${PN}-ada += "libada48"

#RDEPENDS of libstdc++48-devel (libstdc++48-devel)
RDEPENDS_libstdc++48-devel += "libstdc++"
RDEPENDS_libstdc++48-devel += "glibc-dev"

#RDEPENDS of libffi48-devel-64bit (libffi48-devel-64bit)
RDEPENDS_libffi48-devel-64bit += "libffi-64bit"

#RDEPENDS of libgfortran (libgfortran)
RDEPENDS_libgfortran += "libquadmath"

#RDEPENDS of gcc48-c++ (${PN}-c++)
RDEPENDS_${PN}-c++ += "gcc48"
RDEPENDS_${PN}-c++ += "libstdc++48-dev"

#RDEPENDS of gcc48-fortran-32bit (${PN}-fortran-32bit)
RDEPENDS_${PN}-fortran-32bit += "gcc48"
RDEPENDS_${PN}-fortran-32bit += "libgfortran-32bit"
RDEPENDS_${PN}-fortran-32bit += "libquadmath-32bit"

#RDEPENDS of gcc48-fortran-64bit (${PN}-fortran-64bit)
RDEPENDS_${PN}-fortran-64bit += "gcc48"
RDEPENDS_${PN}-fortran-64bit += "libquadmath-64bit"
RDEPENDS_${PN}-fortran-64bit += "libgfortran-64bit"

#RDEPENDS of gcc48-ada-64bit (${PN}-ada-64bit)
RDEPENDS_${PN}-ada-64bit += "libada48-64bit"
RDEPENDS_${PN}-ada-64bit += "gcc48-64bit"

#RDEPENDS of gcc48-objc-64bit (${PN}-objc-64bit)
RDEPENDS_${PN}-objc-64bit += "gcc48"
RDEPENDS_${PN}-objc-64bit += "libobjc-64bit"

#RDEPENDS of gcc48-obj-c++ (${PN}-obj-c++)
RDEPENDS_${PN}-obj-c++ += "gcc48-objc"
RDEPENDS_${PN}-obj-c++ += "gcc48-c++"

#RDEPENDS of gcc48-32bit (${PN}-32bit)
RDEPENDS_${PN}-32bit += "gcc48"
RDEPENDS_${PN}-32bit += "libgomp-32bit"
RDEPENDS_${PN}-32bit += "glibc-dev"
RDEPENDS_${PN}-32bit += "libgcc_s1-32bit"

#RDEPENDS of libstdc++48-devel-64bit (libstdc++48-devel-64bit)
RDEPENDS_libstdc++48-devel-64bit += "glibc-dev"
RDEPENDS_libstdc++48-devel-64bit += "libstdc++-64bit"

#RDEPENDS of libffi48-devel (libffi48-devel)
RDEPENDS_libffi48-devel += "libffi"

#RDEPENDS of gcc48-objc (${PN}-objc)
RDEPENDS_${PN}-objc += "gcc48"
RDEPENDS_${PN}-objc += "libobjc"

#RDEPENDS of libffi48-devel-32bit (libffi48-devel-32bit)
RDEPENDS_libffi48-devel-32bit += "libffi-32bit"

#RDEPENDS of gcc48-gij (${PN}-gij)
RDEPENDS_${PN}-gij += "libgcj"

#RDEPENDS of gcc48 (${PN})
RDEPENDS_${PN} += "libgcc_s1"
RDEPENDS_${PN} += "glibc-dev"
RDEPENDS_${PN} += "libatomic"
RDEPENDS_${PN} += "libgomp"
RDEPENDS_${PN} += "cpp48"
RDEPENDS_${PN} += "libasan"
RDEPENDS_${PN} += "libitm"
RDEPENDS_${PN} += "libtsan"
RDEPENDS_${PN} += "binutils"

#RDEPENDS of gcc48-64bit (${PN}-64bit)
RDEPENDS_${PN}-64bit += "gcc48"
RDEPENDS_${PN}-64bit += "glibc-dev"
RDEPENDS_${PN}-64bit += "libgomp-64bit"
RDEPENDS_${PN}-64bit += "libgcc_s1-64bit"

#RDEPENDS of gcc48-objc-32bit (${PN}-objc-32bit)
RDEPENDS_${PN}-objc-32bit += "gcc48"
RDEPENDS_${PN}-objc-32bit += "libobjc-32bit"

#RDEPENDS of libgfortran-64bit (libgfortran-64bit)
RDEPENDS_libgfortran-64bit += "libquadmath-64bit"

#RDEPENDS of libgfortran-32bit (libgfortran-32bit)
RDEPENDS_libgfortran-32bit += "libquadmath-32bit"

#RDEPENDS of libgcj48-devel (libgcj48-devel)
RDEPENDS_libgcj48-devel += "zlib-dev"
RDEPENDS_libgcj48-devel += "glibc-dev"
RDEPENDS_libgcj48-devel += "gtk2-dev"
RDEPENDS_libgcj48-devel += "libart_lgpl-dev"
RDEPENDS_libgcj48-devel += "libgcj_bc"
RDEPENDS_libgcj48-devel += "libstdc++48-dev"
RDEPENDS_libgcj48-devel += "libgcj48-jar"
RDEPENDS_libgcj48-devel += "libgcj"

#RDEPENDS of libstdc++48-devel-32bit (libstdc++48-devel-32bit)
RDEPENDS_libstdc++48-devel-32bit += "glibc-dev"
RDEPENDS_libstdc++48-devel-32bit += "libstdc++-32bit"

#RDEPENDS of libgcj_bc (libgcj_bc)
RDEPENDS_libgcj_bc += "libgcj"

#RDEPENDS of gcc48-fortran (${PN}-fortran)
RDEPENDS_${PN}-fortran += "gcc48"
RDEPENDS_${PN}-fortran += "libquadmath"
RDEPENDS_${PN}-fortran += "libgfortran"

#RDEPENDS of gcc48-ada-32bit (${PN}-ada-32bit)
RDEPENDS_${PN}-ada-32bit += "libada48-32bit"
RDEPENDS_${PN}-ada-32bit += "gcc48-32bit"


DEPENDS = ""
#DEPENDS of gcc48 
DEPENDS += "zlib-devel"
DEPENDS += "flex"
DEPENDS += "gcc-cross"
DEPENDS += "cloog-isl"
inherit perlnative
DEPENDS += "isl-devel"
DEPENDS += "bison-native"
DEPENDS += "mpc-devel"
DEPENDS += "mpfr-devel"
DEPENDS += "makeinfo"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gcc-4.8.2
 
 
 # We are configuring ppc as ppc64 but with switched multilibs.  Adjust
 # the libstdc++ abi testsuite baseline files accordingly
 
 
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
 
 # Avoid rebuilding of generated files
 contrib/gcc_update --touch
 # Avoid fucking up testsuite results with Java and indirect dispatch
 export LD_AS_NEEDED=0
 # Split version file into version used for directories (X.Y) and
 # version to report with --version (X.Y.Z).
 # See also gcc-dir-version.patch.
 # Also decrement the patchlevel version by one
 if test `cat gcc/DEV-PHASE` == "prerelease"; then
   ( cat gcc/BASE-VER | cut -d '.' -f 1-2 | tr -d '\n'; echo -n .; cat gcc/BASE-VER | cut -d '.' -f 3 | tr '0123456789' '0012345678' ) > gcc/FULL-VER
 else
   mv gcc/BASE-VER gcc/FULL-VER
 fi
 cat gcc/FULL-VER | cut -d '.' -f 1-2 > gcc/BASE-VER
 
 rm -rf obj-i586-tizen-linux
 mkdir obj-i586-tizen-linux
 cd obj-i586-tizen-linux
 RPM_OPT_FLAGS="$RPM_OPT_FLAGS -U_FORTIFY_SOURCE"
 RPM_OPT_FLAGS=`echo $RPM_OPT_FLAGS|sed -e 's/-fno-rtti//g' -e 's/-fno-exceptions//g' -e 's/-Wmissing-format-attribute//g' -e 's/-fstack-protector//g' -e 's/-ffortify=.//g' -e 's/-Wall//g' -e 's/-m32//g' -e 's/-m64//g'`
 # Replace 2 spaces by one finally
 RPM_OPT_FLAGS=`echo $RPM_OPT_FLAGS|sed -e 's/  / /g'`
 
 languages=c
 languages=$languages,c++
 
 J=16
 if test -z "$J"; then
   J=$(getconf _NPROCESSORS_CONF)
   JL=$(($J * 2))
 else
   test 1 -gt "$J" && J=1
   JL=$(($(getconf _NPROCESSORS_CONF)*2))
 fi
 if test "$J" == "0"; then
   J=1
 fi
 if test "$JL" == "0"; then
   JL=1
 fi
 PARALLEL="-j$J -l$JL"
 
 # we don't want some miscompiles in the testsuite, or some fault in
 # the compiler to kill the machine.  Hence we limit the amount of memory
 # by the physical RAM plus half of swap
 #MEM=$(free -m | awk '/^Mem:/ {print $2}')
 #SWAP=$(free -m | awk '/^Swap:/ {print $2}')
 #ulimit -v $(((MEM + SWAP/2)*1024))
 
 # In general we want to ship release checking enabled compilers
 # and run BETA with checking enabled.
 #ENABLE_CHECKING="--enable-checking=yes"
 ENABLE_CHECKING="--enable-checking=release"
 
 # Work around tail/head -1 changes
 export _POSIX2_VERSION=199209
 
 # configure tries to parse include/features.h to detect
 # if glibc supports SSP.  When cross compiling we would need
 # to install a cross glibc, which we don't, or make the whole
 # thing point to the native glibc, which is in /, hence the
 # --with-build-sysroot=/
 
 #%if 0 && 01
 #%else
 #	--enable-threads=posix \
 #%endif
 #	--enable-shared \
 CFLAGS="$RPM_OPT_FLAGS" CXXFLAGS="$RPM_OPT_FLAGS" XCFLAGS="$RPM_OPT_FLAGS" \
 TCFLAGS="$RPM_OPT_FLAGS" GCJFLAGS="$RPM_OPT_FLAGS $GCJ_EXTRA_FLAGS" \
 ../configure \
 	--prefix=/usr \
 	--infodir=/usr/share/info \
 	--mandir=/usr/share/man \
 	--libdir=/usr/lib \
 	--libexecdir=/usr/lib \
     --disable-bootstrap \
 	--enable-languages=$languages \
 	$ENABLE_CHECKING \
 	--with-gxx-include-dir=/usr/include/c++/4.8 \
 	--enable-ssp \
 	--disable-libssp \
 	--disable-plugin \
 	--with-bugurl="http://bugs.tizen.org/" \
 	--with-pkgversion="Tizen" \
 	--disable-libquadmath \
         --disable-libgcj \
 	--disable-libmudflap \
 	--with-slibdir=/lib \
 	--with-system-zlib \
 	--enable-__cxa_atexit \
 	--enable-libstdcxx-allocator=new \
 	--disable-libstdcxx-pch \
 	--enable-version-specific-runtime-libs \
 	--enable-linker-build-id \
 	--program-suffix=-4.8 \
 	--enable-linux-futex \
 	--without-system-libunwind \
 	--with-arch-32=i586 \
 	--with-tune=generic \
 	--build=i586-tizen-linux
 
 
 STAGE1_FLAGS="-g"
 # Only run profiled bootstrap on archs where it works
 #%ifarch i386 i486 i586 i686 pentium3 pentium4 athlon geode x86_64 ppc ppc64 ia64
 #make profiledbootstrap-lean STAGE1_CFLAGS="$STAGE1_FLAGS" BOOT_CFLAGS="$RPM_OPT_FLAGS" $PARALLEL
 #%else
 #make bootstrap-lean STAGE1_CFLAGS="$STAGE1_FLAGS" BOOT_CFLAGS="$RPM_OPT_FLAGS" $PARALLEL
 make STAGE1_CFLAGS="$STAGE1_FLAGS" BOOT_CFLAGS="$RPM_OPT_FLAGS" $PARALLEL
 #%endif
 #make -C gcc proto
 make info
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 export NO_BRP_CHECK_BYTECODE_VERSION=true
 cd obj-i586-tizen-linux
 # Work around tail/head -1 changes
 export _POSIX2_VERSION=199209
 export LIBRARY_PATH=$RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8:$RPM_BUILD_ROOT/usr/lib
 make install DESTDIR=$RPM_BUILD_ROOT
 
 # Remove libffi installed files if we did not want to build it
 rm -f $RPM_BUILD_ROOT/usr/lib/libffi.*
   rm -f $RPM_BUILD_ROOT/usr/lib/libffi.*
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include/ffi.h
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include/ffitarget.h
 rm -f $RPM_BUILD_ROOT/usr/share/man/man3/ffi-4.8.3*
 rm -f $RPM_BUILD_ROOT/usr/share/man/man3/ffi_call-4.8.3*
 rm -f $RPM_BUILD_ROOT/usr/share/man/man3/ffi_prep_cif-4.8.3*
 rm -f $RPM_BUILD_ROOT/usr/share/man/man3/ffi_prep_cif_var-4.8.3*
 
 # Remove some useless .la files
 for lib in libobjc libgfortran libgfortranbegin libquadmath libcaf_single \
     libmudflap libmudflapth libgomp libstdc++ libsupc++ libgcj-tools libgij \
     libasan libatomic libitm libtsan; do
   rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/$lib.la
   rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/$lib.la
 done
 
 mkdir -p $RPM_BUILD_ROOT/usr/lib
 mkdir -p $RPM_BUILD_ROOT/usr/lib
 
 # Merge multilib c++config.h to allow omitting the duplicate and
 # identical other arch specific headers
 dir_ml=
 cxxconfig="`find i586-tizen-linux/libstdc++-v3/include -name c++config.h`"
 for i in `find i586-tizen-linux/[36]*/libstdc++-v3/include -name c++config.h 2>/dev/null`; do
   if ! diff -up $cxxconfig $i; then
     file_32=x
     file_64=x
     case $i in
       i586-tizen-linux/32/*)
         file_32=$i
         file_64=$cxxconfig
         dir_ml=32
 	;;
       i586-tizen-linux/64/*)
         file_32=$cxxconfig
 	file_64=$i
         dir_ml=64
 	;;
     esac
     if ! ( test -f "$file_32" && test -f "$file_64" ); then
       echo "Urgs?"
       exit 1
     fi
     
     cat > $RPM_BUILD_ROOT/usr/include/c++/4.8/i586-tizen-linux/bits/c++config.h <<EOF
 #ifndef _CPP_CPPCONFIG_WRAPPER
 #define _CPP_CPPCONFIG_WRAPPER 1
 #include <bits/wordsize.h>
 #if __WORDSIZE == 32
 `cat $file_32`
 #else
 `cat $file_64`
 #endif
 #endif
 EOF
     break
   fi
 done
 rm -rf $RPM_BUILD_ROOT/usr/include/c++/4.8/i586-tizen-linux/[36]*
 if ! test -z "$dir_ml"; then
   ln -s . $RPM_BUILD_ROOT/usr/include/c++/4.8/i586-tizen-linux/$dir_ml
 fi
 
 # move shared libs from versionspecific dir to main libdir
 for libname in \
   libstdc++ \
   libgomp \
   libatomic \
   libitm \
   libasan \
   libtsan \
     ; do
   for lib in `find $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8 -maxdepth 1 -name $libname.so.*`; do
     mv $lib $RPM_BUILD_ROOT/usr/lib/
   done
   ln -sf /usr/lib/`readlink $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/$libname.so | sed -e 's/\(.*\.so\.[^\.]*\).*/\1/'`  \
          $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/$libname.so
   if test -d $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32; then
     for lib in `find $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32 -maxdepth 1 -name "$libname.so.*"`; do
       mv $lib $RPM_BUILD_ROOT/usr/lib/
     done
     ln -sf /usr/lib/`readlink $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/$libname.so | sed -e 's/\(.*\.so\.[^\.]*\).*/\1/'`  \
          $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/$libname.so
   fi
 done
 # FIXME, tsan is not multilib
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/libtsan.so
 # And we want to move the shlib gdb pretty printers to a more sane
 # place so ldconfig does not complain
 mkdir -p $RPM_BUILD_ROOT/usr/share/gdb/auto-load/usr/lib
 mv $RPM_BUILD_ROOT/usr/lib/libstdc++.so.*-gdb.py $RPM_BUILD_ROOT/usr/share/gdb/auto-load/usr/lib/
 sed -i -e '/^libdir/s/\/gcc\/i586-tizen-linux\/4.8//g' $RPM_BUILD_ROOT/usr/share/gdb/auto-load/usr/lib/libstdc++.so.*-gdb.py
   if test -d $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32; then
     mkdir -p $RPM_BUILD_ROOT/usr/share/gdb/auto-load/usr/lib
     mv $RPM_BUILD_ROOT/usr/lib/libstdc++.so.*-gdb.py $RPM_BUILD_ROOT/usr/share/gdb/auto-load/usr/lib/
     sed -i -e '/^libdir/s/\/gcc\/i586-tizen-linux\/4.8//g' $RPM_BUILD_ROOT/usr/share/gdb/auto-load/usr/lib/libstdc++.so.*-gdb.py
   fi
 
 # Move libgcc_s around
 if test -L $RPM_BUILD_ROOT/lib/libgcc_s.so; then
   rm -f $RPM_BUILD_ROOT/lib/libgcc_s.so
   ln -sf /lib/libgcc_s.so.1 $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/libgcc_s.so
 else
   mv $RPM_BUILD_ROOT/lib/libgcc_s.so $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/
 fi
 chmod a+x $RPM_BUILD_ROOT/lib/libgcc_s.so.1
 if test -L $RPM_BUILD_ROOT/lib/libgcc_s.so; then
   rm -f $RPM_BUILD_ROOT/lib/libgcc_s.so
   ln -sf /lib/libgcc_s.so.1 $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/libgcc_s.so
 else
   mv $RPM_BUILD_ROOT/lib/libgcc_s.so $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/
 fi
 ln -sf /usr/lib/gcc/i586-tizen-linux/4.8/32/libgcc_s.so $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/libgcc_s_32.so
 chmod a+x $RPM_BUILD_ROOT/lib/libgcc_s.so.1
 
 
 
 rm -f $RPM_BUILD_ROOT/usr/bin/c++-4.8
 
 # Remove some crap from the .la files:
 for l in `find $RPM_BUILD_ROOT -name '*.la'`; do
   echo "changing $l"
 # -e '/^dependency_libs/s|/usr/lib/gcc/i586-tizen-linux/4.8/\([^.]*\)\.la |/usr/lib/\1\.la |g'
   sed -e '/^dependency_libs/s| -L${WORKDIR}/[^ ]*||g' \
       -e '/^dependency_libs/s| -L/usr/i586-tizen-linux/bin||g' \
       -e '/^dependency_libs/s|-lm \(-lm \)*|-lm |' \
       -e '/^dependency_libs/s|-L[^ ]* ||g' \
       -e '/^libdir/s|/usr/lib/32|/usr/lib|' \
       -e '/^libdir/s|lib64/\.\./||' \
       < $l  > $l.new
   mv $l.new $l
 done
 
 # Find C++ and Java headers
 find $RPM_BUILD_ROOT/usr/include/c++ \
   -regex ".*/\(org\|gcj\|gnu\|java\|javax\)" -prune \
   -o \( -type d -printf "%%dir " , \
         -printf "/usr/include/c++/%P\n" \) > ../c++-headers
 # Remove files that we do not need to clean up filelist
 rm -f $RPM_BUILD_ROOT/usr/bin/i586-tizen-linux-*
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/install-tools
 #rm -rf $RPM_BUILD_ROOT/usr/lib/pkgconfig/libgcj-4.8.pc
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/root
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/curses.h
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/asm-*
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/linux
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/sound
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/features.h
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/ncurses.h
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/stdio.h
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/zutil.h
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/X11
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/bits
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/obstack.h
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/spe.h
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/tgmath.h
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/bits
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/sys
 # no plugins
 rm -rf $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/plugin
 rm -f  $RPM_BUILD_ROOT/usr/share/info/dir
 rm -f  $RPM_BUILD_ROOT/usr/bin/gccbug-4.8
 
 # delete compile flag tracking from crt files
 crt_list=$RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/crt*.o
 crt32_list=$RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/32/crt*.o
 for o in $crt_list $crt32_list $crt64_list; do
   objcopy -R ".comment.SUSE.OPTs" $o
 done
 
 
 
 rm -f $RPM_BUILD_ROOT/usr/share/man/man7/fsf-funding.7
 rm -f $RPM_BUILD_ROOT/usr/share/man/man7/gfdl.7
 rm -f $RPM_BUILD_ROOT/usr/share/man/man7/gpl.7
 rm -f $RPM_BUILD_ROOT/usr/lib/libiberty.a
 rm -f $RPM_BUILD_ROOT/usr/lib/libiberty.a
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/liblto_plugin.a
 rm -f $RPM_BUILD_ROOT/usr/lib/gcc/i586-tizen-linux/4.8/liblto_plugin.la
 
 # For regular build, some info files do not get renamed properly.
 # Do so here.
 mv $RPM_BUILD_ROOT/usr/share/info/libgomp.info $RPM_BUILD_ROOT/usr/share/info/libgomp-4.8.info
 mv $RPM_BUILD_ROOT/usr/share/info/libitm.info $RPM_BUILD_ROOT/usr/share/info/libitm-4.8.info
 
 cd ..
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} cpplib-4.8
 /usr/share/spec2yocto/macro/lib/find-lang.sh ${D} gcc-4.8
 cat cpplib-4.8.lang gcc-4.8.lang > gcc48-locale.lang
 
 
 
}

PACKAGES = ""
PACKAGES += "libatomic-32bit"
PACKAGES += "libatomic"
PACKAGES += "gcc48-locale"
PACKAGES += "libstdc++"
PACKAGES += "libstdc++48-devel"
PACKAGES += "libstdc++48-doc"
PACKAGES += "libitm"
PACKAGES += "libgcc_s1"
PACKAGES += "gcc48-c++"
PACKAGES += "libitm-32bit"
PACKAGES += "gcc48-32bit"
PACKAGES += "gcc48"
PACKAGES += "libtsan"
PACKAGES += "gcc48-info"
PACKAGES += "libgcc_s1-32bit"
PACKAGES += "libstdc++-locale"
PACKAGES += "libstdc++-32bit"
PACKAGES += "libasan"
PACKAGES += "libgomp-32bit"
PACKAGES += "libstdc++48-devel-32bit"
PACKAGES += "libgomp"
PACKAGES += "cpp48"
PACKAGES += "libasan-32bit"

libatomic-32bit_files = ""
libatomic-32bit_files += "/usr/lib/libatomic.so.*"

libatomic_files = ""
libatomic_files += "/usr/lib/libatomic.so.*"

gcc48-locale_files = ""

libstdc++_files = ""
libstdc++_files += "/usr/lib/libstdc++.so.*"

libstdc++48-devel_files = ""
libstdc++48-devel_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libstdc++.a"
libstdc++48-devel_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libstdc++.so"
libstdc++48-devel_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libsupc++.a"
libstdc++48-devel_files += "/usr/share/gdb"
libstdc++48-devel_files += "/usr/share/gdb/auto-load"
libstdc++48-devel_files += "/usr/share/gdb/auto-load/usr"
libstdc++48-devel_files += "/usr/share/gdb/auto-load/usr/lib"
libstdc++48-devel_files += "/usr/share/gdb/auto-load/usr/lib/libstdc++.so.*-gdb.py"
libstdc++48-devel_files += "/usr/share/gcc-4.8"

libstdc++48-doc_files = ""
libstdc++48-doc_files += "libstdc++-v3/doc/html"

libitm_files = ""
libitm_files += "/usr/lib/libitm.so.*"

libgcc_s1_files = ""
libgcc_s1_files += "/lib/libgcc_s.so.1"

gcc48-c++_files = ""
gcc48-c++_files += "/usr/lib/gcc"
gcc48-c++_files += "/usr/lib/gcc/i586-tizen-linux"
gcc48-c++_files += "/usr/lib/gcc/i586-tizen-linux/4.8"
gcc48-c++_files += "/usr/bin/g++-4.8"
gcc48-c++_files += "/usr/share/man/man1/g++-4.8.1.gz"
gcc48-c++_files += "/usr/lib/gcc/i586-tizen-linux/4.8/cc1plus"

libitm-32bit_files = ""
libitm-32bit_files += "/usr/lib/libitm.so.*"

gcc48-32bit_files = ""
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/*crt*.o"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libgcc*.a"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libgcov.a"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libgcc_s*.so"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libgomp.so"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libgomp.a"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libgomp.spec"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libitm.so"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libitm.a"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libitm.spec"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libatomic.a"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libatomic.so"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libasan.a"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libasan.so"
gcc48-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libasan_preinit.o"

gcc48_files = ""
gcc48_files += "/usr/lib/gcc"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32"
gcc48_files += "/usr/bin/gcc-4.8"
gcc48_files += "/usr/bin/gcov-4.8"
gcc48_files += "/usr/bin/gcc-ar-4.8"
gcc48_files += "/usr/bin/gcc-nm-4.8"
gcc48_files += "/usr/bin/gcc-ranlib-4.8"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/collect2"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/lto1"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/lto-wrapper"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/liblto_plugin.so*"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/README"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/limits.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include-fixed/syslimits.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/omp.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/float.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/iso646.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdarg.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdbool.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdfix.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stddef.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/unwind.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/varargs.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdint.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdint-gcc.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdnoreturn.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/stdalign.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/cross-stdarg.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/cpuid.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/mm3dnow.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/mmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/ammintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/bmmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/emmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/immintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/avxintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/pmmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/xmmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/tmmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/nmmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/smmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/wmmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/x86intrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/ia32intrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/mm_malloc.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/fma4intrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/xopintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/lwpintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/popcntintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/bmiintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/tbmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/avx2intrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/bmi2intrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/fmaintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/lzcntintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/f16cintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/adxintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/fxsrintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/prfchwintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/rdseedintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/rtmintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/xsaveintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/xsaveoptintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/include/xtestintrin.h"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/*crt*.o"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libgcc*.a"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libgcov.a"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libgcc_s*.so"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libgomp.so"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libgomp.a"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libgomp.spec"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libitm.so"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libitm.a"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libitm.spec"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libatomic.so"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libatomic.a"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libasan.so"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libasan.a"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libasan_preinit.o"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libtsan.so"
gcc48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/libtsan.a"
gcc48_files += "/usr/share/man/man1/gcc-4.8.1.gz"
gcc48_files += "/usr/share/man/man1/gcov-4.8.1.gz"

libtsan_files = ""
libtsan_files += "/usr/lib/libtsan.so.*"

gcc48-info_files = ""
gcc48-info_files += "/usr/share/info/*.gz"

libgcc_s1-32bit_files = ""
libgcc_s1-32bit_files += "/lib/libgcc_s.so.1"

libstdc++-locale_files = ""

libstdc++-32bit_files = ""
libstdc++-32bit_files += "/usr/lib/libstdc++.so.*"

libasan_files = ""
libasan_files += "/usr/lib/libasan.so.*"

libgomp-32bit_files = ""
libgomp-32bit_files += "/usr/lib/libgomp.so.*"

libstdc++48-devel-32bit_files = ""
libstdc++48-devel-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libstdc++.a"
libstdc++48-devel-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libstdc++.so"
libstdc++48-devel-32bit_files += "/usr/lib/gcc/i586-tizen-linux/4.8/32/libsupc++.a"
libstdc++48-devel-32bit_files += "/usr/share/gdb/auto-load/usr/lib"
libstdc++48-devel-32bit_files += "/usr/share/gdb/auto-load/usr/lib/libstdc++.so.*-gdb.py"

libgomp_files = ""
libgomp_files += "/usr/lib/libgomp.so.*"

cpp48_files = ""
cpp48_files += "/usr/lib/gcc"
cpp48_files += "/usr/lib/gcc/i586-tizen-linux"
cpp48_files += "/usr/lib/gcc/i586-tizen-linux/4.8"
cpp48_files += "/usr/bin/cpp-4.8"
cpp48_files += "/usr/lib/gcc/i586-tizen-linux/4.8/cc1"
cpp48_files += "/usr/share/man/man1/cpp-4.8.1.gz"

libasan-32bit_files = ""
libasan-32bit_files += "/usr/lib/libasan.so.*"

FILES_libatomic-32bit = "${libatomic-32bit_files}"
FILES_libatomic = "${libatomic_files}"
FILES_${PN}-locale = "${gcc48-locale_files}"
FILES_libstdc++ = "${libstdc++_files}"
FILES_libstdc++48-devel = "${libstdc++48-devel_files}"
FILES_libstdc++48-doc = "${libstdc++48-doc_files}"
FILES_libitm = "${libitm_files}"
FILES_libgcc_s1 = "${libgcc_s1_files}"
FILES_${PN}-c++ = "${gcc48-c++_files}"
FILES_libitm-32bit = "${libitm-32bit_files}"
FILES_${PN}-32bit = "${gcc48-32bit_files}"
FILES_${PN} = "${gcc48_files}"
FILES_libtsan = "${libtsan_files}"
FILES_${PN}-info = "${gcc48-info_files}"
FILES_libgcc_s1-32bit = "${libgcc_s1-32bit_files}"
FILES_libstdc++-locale = "${libstdc++-locale_files}"
FILES_libstdc++-32bit = "${libstdc++-32bit_files}"
FILES_libasan = "${libasan_files}"
FILES_libgomp-32bit = "${libgomp-32bit_files}"
FILES_libstdc++48-devel-32bit = "${libstdc++48-devel-32bit_files}"
FILES_libgomp = "${libgomp_files}"
FILES_cpp48 = "${cpp48_files}"
FILES_libasan-32bit = "${libasan-32bit_files}"

PKG_libatomic-32bit= "libatomic-32bit"
PKG_libatomic= "libatomic"
PKG_gcc48-locale= "gcc48-locale"
PKG_libstdc++= "libstdc++"
PKG_libstdc++48-devel= "libstdc++48-devel"
PKG_libstdc++48-doc= "libstdc++48-doc"
PKG_libitm= "libitm"
PKG_libgcc_s1= "libgcc_s1"
PKG_gcc48-c++= "gcc48-c++"
PKG_libitm-32bit= "libitm-32bit"
PKG_gcc48-32bit= "gcc48-32bit"
PKG_gcc48= "gcc48"
PKG_libtsan= "libtsan"
PKG_gcc48-info= "gcc48-info"
PKG_libgcc_s1-32bit= "libgcc_s1-32bit"
PKG_libstdc++-locale= "libstdc++-locale"
PKG_libstdc++-32bit= "libstdc++-32bit"
PKG_libasan= "libasan"
PKG_libgomp-32bit= "libgomp-32bit"
PKG_libstdc++48-devel-32bit= "libstdc++48-devel-32bit"
PKG_libgomp= "libgomp"
PKG_cpp48= "cpp48"
PKG_libasan-32bit= "libasan-32bit"

require gcc48-extraconf.inc
