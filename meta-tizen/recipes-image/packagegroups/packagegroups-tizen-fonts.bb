SUMMARY = "Tizen fonts packagegroups"
LICENSE = "(BitstreamVera and LGPLv2.0+)"
DESCRIPTION = "Pango and ttf fonts packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-fonts-ttf \
            packagegroup-tizen-fonts-pango \
            "

# ttf fonts packages
RDEPENDS_packagegroup-tizen-fonts-ttf = "\
                                        ttf-dejavu-common \
                                        ttf-dejavu-sans \
                                        ttf-dejavu-sans-condensed \
                                        ttf-dejavu-sans-mono \
                                        ttf-dejavu-serif \
                                        ttf-dejavu-serif-condensed \
                                        "

# Pango modules
RDEPENDS_packagegroup-tizen-fonts-pango = " \
                                            pango-module-basic-fc \
                                            pango-module-arabic-lang \
                                            pango-module-indic-lang \
                                            "
