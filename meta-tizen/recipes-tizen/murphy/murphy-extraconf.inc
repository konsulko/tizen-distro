EXTRA_OECONF = " $CONFIG_OPTIONS --with-dynamic-plugins=$DYNAMIC_PLUGINS"

do_compile_append() {
    make clean
    make ${PARALLEL_MAKE} $V
}