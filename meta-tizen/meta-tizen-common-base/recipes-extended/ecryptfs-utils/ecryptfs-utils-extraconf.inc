DEPENDS += "python"

do_configure_prepend() {
    # Remove unknown macro in configure.ac
    sed -i 's@^AM_GLIB_GNU_GETTEXT@@' configure.ac
}

do_compile_prepend() {
    export HOST_SYS=${HOST_SYS}
    export BUILD_SYS=${BUILD_SYS}
    export STAGING_LIBDIR=${STAGING_LIBDIR}
    export STAGING_INCDIR=${STAGING_INCDIR}
}


# Bypass a QA issue regarding symnlinks.
# A better solution would be to  create a libecryptfs-python-dev package containing the symlinks.
INSANE_SKIP_libecryptfs-python = "dev-so"

PACKAGES += " libecryptfs-dbg "
PACKAGES += " libecryptfs-python-dbg "

FILES_${PN}-dbg += "/lib/security/.debug/pam_ecryptfs.so"

FILES_libecryptfs-dbg += "/usr/lib/ecryptfs/.debug/libecryptfs_key_mod_passphrase.so"

FILES_libecryptfs-python-dbg += "/usr/lib/python2.7/site-packages/ecryptfs-utils/.debug/_libecryptfs.so.0.0.0"
