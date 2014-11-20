SRC_URI= "http://createrepo.baseurl.org/download/${BP}.tar.gz \
          file://fix-native-install.patch \
          file://python-scripts-should-use-interpreter-from-env.patch \
	  file://rpm-createsolvedb.py \
         "