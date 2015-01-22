# The Tizen .spec assumes that Emacs is not installed and therefore
# the lisp files don't get installed. When emacs is installed on the
# host, the .spec derived build rules fail. To remove the host
# environment dependency, disable the check for emacs as done before
# in http://patchwork.openembedded.org/patch/40467/

CACHED_CONFIGUREVARS += "ac_cv_prog_EMACS=no"
