pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    vconftool set -tf int db/bluetooth/status "0" -g 6520
    vconftool set -tf int file/private/bt-service/flight_mode_deactivated "0" -g 6520 -i
    # Temporary workaround needed to generate the image
    #vconftool set -tf string memory/bluetooth/sco_headset_name "" -g 6520 -i
    #vconftool set -tf int memory/bluetooth/device "0" -g 6520 -i
    #vconftool set -tf int memory/bluetooth/btsco "0" -g 6520 -i
}
