SRC_URI += "file://gmp_fix_for_automake-1.12.patch \
            "
acpaths = ""

EXTRA_OECONF += " --enable-cxx=detect"

do_patch_append () {
 # patch are good for tizen PC not tizen IVI.
 cat ${WORKDIR}/gmp_fix_for_automake-1.12.patch | patch -p1 -b --suffix --fuzz=2
}