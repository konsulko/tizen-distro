do_install_append() {
    # This fails in the post install script
    # Comment on of those two lines to define the desktop background:
    #ln -sf tizen_common.png ${D}/${prefix}/share/backgrounds/tizen/current
    ln -sf golfe-morbihan.jpg ${D}/${prefix}/share/backgrounds/tizen/current
}
