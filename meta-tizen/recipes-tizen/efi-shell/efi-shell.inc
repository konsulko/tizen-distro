DESCRIPTION = "Shell for the firmware"
HOMEPAGE = "http://sourceforge.net/projects/edk2/"
SECTION = "Base/Startup"
LICENSE = "BSD-3-Clause"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by efi-shell 
PROVIDES += "efi-shell"
RPROVIDES_efi-shell += "efi-shell"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 
 
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
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 rm -fr ${D}
 install -D ${S}/packaging/shell.efi ${D}/boot/EFI/shellx64.efi
 
 
}

PACKAGES = ""
PACKAGES += "efi-shell"

efi-shell_files = ""
efi-shell_files += "/boot/EFI/shellx64.efi"

FILES_${PN} = "${efi-shell_files}"

PKG_efi-shell= "efi-shell"

require efi-shell-extraconf.inc
