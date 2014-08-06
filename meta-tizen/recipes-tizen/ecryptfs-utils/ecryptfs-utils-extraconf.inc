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

ecryptfs-utils_files += "/lib/security/pam_ecryptfs.so"

ecryptfs-utils-dbg_files += "/lib/security/.debug/pam_ecryptfs.so"
