pkg_postinst_alarm-server() {
    #!/bin/sh -e

    vconftool set -t int db/system/timechange 0
    vconftool set -t double db/system/timechange_external 0
    # Temporary workaround needed to generate the image
    #vconftool set -t int memory/system/timechanged 0 -i -g 5000
    systemctl daemon-reload
    if [ $1 == 1 ]; then
        systemctl restart alarm-server.service
    fi
}
