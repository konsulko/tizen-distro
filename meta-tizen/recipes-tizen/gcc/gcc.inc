DESCRIPTION = "The system GNU C Compiler"
HOMEPAGE = "http://gcc.gnu.org/"
SECTION = "Development/Toolchain"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gcc-gij 
PROVIDES += "gcc-gij"
RPROVIDES_gcc-gij += "gcc-gij"

#PROVIDES by gcc-gij-32bit 
PROVIDES += "gcc-gij-32bit"
RPROVIDES_gcc-gij-32bit += "gcc-gij-32bit"

#PROVIDES by gcc-obj-c++ 
PROVIDES += "gcc-obj-c++"
RPROVIDES_gcc-obj-c++ += "gcc-obj-c++"

#PROVIDES by gcc-fortran-32bit 
PROVIDES += "gcc-fortran-32bit"
RPROVIDES_gcc-fortran-32bit += "gcc-fortran-32bit"

#PROVIDES by gcc-info 
PROVIDES += "gcc-info"
RPROVIDES_gcc-info += "gcc-info"

#PROVIDES by gcc 
PROVIDES += "gcc"
RPROVIDES_gcc += "gcc"
# the PROVIDES rules is ignore "c_compiler  "
PROVIDES += "c_compiler"
RPROVIDES_gcc += "c_compiler"

#PROVIDES by libstdc++-devel 
PROVIDES += "libstdc++-devel"
RPROVIDES_libstdc++-devel += "libstdc++-devel"
RPROVIDES_libstdc++-devel += "libstdc++-dev"

#PROVIDES by gcc-64bit 
PROVIDES += "gcc-64bit"
RPROVIDES_gcc-64bit += "gcc-64bit"

#PROVIDES by gcc-locale 
PROVIDES += "gcc-locale"
RPROVIDES_gcc-locale += "gcc-locale"

#PROVIDES by gcc-objc-64bit 
PROVIDES += "gcc-objc-64bit"
RPROVIDES_gcc-objc-64bit += "gcc-objc-64bit"

#PROVIDES by gcc-c++ 
PROVIDES += "gcc-c++"
RPROVIDES_gcc-c++ += "gcc-c++"
# the PROVIDES rules is ignore "c++_compiler  "
PROVIDES += "c++_compiler"
RPROVIDES_gcc-c++ += "c++_compiler"

#PROVIDES by gcc-fortran 
PROVIDES += "gcc-fortran"
RPROVIDES_gcc-fortran += "gcc-fortran"

#PROVIDES by gcc-c++-64bit 
PROVIDES += "gcc-c++-64bit"
RPROVIDES_gcc-c++-64bit += "gcc-c++-64bit"

#PROVIDES by gcc-z9 
PROVIDES += "gcc-z9"
RPROVIDES_gcc-z9 += "gcc-z9"

#PROVIDES by gcc-objc-32bit 
PROVIDES += "gcc-objc-32bit"
RPROVIDES_gcc-objc-32bit += "gcc-objc-32bit"

#PROVIDES by gcc-java 
PROVIDES += "gcc-java"
RPROVIDES_gcc-java += "gcc-java"

#PROVIDES by libgcj-devel 
PROVIDES += "libgcj-devel"
RPROVIDES_libgcj-devel += "libgcj-devel"
RPROVIDES_libgcj-devel += "libgcj-dev"

#PROVIDES by gcc-c++-32bit 
PROVIDES += "gcc-c++-32bit"
RPROVIDES_gcc-c++-32bit += "gcc-c++-32bit"

#PROVIDES by gcc-ada 
PROVIDES += "gcc-ada"
RPROVIDES_gcc-ada += "gcc-ada"

#PROVIDES by gcc-32bit 
PROVIDES += "gcc-32bit"
RPROVIDES_gcc-32bit += "gcc-32bit"

#PROVIDES by gcc-objc 
PROVIDES += "gcc-objc"
RPROVIDES_gcc-objc += "gcc-objc"

