DESCRIPTION = "The Parma Polyhedra Library"
HOMEPAGE = "http://www.cs.unipr.it/ppl/"
SECTION = "Development/Libraries/C and C++"
LICENSE = "GPL-3.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by libppl_c 
PROVIDES += "libppl_c"
RPROVIDES_libppl_c += "libppl_c"

#PROVIDES by libppl 
PROVIDES += "libppl"
RPROVIDES_libppl += "libppl"

#PROVIDES by ppl 
PROVIDES += "ppl"
RPROVIDES_ppl += "ppl"

#PROVIDES by ppl-devel-static 
PROVIDES += "ppl-devel-static"
RPROVIDES_ppl-devel-static += "ppl-devel-static"
RPROVIDES_ppl-devel-static += "ppl-dev"

#PROVIDES by ppl-doc 
PROVIDES += "ppl-doc"
RPROVIDES_ppl-doc += "ppl-doc"

#PROVIDES by ppl-devel 
PROVIDES += "ppl-devel"
RPROVIDES_ppl-devel += "ppl-devel"
RPROVIDES_ppl-devel += "ppl-dev"

RDEPENDS = ""
#RDEPENDS of ppl-devel-static (${PN}-devel-static)
RDEPENDS_${PN}-devel-static += "ppl-dev"

#RDEPENDS of ppl-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libppl_c"
RDEPENDS_${PN}-devel += "gmp-dev"
RDEPENDS_${PN}-devel += "libppl"


DEPENDS = ""
#DEPENDS of ppl 
DEPENDS += "gcc-cross"
DEPENDS += "gmp"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ppl-0.11.2
 cp ${S}/packaging/ppl.manifest .
 
 
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
         --infodir=/usr/share/info --enable-shared --with-pic --disable-rpath \
 	--disable-watchdog
 #sed -i 's|^hardcode_libdir_flag_spec=.*|hardcode_libdir_flag_spec=""|g' libtool
 #sed -i 's|^runpath_var=LD_RUN_PATH|runpath_var=DIE_RPATH_DIE|g' libtool
 make -j16
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make DESTDIR=${D} INSTALL="install -p" install
 # We don't build the binary, so delete its manpage
 rm -f ${D}/usr/share/man/man1/ppl_lpsol.1
 # We don't build pwl
 rm -Rf ${D}/usr/share/doc/pwl
 # The pdf is enough
 rm -f ${D}/usr/share/doc/ppl/ppl-user-*.ps.gz
 rm -f ${D}/usr/share/doc/ppl/ChangeLog
 rm -f ${D}/usr/share/doc/ppl/TODO
 rm -f ${D}/usr/share/doc/ppl/gpl.*
 rm -f ${D}/usr/share/doc/ppl/fdl.ps.gz
 rm -f ${D}/usr/share/doc/ppl/fdl.pdf
 rm -Rf ${D}/usr/share/doc/ppl/ppl-user-prolog-interface-0.11.2*
 rm -Rf ${D}/usr/share/doc/ppl/ppl-user-ocaml-interface-0.11.2*
 rm -Rf ${D}/usr/share/doc/ppl/ppl-user-java-interface-0.11.2*
 
 
}

PACKAGES = ""
PACKAGES += "ppl-devel"
PACKAGES += "libppl"
PACKAGES += "ppl"
PACKAGES += "libppl_c"
PACKAGES += "ppl-doc"
PACKAGES += "ppl-devel-static"

ppl-devel_files = ""
ppl-devel_files += "ppl.manifest"
ppl-devel_files += "/usr/share/doc/ppl/README.configure"
ppl-devel_files += "/usr/include/ppl.hh"
ppl-devel_files += "/usr/include/ppl_c.h"
ppl-devel_files += "/usr/lib/libppl.so"
ppl-devel_files += "/usr/lib/libppl_c.so"
ppl-devel_files += "/usr/bin/ppl-config"
ppl-devel_files += "/usr/share/man/man1/ppl-config.1.gz"
ppl-devel_files += "/usr/share/man/man3/libppl.3.gz"
ppl-devel_files += "/usr/share/man/man3/libppl_c.3.gz"
ppl-devel_files += "/usr/share/aclocal"
ppl-devel_files += "/usr/share/aclocal/ppl.m4"
ppl-devel_files += "/usr/share/aclocal/ppl_c.m4"

libppl_files = ""
libppl_files += "ppl.manifest"
libppl_files += "/usr/lib/libppl.so.*"

ppl_files = ""
ppl_files += "ppl.manifest"
ppl_files += "/usr/share/doc/ppl"
ppl_files += "/usr/share/doc/ppl/BUGS"
ppl_files += "/usr/share/doc/ppl/COPYING"
ppl_files += "/usr/share/doc/ppl/CREDITS"
ppl_files += "/usr/share/doc/ppl/NEWS"
ppl_files += "/usr/share/doc/ppl/README"
ppl_files += "/usr/bin/ppl_lcdd"
ppl_files += "/usr/bin/ppl_pips"
ppl_files += "/usr/share/man/man1/ppl_lcdd.1.gz"
ppl_files += "/usr/share/man/man1/ppl_pips.1.gz"

libppl_c_files = ""
libppl_c_files += "ppl.manifest"
libppl_c_files += "/usr/lib/libppl_c.so.*"

ppl-doc_files = ""
ppl-doc_files += "ppl.manifest"
ppl-doc_files += "/usr/share/doc/ppl/README.doc"
ppl-doc_files += "/usr/share/doc/ppl/fdl.txt"
ppl-doc_files += "/usr/share/doc/ppl/ppl-user-0.11.2-html/"
ppl-doc_files += "/usr/share/doc/ppl/ppl-user-c-interface-0.11.2-html/"
ppl-doc_files += "/usr/share/doc/ppl/ppl-user-0.11.2.pdf"
ppl-doc_files += "/usr/share/doc/ppl/ppl-user-c-interface-0.11.2.pdf"

ppl-devel-static_files = ""
ppl-devel-static_files += "ppl.manifest"
ppl-devel-static_files += "/usr/lib/libppl.a"
ppl-devel-static_files += "/usr/lib/libppl.la"
ppl-devel-static_files += "/usr/lib/libppl_c.a"
ppl-devel-static_files += "/usr/lib/libppl_c.la"

FILES_${PN}-devel = "${ppl-devel_files}"
FILES_lib${PN} = "${libppl_files}"
FILES_${PN} = "${ppl_files}"
FILES_lib${PN}_c = "${libppl_c_files}"
FILES_${PN}-doc = "${ppl-doc_files}"
FILES_${PN}-devel-static = "${ppl-devel-static_files}"

PKG_ppl-devel= "ppl-devel"
PKG_libppl= "libppl"
PKG_ppl= "ppl"
PKG_libppl_c= "libppl_c"
PKG_ppl-doc= "ppl-doc"
PKG_ppl-devel-static= "ppl-devel-static"

require ppl-extraconf.inc
