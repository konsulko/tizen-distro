SECTION = "Graphics & UI Framework/Wayland Window System"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://0001-Added-APIstosupportmultiseatinwayland.patch"

EXTRA_OECONF += "--enable-multiseat"