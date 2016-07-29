mynewhandle = open("test_code.cpp", "r")
f=0
out = open("comment_output.txt","w")
while True:                            # Keep reading forever
    theline = mynewhandle.readline()   # Try to read next line
    if len(theline) == 0:              # If there are no more lines
        break
    strm = theline
    str1 = "//"  
    str2 = "/*"
    str3 = "*/"

    a = strm.find(str1)
    b = strm.find(str2)
    c = strm.find(str3)
    if f == 0:
    	if a != -1:
    		for i in range(a,len(strm)-1):
    			out.write(strm[i])
    		out.write('\n')
    	if b!=-1:
    		if c!=-1:
    			for i in range(b,len(strm)):
    				out.write(strm[i])
    		else:
    			f=1
    			for i in range(b,len(strm)):
    				out.write(strm[i])
    else:
    	if c!=-1:
    		f=0
    		strm=strm.replace(" ","", 11)
    		c=strm.find(str3)
    		for i in range(0,c+2):
    			out.write(strm[i])
    		out.write('\n')
    	else:
    		strm=strm.replace(" ","", 11)
    		out.write(strm)







    # Now process the line we've just read
    #print(theline, end="")

mynewhandle.close()