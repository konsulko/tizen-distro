DESCRIPTION = "Linux network configuration utilities"
HOMEPAGE = "http://www.linuxfoundation.org/collaborate/workgroups/networking/iproute2"
SECTION = "Productivity/Networking/Routing"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by iproute2 
PROVIDES += "iproute2"
RPROVIDES_iproute2 += "iproute2"
# the PROVIDES rules is ignore "iproute = 3.4.0"
PROVIDES += "iproute"
RPROVIDES_iproute2 += "iproute"

#PROVIDES by iproute2-docs  
PROVIDES += "iproute2-docs "
RPROVIDES_iproute2-docs  += "iproute2-docs "

#PROVIDES by libnetlink-devel 
PROVIDES += "libnetlink-devel"
RPROVIDES_libnetlink-devel += "libnetlink-devel"
RPROVIDES_libnetlink-devel += "libnetlink-dev"
# the PROVIDES rules is ignore "libnetlink = 3.4.0"
PROVIDES += "libnetlink"
RPROVIDES_libnetlink-devel += "libnetlink"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of iproute2 
DEPENDS += "flex"
DEPENDS += "pkgconfig(xtables)"
DEPENDS += "libnl-devel"
DEPENDS += "pkgconfig-native"
DEPENDS += "xz"
DEPENDS += "bison-native"
DEPENDS += "pkgconfig(libpng12)"
DEPENDS += "pkgconfig(libtiff-4)"
DEPENDS += "db4"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/iproute2.manifest .
 find . -name *.orig -delete
 
 
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
 
 # build with -fPIC. For details see
 # https://bugzilla.novell.com/show_bug.cgi?id=388021
 ./configure
 xtlibdir="$(pkg-config xtables --variable=xtlibdir)";
 make -j16 LIBDIR=/usr/lib CCOPTS="-D_GNU_SOURCE -O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wstrict-prototypes -fPIC -DXT_LIB_DIR=\\\"$xtlibdir\\\""
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d ${D}/{etc/,sbin/,usr/{sbin,share/man/man{3,8}}}
 install -d ${D}/{/usr/include,/usr/lib,/usr/share}
 make install DESTDIR=${D} LIBDIR=/usr/lib \
 	MODDESTDIR="${D}//usr/lib/tc"
 # We have m_xt
 rm -f "${D}//usr/lib/tc/m_ipt.so"
 install lib/libnetlink.a ${D}//usr/lib
 chmod -x ${D}//usr/lib/libnetlink.a
 install include/libnetlink.h ${D}/usr/include
 chmod -x ${D}/usr/include/libnetlink.h
 rm ${D}/usr/sbin/ifcfg
 
   rm -rf ${D}/usr/share/info 
   rm -rf ${D}/usr/share/doc/packages 
   rm -rf ${D}/usr/share/doc/iproute2 
   rm -rf ${D}/usr/share/doc/iproute2-3.4.0 
   rm -rf ${D}/usr/share/gtk-doc 
   rm -rf ${D}/usr/share/doc 
   rm -rf ${D}/usr/share/man 
   find ${D} -regex ".*/man/man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/../man./.*.[0-9]" | xargs rm -f -- 
   find ${D} -regex ".*/man/man./.*.[0-9]pm" | xargs rm -f --
 
 
 
}

PACKAGES = ""
PACKAGES += "iproute2"
PACKAGES += "iproute2-docs"
PACKAGES += "libnetlink-devel"

iproute2_files = ""
iproute2_files += "iproute2.manifest"
iproute2_files += "/usr/sbin/*"
iproute2_files += "/etc/iproute2"
iproute2_files += "/etc/iproute2/*"
iproute2_files += "/usr/lib/tc"
iproute2_files += "/usr/share/tc"

iproute2-docs_files = ""
iproute2-docs_files += "/usr/share/info"
iproute2-docs_files += "/usr/share/man"

libnetlink-devel_files = ""
libnetlink-devel_files += "iproute2.manifest"
libnetlink-devel_files += "/usr/include/*"
libnetlink-devel_files += "/usr/lib/lib*"

FILES_${PN} = "${iproute2_files}"
FILES_${PN}-docs = "${iproute2-docs_files}"
FILES_libnetlink-devel = "${libnetlink-devel_files}"

PKG_iproute2= "iproute2"
PKG_iproute2-docs= "iproute2-docs"
PKG_libnetlink-devel= "libnetlink-devel"

require iproute2-extraconf.inc
