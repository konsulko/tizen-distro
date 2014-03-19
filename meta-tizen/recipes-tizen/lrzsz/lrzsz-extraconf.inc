SRC_URI += "file://autotools.patch \
            file://gettext.patch \
            file://lrzsz-check-locale.h.patch \
            file://lrzsz_fix_for_automake-1.12.patch \
            file://makefile.patch \
            "

do_patch_append () {
 cat ${WORKDIR}/autotools.patch | patch -p1
 cat ${WORKDIR}/gettext.patch | patch -p1
 cat ${WORKDIR}/lrzsz-check-locale.h.patch | patch -p1
 cat ${WORKDIR}/lrzsz_fix_for_automake-1.12.patch | patch -p1
 cat ${WORKDIR}/makefile.patch | patch -p1
}


