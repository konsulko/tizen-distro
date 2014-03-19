DESCRIPTION = "Device specific configurations for Touch"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Hardware Adaptation"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

PROVIDES = ""

#PROVIDES by device-config-touch-sitronix 
PROVIDES += "device-config-touch-sitronix"
RPROVIDES_device-config-touch-sitronix += "device-config-touch-sitronix"

#PROVIDES by device-config-touch 
PROVIDES += "device-config-touch"
RPROVIDES_device-config-touch += "device-config-touch"

#PROVIDES by device-config-touch-mxt224 
PROVIDES += "device-config-touch-mxt224"
RPROVIDES_device-config-touch-mxt224 += "device-config-touch-mxt224"

#PROVIDES by device-config-touch-ILI 
PROVIDES += "device-config-touch-ILI"
RPROVIDES_device-config-touch-ILI += "device-config-touch-ILI"

#PROVIDES by device-config-touch-cando 
PROVIDES += "device-config-touch-cando"
RPROVIDES_device-config-touch-cando += "device-config-touch-cando"

#PROVIDES by device-config-touch-eGalax 
PROVIDES += "device-config-touch-eGalax"
RPROVIDES_device-config-touch-eGalax += "device-config-touch-eGalax"

#PROVIDES by device-config-touch-Hanvon 
PROVIDES += "device-config-touch-Hanvon"
RPROVIDES_device-config-touch-Hanvon += "device-config-touch-Hanvon"

#PROVIDES by device-config-touch-Atmel 
PROVIDES += "device-config-touch-Atmel"
RPROVIDES_device-config-touch-Atmel += "device-config-touch-Atmel"

#PROVIDES by device-config-touch-synaptics 
PROVIDES += "device-config-touch-synaptics"
RPROVIDES_device-config-touch-synaptics += "device-config-touch-synaptics"

RDEPENDS = ""

DEPENDS = ""

do_patch() {
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 # >> gbp-apply-patches    # auto-added by gbp
 # << gbp-apply-patches    # auto-added by gbp
 
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
 
 cp ${S}/packaging/device-config-touch.manifest .
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
 mkdir -p ${D}/etc/X11/xorg.conf.d
 install -m 0644 *.conf ${D}/etc/X11/xorg.conf.d/
 
 
 
}

PACKAGES = ""
PACKAGES += "device-config-touch-sitronix"
PACKAGES += "device-config-touch-mxt224"
PACKAGES += "device-config-touch-ILI"
PACKAGES += "device-config-touch-cando"
PACKAGES += "device-config-touch-eGalax"
PACKAGES += "device-config-touch-Hanvon"
PACKAGES += "device-config-touch-Atmel"
PACKAGES += "device-config-touch-synaptics"

device-config-touch-sitronix_files = ""
device-config-touch-sitronix_files += "/etc/X11/xorg.conf.d/70-sitronix-mtev.conf"
device-config-touch-sitronix_files += "device-config-touch.manifest"

device-config-touch-mxt224_files = ""
device-config-touch-mxt224_files += "/etc/X11/xorg.conf.d/60-mxt224-evdevmultitouch.conf"
device-config-touch-mxt224_files += "device-config-touch.manifest"

device-config-touch-ILI_files = ""
device-config-touch-ILI_files += "/etc/X11/xorg.conf.d/90-ILI-mtev.conf"
device-config-touch-ILI_files += "device-config-touch.manifest"

device-config-touch-cando_files = ""
device-config-touch-cando_files += "/etc/X11/xorg.conf.d/60-cando-evdevmultitouch.conf"
device-config-touch-cando_files += "device-config-touch.manifest"

device-config-touch-eGalax_files = ""
device-config-touch-eGalax_files += "/etc/X11/xorg.conf.d/92-exopc-mtev.conf"
device-config-touch-eGalax_files += "device-config-touch.manifest"

device-config-touch-Hanvon_files = ""
device-config-touch-Hanvon_files += "/etc/X11/xorg.conf.d/80-Hanvon-mtev.conf"
device-config-touch-Hanvon_files += "device-config-touch.manifest"

device-config-touch-Atmel_files = ""
device-config-touch-Atmel_files += "device-config-touch.manifest"
device-config-touch-Atmel_files += "/etc/X11/xorg.conf.d/65-Atmel-mtev.conf"

device-config-touch-synaptics_files = ""
device-config-touch-synaptics_files += "/etc/X11/xorg.conf.d/60-synaptics-evdevmultitouch.conf"
device-config-touch-synaptics_files += "device-config-touch.manifest"

FILES_${PN}-sitronix = "${device-config-touch-sitronix_files}"
FILES_${PN}-mxt224 = "${device-config-touch-mxt224_files}"
FILES_${PN}-ILI = "${device-config-touch-ILI_files}"
FILES_${PN}-cando = "${device-config-touch-cando_files}"
FILES_${PN}-eGalax = "${device-config-touch-eGalax_files}"
FILES_${PN}-Hanvon = "${device-config-touch-Hanvon_files}"
FILES_${PN}-Atmel = "${device-config-touch-Atmel_files}"
FILES_${PN}-synaptics = "${device-config-touch-synaptics_files}"

PKG_device-config-touch-sitronix= "device-config-touch-sitronix"
PKG_device-config-touch-mxt224= "device-config-touch-mxt224"
PKG_device-config-touch-ILI= "device-config-touch-ILI"
PKG_device-config-touch-cando= "device-config-touch-cando"
PKG_device-config-touch-eGalax= "device-config-touch-eGalax"
PKG_device-config-touch-Hanvon= "device-config-touch-Hanvon"
PKG_device-config-touch-Atmel= "device-config-touch-Atmel"
PKG_device-config-touch-synaptics= "device-config-touch-synaptics"

require device-config-touch-extraconf.inc
