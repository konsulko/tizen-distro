Create a Tizen Common x86_64 image with Yocto
=============================================

Target: Haswell/Ivy CPU

# Create your working directory

Create a working directory (for example "~/yocto"):

	mkdir -p ${HOME}/yocto
	cd ${HOME}/yocto

Create a download directory (optional). It will act as a common download
directory amongst projects:

	mkdir -p ${HOME}/yocto/downloads

# Download sources

Downlaod Poky:

	git clone git://git.yoctoproject.org/poky

Download Intel layers:

	git clone git://git.yoctoproject.org/meta-intel

Download openembedded layers:

	git clone git://git.openembedded.org/meta-openembedded

Download tizen layer:

	git clone git@github.com:eurogiciel-oss/meta-tizen.git

# Configuration

Configure the environment:

	cd ${HOME}/yocto/poky
	source ./oe-init-build-env build

# Configuration files

## conf/bblayer.conf

This file contains the list of the layers in which poky has to search
for the recipes.

	# LAYER_CONF_VERSION is increased each time build/conf/bblayers.conf
	# changes incompatibly
	LCONF_VERSION = "6"

	BBPATH = "${TOPDIR}"
	BBFILES ?= ""

	BBLAYERS ?= " \
	  ${HOME}/yocto/poky/meta \
	  ${HOME}/yocto/poky/meta-yocto \
	  ${HOME}/yocto/poky/meta-yocto-bsp \
	  ${HOME}/yocto/meta-intel \
	  ${HOME}/yocto/meta-intel/meta-isg/meta-haswell-wc \
	  ${HOME}/yocto/meta-openembedded/meta-efl \
	  ${HOME}/yocto/meta-openembedded/meta-oe \
	  ${HOME}/yocto/meta-openembedded/meta-multimedia \
	  ${HOME}/yocto/meta-openembedded/meta-ruby \
	  ${HOME}/yocto/meta-openembedded/meta-systemd \
	  ${HOME}/yocto/meta-tizen \
	  "
	#For Arch haswell
	#BBLAYERS += "${HOME}/yocto/meta-intel/meta-haswell-wc"
	#For Arch Ivy
	BBLAYERS += "${HOME}/yocto/meta-intel/meta-romley"

## conf/local.conf

Most of default values can be kept. The one that needs to be changed is:

        #For qemu
	MACHINE ?= "qemux86-64"
        #For haswell
	MACHINE ?= "haswell-wc"
        #For Ivy
	MACHINE ?= "romley-ivb"

Other useful option to set:

Download directory:
	DL_DIR ?= "${HOME}/yocto/downloads"

Setting the download directory DL_DIR to a directory shared amongst
projects prevents common data from being downloaded for each project.

Terminal emulator:
	OE_TERMINAL = "screen"

The terminal emulator you want to use.

# WARNING
# WARNING TMP TRICKS WARNING
# WARNING
Unfortunately we have to copy some files to the meta directory

    ls -1 classes/
     image.bbclass
     rootfs_rpm.bbclass

    ls -1 lib/oe/
     package_manager.py
     smack.py

This should be temporary and will be removed as soon as possible.

    cp ${HOME}/yocto/meta-tizen/classes/* ${HOME}/yocto/poky/meta/classes/
    cp ${HOME}/yocto/meta-tizen/lib/oe/* ${HOME}/yocto/poky/meta/lib/oe/

# Build the Tizen Common image

	bitbake tizen-common-core-image-minimal-dev

Two useful options are:

'k' "Continue as much as possible after an error. While the target that
    failed and anything depending on it cannot be built, as much as
    possible will be built before stopping."

'v' "Output more log message data to the terminal."

Which gives:
	1) bitbake -kv tizen-common-core-image-minimal-dev
	2) runqemu qemux86-64 tizen-common-core-image-minimal

The generate image can be found in tmp/deploy/images/${MACHINE}
