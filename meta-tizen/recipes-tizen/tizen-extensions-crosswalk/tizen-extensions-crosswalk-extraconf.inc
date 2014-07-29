do_prep_append() {
 sed -i "s@\$ld -shared@${TARGET_PREFIX}g++  -shared@g"  ${S}/tools/gyp/pylib/gyp/generator/ninja.py
}

LICENSE = "Apache-2.0"