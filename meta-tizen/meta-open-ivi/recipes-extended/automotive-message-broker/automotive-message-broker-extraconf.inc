B="${S}"

INSANE_SKIP_${PN} = "dev-so"

cmake_do_configure_prepend() {
    # Add pthread library to target_link_libraries
    sed -i 's@set(link_libraries -lamb ${libtool_LIBRARY} ${glib_LIBRARIES} ${json_LIBRARIES} -L${CMAKE_CURRENT_BINARY_DIR}/lib)@set(link_libraries -lamb ${libtool_LIBRARY} ${glib_LIBRARIES} ${json_LIBRARIES} -lpthread -L${CMAKE_CURRENT_BINARY_DIR}/lib)@' ${S}/CMakeLists.txt
}

EXTRA_OECMAKE += "-Denable_icecc=OFF"

LDFLAGS += "-lpthread"