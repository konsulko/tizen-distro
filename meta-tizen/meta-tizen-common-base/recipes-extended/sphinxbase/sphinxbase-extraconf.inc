export HOST_SYS
export BUILD_SYS
export STAGING_LIBDIR
export STAGING_INCDIR

inherit pythonnative python-dir

FILES_${PN}-dbg += "${prefix}/lib/python2.7/site-packages/.debug"
  