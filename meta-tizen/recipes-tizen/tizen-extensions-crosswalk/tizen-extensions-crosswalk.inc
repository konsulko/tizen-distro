DESCRIPTION = "Tizen Web APIs implemented using Crosswalk"
HOMEPAGE = "http://nohomepage.org"
SECTION = "Development/Libraries"
LICENSE = "BSD-3-Clause"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "tizen-extensions-crosswalk-bluetooth-demo"
PACKAGES += "tizen-extensions-crosswalk"
PACKAGES += "tizen-extensions-crosswalk-examples"
PACKAGES += "tizen-extensions-crosswalk-system-info-demo"

tizen-extensions-crosswalk-bluetooth-demo_files = ""
tizen-extensions-crosswalk-bluetooth-demo_files += "/usr/bin/tizen-extensions-crosswalk-bluetooth-demo"
tizen-extensions-crosswalk-bluetooth-demo_files += "/opt/share/packages/tizen-extensions-crosswalk-bluetooth-demo.xml"
tizen-extensions-crosswalk-bluetooth-demo_files += "/opt/share/icons/default/small/tizen-extensions-crosswalk-bluetooth-demo.png"
tizen-extensions-crosswalk-bluetooth-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/tizen/*.html"
tizen-extensions-crosswalk-bluetooth-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/tizen/css/*.css"
tizen-extensions-crosswalk-bluetooth-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/tizen/js/*.js"
tizen-extensions-crosswalk-bluetooth-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/tizen/images/*.png"

tizen-extensions-crosswalk_files = ""
tizen-extensions-crosswalk_files += "/usr/bin/tizen-extensions-crosswalk"
tizen-extensions-crosswalk_files += "/usr/lib/tizen-extensions-crosswalk/libtizen*.so"

tizen-extensions-crosswalk-examples_files = ""
tizen-extensions-crosswalk-examples_files += "/usr/bin/tizen-extensions-crosswalk-examples"
tizen-extensions-crosswalk-examples_files += "/opt/share/packages/tizen-extensions-crosswalk-examples.xml"
tizen-extensions-crosswalk-examples_files += "/opt/share/icons/default/small/tizen-extensions-crosswalk-examples.png"
tizen-extensions-crosswalk-examples_files += "/usr/share/tizen-extensions-crosswalk/examples/*.html"
tizen-extensions-crosswalk-examples_files += "/usr/share/tizen-extensions-crosswalk/examples/js/*.js"

tizen-extensions-crosswalk-system-info-demo_files = ""
tizen-extensions-crosswalk-system-info-demo_files += "/usr/bin/tizen-extensions-crosswalk-system-info-demo"
tizen-extensions-crosswalk-system-info-demo_files += "/opt/share/packages/tizen-extensions-crosswalk-system-info-demo.xml"
tizen-extensions-crosswalk-system-info-demo_files += "/opt/share/icons/default/small/tizen-extensions-crosswalk-system-info-demo.png"
tizen-extensions-crosswalk-system-info-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/system_info/*.html"
tizen-extensions-crosswalk-system-info-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/system_info/css/*.css"
tizen-extensions-crosswalk-system-info-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/system_info/js/*.js"
tizen-extensions-crosswalk-system-info-demo_files += "/usr/share/tizen-extensions-crosswalk/demos/system_info/images/*.png"

FILES_${PN}-bluetooth-demo = "${tizen-extensions-crosswalk-bluetooth-demo_files}"
FILES_${PN} = "${tizen-extensions-crosswalk_files}"
FILES_${PN}-examples = "${tizen-extensions-crosswalk-examples_files}"
FILES_${PN}-system-info-demo = "${tizen-extensions-crosswalk-system-info-demo_files}"

PKG_tizen-extensions-crosswalk-bluetooth-demo= "tizen-extensions-crosswalk-bluetooth-demo"
PKG_tizen-extensions-crosswalk= "tizen-extensions-crosswalk"
PKG_tizen-extensions-crosswalk-examples= "tizen-extensions-crosswalk-examples"
PKG_tizen-extensions-crosswalk-system-info-demo= "tizen-extensions-crosswalk-system-info-demo"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require tizen-extensions-crosswalk-rdepends.inc
require tizen-extensions-crosswalk-depends.inc
require tizen-extensions-crosswalk-extraconf.inc
