require recipes-image/images/tizen-core-image-minimal.bb

SUMMARY = "A Tizen ivi image"

LICENSE = "MIT"

DESCRIPTION = "A Tizen ivi image base on Tizen common ."

WESTONSTARTUP="weston-ivi"

CORE_IMAGE_EXTRA_INSTALL += "Modello_AMBSimulator"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Appmanager"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Common"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Dashboard"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Homescreen"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Hvac"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Multimediaplayer"
CORE_IMAGE_EXTRA_INSTALL += "Modello_Nav"
CORE_IMAGE_EXTRA_INSTALL += "Modello_SDL"

CORE_IMAGE_EXTRA_INSTALL += "automotive-message-broker"
CORE_IMAGE_EXTRA_INSTALL += "efl-theme-tizen-hd"
CORE_IMAGE_EXTRA_INSTALL += "festival"
CORE_IMAGE_EXTRA_INSTALL += "genivi-audio-manager"
CORE_IMAGE_EXTRA_INSTALL += "ico-uxf-device-input-controller"
CORE_IMAGE_EXTRA_INSTALL += "ico-uxf-homescreen"

CORE_IMAGE_EXTRA_INSTALL += "ico-uxf-utilities"
CORE_IMAGE_EXTRA_INSTALL += "ico-uxf-weston-plugin"

#CORE_IMAGE_EXTRA_INSTALL += "ico-vic-amb-plugin"
#CORE_IMAGE_EXTRA_INSTALL += "ico-vic-carsimulator"
#CORE_IMAGE_EXTRA_INSTALL += "ico-uxf-homescreen-sample-apps"

CORE_IMAGE_EXTRA_INSTALL += "lemolo"
CORE_IMAGE_EXTRA_INSTALL += "libwebsockets"
CORE_IMAGE_EXTRA_INSTALL += "murphy"
CORE_IMAGE_EXTRA_INSTALL += "node-startup-controller"
CORE_IMAGE_EXTRA_INSTALL += "pulseaudio-module-murphy-ivi"
# TMP Remove rygel
# BTY-36
#CORE_IMAGE_EXTRA_INSTALL += "rygel"
#CORE_IMAGE_EXTRA_INSTALL += "Modello_Phone"
#CORE_IMAGE_EXTRA_INSTALL += "Modello_Installer"

CORE_IMAGE_EXTRA_INSTALL += "sphinxbase"
CORE_IMAGE_EXTRA_INSTALL += "udev-rules-ivi"
CORE_IMAGE_EXTRA_INSTALL += "genivi-shell"
CORE_IMAGE_EXTRA_INSTALL += "weston-ivi-shell"

# Crosswalk
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-crosswalk"

# Time zone
CORE_IMAGE_EXTRA_INSTALL += "tzdata"
