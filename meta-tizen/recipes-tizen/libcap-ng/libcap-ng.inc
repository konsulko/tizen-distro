DESCRIPTION = "An alternate POSIX capabilities library"
HOMEPAGE = "http://people.redhat.com/sgrubb/libcap-ng"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libcap-ng-devel 
PROVIDES += "libcap-ng-devel"
RPROVIDES_libcap-ng-devel += "libcap-ng-devel"
RPROVIDES_libcap-ng-devel += "libcap-ng-dev"

#PROVIDES by libcap-ng 
PROVIDES += "libcap-ng"
RPROVIDES_libcap-ng += "libcap-ng"

#PROVIDES by libcap-ng-utils 
PROVIDES += "libcap-ng-utils"
RPROVIDES_libcap-ng-utils += "libcap-ng-utils"

RDEPENDS = ""
#RDEPENDS of libcap-ng-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libcap-ng"
RDEPENDS_${PN}-devel += "pkgconfig"


DEPENDS = ""
#DEPENDS of libcap-ng 
inherit pythonnative
DEPENDS += "attr"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n libcap-ng-0.6.6
 cp ${S}/packaging/libcap-ng.manifest .
 
 
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
         --infodir=/usr/share/info --disable-static --with-pic --with-python=no
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
PACKAGES += "libcap-ng-devel"
PACKAGES += "libcap-ng"
PACKAGES += "libcap-ng-utils"

libcap-ng-devel_files = ""
libcap-ng-devel_files += "libcap-ng.manifest"
libcap-ng-devel_files += "/usr/lib/pkgconfig/libcap-ng.pc"

libcap-ng_files = ""
libcap-ng_files += "libcap-ng.manifest"
libcap-ng_files += "GPL-2.0+ COPYING.LIB"

libcap-ng-utils_files = ""
libcap-ng-utils_files += "libcap-ng.manifest"
libcap-ng-utils_files += "GPL-2.0+ COPYING"

FILES_${PN}-devel = "${libcap-ng-devel_files}"
FILES_${PN} = "${libcap-ng_files}"
FILES_${PN}-utils = "${libcap-ng-utils_files}"

PKG_libcap-ng-devel= "libcap-ng-devel"
PKG_libcap-ng= "libcap-ng"
PKG_libcap-ng-utils= "libcap-ng-utils"

require libcap-ng-extraconf.inc
