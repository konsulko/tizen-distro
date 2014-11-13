SRC_URI += " file://FixCXXFlag.patch"
SRC_URI += " file://fixHardedPath.patch"

FILES_${PN}-dbg += "/usr/lib/automotive-message-broker/.debug"
