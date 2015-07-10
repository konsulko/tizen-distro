SUMMARY = "Open IVI packagegroups HMI apps"
LICENSE = "Apache-2.0"
DESCRIPTION = "HMI app suite"

inherit packagegroup

PACKAGES = "\
            packagegroups-hmi-apps \
            "

# HMI apps
RDEPENDS_packagegroups-hmi-apps = " \
                                            openivi-common-app \
                                            openivi-homescreen \
                                            "
