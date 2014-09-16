inherit autotools gtk-doc pkgconfig gettext

# -ldb needs this on some platforms
LDFLAGS += "-lpthread"

# Parallel make shows many issues with this source code.
# Current problems seem to be duplicate execution of the calander/backends
# directories by make resulting in truncated/corrupt .la files
#PARALLEL_MAKE = ""

