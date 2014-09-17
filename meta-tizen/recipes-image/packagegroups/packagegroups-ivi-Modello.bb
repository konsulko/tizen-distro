SUMMARY = "Tizen IVI packagegroups Modello"
LICENSE = "Apache-2.0"
DESCRIPTION = "Modello packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-ivi-modello \
            "

# Modello modules
# To add: "Modello_Phone"
RDEPENDS_packagegroup-tizen-ivi-modello = " \
                                            Modello_Installer-xwalk \ 
                                            Modello_AMBSimulator \
                                            Modello_Appmanager \
                                            Modello_Common \
                                            Modello_Dashboard \
                                            Modello_Homescreen \
                                            Modello_Hvac \
                                            Modello_Multimediaplayer \
                                            Modello_Nav \
                                            Modello_SDL \
                                            "
