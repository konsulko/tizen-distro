inherit autotools 
inherit gtk-doc 
inherit pkgconfig 
inherit gettext

export HOST_SYS
export BUILD_SYS
export STAGING_LIBDIR
export STAGING_INCDIR

#DEPENDS += "gobject-introspection"
#gtk-doc-stub?

# -ldb needs this on some platforms
LDFLAGS += "-lpthread"

# Parallel make shows many issues with this source code.
# Current problems seem to be duplicate execution of the calander/backends
# directories by make resulting in truncated/corrupt .la files
#PARALLEL_MAKE = ""

