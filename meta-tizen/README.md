Create a Tizen Common x86_64 image with Yocto
=============================================

Target: Haswell/Ivy CPU

# Create your working directory
Create a working directory (for example "${HOME}/yocto","/mnt/ssd","/tmp"):
	WORKINGDIR=${HOME}/yocto
	mkdir -p ${WORKINGDIR}
	cd ${WORKINGDIR}

Create a download directory (optional). It will act as a common download
directory amongst projects:

	mkdir -p ${WORKINGDIR}/downloads

# Download sources

Downlaod Poky (patched version for rpm 4 support):
	git clone git@github.com:eurogiciel-oss/poky.git

Download Intel layers:
	git clone git://git.yoctoproject.org/meta-intel

Download openembedded layers:

	git clone git://git.openembedded.org/meta-openembedded

Download tizen layer:

	git clone git@github.com:eurogiciel-oss/meta-tizen.git

# Configuration

Configure the environment:
	BUILDID="alice"
	cd ${WORKINGDIR}/poky
	source ./oe-init-build-env build-${BUILDID}

# Configuration files

## conf/bblayer.conf

This file contains the list of the layers in which poky has to search
for the recipes.

	BBPATH = "${TOPDIR}"
	BBFILES ?= ""

	WORKINGDIR=${HOME}/yocto

	BBLAYERS ?= " \
	  ${WORKINGDIR}/poky/meta \
	  ${WORKINGDIR}/poky/meta-yocto \
	  ${WORKINGDIR}/poky/meta-yocto-bsp \
	  ${WORKINGDIR}/meta-intel \
	  ${WORKINGDIR}/meta-intel/meta-isg/meta-haswell-wc \
	  ${WORKINGDIR}/meta-openembedded/meta-efl \
	  ${WORKINGDIR}/meta-openembedded/meta-oe \
	  ${WORKINGDIR}/meta-openembedded/meta-multimedia \
	  ${WORKINGDIR}/meta-openembedded/meta-ruby \
	  ${WORKINGDIR}/meta-openembedded/meta-systemd \
	  ${WORKINGDIR}/meta-tizen \
	  "
	#For Arch haswell
	#BBLAYERS_append = "${WORKINGDIR}/meta-intel/meta-haswell-wc "
	#For Arch Ivy
	BBLAYERS_append = "${WORKINGDIR}/meta-intel/meta-romley "

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
	DL_DIR ?= "${WORKINGDIR}/downloads"

Setting the download directory DL_DIR to a directory shared amongst
projects prevents common data from being downloaded for each project.

Terminal emulator:
	OE_TERMINAL = "screen"

The terminal emulator you want to use.

# WARNING' tmp add to /etc/sudoers 'WARNING
1)
  sudoedit /etc/sudoers
  ronanguirec ALL=(ALL) NOPASSWD: ALL

2)
  bitbake tar-replacement-native

# Build the Tizen Common image
	tizen-common-core-image-minimal-dev

Which gives:
	1) bitbake -kv tizen-common-core-image-minimal-dev
	2) runqemu qemux86-64 tizen-common-core-image-minimal

The generate image can be found in tmp/deploy/images/${MACHINE}