#PROVIDES by gcc-fortran-64bit 
PROVIDES += "gcc-fortran-64bit"
RPROVIDES_gcc-fortran-64bit += "gcc-fortran-64bit"

#PROVIDES by cpp 
PROVIDES += "cpp"
RPROVIDES_cpp += "cpp"

#PROVIDES by gcc-gij-64bit 
PROVIDES += "gcc-gij-64bit"
RPROVIDES_gcc-gij-64bit += "gcc-gij-64bit"

RDEPENDS = ""
#RDEPENDS of gcc-gij (${PN}-gij)
RDEPENDS_${PN}-gij += "gcc48-gij"

#RDEPENDS of gcc-gij-32bit (${PN}-gij-32bit)
RDEPENDS_${PN}-gij-32bit += "gcc48-gij-32bit"

#RDEPENDS of gcc-obj-c++ (${PN}-obj-c++)
RDEPENDS_${PN}-obj-c++ += "gcc-objc"
RDEPENDS_${PN}-obj-c++ += "gcc48-obj-c++"

#RDEPENDS of gcc-fortran-32bit (${PN}-fortran-32bit)
RDEPENDS_${PN}-fortran-32bit += "gcc48-fortran-32bit"
RDEPENDS_${PN}-fortran-32bit += "gcc-fortran"

#RDEPENDS of gcc-info (${PN}-info)
RDEPENDS_${PN}-info += "gcc48-info"

#RDEPENDS of gcc (${PN})
RDEPENDS_${PN} += "cpp"
RDEPENDS_${PN} += "gcc48"

#RDEPENDS of libstdc++-devel (libstdc++-devel)
RDEPENDS_libstdc++-devel += "libstdc++48-dev"

#RDEPENDS of gcc-64bit (${PN}-64bit)
RDEPENDS_${PN}-64bit += "gcc"
RDEPENDS_${PN}-64bit += "gcc48-64bit"

#RDEPENDS of gcc-locale (${PN}-locale)
RDEPENDS_${PN}-locale += "gcc48-locale"

#RDEPENDS of gcc-objc-64bit (${PN}-objc-64bit)
RDEPENDS_${PN}-objc-64bit += "gcc48-objc-64bit"
RDEPENDS_${PN}-objc-64bit += "gcc-objc"

#RDEPENDS of gcc-c++ (${PN}-c++)
RDEPENDS_${PN}-c++ += "gcc"
RDEPENDS_${PN}-c++ += "gcc48-c++"

#RDEPENDS of gcc-fortran (${PN}-fortran)
RDEPENDS_${PN}-fortran += "gcc"
RDEPENDS_${PN}-fortran += "gcc48-fortran"

#RDEPENDS of gcc-c++-64bit (${PN}-c++-64bit)
RDEPENDS_${PN}-c++-64bit += "gcc-64bit"
RDEPENDS_${PN}-c++-64bit += "libstdc++48-dev"
RDEPENDS_${PN}-c++-64bit += "gcc-c++"

#RDEPENDS of gcc-z9 (${PN}-z9)
RDEPENDS_${PN}-z9 += "gcc"

#RDEPENDS of gcc-objc-32bit (${PN}-objc-32bit)
RDEPENDS_${PN}-objc-32bit += "gcc-objc"
RDEPENDS_${PN}-objc-32bit += "gcc48-objc-32bit"

#RDEPENDS of gcc-java (${PN}-java)
RDEPENDS_${PN}-java += "gcc48-java"
RDEPENDS_${PN}-java += "libgcj-dev"
RDEPENDS_${PN}-java += "gcc"

#RDEPENDS of libgcj-devel (libgcj-devel)
RDEPENDS_libgcj-devel += "libgcj48-dev"

#RDEPENDS of gcc-c++-32bit (${PN}-c++-32bit)
RDEPENDS_${PN}-c++-32bit += "libstdc++48-dev"
RDEPENDS_${PN}-c++-32bit += "gcc-32bit"
RDEPENDS_${PN}-c++-32bit += "gcc-c++"

#RDEPENDS of gcc-ada (${PN}-ada)
RDEPENDS_${PN}-ada += "gcc"
RDEPENDS_${PN}-ada += "gcc48-ada"

