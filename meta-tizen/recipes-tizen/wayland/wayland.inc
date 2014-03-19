DESCRIPTION = "Wayland Compositor Infrastructure"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Graphics & UI Framework/Wayland Window System"
LICENSE = "MIT"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by wayland 
PROVIDES += "wayland"
RPROVIDES_wayland += "wayland"

#PROVIDES by wayland-devel 
PROVIDES += "wayland-devel"
RPROVIDES_wayland-devel += "wayland-devel"
RPROVIDES_wayland-devel += "wayland-dev"

#PROVIDES by libwayland-cursor 
PROVIDES += "libwayland-cursor"
RPROVIDES_libwayland-cursor += "libwayland-cursor"

#PROVIDES by libwayland-client 
PROVIDES += "libwayland-client"
RPROVIDES_libwayland-client += "libwayland-client"

#PROVIDES by libwayland-server 
PROVIDES += "libwayland-server"
RPROVIDES_libwayland-server += "libwayland-server"

RDEPENDS = ""
#RDEPENDS of wayland-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libwayland-server"
RDEPENDS_${PN}-devel += "libwayland-cursor"
RDEPENDS_${PN}-devel += "libwayland-client"


DEPENDS = ""
#DEPENDS of wayland 
DEPENDS += "doxygen"
DEPENDS += "pkgconfig(libffi)"
DEPENDS += "expat"
DEPENDS += "automake-native"
DEPENDS += "xz"
DEPENDS += "libtool-cross"
DEPENDS += "autoconf-native"
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/wayland.manifest .
 
 
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
   ./autogen.sh --build=${TARGET_SYS} --host=${HOST_SYS} \
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
         --infodir=/usr/share/info
 
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
 
  _target=""; 
  _symlinks=0; 
  _symlinks=1; 
  fdupes -q -n -r ${D}//usr/share/man | 
   while read _file; do 
     if test -z "$_target" ; then 
       _target="$_file"; 
     else 
       if test -z "$_file" ; then 
 	_target=""; 
 	continue ; 
       fi ; 
       if test "$_symlinks" = 1; then 
         ln -sf "${_target#${D}}" "$_file"; 
       else 
         ln -f "$_target" "$_file"; 
       fi ;
     fi ; 
  done 
 
 
}

PACKAGES = ""
PACKAGES += "libwayland-server"
PACKAGES += "wayland-devel"
PACKAGES += "libwayland-client"
PACKAGES += "libwayland-cursor"

libwayland-server_files = ""
libwayland-server_files += "wayland.manifest"
libwayland-server_files += "/usr/lib/libwayland-server.so.0*"

wayland-devel_files = ""
wayland-devel_files += "wayland.manifest"
wayland-devel_files += "/usr/bin/wayland-scanner"
wayland-devel_files += "/usr/include/wayland-*.h"
wayland-devel_files += "/usr/lib/libwayland-*.so"
wayland-devel_files += "/usr/lib/pkgconfig/wayland-*.pc"
wayland-devel_files += "/usr/share/pkgconfig/wayland-*.pc"
wayland-devel_files += "/usr/share/wayland/wayland*"
wayland-devel_files += "/usr/share/aclocal"
wayland-devel_files += "/usr/share/man/man3/*"
wayland-devel_files += "README TODO"

libwayland-client_files = ""
libwayland-client_files += "wayland.manifest"
libwayland-client_files += "/usr/lib/libwayland-client.so.0*"

libwayland-cursor_files = ""
libwayland-cursor_files += "wayland.manifest"
libwayland-cursor_files += "/usr/lib/libwayland-cursor.so.0*"

FILES_lib${PN}-server = "${libwayland-server_files}"
FILES_${PN}-devel = "${wayland-devel_files}"
FILES_lib${PN}-client = "${libwayland-client_files}"
FILES_lib${PN}-cursor = "${libwayland-cursor_files}"

PKG_libwayland-server= "libwayland-server"
PKG_wayland-devel= "wayland-devel"
PKG_libwayland-client= "libwayland-client"
PKG_libwayland-cursor= "libwayland-cursor"

require wayland-extraconf.inc
