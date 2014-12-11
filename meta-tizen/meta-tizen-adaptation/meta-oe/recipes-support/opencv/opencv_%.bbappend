SECTION = "Base/Libraries"

# We don't want gtk+
PACKAGECONFIG[gtk] = "-DWITH_GTK=OFF"
