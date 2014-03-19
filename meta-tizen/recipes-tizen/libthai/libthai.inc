DESCRIPTION = "Thai Language Support Routines"
HOMEPAGE = "http://linux.thai.net/plone/TLWG/libthai/"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libthai 
PROVIDES += "libthai"
RPROVIDES_libthai += "libthai"

#PROVIDES by libthai-data 
PROVIDES += "libthai-data"
RPROVIDES_libthai-data += "libthai-data"

#PROVIDES by libthai-devel 
PROVIDES += "libthai-devel"
RPROVIDES_libthai-devel += "libthai-devel"
RPROVIDES_libthai-devel += "libthai-dev"

RDEPENDS = ""
#RDEPENDS of libthai (${PN})
RDEPENDS_${PN} += "libthai-data"

#RDEPENDS of libthai-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libthai"


DEPENDS = ""
#DEPENDS of libthai 
DEPENDS += "libdatrie"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libthai.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic
 make -j16
 
 
 
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
 
 
 
}

PACKAGES = ""
PACKAGES += "libthai"
PACKAGES += "libthai-data"
PACKAGES += "libthai-devel"

libthai_files = ""
libthai_files += "libthai.manifest"
libthai_files += "/usr/lib/libthai.so.*"

libthai-data_files = ""
libthai-data_files += "libthai.manifest"
libthai-data_files += "/usr/share/libthai/"

libthai-devel_files = ""
libthai-devel_files += "libthai.manifest"
libthai-devel_files += "/usr/include/thai/"
libthai-devel_files += "/usr/lib/libthai.so"
libthai-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${libthai_files}"
FILES_${PN}-data = "${libthai-data_files}"
FILES_${PN}-devel = "${libthai-devel_files}"

PKG_libthai= "libthai"
PKG_libthai-data= "libthai-data"
PKG_libthai-devel= "libthai-devel"

require libthai-extraconf.inc
