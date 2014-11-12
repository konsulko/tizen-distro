export CFLAGS+=" --fPIC"

do_prep_append() {
 sed -i "s@\$ld -shared@${CXX}  -shared@g"  ${S}/tools/gyp/pylib/gyp/generator/ninja.py
}

do_compile_prepend() {

 CC_host="gcc"; export CC_host
 CXX_host="g++"; export CXX_host

 LD="${CXX}" export LD
 CC="${CC}" export CC
 CXX="${CXX}" export CXX
}