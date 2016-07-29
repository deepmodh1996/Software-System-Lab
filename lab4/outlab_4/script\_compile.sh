ls -1 *.c >>ftemp.txt

for filename in $(cat ftemp.txt)
do
	file1=$(echo "$filename" | cut -d '.' -f1)
	ext1='.c'
	gcc -o $file1 $file1$ext1 2> temp.txt
	i=$( wc -l < temp.txt )
		if [ $i -eq 0 ]
		then 
			echo "$filename">>good.txt
			rm $file1
		else
			echo "$filename">>bad.txt
		fi
	>temp.txt
done
rm ftemp.txt
rm temp.txt
exit