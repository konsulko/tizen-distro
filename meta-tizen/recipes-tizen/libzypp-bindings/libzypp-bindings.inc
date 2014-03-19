DESCRIPTION = "Bindings for libzypp"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Sources"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libzypp-bindings 
PROVIDES += "libzypp-bindings"
RPROVIDES_libzypp-bindings += "libzypp-bindings"

#PROVIDES by python-zypp 
PROVIDES += "python-zypp"
RPROVIDES_python-zypp += "python-zypp"

RDEPENDS = ""
#RDEPENDS of python-zypp (python-zypp)
RDEPENDS_python-zypp += "libzypp"


DEPENDS = ""
#DEPENDS of libzypp-bindings 
DEPENDS += "libzypp"
DEPENDS += "gcc-cross"
DEPENDS += "python-devel"
DEPENDS += "cmake"
DEPENDS += "swig"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libzypp-bindings.manifest .
 
 
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
 
 mkdir build
 cd build
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export FFLAGS ; 
   cmake \
         -DCMAKE_VERBOSE_MAKEFILE=ON \
         -DCMAKE_INSTALL_PREFIX:PATH=/usr \
         -DCMAKE_INSTALL_LIBDIR:PATH=/usr/lib \
         -DINCLUDE_INSTALL_DIR:PATH=/usr/include \
         -DLIB_INSTALL_DIR:PATH=/usr/lib \
         -DSYSCONF_INSTALL_DIR:PATH=/etc \
         -DSHARE_INSTALL_PREFIX:PATH=/usr/share \
         -DCMAKE_SKIP_RPATH:BOOL=ON \
         -DBUILD_SHARED_LIBS:BOOL=ON \
         -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake -DCMAKE_INSTALL_PREFIX=%{prefix} \
       -DPYTHON_SITEDIR=/usr/lib/python2.7/site-packages \
       -DLIB=lib \
       -DCMAKE_VERBOSE_MAKEFILE=TRUE \
       -DCMAKE_C_FLAGS_RELEASE:STRING="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" \
       -DCMAKE_CXX_FLAGS_RELEASE:STRING="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" \
       -DCMAKE_BUILD_TYPE=Release \
       -DCMAKE_SKIP_RPATH=1 \
       ..
 make -j1
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cd build
 make install DESTDIR=$RPM_BUILD_ROOT
 
 
}

PACKAGES = ""
PACKAGES += "python-zypp"

python-zypp_files = ""
python-zypp_files += "libzypp-bindings.manifest"
python-zypp_files += "/usr/lib/python2.7/site-packages/_zypp.so"
python-zypp_files += "/usr/lib/python2.7/site-packages/zypp.py*"

FILES_python-zypp = "${python-zypp_files}"

PKG_python-zypp= "python-zypp"

require libzypp-bindings-extraconf.inc
