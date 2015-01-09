#!/bin/sh
# Hook to add source component/revision info to commit message
# Parameter:
#   $1 patch-file
#   $2 revision
#   $3 reponame

patchfile=$1
rev=$2
reponame=$3

# Some patches in meta-tizen follow the "component: change" pattern,
# some do not.  Even if used, the component can be misleading because
# it appears in both meta-tizen (as .bbappend file) and other
# components (as .bb file). Therefore always add the "meta-tizen"
# prefix.
sed -i -e "s#Subject: \[PATCH\] \(.*\)#Subject: \[PATCH\] meta-tizen: \1#" $patchfile

if grep -q '^Signed-off-by:' $patchfile; then
    sed -i -e "0,/^Signed-off-by:/s#\(^Signed-off-by:.*\)#\(From meta-tizen rev: $rev\)\n\n\1#" $patchfile
else
    sed -i -e "0,/^---$/s#^---\$#\(From meta-tizen rev: $rev\)\n---#" $patchfile
fi
