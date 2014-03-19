SRC_URI += "file://relative-libdir.patch;striplevel=0 "

SRC_URI += "file://package_utilies.m4 \
           "
           
# the package comes with a custom config.h.in, it cannot be
# overwritten by autoheader
export AUTOHEADER = "true"
EXTRA_OECONF = "INSTALL_USER=root INSTALL_GROUP=root"
EXTRA_OECONF_append_class-native = " --enable-gettext=no"

EXTRA_OEMAKE = "PKG_LIB_DIR=${base_libdir} PKG_DEVLIB_DIR=${libdir}"

do_patch_append () {
 cat ${WORKDIR}/relative-libdir.patch | patch -p0 -b
 cp ${WORKDIR}/package_utilies.m4 m4/
}