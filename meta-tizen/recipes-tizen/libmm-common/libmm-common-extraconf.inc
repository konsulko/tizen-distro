do_compile() {
 cd ${S}
  LANG=C
  export LANG
  unset DISPLAY
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  autotools_do_configure
  oe_runmake ${PARALLEL_MAKE}

}


