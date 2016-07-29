#!/usr/bin/python3

import csv   
import sys    
import re 

def selected(el):
    return el[-2]=="1"

if len(sys.argv)!=2:
    print("please give exactly one csv filename as input")
    sys.exit()

f = open(sys.argv[1], 'r') 
reader = csv.reader(f) 
L=[] 
i=0
myhash={'A':1}
myhash.clear()
for row in reader:  
    if row[0]=="Sno":
        newheaders=row
        for j in range(0,len(row)):
            myhash[row[j]]=j+1
    match= re.search(r'\D',row[0])
    if match:
        i=i
    else:
        i=i+1
        newrow=row
        tot=0
        for j in range(1,len(row)-1):
            if row[j]!='NA':
                tot=tot+float(row[j])
        newrow.append(tot)
        L.append(newrow)
L1=filter(selected,L)
L=sorted(L,key=lambda x: int((-1)*x[-1]))
L1=sorted(L1,key=lambda x: int((-1)*x[-1]))
print ('no. of students selected are:',len(L1))

for cols in myhash:
    print (cols,myhash[cols],'\n')
f.close()      
newheaders.append("total_marks")
with open('marks_sorted.csv', 'w') as fp:
    a = csv.writer(fp, delimiter=',')
    a.writerow(newheaders)
    a.writerows(L)

