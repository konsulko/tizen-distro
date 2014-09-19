FILES_${PN} += "/usr/lib/systemd/system/system-server.service"
FILES_${PN} += "/usr/lib/systemd/system/system-server.socket" 


inherit tizen_cmake

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 
 
 
}