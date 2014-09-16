FILES_${PN} += "/usr/lib/systemd/system/system-server.service"
FILES_${PN} += "/usr/lib/systemd/system/system-server.socket" 

DEPENDS += "heynoti-native"