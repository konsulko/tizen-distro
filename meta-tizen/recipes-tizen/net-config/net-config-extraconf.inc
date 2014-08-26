pkg_postinst_${PN}() {
    #!/bin/sh -e

    # Temporary remove failing vconftool commands
    #vconftool set -t int memory/dnet/state 0 -i
    #vconftool set -t int memory/wifi/state 0 -i
    #vconftool set -t int memory/wifi/transfer_state 0 -i
    #vconftool set -t int memory/wifi/strength 0 -i
    #vconftool set -t int memory/wifi/bgscan_mode 0 -i
    #vconftool set -t int memory/dnet/wifi 0 -i
    #vconftool set -t int memory/dnet/network_config 0 -i
    #vconftool set -t int memory/dnet/status 0 -i
    #vconftool set -t string memory/dnet/ip "" -i
    #vconftool set -t string memory/dnet/proxy "" -i
    #vconftool set -t string memory/wifi/connected_ap_name "" -i
    #vconftool set -t string db/wifi/bssid_address ""
    #Default Call Statistics
    vconftool set -t int db/dnet/statistics/cellular/totalsnt "0"
    vconftool set -t int db/dnet/statistics/cellular/totalrcv "0"
    vconftool set -t int db/dnet/statistics/cellular/lastsnt "0"
    vconftool set -t int db/dnet/statistics/cellular/lastrcv "0"
    vconftool set -t int db/dnet/statistics/wifi/totalsnt "0"
    vconftool set -t int db/dnet/statistics/wifi/totalrcv "0"
    vconftool set -t int db/dnet/statistics/wifi/lastsnt "0"
    vconftool set -t int db/dnet/statistics/wifi/lastrcv "0"
    vconftool set -t int file/private/wifi/last_power_state "0"
    systemctl daemon-reload
    if [ "$1" == "1" ]; then
        systemctl restart net-config.service
    fi

}