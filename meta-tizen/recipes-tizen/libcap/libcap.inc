DESCRIPTION = "Library for Capabilities (linux-privs) Support"
HOMEPAGE = "https://sites.google.com/site/fullycapable/"
SECTION = "Base/Libraries"
LICENSE = "BSD-3-Clause and GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcap 
PROVIDES += "libcap"
RPROVIDES_libcap += "libcap"

#PROVIDES by libcap-tools 
PROVIDES += "libcap-tools"
RPROVIDES_libcap-tools += "libcap-tools"
# the PROVIDES rules is ignore "libcap-progs  "
PROVIDES += "libcap-progs"
RPROVIDES_libcap-tools += "libcap-progs"

#PROVIDES by libcap-devel 
PROVIDES += "libcap-devel"
RPROVIDES_libcap-devel += "libcap-devel"
RPROVIDES_libcap-devel += "libcap-dev"

RDEPENDS = ""
#RDEPENDS of libcap-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libcap"


DEPENDS = ""
#DEPENDS of libcap 
DEPENDS += "fdupes-native"
DEPENDS += "attr"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libcap.manifest .
 
 
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
 
 lib=lib make -j16 DEBUG="-g -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install DESTDIR=${D} LIBDIR=${D}/lib MANDIR=${D}/usr/share/man PKGCONFIGDIR=${D}/usr/lib/pkgconfig RAISE_SETFCAP=no
 # remove unneeded files
 rm -f ${D}/lib/*.*a
 # move *.so file to libdir and relink
 rm -f ${D}/lib/*.so
 mkdir -p ${D}/usr/lib
 ln -s /lib/libcap.so.2 ${D}/usr/lib/libcap.so
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
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
PACKAGES += "libcap"
PACKAGES += "libcap-tools"
PACKAGES += "libcap-devel"

libcap_files = ""
libcap_files += "libcap.manifest"

libcap-tools_files = ""
libcap-tools_files += "libcap.manifest"
libcap-tools_files += "/usr/share/man/man1/*"
libcap-tools_files += "/usr/share/man/man8/*"
libcap-tools_files += "/sbin/*"

libcap-devel_files = ""
libcap-devel_files += "libcap.manifest"
libcap-devel_files += "/usr/include/sys/capability.h"
libcap-devel_files += "/usr/lib/*.so"
libcap-devel_files += "/usr/lib/pkgconfig/*.pc"
libcap-devel_files += "/usr/share/man/man3/*"

FILES_${PN} = "${libcap_files}"
FILES_${PN}-tools = "${libcap-tools_files}"
FILES_${PN}-devel = "${libcap-devel_files}"

PKG_libcap= "libcap"
PKG_libcap-tools= "libcap-tools"
PKG_libcap-devel= "libcap-devel"

require libcap-extraconf.inc
