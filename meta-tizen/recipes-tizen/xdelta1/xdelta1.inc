DESCRIPTION = "Binary delta generator and RCS replacement library"
HOMEPAGE = "http://xdelta.org/"
SECTION = "Platform Development/Tools"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by xdelta 
PROVIDES += "xdelta"
RPROVIDES_xdelta += "xdelta"

#PROVIDES by xdelta-devel 
PROVIDES += "xdelta-devel"
RPROVIDES_xdelta-devel += "xdelta-devel"
RPROVIDES_xdelta-devel += "xdelta-dev"

RDEPENDS = ""
#RDEPENDS of xdelta-devel (xdelta-devel)
RDEPENDS_xdelta-devel += "pkgconfig(glib-2.0)"
RDEPENDS_xdelta-devel += "xdelta"


DEPENDS = ""
#DEPENDS of xdelta 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "libtool-cross"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/xdelta.manifest .
 chmod -x AUTHORS COPYING INSTALL Makefile.am NEWS README *.c *.h *.in xd* */*
 
 
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
 
 export CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64"
 
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
         --infodir=/usr/share/info --disable-static
 make
 
 
 
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
PACKAGES += "xdelta"
PACKAGES += "xdelta-devel"

xdelta_files = ""
xdelta_files += "xdelta.manifest"
xdelta_files += "/usr/bin/xdelta"
xdelta_files += "/usr/share/man/man1/xdelta.*"
xdelta_files += "/usr/lib/lib*.so.*"

xdelta-devel_files = ""
xdelta-devel_files += "xdelta.manifest"
xdelta-devel_files += "/usr/include/*"
xdelta-devel_files += "/usr/bin/xdelta-config"
xdelta-devel_files += "/usr/lib/*.so"
xdelta-devel_files += "/usr/share/aclocal/xdelta.m4"

FILES_${PN} = "${xdelta_files}"
FILES_${PN}-devel = "${xdelta-devel_files}"

PKG_xdelta= "xdelta"
PKG_xdelta-devel= "xdelta-devel"

require xdelta1-extraconf.inc
