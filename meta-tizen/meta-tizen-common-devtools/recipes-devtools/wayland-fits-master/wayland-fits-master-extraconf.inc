SRC_URI += "file://temporarily-removeliboostcheckinconfigure.patch"

do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;

  export CXXFLAGS="-DMEDIA_PATH='\"${prefix}/share/media\"'"
  export LDFLAGS="-lboost_system -lboost_filesystem -lboost_thread -lboost_regex -lboost_program_options"

  autotools_do_configure
  make -j16



}

