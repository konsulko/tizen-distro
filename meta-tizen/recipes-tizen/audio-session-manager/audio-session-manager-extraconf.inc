pkg_postinst_${PN}() {
    #!/bin/sh -e

    [ "x\$D" == "x" ] && ldconfig
    # Temporary workaround needed to generate the image
    #vconftool set -t int memory/Sound/SoundStatus "0" -g 29 -f -i
}
