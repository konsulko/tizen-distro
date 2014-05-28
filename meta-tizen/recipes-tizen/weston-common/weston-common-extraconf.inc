inherit useradd

FILESEXTRAPATHS_prepend := "${THISDIR}/weston-common"

SRC_URI += "file://0001-Fix-path-to-binary-ln-and-chmod.patch"

USERADD_PACKAGES = "${PN}"

GROUPADD_PARAM_${PN} = "-g 191 display;-g 100 users;-g 1004 input;-g 190 systemd-journal;-g 54 lock"

USERADD_PARAM_${PN} = "  -d /run/display -m  -u 115  -g display -G users,input,tty,display  -s /bin/sh display; "
USERADD_PARAM_${PN} += " -d /home/alice -m -u 5001   -g users   -G display -r -s /bin/sh alice; "
USERADD_PARAM_${PN} += " -d /home/bob   -m -u 5002   -g users   -G display -r -s /bin/sh bob; "
USERADD_PARAM_${PN} += " -d /home/carole -m -u 5003   -g users   -G display -r -s /bin/sh carole; "
USERADD_PARAM_${PN} += " -d /home/guest -m -u 9999   -g users   -G display -r -s /bin/sh guest "

pkg_postinst_${PN} () {
for user in alice bob carol app guest; do
	for appdir in desktop manifest dbspace; do
		mkdir -p ${D}/home/$user/.applications/$appdir
	done
	find ${D}/home/$user/ -type d -exec chsmack -a User {} \;
	chown -R $user:users ${D}/home/$user/
done
}
