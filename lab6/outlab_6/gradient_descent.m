fexp=input('give function in {double quotes} :');
f=inline(fexp);
%f obtained
xold = 0;
xnew = 5;
yold = 0;
ynew = 5;
alpha = 0.01;
precision = 0.01;

fid = fopen('output.dat','w');

while(distance(xnew,ynew,xold,yold)>precision)
	fprintf(fid,'%f %f %f\n',xnew,ynew,f(xnew,ynew));
	xold = xnew;
	yold = ynew;
	xnew = xold - alpha * ((f(xold+0.0001,yold)-f(xold,yold))/0.0001);
	ynew = yold - alpha * ((f(xold,yold+0.0001)-f(xold,yold))/0.0001);
endwhile

fclose(fid);

fid2 = fopen('temp.dat','w');

fprintf(fid2,'%s',f);

fclose(fid2);
