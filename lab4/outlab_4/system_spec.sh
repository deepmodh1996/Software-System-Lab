#! /bin/bash

mapfile -t freq < <( cat /proc/cpuinfo | grep "MHz" | cut -d ':' -f2 )
mapfile -t phybits < <( cat /proc/cpuinfo | grep "address" | cut -d ':' -f2 | cut -d 'p' -f1)
mapfile -t virbits < <( cat /proc/cpuinfo | grep "address" | cut -d ':' -f2 | cut -d ',' -f2 | cut -d 'v' -f1)

   printf "%sMHz\n" "${freq[0]}"
   printf "%s\n" "${phybits[0]}"
   printf "%s\n" "${virbits[0]}"



