#!/bin/bash



tr -d ' \t' <$1 >draco.txt


cat draco.txt | grep '>' | cut -d '>' -f1  > temp
mv temp draco.txt
 
sed '/^\//d' draco.txt > temp
mv temp draco.txt
  
cat draco.txt | grep '#include' | cut -d '<' -f2  > tt
mv tt draco.txt

for line in $(cat "draco.txt")
do
       printf "$line \n"

done
rm draco.txt

exit

