#! /bin/bash/

read -p "Enter string : " name
echo $name>>testfile
awk '{for(i=1;i<=NF;i++) a[$i]++} END {for(k in a) print k,a[k]}' testfile 

rm testfile
exit
