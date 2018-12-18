ldapsearch -x  "(uid=z*)" cn | grep cn  | sed "s/cn: //" | sort -r | grep Z
