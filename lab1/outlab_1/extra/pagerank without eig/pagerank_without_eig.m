%In this file repeated multiplication of pagerank vector and C'
%is done to determine pagerank


file = "small.txt";
fid = fopen (file, "r");
i=1;
% matrix A is initialised zero
A=zeros(1000,1000);

while (! feof (fid) )
  %input is taken as string line by line
  text_line = fgetl (fid);
  %string array converted to num array
  B=str2num(text_line); 
  %length of B denotes number of out going edges of page i
  L=length(B);
  
  %forming connectivity matrix  
  for j= 1:L
    A(B(j),i)=1/L;
  endfor
  
  i++;
endwhile
fclose (fid);

%now A is connectivity matrix(C)

B=ones(1000,1000);
A=A+0.00015*B;

%now A=C+(0.15)/n*(1-matrix)

%pagerank vector P is initialised with all elements 1/N
P=ones(1000,1);
for i=1:1000
  P(i,1)=1/1000;
endfor

%P is multiplied by A and normalised till the consecutive values of P
%have norm >= 0.001
while true
  Q=A*P;
  sum=0;
  for j=1:1000
    sum=sum+Q(j,1);  
  endfor
  
  %Q(=A*P) is normalised
  for j=1:1000
    Q(j,1)=(1000*Q(j,1))/sum ; 
  endfor
  
  if norm(P-Q,2)<0.001
      P=Q;
      break;
  endif
  P=Q;
  
endwhile

%maximum of pagerank vector P is taken 20 times to get top 20 pages
for j=1:20
  m=P(1,1);
  index=1;
  for i=1:1000
    if P(i,1)>=m
      index=i;
      m=P(i,1);
    endif
  endfor
  disp(index);
  %each time we determine maximum value , we set it -1 , so that we get second max value
  % in next iteration
  P(index,1)=-1;
 endfor

