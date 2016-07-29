mynewhandle = open("tenth.txt", "r")
import csv
with open('MYFILE.csv', 'w', newline='') as csvfile:
	c= csv.writer(csvfile, delimiter=' ', quotechar='|', quoting=csv.QUOTE_MINIMAL)
while True:
	theline = mynewhandle.readline()
	if len(theline)==0:
		break
	ss=theline
	if ss[0] == 'R':
		fd=open("MYFILE.csv",'a')
		fd.write(ss[0:7]+","+ss[8:22]+","+ss[41:44]+","+ss[45:48]+","+ss[49:53]+",")
		fd.write(ss[41:44]+","+ss[45:48]+","+ss[49:53]+","+ss[41:44]+","+ss[45:48]+","+ss[49:53]+","+ss[41:44]+","+ss[45:48]+","+ss[49:53]+",")
		fd.write(ss[41:44]+","+ss[45:48]+","+ss[49:53]+","+ss[111:115]+","+ss[117:120]+",")
		break
while True:
	theline = mynewhandle.readline()
	if len(theline)==0:
		break
	ss=theline
	if ss[0]==' ' and len(ss) >20:
		if ss[20] =='P':
			fd.write("Part_2A,,,,,,Part_2B,,Part_2C,,Part_2D,,,,,,,,Part_3A,,,,Part_3B,,,,\n")
			fd.close()
			break
while True:                            # Keep reading forever
    theline = mynewhandle.readline()   # Try to read next line
    if len(theline) == 0:              # If there are no more lines
        break
    ss = theline
    ss1 = ""
    roll = ""
    name = ""
    sub1 = ""
    mrk1 = ""
    grd1 = ""

    sub2 = ""
    mrk2 = ""
    grd2 = ""

    sub3 = ""
    mrk3 = ""
    grd3 = ""

    sub4 = ""
    mrk4 = ""
    grd4 = ""

    sub5 = ""
    mrk5 = ""
    grd5 = ""
    stt = ""
    cpi = ""


    tt = ss.upper()
    if ss[0] <= '9' and ss[0] >= '0':
     	for kapil in ss  :
     		if kapil == ' ' :
     			break
     		roll = roll + kapil
     	#print (roll)
     	ss=ss.replace(roll, "", 1)
     	
     	for kapil in ss :
     		if kapil == '1' or kapil == '0' :
     			break
     		name = name + kapil
     	#print (name)
     	name=name.replace( " ", "", 1)
     	ss=ss.replace(name, "", 1)
     	#print (ss)
     	cpi = "NA"

     	sub1 = ss[0:4]
     	ss=ss.replace(sub1, "", 1)
     	mrk1 = mrk1 + ss[0:5]
     	ss=ss.replace(mrk1, "", 1)
     	grd1 = grd1+ss[0:5]
     	ss=ss.replace(grd1, "", 1)


     	sub2 = sub2 + ss[0:4]
     	ss=ss.replace(sub2, "", 1)
     	mrk2 = mrk2 + ss[0:5]
     	ss=ss.replace(mrk2, "", 1)
     	grd2 = grd2+ss[0:5]
     	ss=ss.replace(grd2, "", 1)

     	sub3 = sub3 + ss[0:4]
     	ss=ss.replace(sub3, "", 1)
     	mrk3 = mrk3 + ss[0:5]
     	ss=ss.replace(mrk3, "", 1)
     	grd3 = grd3+ss[0:5]
     	ss=ss.replace(grd3, "", 1)

     	sub4 = sub4 + ss[0:4]
     	ss=ss.replace(sub4, "", 1)
     	mrk4 = mrk4 + ss[0:5]
     	ss=ss.replace(mrk4, "", 1)
     	grd4 = grd4 + ss[0:5]
     	ss=ss.replace(grd4, "", 1)

     	sub5 = sub5 + ss[0:4]
     	ss=ss.replace(sub5, "", 1)
     	mrk5 = mrk5 + ss[0:5]
     	ss=ss.replace(mrk5, "", 1)
     	grd5 = grd5 + ss[0:5]
     	ss=ss.replace(grd5, "", 1)
     	stt = stt + ss[0:5]
     	ss=ss.replace(stt, "", 1)
     	#print(stt)
     	if stt == " QUAL":
     		cpi=ss[0:5]
     	fd = open('MYFILE.csv','a')
     	ssl=roll+","+name+","+sub1+","+mrk1+","+grd1+","+sub2+","+mrk2+","+grd2+","+sub3+","+mrk3+","+grd3
     	ssl=ssl+","+sub4+","+mrk4+","+grd4+","+sub5+","+mrk5+","+grd5+","+stt+","+cpi+","
     	fd.write(ssl)
     	fd.close()
    if ss[0] == ' ' and len(ss) > 20:
    	if ss[20] == '5':
    		ss=ss.strip()
    		ss=ss.replace("  ",",")
    		ss=ss.replace(" ",",")
    		ss=ss+"\n"
    		fd=open('MYFILE.csv','a')
    		fd.write(ss)
    		fd.close()
     	
        

             



mynewhandle.close()