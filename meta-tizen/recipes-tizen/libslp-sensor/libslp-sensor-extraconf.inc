PACKAGES += " libsensor "
PACKAGES += " libsensor-dev "

libsensor_files = ""
libsensor_files += "sensor.manifest"
libsensor_files += "${prefix}/lib/libsensor.so.*"

libsensor-dev_files = ""
libsensor-dev_files += "sensor-devel.manifest"
libsensor-dev_files += "${prefix}/include/sensor/*.h"
libsensor-dev_files += "${prefix}/lib/libsensor.so"
libsensor-dev_files += "${prefix}/lib/pkgconfig/sensor.pc"

FILES_${PN} = "${libsensor_files}"
FILES_${PN}-dev = "${libsensor-dev_files}"

PKG_libsensor= "libsensor"
PKG_libsensor-dev= "libsensor-dev"
