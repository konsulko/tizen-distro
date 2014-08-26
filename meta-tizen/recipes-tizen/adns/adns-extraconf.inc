do_configure_prepend() {
    sed -i 's@AC_MSG_WARN(\[tsearch missing - not building client program(s) $PROGS_IF_TSEARCH\])@@' configure.in
    sed -i 's@AC_MSG_WARN(\[inet_aton is in libresolv, urgh.  Must use -lresolv.\])@@' configure.in
}