#RDEPENDS of gcc-32bit (${PN}-32bit)
RDEPENDS_${PN}-32bit += "gcc"
RDEPENDS_${PN}-32bit += "gcc48-32bit"

#RDEPENDS of gcc-objc (${PN}-objc)
RDEPENDS_${PN}-objc += "gcc"
RDEPENDS_${PN}-objc += "gcc48-objc"

#RDEPENDS of gcc-fortran-64bit (${PN}-fortran-64bit)
RDEPENDS_${PN}-fortran-64bit += "gcc48-fortran-64bit"
RDEPENDS_${PN}-fortran-64bit += "gcc-fortran"

#RDEPENDS of cpp (cpp)
RDEPENDS_cpp += "cpp48"

#RDEPENDS of gcc-gij-64bit (${PN}-gij-64bit)
RDEPENDS_${PN}-gij-64bit += "gcc48-gij-64bit"


DEPENDS = ""

do_patch() {
 
 
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
 
 echo "This is a dummy package to provide a dependency on the system compiler." > README
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p $RPM_BUILD_ROOT/lib
 mkdir -p $RPM_BUILD_ROOT/usr/bin
 mkdir -p $RPM_BUILD_ROOT/usr/share/man/man1
 mkdir -p $RPM_BUILD_ROOT/usr/share/doc/packages/gcc-objc/
 mkdir -p $RPM_BUILD_ROOT/usr/share/doc/packages/gcc-obj-c++/
 # Link all the binaries
 for program in \
         gcc gcov \
         g++ \
         cpp \
 	gcj gcjh gcj-dbtool jcf-dump jv-convert gc-analyze \
 	gij \
 	gappletviewer \
 	gjar gjarsigner gjavah gkeytool gnative2ascii gorbd grmic \
 	grmid grmiregistry gserialver gtnameserv \
 	grmiregistry32 \
 	gij32 \
         gfortran \
 	gnat gnatbind gnatbl gnatchop gnatclean gnatfind gnatkr \
 	gnatlink gnatls gnatmake gnatname gnatprep gnatxref gprmake \
     ; do
   ln -sf $program-4.8 $RPM_BUILD_ROOT/usr/bin/$program
 done
 # Link section 1 manpages
 for man1 in \
         gcc gcov \
         g++ \
         cpp \
         gfortran \
 	gcj gcjh gcj-dbtool jcf-dump jv-convert gc-analyze \
 	gij \
 	gappletviewer gjar gjarsigner gjavah \
 	gkeytool gnative2ascii gorbd grmic grmid grmiregistry gserialver \
 	gtnameserv \
     ; do
   ln -sf $man1-4.8.1.gz $RPM_BUILD_ROOT/usr/share/man/man1/$man1.1.gz
 done
 # Provide the traditional /lib/cpp that only handles C
 cp $RPM_SOURCE_DIR/cpp $RPM_BUILD_ROOT/lib/
 chmod 755 $RPM_BUILD_ROOT/lib/cpp
 # Provide extra symlinks
 ln -sf g++-4.8 $RPM_BUILD_ROOT/usr/bin/c++
 ln -sf gcc-4.8 $RPM_BUILD_ROOT/usr/bin/cc
 ln -sf g++-4.8.1.gz $RPM_BUILD_ROOT/usr/share/man/man1/c++.1.gz
 ln -sf gcc-4.8.1.gz $RPM_BUILD_ROOT/usr/share/man/man1/cc.1.gz
 
 
}

PACKAGES = ""
PACKAGES += "gcc"
PACKAGES += "gcc-fortran-32bit"
PACKAGES += "libstdc++-devel"
PACKAGES += "gcc-ada"
PACKAGES += "gcc-gij-32bit"
PACKAGES += "gcc-32bit"
PACKAGES += "gcc-gij"
PACKAGES += "gcc-objc"
PACKAGES += "gcc-info"
PACKAGES += "gcc-obj-c++"
PACKAGES += "gcc-objc-32bit"
PACKAGES += "gcc-java"
PACKAGES += "cpp"
PACKAGES += "libgcj-devel"
PACKAGES += "gcc-c++"
PACKAGES += "gcc-c++-32bit"
PACKAGES += "gcc-locale"
PACKAGES += "gcc-fortran"

