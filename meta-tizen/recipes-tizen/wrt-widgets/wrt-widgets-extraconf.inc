pkg_postinst_${PN}() {
    #!/bin/sh -e

    # setup xwalk preinstall service (inside user session)
    mkdir -p $D${systemd_unitdir}/user/default.target.wants/
    ln -sf ../xwalk_widgets_preinstall.service $D${systemd_unitdir}/user/default.target.wants/

}