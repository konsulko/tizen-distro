DESCRIPTION = "GUPnP-AV is a collection of helpers for building UPnP AV applications"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gupnp-av-devel 
PROVIDES += "gupnp-av-devel"
RPROVIDES_gupnp-av-devel += "gupnp-av-devel"
RPROVIDES_gupnp-av-devel += "gupnp-av-dev"

#PROVIDES by gupnp-av 
PROVIDES += "gupnp-av"
RPROVIDES_gupnp-av += "gupnp-av"

RDEPENDS = ""
#RDEPENDS of gupnp-av-devel (gupnp-av-devel)
RDEPENDS_gupnp-av-devel += "gupnp-av"

#RDEPENDS of gupnp-av (gupnp-av)
RDEPENDS_gupnp-av += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of gupnp-av 
DEPENDS += "pkgconfig(gobject-2.0)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "GUPnP"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gupnp-av-0.12.4
 
 
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
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=/usr/bin \
   install  
   rm -f ${D}/usr/share/info/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 rm -rf  $RPM_BUILD_ROOT/usr/share/gtk-doc
 
 
}

PACKAGES = ""
PACKAGES += "gupnp-av-devel"
PACKAGES += "gupnp-av"

gupnp-av-devel_files = ""
gupnp-av-devel_files += "/usr/include/gupnp-av-1.0/libgupnp-av"
gupnp-av-devel_files += "/usr/lib/*.so"
gupnp-av-devel_files += "/usr/lib/pkgconfig/gupnp-av-1.0.pc"

gupnp-av_files = ""
gupnp-av_files += "AUTHORS COPYING README"
gupnp-av_files += "/usr/lib/*.so.*"
gupnp-av_files += "/usr/share/gupnp-av/*.xsd"

FILES_${PN}-devel = "${gupnp-av-devel_files}"
FILES_${PN} = "${gupnp-av_files}"

PKG_gupnp-av-devel= "gupnp-av-devel"
PKG_gupnp-av= "gupnp-av"

require GUPnP-AV-extraconf.inc
