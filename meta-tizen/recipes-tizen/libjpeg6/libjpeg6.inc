DESCRIPTION = "A library for manipulating JPEG image format files"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "IJG"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libjpeg6-devel 
PROVIDES += "libjpeg6-devel"
RPROVIDES_libjpeg6-devel += "libjpeg6-devel"
RPROVIDES_libjpeg6-devel += "libjpeg6-dev"

#PROVIDES by libjpeg6 
PROVIDES += "libjpeg6"
RPROVIDES_libjpeg6 += "libjpeg6"

#PROVIDES by libjpeg6-docs  
PROVIDES += "libjpeg6-docs "
RPROVIDES_libjpeg6-docs  += "libjpeg6-docs "

RDEPENDS = ""
#RDEPENDS of libjpeg6-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libjpeg6"


DEPENDS = ""
#DEPENDS of libjpeg6 
DEPENDS += "autoconf-native"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n jpeg-6b
 cp ${S}/packaging/libjpeg6.manifest .
 
 # libjpeg 6b includes a horribly obsolete version of libtool.
 # Blow it away and replace with build system's version.
 rm -f ltmain.sh ltconfig aclocal.m4
 
 
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
         --infodir=/usr/share/info --enable-shared --disable-static
 
 make libdir=/usr/lib -j16
 
 exit 0
 LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH make test libdir=/usr/lib
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/usr/bin
 mkdir -p ${D}/usr/include
 mkdir -p ${D}/usr/lib
 mkdir -p ${D}/usr/share/man/man1
 
 # The make_install macro doesn't work here...
 
   oe_runmake \
         DESTDIR=${D} \
         BINDIR=/usr/bin \
         prefix=/usr \
         exec_prefix=/usr \
         bindir=/usr/bin \
         sbindir=/usr/sbin \
         sysconfdir=/etc \
         datadir=/usr/share \
         includedir=/usr/include \
         libdir=/usr/lib \
         libexecdir=/usr/libexec \
         localstatedir=}/var \
         sharedstatedir=/usr/com \
         mandir=/usr/share/man \
         infodir=/usr/share/info \
   install
 
 # Work around the broken makefiles...
 mv ${D}/usr/share/man/*.1 ${D}/usr/share/man/man1
 rm -f ${D}/usr/lib/libjpeg.la
 
 
 
}

PACKAGES = ""
PACKAGES += "libjpeg6-devel"
PACKAGES += "libjpeg6"
PACKAGES += "libjpeg6-docs"

libjpeg6-devel_files = ""
libjpeg6-devel_files += "libjpeg6.manifest"
libjpeg6-devel_files += "/usr/bin/*"
libjpeg6-devel_files += "/usr/include/*.h"
libjpeg6-devel_files += "/usr/lib/*.so"

libjpeg6_files = ""
libjpeg6_files += "libjpeg6.manifest"
libjpeg6_files += "/usr/lib/libjpeg.so.*"

libjpeg6-docs_files = ""
libjpeg6-docs_files += "/usr/share/info"
libjpeg6-docs_files += "/usr/share/man"

FILES_${PN}-devel = "${libjpeg6-devel_files}"
FILES_${PN} = "${libjpeg6_files}"
FILES_${PN}-docs = "${libjpeg6-docs_files}"

PKG_libjpeg6-devel= "libjpeg6-devel"
PKG_libjpeg6= "libjpeg6"
PKG_libjpeg6-docs= "libjpeg6-docs"

require libjpeg6-extraconf.inc
