SUMMARY = "Tizen multimedia packagegroups"
LICENSE = "MIT"
DESCRIPTION = "Tizen multimedia packages."

inherit packagegroup

PACKAGES = " \
            packagegroup-tizen-gstreamer\
            "

# gstreamer packages
RDEPENDS_packagegroup-tizen-gstreamer = " \
                                        gstreamer1.0 \
                                        gstreamer1.0-plugins-bad \
                                        gstreamer1.0-plugins-base \
                                        gstreamer1.0-plugins-good \
                                        gstreamer1.0-plugins-ugly \
                                        "
