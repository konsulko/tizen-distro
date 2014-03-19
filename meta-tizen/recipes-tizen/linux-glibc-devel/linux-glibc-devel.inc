DESCRIPTION = "Linux headers for userspace development"
HOMEPAGE = "http://www.kernel.org/"
SECTION = "Development/Libraries"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by linux-glibc-devel 
PROVIDES += "linux-glibc-devel"
RPROVIDES_linux-glibc-devel += "linux-glibc-devel"
RPROVIDES_linux-glibc-devel += "linux-glibc-dev"
# the PROVIDES rules is ignore "kernel-headers  "
PROVIDES += "kernel-headers"
RPROVIDES_linux-glibc-devel += "kernel-headers"
# the PROVIDES rules is ignore "linux-kernel-headers = 3.10"
PROVIDES += "linux-kernel-headers"
RPROVIDES_linux-glibc-devel += "linux-kernel-headers"

RDEPENDS = ""
#RDEPENDS of linux-glibc-devel (${PN})
RDEPENDS_${PN} += "coreutils"


DEPENDS = ""
#DEPENDS of linux-glibc-devel 
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n linux-glibc-devel-3.10
 cp ${S}/packaging/linux-glibc-devel.manifest .
 
 
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
 
 cat > version.h <<-BOGUS
 #ifdef __KERNEL__
 #error "======================================================="
 #error "You should not include /usr/include/{linux,asm}/ header"
 #error "files directly for the compilation of kernel modules."
 #error ""
 #error "glibc now uses kernel header files from a well-defined"
 #error "working kernel version (as recommended by Linus Torvalds)"
 #error "These files are glibc internal and may not match the"
 #error "currently running kernel. They should only be"
 #error "included via other system header files - user space"
 #error "programs should not directly include <linux/*.h> or"
 #error "<asm/*.h> as well."
 #error ""
 #error "Since Linux 2.6, the kernel module build process has been"
 #error "updated such that users building modules should not typically"
 #error "need to specify additional include directories at all."
 #error ""
 #error "To build kernel modules, ensure you have the build environment "
 #error "available either via the kernel-devel and kernel-<flavor>-devel "
 #error "packages or a properly configured kernel source tree."
 #error ""
 #error "Then, modules can be built using:"
 #error "make -C <path> M=$PWD"
 #error ""
 #error "For the currently running kernel there will be a symbolic "
 #error "link pointing to the build environment located at "
 #error "/lib/modules/$(uname -r)/build for use as <path>."
 #error ""
 #error "If you are seeing this message, your environment is "
 #error "not configured properly. "
 #error ""
 #error "Please adjust the Makefile accordingly."
 #error "======================================================="
 #else
 BOGUS
 # Get LINUX_VERSION_CODE and KERNEL_VERSION directly from kernel
 cat usr/include/linux/version.h >> version.h
 cat >> version.h <<-BOGUS
 #endif
 BOGUS
 cat version.h
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 cp -a usr ${D}
 cp -a version.h ${D}/usr/include/linux/
 # Temporarily exclude i2c header files, which are provided by i2c-tools instead
 rm -fv   ${D}/usr/include/linux/i2c-dev.h
 # resolve file conflict with glibc for now
 rm -fv   ${D}//usr/include/scsi/scsi*
 # Replace the directory /usr/include/asm with a symlink.
 # libc contained a symlink /usr/include/asm into kernel-source up to 7.0 (2.1.3)
 # glibc-devel contained a symlink /usr/include/asm into kernel-source in 7.1 (2.2)
 # glibc-devel contained a directory /usr/include/asm from 7.2 (2.2.2) up to 10.1/SLES10 (2.4)
 # The directory moved from glibc-devel to linux-kernel-headers in 10.2 (2.6.18.2)
 # The directory turned into a symlink in 10.3 (2.6.22)
 # rpm will remove obsolete files after the post install scripts
 # A trigger will run after the /usr/include/asm was removed
 # Create a dummy symlink now for rpmlint happiness, we %ghost this and create
 # a proper symlink during %post:
 ln -sfn asm-dummy ${D}/usr/include/asm
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/usr/include | 
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
PACKAGES += "linux-glibc-devel"

linux-glibc-devel_files = ""
linux-glibc-devel_files += "linux-glibc-devel.manifest"
linux-glibc-devel_files += "/usr/include/*"

FILES_${PN} = "${linux-glibc-devel_files}"

PKG_linux-glibc-devel= "linux-glibc-devel"

require linux-glibc-devel-extraconf.inc