gcc_files = ""
gcc_files += "/usr/bin/gcc"
gcc_files += "/usr/bin/cc"
gcc_files += "/usr/bin/gcov"
gcc_files += "/usr/share/man/man1/gcc.1.gz"
gcc_files += "/usr/share/man/man1/cc.1.gz"
gcc_files += "/usr/share/man/man1/gcov.1.gz"

gcc-fortran-32bit_files = ""
gcc-fortran-32bit_files += "README"

libstdc++-devel_files = ""
libstdc++-devel_files += "README"

gcc-ada_files = ""
gcc-ada_files += "/usr/bin/gnat"
gcc-ada_files += "/usr/bin/gnatbind"
gcc-ada_files += "/usr/bin/gnatbl"
gcc-ada_files += "/usr/bin/gnatchop"
gcc-ada_files += "/usr/bin/gnatclean"
gcc-ada_files += "/usr/bin/gnatfind"
gcc-ada_files += "/usr/bin/gnatkr"
gcc-ada_files += "/usr/bin/gnatlink"
gcc-ada_files += "/usr/bin/gnatls"
gcc-ada_files += "/usr/bin/gnatmake"
gcc-ada_files += "/usr/bin/gnatname"
gcc-ada_files += "/usr/bin/gnatprep"
gcc-ada_files += "/usr/bin/gnatxref"
gcc-ada_files += "/usr/bin/gprmake"

gcc-gij-32bit_files = ""
gcc-gij-32bit_files += "/usr/bin/gij32"
gcc-gij-32bit_files += "/usr/bin/grmiregistry32"

gcc-32bit_files = ""
gcc-32bit_files += "README"

gcc-gij_files = ""
gcc-gij_files += "/usr/bin/gij"
gcc-gij_files += "/usr/bin/gappletviewer"
gcc-gij_files += "/usr/bin/gjar"
gcc-gij_files += "/usr/bin/gjarsigner"
gcc-gij_files += "/usr/bin/gjavah"
gcc-gij_files += "/usr/bin/gkeytool"
gcc-gij_files += "/usr/bin/gnative2ascii"
gcc-gij_files += "/usr/bin/gorbd"
gcc-gij_files += "/usr/bin/grmic"
gcc-gij_files += "/usr/bin/grmid"
gcc-gij_files += "/usr/bin/grmiregistry"
gcc-gij_files += "/usr/bin/gserialver"
gcc-gij_files += "/usr/bin/gtnameserv"
gcc-gij_files += "/usr/share/man/man1/gij.1.gz"
gcc-gij_files += "/usr/share/man/man1/gappletviewer.1.gz"
gcc-gij_files += "/usr/share/man/man1/gjar.1.gz"
gcc-gij_files += "/usr/share/man/man1/gjarsigner.1.gz"
gcc-gij_files += "/usr/share/man/man1/gjavah.1.gz"
gcc-gij_files += "/usr/share/man/man1/gkeytool.1.gz"
gcc-gij_files += "/usr/share/man/man1/gnative2ascii.1.gz"
gcc-gij_files += "/usr/share/man/man1/gorbd.1.gz"
gcc-gij_files += "/usr/share/man/man1/grmic.1.gz"
gcc-gij_files += "/usr/share/man/man1/grmid.1.gz"
gcc-gij_files += "/usr/share/man/man1/grmiregistry.1.gz"
gcc-gij_files += "/usr/share/man/man1/gserialver.1.gz"
gcc-gij_files += "/usr/share/man/man1/gtnameserv.1.gz"

gcc-objc_files = ""
gcc-objc_files += "README"

gcc-info_files = ""
gcc-info_files += "README"

gcc-obj-c++_files = ""
gcc-obj-c++_files += "README"

