do_package_prepend() {
    bb.build.exec_func('tizen_copy_manifest', d)
}
