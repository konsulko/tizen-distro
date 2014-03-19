DESCRIPTION = "Tizen Buffer Manager - exynos4412 backend"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "MIT"

PROVIDES = ""

PACKAGES = ""
PACKAGES += "libtbm-exynos4412"

libtbm-exynos4412_files = ""
libtbm-exynos4412_files += "/usr/lib/bufmgr/libtbm_*.so*"

FILES_${PN} = "${libtbm-exynos4412_files}"

PKG_libtbm-exynos4412= "libtbm-exynos4412"

SRC_URI = ""

inherit tizenBuildUtils

S = "${WORKDIR}/git"

require libtbm-exynos4412-rdepends.inc
require libtbm-exynos4412-depends.inc
require libtbm-exynos4412-extraconf.inc
