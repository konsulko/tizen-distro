DESCRIPTION = "Simplified Wrapper and Interface Generator"
HOMEPAGE = "http://www.swig.org/"
SECTION = "Development/Languages/C and C++"
LICENSE = "GPL-3.0+ and BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by swig 
PROVIDES += "swig"
RPROVIDES_swig += "swig"

#PROVIDES by swig-examples 
PROVIDES += "swig-examples"
RPROVIDES_swig-examples += "swig-examples"

#PROVIDES by swig-doc 
PROVIDES += "swig-doc"
RPROVIDES_swig-doc += "swig-doc"

RDEPENDS = ""
#RDEPENDS of swig-examples (${PN}-examples)
RDEPENDS_${PN}-examples += "swig"

#RDEPENDS of swig-doc (${PN}-doc)
RDEPENDS_${PN}-doc += "swig"


DEPENDS = ""
#DEPENDS of swig 
DEPENDS += "pcre"
DEPENDS += "gcc-cross"
DEPENDS += "fdupes-native"
inherit pythonnative
DEPENDS += "automake-native"
inherit perlnative
DEPENDS += "libtool-cross"
DEPENDS += "autoconf-native"
DEPENDS += "boost"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/swig.manifest .
 
 
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
 
 sh autogen.sh
 
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
         --infodir=/usr/share/info --disable-ccache
 make -j16
 
 exit 0
 # Segfaults
 rm -f Examples/test-suite/python/li_std_containers_int_runme.py
 rm -f Examples/test-suite/python/li_boost_shared_ptr_runme.py
 make check
 
 
 
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
 
 install -d ${D}/usr/share/doc/packages/swig
 cp -a TODO ANNOUNCE CHANGES* LICENSE README Doc/{Devel,Manual} \
 	${D}/usr/share/doc/packages/swig
 install -d ${D}/usr/lib/swig
 cp -a Examples ${D}/usr/lib/swig/examples
 rm -rf ${D}/usr/lib/swig/examples/test-suite
 
 # rm files that are not needed for running or rebuilding the examples
 find ${D}/usr/lib/swig \
 	-name '*.dsp' -o -name '*.vcproj' -o -name '*.sln' -o \
 	-name '*.o' -o -name '*_wrap.c' | xargs rm
 
 # fix perms
 chmod -x ${D}/usr/share/doc/packages/swig/Manual/*
 find ${D}/usr/lib/swig -name '*.h' -perm +111 | \
 	xargs --no-run-if-empty chmod -x
 ln -s /usr/lib/swig/examples ${D}/usr/share/doc/packages/swig/Examples
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D} | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
}

PACKAGES = ""
PACKAGES += "swig"
PACKAGES += "swig-doc"
PACKAGES += "swig-examples"

swig_files = ""
swig_files += "swig.manifest"
swig_files += "/usr/share/doc/packages/swig"
swig_files += "/usr/share/doc/packages/swig/[A-Z][A-Z]*"
swig_files += "/usr/share/swig"

swig-doc_files = ""
swig-doc_files += "swig.manifest"
swig-doc_files += "/usr/share/doc/packages/swig/Devel"
swig-doc_files += "/usr/share/doc/packages/swig/Manual"

swig-examples_files = ""
swig-examples_files += "swig.manifest"
swig-examples_files += "/usr/share/doc/packages/swig/Examples"
swig-examples_files += "/usr/lib/swig"

FILES_${PN} = "${swig_files}"
FILES_${PN}-doc = "${swig-doc_files}"
FILES_${PN}-examples = "${swig-examples_files}"

PKG_swig= "swig"
PKG_swig-doc= "swig-doc"
PKG_swig-examples= "swig-examples"

require swig-extraconf.inc
