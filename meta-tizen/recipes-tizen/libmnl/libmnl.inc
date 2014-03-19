DESCRIPTION = "Minimalistic Netlink communication library"
HOMEPAGE = "http://netfilter.org/projects/libmnl/"
SECTION = "Productivity/Networking/Security"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libmnl 
PROVIDES += "libmnl"
RPROVIDES_libmnl += "libmnl"

#PROVIDES by libmnl-devel 
PROVIDES += "libmnl-devel"
RPROVIDES_libmnl-devel += "libmnl-devel"
RPROVIDES_libmnl-devel += "libmnl-dev"

RDEPENDS = ""
#RDEPENDS of libmnl-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libmnl"


DEPENDS = ""
#DEPENDS of libmnl 
DEPENDS += "libtool-cross"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmnl.manifest .
 
 
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
 
 if [ ! -e configure ]; then
 	autoreconf -fi;
 fi;
 
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
         --infodir=/usr/share/info --includedir=/usr/include/libmnl-1.0.3
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
PACKAGES += "libmnl"
PACKAGES += "libmnl-devel"

libmnl_files = ""
libmnl_files += "libmnl.manifest"
libmnl_files += "/usr/lib/libmnl.so.0*"

libmnl-devel_files = ""
libmnl-devel_files += "libmnl.manifest"
libmnl-devel_files += "/usr/include/libmnl*"
libmnl-devel_files += "/usr/lib/libmnl.so"
libmnl-devel_files += "/usr/lib/pkgconfig/libmnl.pc"

FILES_${PN} = "${libmnl_files}"
FILES_${PN}-devel = "${libmnl-devel_files}"

PKG_libmnl= "libmnl"
PKG_libmnl-devel= "libmnl-devel"

require libmnl-extraconf.inc
