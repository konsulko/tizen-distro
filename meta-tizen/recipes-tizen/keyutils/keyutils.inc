DESCRIPTION = "Linux Key Management Utilities"
HOMEPAGE = "http://people.redhat.com/~dhowells/keyutils/"
SECTION = "System/Kernel"
LICENSE = "GPL-2.0+  LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by keyutils 
PROVIDES += "keyutils"
RPROVIDES_keyutils += "keyutils"

#PROVIDES by libkeyutils 
PROVIDES += "libkeyutils"
RPROVIDES_libkeyutils += "libkeyutils"

#PROVIDES by keyutils-devel 
PROVIDES += "keyutils-devel"
RPROVIDES_keyutils-devel += "keyutils-devel"
RPROVIDES_keyutils-devel += "keyutils-dev"

RDEPENDS = ""
#RDEPENDS of keyutils-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libkeyutils"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/keyutils.manifest .
 
 
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
 
 make -j16 NO_ARLIB=1 CFLAGS="$RPM_OPT_FLAGS" CC="${HOST_SYS}-gcc"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install NO_ARLIB=1 DESTDIR=$RPM_BUILD_ROOT LIBDIR=/lib USRLIBDIR=/usr/lib
 
 
}

PACKAGES = ""
PACKAGES += "keyutils"
PACKAGES += "libkeyutils"
PACKAGES += "keyutils-devel"

keyutils_files = ""
keyutils_files += "keyutils.manifest"
keyutils_files += "GPL-2.0+ ; LGPL-2.1+ LICENCE.GPL"
keyutils_files += "/sbin/*"
keyutils_files += "/bin/*"
keyutils_files += "/usr/share/keyutils"
keyutils_files += "/usr/share/man/*/*"
keyutils_files += "/etc/*"

libkeyutils_files = ""
libkeyutils_files += "keyutils.manifest"
libkeyutils_files += "GPL-2.0+ ; LGPL-2.1+ LICENCE.LGPL"
libkeyutils_files += "/lib/libkeyutils.so.*"

keyutils-devel_files = ""
keyutils-devel_files += "keyutils.manifest"
keyutils-devel_files += "/usr/lib/libkeyutils.so"
keyutils-devel_files += "/usr/include/*"

FILES_${PN} = "${keyutils_files}"
FILES_lib${PN} = "${libkeyutils_files}"
FILES_${PN}-devel = "${keyutils-devel_files}"

PKG_keyutils= "keyutils"
PKG_libkeyutils= "libkeyutils"
PKG_keyutils-devel= "keyutils-devel"

require keyutils-extraconf.inc
