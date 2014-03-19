SRC_URI += "file://fix_build.patch "

do_patch_append () {
 cat ${WORKDIR}/findutils_fix_doc.patch | patch -p1 -b
 cat ${WORKDIR}/fix_build.patch | patch -p1 -b
}
