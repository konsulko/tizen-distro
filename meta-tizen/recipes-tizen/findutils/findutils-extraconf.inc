SRC_URI += "file://findutils_fix_doc.patch "

do_patch_append () {
 cat ${WORKDIR}/findutils_fix_doc.patch | patch -p1 -b
}
