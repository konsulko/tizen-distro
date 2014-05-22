SRC_URI += "file://fix-include-directories-in-CMakeList.txt.patch"


privacy-manager-client_files = ""
privacy-manager-client_files += "privacy-manager-client.manifest"
privacy-manager-client_files += "${prefix}/lib/libprivacy-manager-client.so.*"
privacy-manager-client_files += "${prefix}/share/privacy-manager/privacy-filter-list.ini"
privacy-manager-client_files += "${prefix}/lib/libprivileges.so"
privacy-manager-client_files += "${prefix}/lib/systemd/system/multi-user.target.wants"

privacy-manager-server_files = ""
privacy-manager-server_files += "privacy-manager-server.manifest"
privacy-manager-server_files += "${prefix}/lib/libprivacy-manager-server.so.*"
privacy-manager-server_files += "/opt/dbspace/.privacylist.db"
privacy-manager-server_files += "${prefix}/bin/*"

privacy-manager-server-dev_files = ""
privacy-manager-server-dev_files += "${prefix}/include/privacy_manager/server/privacy_manager_daemon.h"
privacy-manager-server-dev_files += "${prefix}/lib/pkgconfig/privacy-manager-server.pc"
privacy-manager-server-dev_files += "${prefix}/lib/libprivacy-manager-server.so"

capi-security-privacy-manager_files = ""
capi-security-privacy-manager_files += "${prefix}/lib/libcapi-security-privacy-manager.so.*"
capi-security-privacy-manager_files += "capi-security-privacy-manager.manifest"

privacy-manager-client-dev_files = ""
privacy-manager-client-dev_files += "privacy-manager-client-devel.manifest"
privacy-manager-client-dev_files += "${prefix}/include/*"
privacy-manager-client-dev_files += "${prefix}/lib/pkgconfig/privacy-manager-client.pc"
privacy-manager-client-dev_files += "${prefix}/lib/libprivacy-manager-client.so"

capi-security-privacy-manager-dev_files = ""
capi-security-privacy-manager-dev_files += "capi-security-privacy-manager-devel.manifest"
capi-security-privacy-manager-dev_files += "${prefix}/include/privacymgr/*.h"
capi-security-privacy-manager-dev_files += "${prefix}/lib/libcapi-security-privacy-manager.so"
capi-security-privacy-manager-dev_files += "${prefix}/lib/pkgconfig/capi-security-privacy-manager.pc"


INSANE_SKIP_${PN} = "already-stripped"

FILES_privacy-manager-client = "${privacy-manager-client_files}"
FILES_${PN} = "${privacy-manager-server_files}"
FILES_${PN}-dev = "${privacy-manager-server-dev_files}"
FILES_capi-security-privacy-manager = "${capi-security-privacy-manager_files}"
FILES_privacy-manager-client-dev = "${privacy-manager-client-dev_files}"
FILES_capi-security-privacy-manager-dev = "${capi-security-privacy-manager-dev_files}"

PKG_privacy-manager-client= "privacy-manager-client"
PKG_privacy-manager-server= "privacy-manager-server"
PKG_privacy-manager-server-dev= "privacy-manager-server-dev"
PKG_capi-security-privacy-manager= "capi-security-privacy-manager"
PKG_privacy-manager-client-dev= "privacy-manager-client-dev"
PKG_capi-security-privacy-manager-dev= "capi-security-privacy-manager-dev"
