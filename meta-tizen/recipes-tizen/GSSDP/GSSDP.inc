DESCRIPTION = "GSSDP implements resource discovery and announcement over SSDP"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "LGPLv2+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gssdp 
PROVIDES += "gssdp"
RPROVIDES_gssdp += "gssdp"

#PROVIDES by gssdp-devel 
PROVIDES += "gssdp-devel"
RPROVIDES_gssdp-devel += "gssdp-devel"
RPROVIDES_gssdp-devel += "gssdp-dev"

RDEPENDS = ""
#RDEPENDS of gssdp (gssdp)
RDEPENDS_gssdp += "dbus"
RDEPENDS_gssdp += "libsoup"
RDEPENDS_gssdp += "/sbin/ldconfig"

#RDEPENDS of gssdp-devel (gssdp-devel)
RDEPENDS_gssdp-devel += "gssdp"


DEPENDS = ""
#DEPENDS of gssdp 
DEPENDS += "pkgconfig(dbus-glib-1)"
DEPENDS += "pkgconfig(libsoup-2.4)"
DEPENDS += "pkgconfig(glib-2.0)"
DEPENDS += "pkgconfig(gconf-2.0)"
DEPENDS += "pkgconfig(libxml-2.0)"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gssdp-0.14.4
 
 
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
 
 
}

PACKAGES = ""
PACKAGES += "gssdp"
PACKAGES += "gssdp-devel"

gssdp_files = ""
gssdp_files += "AUTHORS COPYING"
gssdp_files += "/usr/lib/*.so.*"

gssdp-devel_files = ""
gssdp-devel_files += "/usr/share/gtk-doc/html/gssdp"
gssdp-devel_files += "/usr/lib/*.so"
gssdp-devel_files += "/usr/lib/pkgconfig/gssdp-1.0.pc"
gssdp-devel_files += "/usr/include/gssdp-1.0"

FILES_${PN} = "${gssdp_files}"
FILES_${PN}-devel = "${gssdp-devel_files}"

PKG_gssdp= "gssdp"
PKG_gssdp-devel= "gssdp-devel"

require GSSDP-extraconf.inc
