SUMMARY = "Tizen dev tools packagegroups"
LICENSE = "MIT"
DESCRIPTION = "Tizen dev tools packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-dev-tools\
            "

# dev tools fonts packages
RDEPENDS_packagegroup-tizen-dev-tools = " \
                                        attr \
                                        acl \
                                        util-linux-agetty \
                                        strace \
                                        gdb \
                                        lsof \
                                        screen \
                                        ldd \
                                        libcap \
                                        sudo \
                                        connman-client \
                                        git \
                                        python-json \
                                        dlogutil \
                                        "