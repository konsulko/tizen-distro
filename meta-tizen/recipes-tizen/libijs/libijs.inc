DESCRIPTION = "IJS raster image transport protocol library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libijs-devel 
PROVIDES += "libijs-devel"
RPROVIDES_libijs-devel += "libijs-devel"
RPROVIDES_libijs-devel += "libijs-dev"

#PROVIDES by libijs 
PROVIDES += "libijs"
RPROVIDES_libijs += "libijs"

RDEPENDS = ""
#RDEPENDS of libijs-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libijs"


DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libijs.manifest .
 
 
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
 
 export CFLAGS="$RPM_OPT_FLAGS"    
 export CXXFLAGS="$RPM_OPT_FLAGS"    
 
 
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
         --infodir=/usr/share/info --enable-shared
 
 make   CFLAGS="$CFLAGS"
 
 
 
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
PACKAGES += "libijs-devel"
PACKAGES += "libijs"

libijs-devel_files = ""
libijs-devel_files += "libijs.manifest"
libijs-devel_files += "/usr/include/ijs/*.h"
libijs-devel_files += "/usr/lib/*.so"
libijs-devel_files += "/usr/lib/pkgconfig/ijs.pc"
libijs-devel_files += "/usr/bin/*"
libijs-devel_files += "/usr/share/man/man1/ijs-config.1.gz"

libijs_files = ""
libijs_files += "libijs.manifest"
libijs_files += "/usr/lib/libijs-0.35.so"

FILES_${PN}-devel = "${libijs-devel_files}"
FILES_${PN} = "${libijs_files}"

PKG_libijs-devel= "libijs-devel"
PKG_libijs= "libijs"

require libijs-extraconf.inc
