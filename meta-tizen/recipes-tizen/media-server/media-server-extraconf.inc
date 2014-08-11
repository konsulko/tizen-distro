SRC_URI += "file://Makefile.am.diff"

do_install_append() {
    rm -fr ${D}/etc
}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    vconftool set -t int db/filemanager/dbupdate "1" -f
    # Temporary workaround needed to generate the image
    #vconftool set -t int memory/filemanager/Mmc "0" -i -f
    #vconftool set -t string db/private/mediaserver/mmc_info "" -f
    vconftool set -t int file/private/mediaserver/scan_internal "1" -f
    vconftool set -t int file/private/mediaserver/scan_directory "1" -f
    chgrp users $D${prefix}/bin/media-data-sdk_create_db.sh
    chgrp -R users $D${prefix}/data/data-media
}
