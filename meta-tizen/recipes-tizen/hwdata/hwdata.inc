DESCRIPTION = "Hardware identification and configuration data"
HOMEPAGE = "http://git.fedorahosted.org/git/hwdata.git"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"
PV = "0.260"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by hwdata
# the PROVIDES rules is ignore "pciutils-ids  "
PROVIDES += "pciutils-ids"
RPROVIDES_hwdata += "pciutils-ids"


#PROVIDES by hwdata-ivi
PROVIDES += "hwdata-ivi"


RDEPENDS = ""
#RDEPENDS of hwdata-ivi (${PN}-ivi)
RDEPENDS_${PN}-ivi += "hwdata"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n hwdata-0.260-1
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  
  autotools_do_configure
  cp ${S}/packaging/hwdata.manifest .
  
  
  
  
}
EXTRA_OECONF += ""

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}${sysconfdir}/modprobe.d
 mv ${D}${prefix}/lib/modprobe.d/dist-blacklist.conf \
    ${D}${sysconfdir}/modprobe.d/blacklist.conf
 rm -rf ${D}${prefix}/lib
 install -m644 blacklist.conf ${D}/${sysconfdir}/modprobe.d
 install -m644 video.conf ${D}/${sysconfdir}/modprobe.d
 
 
 
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " hwdata "
PACKAGES += " hwdata-ivi "

hwdata_files = ""
hwdata_files += "${sysconfdir}/modprobe.d/blacklist.conf"
hwdata_files += "${prefix}/share/hwdata"
hwdata_files += "${prefix}/share/hwdata/*"
MANIFESTFILES_${PN} = "hwdata.manifest"
DIRFILES_${PN} = ""
DIRFILES_${PN} += "${prefix}/share/hwdata"

hwdata-ivi_files = ""
hwdata-ivi_files += "${sysconfdir}/modprobe.d/video.conf"

FILES_${PN} = "${hwdata_files}"
FILES_${PN}-ivi = "${hwdata-ivi_files}"

PKG_hwdata= "hwdata"
PKG_hwdata-ivi= "hwdata-ivi"

require hwdata-extraconf.inc

