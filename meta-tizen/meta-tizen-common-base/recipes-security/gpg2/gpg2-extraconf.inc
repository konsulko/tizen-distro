SRC_URI += " file://0001-Update-autoconf-macros.patch "
SRC_URI += " file://0002-Do-not-set-gcrypt-thread-callback.patch "
SRC_URI += " file://0003-Remove-obsolete-function-gcry_md_start_debug.patch "

gpg2_files += "/usr/lib/*"

EXTRA_OECONF += " --disable-doc "
