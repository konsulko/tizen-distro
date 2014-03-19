DESCRIPTION = "The Tcl Programming Language"
HOMEPAGE = "http://www.tcl.tk"
SECTION = "Development/Languages"
LICENSE = "TIZEN-TCL"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by tcl-devel 
PROVIDES += "tcl-devel"
RPROVIDES_tcl-devel += "tcl-devel"
RPROVIDES_tcl-devel += "tcl-dev"

#PROVIDES by tcl 
PROVIDES += "tcl"
RPROVIDES_tcl += "tcl"
# the PROVIDES rules is ignore "tclsh  "
PROVIDES += "tclsh"
RPROVIDES_tcl += "tclsh"
# the PROVIDES rules is ignore "tclsh8.6  "
PROVIDES += "tclsh8.6"
RPROVIDES_tcl += "tclsh8.6"

RDEPENDS = ""
#RDEPENDS of tcl-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "tcl"

#RDEPENDS of tcl (${PN})
RDEPENDS_${PN} += "/usr/bin/rm"


DEPENDS = ""
#DEPENDS of tcl 
DEPENDS += "autoconf-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n tcl8.6.0
 cp ${S}/packaging/tcl.manifest .
 
 
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
 
 cd unix
 autoconf
 
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
     --enable-man-symlinks \
     --enable-man-compression=gzip
 make -j16 \
         PACKAGE_DIR=/usr/lib/tcl \
         TCL_LIBRARY="/usr/lib/tcl/tcl8.6" \
         TCL_PACKAGE_PATH="/usr/lib/tcl /usr/share/tcl"
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make -C unix install install-private-headers \
     INSTALL_ROOT=${D} \
     TCL_LIBRARY="/usr/lib/tcl/tcl8.6"
 rm -f ${D}/usr/lib/tcl/tcl8.6/ldAix
 ln -sf tclsh8.6 ${D}/usr/bin/tclsh
 mkdir -p ${D}/usr/share/tcl
 install -D ${S}/packaging/macros.tcl -m 644 ${D}/etc/rpm/macros.tcl
 
 
}

PACKAGES = ""
PACKAGES += "tcl-devel"
PACKAGES += "tcl"

tcl-devel_files = ""
tcl-devel_files += "tcl.manifest"
tcl-devel_files += "/usr/share/man/man3/*"
tcl-devel_files += "/usr/include/*"
tcl-devel_files += "/usr/lib/tcl/*/tclAppInit.c"
tcl-devel_files += "/usr/lib/*.a"
tcl-devel_files += "/usr/lib/tclConfig.sh"
tcl-devel_files += "/usr/lib/pkgconfig/tcl.pc"
tcl-devel_files += "/usr/lib/tclooConfig.sh"

tcl_files = ""
tcl_files += "tcl.manifest"
tcl_files += "/usr/share/man/man1/*"
tcl_files += "/usr/share/man/mann/*"
tcl_files += "/usr/bin/*"
tcl_files += "/usr/lib/lib*.so"
tcl_files += "/usr/share/tcl"
tcl_files += "/usr/lib/tcl"
tcl_files += "/etc/rpm/macros.tcl"

FILES_${PN}-devel = "${tcl-devel_files}"
FILES_${PN} = "${tcl_files}"

PKG_tcl-devel= "tcl-devel"
PKG_tcl= "tcl"

require tcl-extraconf.inc
