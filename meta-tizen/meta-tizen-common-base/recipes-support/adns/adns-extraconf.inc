SRC_URI += "file://0001-Yocto-fix-remove-unknown-configure-functions.patch"
SRC_URI += "file://0001-Do-not-generate-README-from-README.html.patch"

do_configure_prepend() {
    # Create symlinks to regress/hmacros.i4 and regress/hsyscalls.i4 in root src dir since they are not searched in the regress/ dir.
    # There is probably a better way to manage that such as adding the regress/ dir to the src dirs but it seems to already be the case...
    ln -sfn regress/hmacros.i4 hmacros.i4
    ln -sfn regress/hsyscalls.i4 hsyscalls.i4
    # Remove '`' and ''' around hsyscalls.i4 which prevent the file from being found.
    grep -rl "m4_include" regress | xargs sed -i "s@m4_include(\`hsyscalls.i4')@m4_include(hsyscalls.i4)@g"
}
