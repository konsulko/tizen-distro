SUMMARY = "Tizen IVI packagegroups ICO"
LICENSE = "Apache-2.0"
DESCRIPTION = "ICO  packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-ivi-ico \
            "

# ICO packages
RDEPENDS_packagegroup-tizen-ivi-ico = " \
                                        ico-uxf-device-input-controller \
                                        ico-uxf-homescreen \
                                        ico-uxf-homescreen-sample-apps \
                                        ico-uxf-utilities \
                                        ico-uxf-weston-plugin \
                                        ico-vic-amb-plugin \
                                        ico-vic-carsimulator \
                                        "