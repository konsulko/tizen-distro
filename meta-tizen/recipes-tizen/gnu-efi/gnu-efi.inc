DESCRIPTION = "EFI development environment"
HOMEPAGE = "http://sourceforge.net/projects/gnu-efi/"
SECTION = "System/Boot"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by gnu-efi 
PROVIDES += "gnu-efi"
RPROVIDES_gnu-efi += "gnu-efi"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of gnu-efi 
DEPENDS += "pciutils"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n gnu-efi-3.0
 cp ${S}/packaging/gnu-efi.manifest .
 
 
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
 
 make
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 make install PREFIX=/usr INSTALLROOT=${D}
 
 
}

PACKAGES = ""
PACKAGES += "gnu-efi"

gnu-efi_files = ""
gnu-efi_files += "gnu-efi.manifest"
gnu-efi_files += "/usr/include/efi/*"
gnu-efi_files += "/usr/lib/*"

FILES_${PN} = "${gnu-efi_files}"

PKG_gnu-efi= "gnu-efi"

require gnu-efi-extraconf.inc
