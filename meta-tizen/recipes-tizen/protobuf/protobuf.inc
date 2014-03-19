DESCRIPTION = "Protocol Buffers - Google's data interchange format"
HOMEPAGE = "http://code.google.com/p/protobuf/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libprotobuf8 
PROVIDES += "libprotobuf8"
RPROVIDES_libprotobuf8 += "libprotobuf8"

#PROVIDES by libprotoc8 
PROVIDES += "libprotoc8"
RPROVIDES_libprotoc8 += "libprotoc8"

#PROVIDES by protobuf-devel 
PROVIDES += "protobuf-devel"
RPROVIDES_protobuf-devel += "protobuf-devel"
RPROVIDES_protobuf-devel += "protobuf-dev"
# the PROVIDES rules is ignore "libprotobuf-devel = 2.5.0"
PROVIDES += "libprotobuf-devel"
RPROVIDES_protobuf-devel += "libprotobuf-devel"
RPROVIDES_protobuf-devel += "libprotobuf-dev"

#PROVIDES by protobuf 
PROVIDES += "protobuf"
RPROVIDES_protobuf += "protobuf"

#PROVIDES by libprotobuf-lite8 
PROVIDES += "libprotobuf-lite8"
RPROVIDES_libprotobuf-lite8 += "libprotobuf-lite8"

RDEPENDS = ""
#RDEPENDS of protobuf-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libprotobuf8"
RDEPENDS_${PN}-devel += "zlib-dev"
RDEPENDS_${PN}-devel += "gcc-c++"
RDEPENDS_${PN}-devel += "libprotobuf-lite8"


DEPENDS = ""
#DEPENDS of protobuf-devel 

do_patch() {
 
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
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
 
 #
 
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
 oe_runmake -j16
 #
 
 
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
 /bin/rm ${D}/usr/lib/*.la
 /bin/install -Dm 0644 editors/proto.vim ${D}/usr/share/vim/site/syntax/proto.vim
 
}

PACKAGES = ""
PACKAGES += "libprotobuf8"
PACKAGES += "protobuf-devel"
PACKAGES += "libprotoc8"
PACKAGES += "libprotobuf-lite8"

libprotobuf8_files = ""
libprotobuf8_files += "/usr/lib/libprotobuf.so.8*"

protobuf-devel_files = ""
protobuf-devel_files += "COPYING.txt"
protobuf-devel_files += "CHANGES.txt CONTRIBUTORS.txt README.txt"
protobuf-devel_files += "examples"
protobuf-devel_files += "/usr/bin/protoc"
protobuf-devel_files += "/usr/include/google"
protobuf-devel_files += "/usr/lib/*.so"
protobuf-devel_files += "/usr/lib/pkgconfig/*"
protobuf-devel_files += "/usr/share/vim"

libprotoc8_files = ""
libprotoc8_files += "/usr/lib/libprotoc.so.8*"

libprotobuf-lite8_files = ""
libprotobuf-lite8_files += "/usr/lib/libprotobuf-lite.so.8*"

FILES_lib${PN}8 = "${libprotobuf8_files}"
FILES_${PN}-devel = "${protobuf-devel_files}"
FILES_libprotoc8 = "${libprotoc8_files}"
FILES_lib${PN}-lite8 = "${libprotobuf-lite8_files}"

PKG_libprotobuf8= "libprotobuf8"
PKG_protobuf-devel= "protobuf-devel"
PKG_libprotoc8= "libprotoc8"
PKG_libprotobuf-lite8= "libprotobuf-lite8"

require protobuf-extraconf.inc
