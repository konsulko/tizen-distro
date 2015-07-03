SUMMARY = "Tizen:Common packagegroups Open IVI"
LICENSE = "Apache-2.0"
DESCRIPTION = "Open IVI packages"

inherit packagegroup

PACKAGES = "\
            packagegroup-open-ivi \
            "

# Open IVI modules
RDEPENDS_packagegroup-tizen-ivi-modello = " \
                                            Modello-Installer-xwalk \ 
                                            Modello-AMBSimulator \
                                            Modello-Appmanager \
                                            Modello-Common \
                                            Modello-Dashboard \
                                            Modello-Homescreen \
                                            Modello-Hvac \
                                            Modello-Multimediaplayer \
                                            Modello-Nav \
                                            Modello-SDL \
                                            Modello-Phone \
                                            "
