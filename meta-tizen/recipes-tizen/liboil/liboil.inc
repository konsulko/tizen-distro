DESCRIPTION = "Library of Optimized Inner Loops"
HOMEPAGE = "http://liboil.freedesktop.org/wiki/"
SECTION = "System/Libraries"
LICENSE = "BSD-2-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by liboil 
PROVIDES += "liboil"
RPROVIDES_liboil += "liboil"

#PROVIDES by liboil-devel 
PROVIDES += "liboil-devel"
RPROVIDES_liboil-devel += "liboil-devel"
RPROVIDES_liboil-devel += "liboil-dev"

RDEPENDS = ""
#RDEPENDS of liboil-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "liboil"
RDEPENDS_${PN}-devel += "glibc-dev"


DEPENDS = ""
#DEPENDS of liboil 
DEPENDS += "glib"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/liboil.manifest .
 
 
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
 oe_runmake -j16
 # Do NOT! disable running the testsuite or make failures
 # non-fatal for the build!
 
 exit 0
 oe_runmake check
 
 
 
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
 
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/liboil 
   rm -rf ${D}/usr/share/doc/liboil-0.3.17 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
}

PACKAGES = ""
PACKAGES += "liboil"
PACKAGES += "liboil-devel"

liboil_files = ""
liboil_files += "liboil.manifest"
liboil_files += "/usr/lib/*.so.*"

liboil-devel_files = ""
liboil-devel_files += "liboil.manifest"
liboil-devel_files += "/usr/bin/oil-bugreport"
liboil-devel_files += "/usr/include/liboil-*"
liboil-devel_files += "/usr/lib/*.so"
liboil-devel_files += "/usr/lib/pkgconfig/*.pc"

FILES_${PN} = "${liboil_files}"
FILES_${PN}-devel = "${liboil-devel_files}"

PKG_liboil= "liboil"
PKG_liboil-devel= "liboil-devel"

require liboil-extraconf.inc
