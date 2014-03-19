DESCRIPTION = "Cross-platform make system"
HOMEPAGE = "http://www.cmake.org"
SECTION = "Platfrom Development/Tools"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by cmake 
PROVIDES += "cmake"
RPROVIDES_cmake += "cmake"

#PROVIDES by cmake-docs  
PROVIDES += "cmake-docs "
RPROVIDES_cmake-docs  += "cmake-docs "

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of cmake 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(libcurl)"
DEPENDS += "ncurses-devel"
DEPENDS += "expat-devel"
DEPENDS += "fdupes-native"
DEPENDS += "gcc-c++"
DEPENDS += "procps"
DEPENDS += "pkgconfig(libarchive)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n cmake-2.8.11.2
 cp ${S}/packaging/cmake.manifest .
 
 
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
 
 export CXXFLAGS="$RPM_OPT_FLAGS"
 export CFLAGS="$CXXFLAGS"
 ./configure \
     --prefix=/usr \
     --datadir=/share/cmake \
     --docdir=/share/doc/packages/cmake \
     --mandir=/share/man \
     --system-libs \
     --parallel=016 \
     --no-qt-gui
 make VERBOSE=1 -j16
 
 
 
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
 mkdir -p ${D}/usr/lib/cmake
 find ${D}/usr/share/cmake -type f -print0 | xargs -0 chmod 644
 cp ${S}/packaging/TizenCommon.cmake ${D}//usr/share/cmake/Modules
 
 # Install cmake rpm macros
 install -D -p -m 0644 ${S}/packaging/macros.cmake \
   ${D}/etc/rpm/macros.cmake
 
 fdupes ${D}/usr/share/cmake
 
 
 
}

PACKAGES = ""
PACKAGES += "cmake"
PACKAGES += "cmake-docs"

cmake_files = ""
cmake_files += "cmake.manifest"
cmake_files += "/etc/rpm/macros.cmake"
cmake_files += "/usr/share/doc/packages/cmake"
cmake_files += "/usr/share/aclocal/cmake.m4"
cmake_files += "/usr/bin/ccmake"
cmake_files += "/usr/bin/cmake"
cmake_files += "/usr/bin/cpack"
cmake_files += "/usr/bin/ctest"
cmake_files += "/usr/share/cmake"

cmake-docs_files = ""
cmake-docs_files += "/usr/share/info"
cmake-docs_files += "/usr/share/man"

FILES_${PN} = "${cmake_files}"
FILES_${PN}-docs = "${cmake-docs_files}"

PKG_cmake= "cmake"
PKG_cmake-docs= "cmake-docs"

require cmake-extraconf.inc
