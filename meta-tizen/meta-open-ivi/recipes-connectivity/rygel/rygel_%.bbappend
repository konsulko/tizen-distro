# Disable everything but the media-export plugin, add the lms plugin
PACKAGECONFIG = "media-export lms"
PACKAGECONFIG[lms] = "--enable-lms-plugin,--disable-lms-plugin,sqlite3"

# LightMediaScanner plugin patches
SRC_URI += "file://0001-Add-LightMediaScanner-plugin.patch \
            file://0002-lms-add-C-source-files.patch \
            "
