do_configure_prepend() {
    # Fix configure error: "error: required file './ABOUT-NLS' not found"
    sed -i 's/^AM_INIT_AUTOMAKE$/AM_INIT_AUTOMAKE(\[foreign\])/' configure.ac
}
