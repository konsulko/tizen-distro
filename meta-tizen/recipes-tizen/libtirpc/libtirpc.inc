DESCRIPTION = "Transport Independent RPC Library"
HOMEPAGE = "http://sourceforge.net/projects/libtirpc/"
SECTION = "System/Libraries"
LICENSE = "BSD-4-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libtirpc 
PROVIDES += "libtirpc"
RPROVIDES_libtirpc += "libtirpc"

#PROVIDES by libtirpc-docs  
PROVIDES += "libtirpc-docs "
RPROVIDES_libtirpc-docs  += "libtirpc-docs "

#PROVIDES by libtirpc-devel 
PROVIDES += "libtirpc-devel"
RPROVIDES_libtirpc-devel += "libtirpc-devel"
RPROVIDES_libtirpc-devel += "libtirpc-dev"

RDEPENDS = ""
#RDEPENDS of libtirpc-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "glibc-dev"
RDEPENDS_${PN}-devel += "libtirpc"


DEPENDS = ""
#DEPENDS of libtirpc 
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig(pkg-config)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libtirpc.manifest .
 
 
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
 
 autoreconf -fiv
 
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
         --infodir=/usr/share/info --disable-static --with-pic --libdir=/lib
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
 mkdir -p ${D}/usr/lib
 ln -s -v /lib/$(readlink ${D}/lib/libtirpc.so) ${D}/usr/lib/libtirpc.so
 rm -rf ${D}/lib/*.so
 mv -v ${D}/lib/pkgconfig ${D}//usr/lib
 
 
}

PACKAGES = ""
PACKAGES += "libtirpc"
PACKAGES += "libtirpc-docs"
PACKAGES += "libtirpc-devel"

libtirpc_files = ""
libtirpc_files += "libtirpc.manifest"
libtirpc_files += "/etc/netconfig"
libtirpc_files += "/lib/libtirpc.so.1*"

libtirpc-docs_files = ""
libtirpc-docs_files += "/usr/share/info"
libtirpc-docs_files += "/usr/share/man"

libtirpc-devel_files = ""
libtirpc-devel_files += "libtirpc.manifest"
libtirpc-devel_files += "/usr/lib/libtirpc.so"
libtirpc-devel_files += "/usr/include/tirpc/"
libtirpc-devel_files += "/usr/include/tirpc/*"
libtirpc-devel_files += "/usr/lib/pkgconfig/*"

FILES_${PN} = "${libtirpc_files}"
FILES_${PN}-docs = "${libtirpc-docs_files}"
FILES_${PN}-devel = "${libtirpc-devel_files}"

PKG_libtirpc= "libtirpc"
PKG_libtirpc-docs= "libtirpc-docs"
PKG_libtirpc-devel= "libtirpc-devel"

require libtirpc-extraconf.inc
