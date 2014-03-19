DESCRIPTION = "GObject-based library providing commonly used data structures"
HOMEPAGE = "http://live.gnome.org/Libgee"
SECTION = "System/Libraries"
LICENSE = "LGPL-2.1+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by typelib-Gee 
PROVIDES += "typelib-Gee"
RPROVIDES_typelib-Gee += "typelib-Gee"

#PROVIDES by libgee 
PROVIDES += "libgee"
RPROVIDES_libgee += "libgee"

#PROVIDES by libgee-devel 
PROVIDES += "libgee-devel"
RPROVIDES_libgee-devel += "libgee-devel"
RPROVIDES_libgee-devel += "libgee-dev"

RDEPENDS = ""
#RDEPENDS of libgee (${PN})
RDEPENDS_${PN} += "/sbin/ldconfig"

#RDEPENDS of libgee-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "typelib-Gee"
RDEPENDS_${PN}-devel += "libgee"


DEPENDS = ""
#DEPENDS of libgee 
DEPENDS += "gobject-introspection"
DEPENDS += "vala"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "gnome-common"

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
 
 
 [ -x ./autogen.sh ] && NOCONFIGURE=1 ./autogen.sh
 
 
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
         --infodir=/usr/share/info \
  --disable-static
 
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
PACKAGES += "typelib-Gee"
PACKAGES += "libgee"
PACKAGES += "libgee-devel"

typelib-Gee_files = ""
typelib-Gee_files += "/usr/lib/girepository-1.0/Gee-0.8.typelib"

libgee_files = ""
libgee_files += "/usr/lib/*.so.*"

libgee-devel_files = ""
libgee-devel_files += "/usr/include/gee-0.8/"
libgee-devel_files += "/usr/lib/*.so"
libgee-devel_files += "/usr/lib/pkgconfig/*.pc"
libgee-devel_files += "/usr/share/gir-1.0/*.gir"
libgee-devel_files += "/usr/share/vala"
libgee-devel_files += "/usr/share/vala/vapi"
libgee-devel_files += "/usr/share/vala/vapi/*.vapi"

FILES_typelib-Gee = "${typelib-Gee_files}"
FILES_${PN} = "${libgee_files}"
FILES_${PN}-devel = "${libgee-devel_files}"

PKG_typelib-Gee= "typelib-Gee"
PKG_libgee= "libgee"
PKG_libgee-devel= "libgee-devel"

require libgee-extraconf.inc