gcc-objc-32bit_files = ""
gcc-objc-32bit_files += "README"

gcc-java_files = ""
gcc-java_files += "/usr/bin/gcj"
gcc-java_files += "/usr/bin/gcjh"
gcc-java_files += "/usr/bin/gcj-dbtool"
gcc-java_files += "/usr/bin/jcf-dump"
gcc-java_files += "/usr/bin/jv-convert"
gcc-java_files += "/usr/bin/gc-analyze"
gcc-java_files += "/usr/share/man/man1/gcj.1.gz"
gcc-java_files += "/usr/share/man/man1/gcjh.1.gz"
gcc-java_files += "/usr/share/man/man1/gcj-dbtool.1.gz"
gcc-java_files += "/usr/share/man/man1/jcf-dump.1.gz"
gcc-java_files += "/usr/share/man/man1/jv-convert.1.gz"
gcc-java_files += "/usr/share/man/man1/gc-analyze.1.gz"

cpp_files = ""
cpp_files += "/lib/cpp"
cpp_files += "/usr/bin/cpp"
cpp_files += "/usr/share/man/man1/cpp.1.gz"

libgcj-devel_files = ""
libgcj-devel_files += "README"

gcc-c++_files = ""
gcc-c++_files += "/usr/bin/g++"
gcc-c++_files += "/usr/bin/c++"
gcc-c++_files += "/usr/share/man/man1/g++.1.gz"
gcc-c++_files += "/usr/share/man/man1/c++.1.gz"

gcc-c++-32bit_files = ""
gcc-c++-32bit_files += "README"

gcc-locale_files = ""
gcc-locale_files += "README"

gcc-fortran_files = ""
gcc-fortran_files += "/usr/bin/gfortran"
gcc-fortran_files += "/usr/share/man/man1/gfortran.1.gz"

FILES_${PN} = "${gcc_files}"
FILES_${PN}-fortran-32bit = "${gcc-fortran-32bit_files}"
FILES_libstdc++-devel = "${libstdc++-devel_files}"
FILES_${PN}-ada = "${gcc-ada_files}"
FILES_${PN}-gij-32bit = "${gcc-gij-32bit_files}"
FILES_${PN}-32bit = "${gcc-32bit_files}"
FILES_${PN}-gij = "${gcc-gij_files}"
FILES_${PN}-objc = "${gcc-objc_files}"
FILES_${PN}-info = "${gcc-info_files}"
FILES_${PN}-obj-c++ = "${gcc-obj-c++_files}"
FILES_${PN}-objc-32bit = "${gcc-objc-32bit_files}"
FILES_${PN}-java = "${gcc-java_files}"
FILES_cpp = "${cpp_files}"
FILES_libgcj-devel = "${libgcj-devel_files}"
FILES_${PN}-c++ = "${gcc-c++_files}"
FILES_${PN}-c++-32bit = "${gcc-c++-32bit_files}"
FILES_${PN}-locale = "${gcc-locale_files}"
FILES_${PN}-fortran = "${gcc-fortran_files}"

PKG_gcc= "gcc"
PKG_gcc-fortran-32bit= "gcc-fortran-32bit"
PKG_libstdc++-devel= "libstdc++-devel"
PKG_gcc-ada= "gcc-ada"
PKG_gcc-gij-32bit= "gcc-gij-32bit"
PKG_gcc-32bit= "gcc-32bit"
PKG_gcc-gij= "gcc-gij"
PKG_gcc-objc= "gcc-objc"
PKG_gcc-info= "gcc-info"
PKG_gcc-obj-c++= "gcc-obj-c++"
PKG_gcc-objc-32bit= "gcc-objc-32bit"
PKG_gcc-java= "gcc-java"
PKG_cpp= "cpp"
PKG_libgcj-devel= "libgcj-devel"
PKG_gcc-c++= "gcc-c++"
PKG_gcc-c++-32bit= "gcc-c++-32bit"
PKG_gcc-locale= "gcc-locale"
PKG_gcc-fortran= "gcc-fortran"

require gcc-extraconf.inc
