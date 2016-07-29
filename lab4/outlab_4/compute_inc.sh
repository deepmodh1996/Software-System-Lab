#! /bin/bash



 i=1;
 temp=1;

 str3=$(pwd);
 str4='/population.csv';
 str5=$str3$str4;

for line in $(cat $str5)
do  

  s1=$(echo "$line" | cut -d ',' -f1);
  s2=$(echo "$line" | cut -d ',' -f2);

  if [ $i -ne 1 ]
  then
     echo "$s1,$(($s2-$temp))" >> population_inc.csv;
  fi   

  temp=$s2;
  i=$(($i+1));  

done
