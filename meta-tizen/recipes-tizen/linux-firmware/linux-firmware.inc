DESCRIPTION = "Firmware for various devices"
HOMEPAGE = "ftp://ftp.kernel.org//pub/linux/kernel/people/dwmw2/firmware/"
SECTION = "System/Kernel"
LICENSE = "Redistributable, no modification permitted"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by linux-firmware 
PROVIDES += "linux-firmware"
RPROVIDES_linux-firmware += "linux-firmware"

#PROVIDES by linux-firmware-ivi 
PROVIDES += "linux-firmware-ivi"
RPROVIDES_linux-firmware-ivi += "linux-firmware-ivi"

RDEPENDS = ""

DEPENDS = ""
#DEPENDS of linux-firmware 
DEPENDS += "fdupes-native"

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/linux-firmware.manifest .
 find . -type f -exec chmod 0644 {} ';'
 
 
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
 
 # Nothing to build
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 mkdir -p ${D}/lib/firmware
 cp -a * ${D}/lib/firmware/
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D}/lib/firmware | 
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
PACKAGES += "linux-firmware"
PACKAGES += "linux-firmware-ivi"

linux-firmware_files = ""
linux-firmware_files += "linux-firmware.manifest"
linux-firmware_files += "/lib/firmware/*"

linux-firmware-ivi_files = ""
linux-firmware-ivi_files += "linux-firmware.manifest"
linux-firmware-ivi_files += "/lib/firmware/iwlwifi-6000g2b-6.ucode"
linux-firmware-ivi_files += "/lib/firmware/iwlwifi-7260-8.ucode"
linux-firmware-ivi_files += "/lib/firmware/iwlwifi-3160-8.ucode"
linux-firmware-ivi_files += "/lib/firmware/intel/ibt-hw-37.7.10-fw-1.80.2.3.d.bseq"
linux-firmware-ivi_files += "/lib/firmware/intel/ibt-hw-37.7.bseq"
linux-firmware-ivi_files += "/lib/firmware/LICENCE.ibt_firmware"
linux-firmware-ivi_files += "/lib/firmware/LICENCE.iwlwifi_firmware"

FILES_${PN} = "${linux-firmware_files}"
FILES_${PN}-ivi = "${linux-firmware-ivi_files}"

PKG_linux-firmware= "linux-firmware"
PKG_linux-firmware-ivi= "linux-firmware-ivi"

require linux-firmware-extraconf.inc
