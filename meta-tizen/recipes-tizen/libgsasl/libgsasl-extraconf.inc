inherit gettext

do_configure_append() {
    sed -i 's/AM_INIT_AUTOMAKE(\[1.10 -Wall -Werror\])/AM_INIT_AUTOMAKE(\[1.10 -Wall\])/' configure.ac
}
