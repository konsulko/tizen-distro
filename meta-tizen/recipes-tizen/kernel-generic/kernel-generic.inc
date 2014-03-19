DESCRIPTION = "The Linux kernel"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Kernel"
LICENSE = "GPL-2.0"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by kernel-x86-generic 
PROVIDES += "kernel-x86-generic"
RPROVIDES_kernel-x86-generic += "kernel-x86-generic"
# the PROVIDES rules is ignore "kernel = 3.12.4-1"
PROVIDES += "kernel"
RPROVIDES_kernel-x86-generic += "kernel"
# the PROVIDES rules is ignore "kernel-uname-r = 3.12.4-1-x86-generic"
PROVIDES += "kernel-uname-r"
RPROVIDES_kernel-x86-generic += "kernel-uname-r"

#PROVIDES by perf 
PROVIDES += "perf"
RPROVIDES_perf += "perf"
# the PROVIDES rules is ignore "perf = 3.12.4-1-x86-generic"
PROVIDES += "perf"
RPROVIDES_perf += "perf"

#PROVIDES by kernel-x86-generic-devel 
PROVIDES += "kernel-x86-generic-devel"
RPROVIDES_kernel-x86-generic-devel += "kernel-x86-generic-devel"
RPROVIDES_kernel-x86-generic-devel += "kernel-x86-generic-dev"
# the PROVIDES rules is ignore "kernel-devel = 3.12.4-1-x86-generic"
PROVIDES += "kernel-devel"
RPROVIDES_kernel-x86-generic-devel += "kernel-devel"
RPROVIDES_kernel-x86-generic-devel += "kernel-dev"
# the PROVIDES rules is ignore "kernel-devel-uname-r = 3.12.4-1-x86-generic"
PROVIDES += "kernel-devel-uname-r"
RPROVIDES_kernel-x86-generic-devel += "kernel-devel-uname-r"
RPROVIDES_kernel-x86-generic-devel += "kernel-dev"

RDEPENDS = ""
#RDEPENDS of kernel-x86-generic (kernel-x86-generic)
RDEPENDS_kernel-x86-generic += "/usr/bin/ln"
RDEPENDS_kernel-x86-generic += "/usr/sbin/depmod"
RDEPENDS_kernel-x86-generic += "/usr/bin/kmod"
RDEPENDS_kernel-x86-generic += "/usr/bin/sort"
RDEPENDS_kernel-x86-generic += "/usr/bin/dracut"
RDEPENDS_kernel-x86-generic += "/usr/bin/sed"
RDEPENDS_kernel-x86-generic += "rpm"

#RDEPENDS of perf (perf)
RDEPENDS_perf += "kernel-x86-generic"

#RDEPENDS of kernel-x86-generic-devel (kernel-x86-generic-devel)
RDEPENDS_kernel-x86-generic-devel += "kernel-x86-generic"
RDEPENDS_kernel-x86-generic-devel += "/usr/bin/find"


DEPENDS = ""
#DEPENDS of kernel-x86-generic 
DEPENDS += "flex"
DEPENDS += "net-tools"
DEPENDS += "bc"
DEPENDS += "elfutils"
DEPENDS += "python-devel"
DEPENDS += "module-init-tools"
DEPENDS += "findutils"
DEPENDS += "which"
DEPENDS += "bison-native"
DEPENDS += "binutils"

