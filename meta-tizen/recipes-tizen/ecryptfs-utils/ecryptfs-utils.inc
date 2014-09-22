DESCRIPTION = "ECryptfs utilities"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by ecryptfs-utils


#PROVIDES by libecryptfs-python
PROVIDES += "libecryptfs-python"


#PROVIDES by libecryptfs
PROVIDES += "libecryptfs"


#PROVIDES by libecryptfs-dev
PROVIDES += "libecryptfs-dev"


RDEPENDS = ""
#RDEPENDS of libecryptfs-python (libecryptfs-python)
RDEPENDS_libecryptfs-python += "libecryptfs"

#RDEPENDS of ecryptfs-utils (${PN})
RDEPENDS_${PN} += "keyutils"
RDEPENDS_${PN} += "libecryptfs"
RDEPENDS_${PN} += "eglibc"

#RDEPENDS of libecryptfs-dev (libecryptfs-dev)
RDEPENDS_libecryptfs-dev += "libecryptfs"
RDEPENDS_libecryptfs-dev += "keyutils"


DEPENDS = ""
#DEPENDS of ecryptfs-utils
DEPENDS += "keyutils"
DEPENDS_append_class-native = " intltool-native"
DEPENDS_append_class-target = " intltool-native"
inherit pythonnative
DEPENDS_append_class-native = " fdupes-native"
DEPENDS_append_class-target = " fdupes-native"
DEPENDS += "glib-2.0"
DEPENDS += "nss"
DEPENDS += "libpam"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n ecryptfs-utils-104
 cp ${S}/packaging/ecryptfs-utils.manifest .
 
 
 
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
  oe_runmake -j16
  
  
  
  
}
EXTRA_OECONF += " --disable-openssl"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 rm -rf ${D}
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 #find_lang ecryptfs-utils
 
 
  _target=""; 
  _symlinks=0; 
   
  fdupes -q -n -r ${D} | 
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

pkg_postinst_libecryptfs() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

pkg_postrm_libecryptfs() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libecryptfs "
PACKAGES += " libecryptfs-python "
PACKAGES += " ecryptfs-utils "
PACKAGES += " libecryptfs-dev "

libecryptfs_files = ""
libecryptfs_files += "${prefix}/lib/libecryptfs.so.*"
libecryptfs_files += "${prefix}/lib/ecryptfs/*"
MANIFESTFILES_libecryptfs = "ecryptfs-utils.manifest"

libecryptfs-python_files = ""
libecryptfs-python_files += "/usr/lib/python2.7/site-packages/ecryptfs-utils/*"
libecryptfs-python_files += "/usr/lib64/python2.7/site-packages/ecryptfs-utils/*"

ecryptfs-utils_files = ""
ecryptfs-utils_files += "AUTHORS NEWS"
ecryptfs-utils_files += "${prefix}/bin/ecryptfs*"
ecryptfs-utils_files += "/sbin/mount.ecryptfs*"
ecryptfs-utils_files += "/sbin/umount.ecryptfs*"
ecryptfs-utils_files += "/lib/security/pam_ecryptfs.so"
ecryptfs-utils_files += "${mandir}/man1/*ecryptfs*"
ecryptfs-utils_files += "${mandir}/man7/*ecryptfs*"
ecryptfs-utils_files += "${mandir}/man8/*ecryptfs*"
ecryptfs-utils_files += "${prefix}/share/doc/ecryptfs-utils/*"
ecryptfs-utils_files += "${prefix}/share/ecryptfs-utils/*"
MANIFESTFILES_${PN} = "ecryptfs-utils.manifest"

libecryptfs-dev_files = ""
libecryptfs-dev_files += "${prefix}/include/ecryptfs.h"
libecryptfs-dev_files += "${prefix}/lib/libecryptfs.so"
libecryptfs-dev_files += "${prefix}/lib/pkgconfig/libecryptfs.pc"

FILES_libecryptfs = "${libecryptfs_files}"
FILES_libecryptfs-python = "${libecryptfs-python_files}"
FILES_${PN} = "${ecryptfs-utils_files}"
FILES_libecryptfs-dev = "${libecryptfs-dev_files}"

PKG_libecryptfs= "libecryptfs"
PKG_libecryptfs-python= "libecryptfs-python"
PKG_ecryptfs-utils= "ecryptfs-utils"
PKG_libecryptfs-dev= "libecryptfs-dev"

require ecryptfs-utils-extraconf.inc

