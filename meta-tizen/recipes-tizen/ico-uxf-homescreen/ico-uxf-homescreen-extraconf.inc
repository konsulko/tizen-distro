do_prep() {

    cd ${S}
    chmod -Rf a+rX,u+w,g-w,o-w ${S}
 
    mkdir -p weston
    cp -av ${STAGING_DIR_TARGET}/usr/share/genivi-shell/protocol/*.xml weston/

    ls weston/*.xml | while read protocol ; do
        ${STAGING_BINDIR_NATIVE}/wayland-scanner client-header < "${protocol}" > "${protocol/.xml/}-client-protocol.h"
        ${STAGING_BINDIR_NATIVE}/wayland-scanner code < "${protocol}" > "${protocol/.xml/.c}"
    done
}
