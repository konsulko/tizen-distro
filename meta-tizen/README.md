Create a Tizen Common x86_64 image with Yocto
=============================================

Target: Haswell CPU

# Create your working directory

Create a working directory (for example "~/yocto"):

	mkdir ~/yocto
	cd ~/yocto

Create a download directory (optional). It will act as a common download
directory amongst projects:

	mkdir ~/downloads

# Download sources

Downlaod Poky:

	git clone git://git.yoctoproject.org/poky

Download Intel layers:

	git clone git://git.yoctoproject.org/meta-intel

Download openembedded layers:

	git clone git://git.openembedded.org/meta-openembedded

Download tizen layer:

	git@github.com:eurogiciel-oss/meta-tizen.git

# Configuration

Configure the environment:

	cd poky
	. ./oe-init-build-env

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
	  /home/user/yocto/poky/meta \
	  /home/user/yocto/poky/meta-yocto \
	  /home/user/yocto/poky/meta-yocto-bsp \
	  /home/user/yocto/meta-intel \
	  /home/user/yocto/meta-intel/meta-isg/meta-haswell-wc \
	  /home/user/yocto/meta-openembedded/meta-efl \
	  /home/user/yocto/meta-openembedded/meta-oe \
	  /home/user/yocto/meta-openembedded/meta-multimedia \
	  /home/user/yocto/meta-openembedded/meta-ruby \
	  /home/user/yocto/meta-openembedded/meta-systemd \
	  /home/user/yocto/meta-tizen \
	  "

## conf/local.conf

Most of default values can be kept. The one that needs to be changed is:

	MACHINE ?= "qemux86-64:wq
	:wq"

Other useful option to set:

Download directory:

	DL_DIR ?= "${HOME}/yocto/downloads"

Setting the download directory DL_DIR to a directory shared amongst
projects prevents common data from being downloaded for each project.

Terminal emulator:

	OE_TERMINAL = "screen"

The terminal emulator you want to use.

Example of a complete configuration file (without comments):

	BB_NUMBER_THREADS ?= "${@oe.utils.cpu_count()}"
	PARALLEL_MAKE ?= "-j ${@oe.utils.cpu_count()}"
	MACHINE ?= "genericx86-64"
	DL_DIR ?= "${HOME}/yocto/downloads"
	BB_GENERATE_MIRROR_TARBALLS = "1"
	DISTRO ?= "poky"
	PACKAGE_CLASSES ?= "package_rpm"
	EXTRA_IMAGE_FEATURES = "debug-tweaks"
	USER_CLASSES ?= "buildstats image-mklibs image-prelink"
	OE_TERMINAL = "screen"
	PATCHRESOLVE = "noop"
	BB_DISKMON_DIRS = "\
		STOPTASKS,${TMPDIR},1G,100K \
		STOPTASKS,${DL_DIR},1G,100K \
		STOPTASKS,${SSTATE_DIR},1G,100K \
		ABORT,${TMPDIR},100M,1K \
		ABORT,${DL_DIR},100M,1K \
		ABORT,${SSTATE_DIR},100M,1K"
		PACKAGECONFIG_pn-qemu-native = "sdl"
		ASSUME_PROVIDED += "libsdl-native"
	CONF_VERSION = "1"

1) Unfortunately we have to copy some files to the meta directory
#ls -1 classes/
    image.bbclass
    rootfs_rpm.bbclass
#ls -1 lib/oe/
package_manager.py
smack.py

This should be temporary and will be removed as soon as possible.

# cp classes/* ${POCKY_PATH}/meta/classes/
# cp lib/oe/* ${POCKY_PATH}/lib/oe/

# Build the Tizen Common image

	bitbake tizen-common-core-image-minimal

Two useful options are:

'k' "Continue as much as possible after an error. While the target that
    failed and anything depending on it cannot be built, as much as
    possible will be built before stopping."

'v' "Output more log message data to the terminal."

Which gives:
	1) bitbake -kv tizen-common-core-image-minimal
	2) runqemu qemux86-64 tizen-common-core-image-minimal bootparams="S"
	3) /etc/smack/init_attr
The generate image can be found in tmp/deploy/images/qemux86-64/
