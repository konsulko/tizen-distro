DESCRIPTION = "Programming language for GNOME"
HOMEPAGE = "http://live.gnome.org/Vala"
SECTION = "Development/Gnome"
LICENSE = "LGPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libvala 
PROVIDES += "libvala"
RPROVIDES_libvala += "libvala"

#PROVIDES by vala 
PROVIDES += "vala"
RPROVIDES_vala += "vala"

#PROVIDES by libvala-devel 
PROVIDES += "libvala-devel"
RPROVIDES_libvala-devel += "libvala-devel"
RPROVIDES_libvala-devel += "libvala-dev"

RDEPENDS = ""
#RDEPENDS of vala (${PN})
RDEPENDS_${PN} += "update-alternatives"

#RDEPENDS of libvala-devel (lib${PN}-devel)
RDEPENDS_lib${PN}-devel += "libvala"


DEPENDS = ""
#DEPENDS of vala 
DEPENDS += "glib"
DEPENDS += "flex"
DEPENDS += "fdupes-native"
DEPENDS += "bison-native"
DEPENDS += "xz"

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
         --infodir=/usr/share/info --with-pic --enable-vapigen
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
   
  fdupes -q -n -r ${D}/usr/share | 
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
PACKAGES += "libvala"
PACKAGES += "vala"
PACKAGES += "libvala-devel"

libvala_files = ""
libvala_files += "/usr/lib/libvala-0.20.so.*"

vala_files = ""
vala_files += "/usr/bin/vala-0.20"
vala_files += "/usr/bin/valac-0.20"
vala_files += "/usr/bin/vala-gen-introspect-0.20"
vala_files += "/usr/bin/vapicheck-0.20"
vala_files += "/usr/bin/vapigen-0.20"
vala_files += "/usr/share/man/man1/valac-0.20.1*"
vala_files += "/usr/share/man/man1/vala-gen-introspect-0.20.1*"
vala_files += "/usr/share/man/man1/vapigen-0.20.1*"
vala_files += "/usr/share/aclocal/vala.m4"
vala_files += "/usr/share/aclocal/vapigen.m4"
vala_files += "/usr/share/pkgconfig/vapigen-0.20.pc"
vala_files += "/usr/share/vala"
vala_files += "/usr/share/vala/Makefile.vapigen"
vala_files += "/usr/share/vala-0.20/"
vala_files += "/usr/lib/vala-0.20/"

libvala-devel_files = ""
libvala-devel_files += "AUTHORS ChangeLog NEWS README"
libvala-devel_files += "/usr/include/vala-0.20/"
libvala-devel_files += "/usr/lib/libvala-0.20.so"
libvala-devel_files += "/usr/lib/pkgconfig/libvala-0.20.pc"

FILES_lib${PN} = "${libvala_files}"
FILES_${PN} = "${vala_files}"
FILES_lib${PN}-devel = "${libvala-devel_files}"

PKG_libvala= "libvala"
PKG_vala= "vala"
PKG_libvala-devel= "libvala-devel"

require vala-extraconf.inc
