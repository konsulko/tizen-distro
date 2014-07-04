SRCREV = "36689a76e79bf6e6231f6f03cbfad297d4411588"
PV = "1.6.0+git${SRCPV}"

DEFAULT_PREFERENCE = "100"

SRC_URI = "git://git.yoctoproject.org/pseudo;branch=seebs/xattr"

DEPENDS += "attr"
