inherit cmake

B = "${S}"

SRC_URI += "file://0001-PATCH-link-to-the-pthread-library.patch"

do_configure_prepend() {
    # Remove failing expression
    sed -i 's!STRING(REGEX MATCH .*!!g' ${S}/CMakeLists.txt
    sed -i 's!ADD_DEFINITIONS("-DAPI_VERSION=.*!!g' ${S}/CMakeLists.txt

    # Replace undefined variables
    find ${S} -name "CMakeLists.txt" -exec sed -i 's!\${LIB_INSTALL_DIR}!lib!g' {} \;
    find ${S} -name "CMakeLists.txt" -exec sed -i 's!\${INCLUDE_INSTALL_DIR}!/usr/include!g' {} \;

    # Replace macros that aren't automatically expanded
    sed -i 's!@LIB_INSTALL_DIR@!${prefix}/lib!g' ${S}/build/security-server/security-server.pc.in ${S}/build/security-manager/security-manager.pc.in
}

CXXFLAGS += "-std=c++11"
