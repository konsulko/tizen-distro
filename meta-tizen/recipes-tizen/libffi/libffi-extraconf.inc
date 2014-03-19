do_install_append () {
 for sub_man in $(seq 1 9) 0p 1p 3p 3pm n ;do
  DATA_DIR=${D}/usr/share/man/man${sub_man}
  if [ -d ${DATA_DIR} ]; then
   find ${DATA_DIR} -name \*.${sub_man} -exec gzip {} \;
  fi
 done
}