%In this file eigs function is used to calculate pagerank
%In a different file an implementation is given which does not use eig function

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

[V,a] = eigs(A,1,1.15);

%a is eigen value of matrix A (which is around 1.15)

for i=1:1000
   %since eigenvector given by eigs function has negative elements
   %all elements are multiplied by -1
   V(i,1)=(-1)*V(i,1);
endfor

%maximum of eigenvector V is taken 20 times to get top 20 pages
for j=1:20
  m=V(1,1);
  index=1;
  for i=1:1000
    if V(i,1)>=m
      index=i;
      m=V(i,1);
    endif
  endfor
  disp(index);
  %each time we determine maximum value , we set it -1 , so that we get second max value
  % in next iteration
  V(index,1)=-1;
 endfor

