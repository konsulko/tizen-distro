SUMMARY = "Config image"
DESCRIPTION = "This Config image"
SECTION = "config"
PR = "r1"
LICENSE = "MIT"
LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

do_install() {
  mkdir -p ${D}${sysconfdir}
  echo "Tizen on Yocto" > ${D}${sysconfdir}/tizen
  
  touch ${D}${sysconfdir}/environment
  chmod 0644 ${D}${sysconfdir}/environment
  
}

pkg_postinst_${PN} () {
  chsmack -t $D${sysconfdir}
  chsmack -a 'System::Shared' $D${sysconfdir}
  
  mkdir -p $D${localstatedir}/volatile/log
  chsmack -t $D${localstatedir}/volatile/log
  chsmack -a 'System::Log'  $D${localstatedir}/volatile/log

}

FILES_${PN} = "${sysconfdir}/tizen \
               ${sysconfdir}/environment "