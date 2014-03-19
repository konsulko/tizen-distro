DEPENDS += "ncurses-native"
DEPENDS += "readline-native"

SRC_URI += "file://0001-Fix-cross-build.patch "

do_patch_append () {
 cat ${WORKDIR}/0001-Fix-cross-build.patch | patch -p1 -b
}