SUMMARY = "Tizen IVI packagegroups"
LICENSE = "Apache-2.0"
DESCRIPTION = "ICO and Modello packages."

inherit packagegroup

PACKAGES = "\
            packagegroup-tizen-ivi-ico \
            packagegroup-tizen-ivi-modello \
            "

# ICO packages
RDEPENDS_packagegroup-tizen-ivi-ico = " \
                                        ico-uxf-device-input-controller \
                                        ico-uxf-homescreen \
                                        ico-uxf-utilities \
                                        ico-uxf-weston-plugin \
                                        ico-vic-amb-plugin \
                                        ico-vic-carsimulator \
                                        ico-uxf-homescreen-sample-apps \
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
