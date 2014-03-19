DESCRIPTION = "PCI utilities for Kernel version 2"
HOMEPAGE = "http://atrey.karlin.mff.cuni.cz/~mj/pciutils.shtml"
SECTION = "Base/Device Management"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by pciutils-docs  
PROVIDES += "pciutils-docs "
RPROVIDES_pciutils-docs  += "pciutils-docs "

#PROVIDES by pciutils-devel 
PROVIDES += "pciutils-devel"
RPROVIDES_pciutils-devel += "pciutils-devel"
RPROVIDES_pciutils-devel += "pciutils-dev"

#PROVIDES by libpci 
PROVIDES += "libpci"
RPROVIDES_libpci += "libpci"

#PROVIDES by pciutils 
PROVIDES += "pciutils"
RPROVIDES_pciutils += "pciutils"

RDEPENDS = ""
#RDEPENDS of pciutils-devel (${PN}-devel)
RDEPENDS_${PN}-devel += "libpci"

#RDEPENDS of pciutils (${PN})
RDEPENDS_${PN} += "pciutils-ids"


DEPENDS = ""
#DEPENDS of pciutils 
DEPENDS += "zlib-devel"
DEPENDS += "pkgconfig-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/pciutils.manifest .
 
 
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
 
 make -j16 OPT="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -Wall" PREFIX=/usr LIBDIR=/usr/lib SBINDIR=/usr/sbin STRIP="" SHARED="yes" IDSDIR=/usr/share/hwdata
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install PREFIX=${D}/usr SBINDIR=${D}/usr/sbin \
              ROOT=${D}/ MANDIR=${D}//usr/share/man STRIP="" \
 	     SHARED="yes" LIBDIR=${D}//usr/lib IDSDIR=${D}//usr/share/hwdata
 mkdir -p ${D}/usr/include/pci
 cp -p lib/{pci,header,config,types}.h ${D}/usr/include/pci/
 rm -rf ${D}/usr/share/hwdata/pci.ids*
 install -D -m 0644 lib/libpci.pc ${D}/usr/lib/pkgconfig/libpci.pc
 ln -sf libpci.so.3 ${D}/usr/lib/libpci.so
 
 
}

PACKAGES = ""
PACKAGES += "pciutils-docs"
PACKAGES += "pciutils-devel"
PACKAGES += "libpci"
PACKAGES += "pciutils"

pciutils-docs_files = ""
pciutils-docs_files += "/usr/share/info"
pciutils-docs_files += "/usr/share/man"

pciutils-devel_files = ""
pciutils-devel_files += "pciutils.manifest"
pciutils-devel_files += "/usr/include/pci/"
pciutils-devel_files += "/usr/lib/*.so"
pciutils-devel_files += "/usr/lib/pkgconfig/libpci.pc"

libpci_files = ""
libpci_files += "pciutils.manifest"
libpci_files += "/usr/lib/libpci.so.*"

pciutils_files = ""
pciutils_files += "pciutils.manifest"
pciutils_files += "/usr/sbin/*"

FILES_${PN}-docs = "${pciutils-docs_files}"
FILES_${PN}-devel = "${pciutils-devel_files}"
FILES_libpci = "${libpci_files}"
FILES_${PN} = "${pciutils_files}"

PKG_pciutils-docs= "pciutils-docs"
PKG_pciutils-devel= "pciutils-devel"
PKG_libpci= "libpci"
PKG_pciutils= "pciutils"

require pciutils-extraconf.inc
