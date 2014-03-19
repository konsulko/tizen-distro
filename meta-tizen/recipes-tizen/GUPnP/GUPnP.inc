DESCRIPTION = "GUPnP is an framework for creating UPnP devices & control points"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gupnp-devel 
PROVIDES += "gupnp-devel"
RPROVIDES_gupnp-devel += "gupnp-devel"
RPROVIDES_gupnp-devel += "gupnp-dev"

#PROVIDES by gupnp 
PROVIDES += "gupnp"
RPROVIDES_gupnp += "gupnp"

RDEPENDS = ""
#RDEPENDS of gupnp-devel (gupnp-devel)
RDEPENDS_gupnp-devel += "gupnp"

#RDEPENDS of gupnp (gupnp)
RDEPENDS_gupnp += "/sbin/ldconfig"


DEPENDS = ""
#DEPENDS of gupnp 
DEPENDS += "GSSDP"
DEPENDS += "pkgconfig(gio-2.0)"
DEPENDS += "pkgconfig(libxml-2.0)"
DEPENDS += "pkgconfig(gmodule-2.0)"
DEPENDS += "pkgconfig(uuid)"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gupnp-0.20.5
 
 
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
PACKAGES += "gupnp-devel"
PACKAGES += "gupnp"

gupnp-devel_files = ""
gupnp-devel_files += "/usr/lib/pkgconfig/gupnp-1.0.pc"
gupnp-devel_files += "/usr/lib/*.so"
gupnp-devel_files += "/usr/include/gupnp-1.0"
gupnp-devel_files += "/usr/bin/gupnp-binding-tool"

gupnp_files = ""
gupnp_files += "/usr/lib/*.so.*"

FILES_${PN}-devel = "${gupnp-devel_files}"
FILES_${PN} = "${gupnp_files}"

PKG_gupnp-devel= "gupnp-devel"
PKG_gupnp= "gupnp"

require GUPnP-extraconf.inc
