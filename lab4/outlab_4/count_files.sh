#! /bin/bash





Numo=$(ls -l $(pwd) | grep -c ^-)
Numd=$(ls -l $(pwd) | grep -c ^d)


echo "$Numo"

echo "$Numd"

exit
