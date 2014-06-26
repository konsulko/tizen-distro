EXTRA_OEMAKE_class-native = " \
  LIBATTR=yes \
  PAM_CAP=no \
  INDENT=  \
  lib=${@os.path.basename('${libdir}')} \
  RAISE_SETFCAP=no \
"

BBCLASSEXTEND_append = " nativesdk "

DEPENDS_class-native = "attr-native "