do_patch() {
 # Unpack the kernel tarbal
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n kernel-x86-generic-3.12.4
 
 
 
 ###
 ### BUILD
 ###
 
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
 
 # Make sure EXTRAVERSION says what we want it to say
 sed -i "s/^EXTRAVERSION.*/EXTRAVERSION = -1-x86-generic/" Makefile
 
 # Build perf
 make -s -C tools/lib/traceevent ARCH=x86_64 -j16
 make -s -C tools/perf WERROR=0 ARCH=x86_64
 
 # Build kernel and modules
 
 make -s ARCH=x86_64 generic_x86_64_defconfig
 
 make -s ARCH=x86_64 -j16 bzImage
 make -s ARCH=x86_64 -j16 modules
 
 
 
 ###
 ### INSTALL
 ###
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 install -d ${D}/boot
 
 install -m 644 .config ${D}/boot/config-3.12.4-1-x86-generic
 install -m 644 System.map ${D}/boot/System.map-3.12.4-1-x86-generic
 install -m 755 arch/x86/boot/bzImage ${D}/boot/vmlinuz-3.12.4-1-x86-generic
 # Dummy initrd, will not be included in the actual package but needed for files
 touch ${D}/boot/initrd-3.12.4-1-x86-generic.img
 
 make -s ARCH=x86_64 INSTALL_MOD_PATH=${D} modules_install KERNELRELEASE=3.12.4-1-x86-generic
 make -s ARCH=x86_64 INSTALL_MOD_PATH=${D} vdso_install KERNELRELEASE=3.12.4-1-x86-generic
 rm -rf ${D}/lib/firmware
 
 # And save the headers/makefiles etc for building modules against
 #
 # This all looks scary, but the end result is supposed to be:
 # * all arch relevant include/ files
 # * all Makefile/Kconfig files
 # * all script/ files
 
 # Remove existing build/source links and create pristine dirs
 rm ${D}/lib/modules/3.12.4-1-x86-generic/build
 rm ${D}/lib/modules/3.12.4-1-x86-generic/source
 install -d ${D}/lib/modules/3.12.4-1-x86-generic/build
 ln -s build ${D}/lib/modules/3.12.4-1-x86-generic/source
 
 # First, copy all dirs containing Makefile of Kconfig files
 cp --parents `find  -type f -name "Makefile*" -o -name "Kconfig*"` ${D}/lib/modules/3.12.4-1-x86-generic/build
 install Module.symvers ${D}/lib/modules/3.12.4-1-x86-generic/build/
 install System.map ${D}/lib/modules/3.12.4-1-x86-generic/build/
 
 # Then, drop all but the needed Makefiles/Kconfig files
 rm -rf ${D}/lib/modules/3.12.4-1-x86-generic/build/Documentation
 rm -rf ${D}/lib/modules/3.12.4-1-x86-generic/build/scripts
 rm -rf ${D}/lib/modules/3.12.4-1-x86-generic/build/include
 
 # Copy config and scripts
 install .config ${D}/lib/modules/3.12.4-1-x86-generic/build/
 cp -a scripts ${D}/lib/modules/3.12.4-1-x86-generic/build
 if [ -d arch/x86/scripts ]; then
     cp -a arch/x86/scripts ${D}/lib/modules/3.12.4-1-x86-generic/build/arch/x86/ || :
 fi
 if [ -f arch/x86/*lds ]; then
     cp -a arch/x86/*lds ${D}/lib/modules/3.12.4-1-x86-generic/build/arch/x86/ || :
 fi
 rm -f ${D}/lib/modules/3.12.4-1-x86-generic/build/scripts/*.o
 rm -f ${D}/lib/modules/3.12.4-1-x86-generic/build/scripts/*/*.o
 cp -a --parents arch/x86/include ${D}/lib/modules/3.12.4-1-x86-generic/build
 
 # Copy include files
 mkdir -p ${D}/lib/modules/3.12.4-1-x86-generic/build/include
 find include/ -mindepth 1 -maxdepth 1 -type d | xargs -I{} cp -a {} ${D}/lib/modules/3.12.4-1-x86-generic/build/include
 
 # Save the vmlinux file for kernel debugging into the devel package
 cp vmlinux ${D}/lib/modules/3.12.4-1-x86-generic
 
 # Mark modules executable so that strip-to-file can strip them
 find ${D}/lib/modules/3.12.4-1-x86-generic -name "*.ko" -type f | xargs --no-run-if-empty chmod 755
 
 # Move the devel headers out of the root file system
 install -d ${D}/usr/src/kernels
 mv ${D}/lib/modules/3.12.4-1-x86-generic/build ${D}/usr/src/kernels/3.12.4-1-x86-generic
 
 ln -sf /usr/src/kernels/3.12.4-1-x86-generic ${D}/lib/modules/3.12.4-1-x86-generic/build
 
 # Install perf
 install -d ${D}
 make -s -C tools/perf DESTDIR=${D} install
 install -d  ${D}/usr/bin
 install -d  ${D}/usr/libexec
 mv ${D}/bin/* ${D}/usr/bin/
 mv ${D}/libexec/* ${D}/usr/libexec/
 rm ${D}/etc/bash_completion.d/perf
 
 
 
 ###
 ### SCRIPTS
 ###
 
 
}

PACKAGES = ""
PACKAGES += "kernel-x86-generic"
PACKAGES += "perf"
PACKAGES += "kernel-x86-generic-devel"

kernel-x86-generic_files = ""
kernel-x86-generic_files += "/boot/vmlinuz-3.12.4-1-x86-generic"
kernel-x86-generic_files += "/boot/System.map-3.12.4-1-x86-generic"
kernel-x86-generic_files += "/boot/config-3.12.4-1-x86-generic"
kernel-x86-generic_files += "/lib/modules/3.12.4-1-x86-generic"
kernel-x86-generic_files += "/lib/modules/3.12.4-1-x86-generic/kernel"
kernel-x86-generic_files += "/lib/modules/3.12.4-1-x86-generic/build"
kernel-x86-generic_files += "/lib/modules/3.12.4-1-x86-generic/source"
kernel-x86-generic_files += "/lib/modules/3.12.4-1-x86-generic/vdso"
kernel-x86-generic_files += "/lib/modules/3.12.4-1-x86-generic/modules.*"

perf_files = ""
perf_files += "/usr/bin/perf"
perf_files += "/usr/libexec/perf-core"

kernel-x86-generic-devel_files = ""
kernel-x86-generic-devel_files += "/lib/modules/3.12.4-1-x86-generic/vmlinux"

FILES_${PN} = "${kernel-x86-generic_files}"
FILES_perf = "${perf_files}"
FILES_${PN}-devel = "${kernel-x86-generic-devel_files}"

PKG_kernel-x86-generic= "kernel-x86-generic"
PKG_perf= "perf"
PKG_kernel-x86-generic-devel= "kernel-x86-generic-devel"

require kernel-generic-extraconf.inc
