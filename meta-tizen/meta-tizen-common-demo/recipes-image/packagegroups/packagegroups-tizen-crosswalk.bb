SUMMARY = "Tizen Crosswalk packagegroups"
LICENSE = "(BSD-3-Clause and LGPL-2.1+ and Apache-2.0)"
DESCRIPTION = "A tizen specific packagegroup that contains both crosswalk and tizen-extensions-crosswalk packages."

inherit packagegroup

PACKAGES = "packagegroup-tizen-crosswalk"

RDEPENDS_packagegroup-tizen-crosswalk = "\
                                        crosswalk \
                                        tizen-extensions-crosswalk \
                                        wrt-widgets \
                                        "
