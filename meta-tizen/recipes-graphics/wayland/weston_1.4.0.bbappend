FILESEXTRAPATHS_prepend := "${THISDIR}/weston"

SRC_URI += "file://0001-Update-to-1.4.0.patch \
            file://0002-This-vfunc-lets-us-read-out-a-rectangle-of-pixels-fr.patch \
            file://0003-compositor-implement-xdg_surface_set_minimized.patch \
            file://0004-compositor-use-Mod-Tab-to-show-raise-minimized-surfa.patch \
            file://0005-toytoolkit-totally-switch-to-xdg-shell-protocol.patch \
            file://0006-packaging-add-weston-editor-weston-subsurfaces-clien.patch \
            file://0007-shell-position-input-panel-layer-above-fullscreen-la.patch \
            file://0008-packaging-add-the-RDP-backend.patch \
            file://0009-packaging-fix-the-RDP-backend-build.patch \
            file://0010-packaging-fix-obs-build.patch \
            file://0011-shell-make-panel-optional-panel-false-in-weston.ini.patch \
            file://0012-shell-1.4.0-Hack-to-allow-selecting-a-default-output.patch \
            file://0013-allow-to-start-weston-with-system-user.patch"
