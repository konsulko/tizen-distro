inherit useradd

USERADD_PACKAGES = "${PN}"

GROUPADD_PARAM_${PN} = "-g 191 display;-g 100 users"

USERADD_PARAM_${PN} = "  -d /run/display -m  -u 115  -g display -G users  -s /bin/false display; "
USERADD_PARAM_${PN} += " -d /home/alice -m -u 5001   -g users   -G display -r -s /bin/sh alice; "
USERADD_PARAM_${PN} += " -d /home/bob   -m -u 5002   -g users   -G display -r -s /bin/sh bob; "
USERADD_PARAM_${PN} += " -d /home/carole -m -u 5003   -g users   -G display -r -s /bin/sh carole; "
USERADD_PARAM_${PN} += " -d /home/guest -m -u 9999   -g users   -G display -r -s /bin/sh guest "

