%%%%
%%%%  case 1  roots calculated easily as solution of quadratic.
%%%%         extra findrange function(uses binary type algorithm) used to get range around root .
%%%%
%%%%  case 2  and case 3  found ranges by traversing by bruteforce assuming ranges can be more than 2
%%%%

%% input required values
xi=input("give input xi: ");
yi=input("give input yi: ");
xf=input("give input xf: ");
yf=input("give input yf: ");
v=input("give input v: ");


i=0;

% value of required constants
g=9.80665;
k=0.05;

% quadrant take cares if dartboard behind shooter. quadrant=1 implies dartboard behind and viceversa.
quadrant=0;

% as diff of x and y  are relavent better to calculate them 
diffx=xf-xi;
diffy=yf-yi;

% assigns value to quadrant
if  diffx<0
  disp("dartboard behind shooter");
  diffx=0-diffx;
  quadrant=1;
endif

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%------------------CASE 1-------------------%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Calculating required coefficient for quadratic solving 
a=((((g*diffx*diffx)/2)/v)/v);
b=0-(diffx);
c=diffy+a;

% To check nature of roots
D=(b*b)-(4*(a*c));
D1=(b*b)-(4*(a*(c-0.03)));

% both roots exist
if D>0

  s1=(((0-b)-(sqrt(D)))/2)/a;
  s2=(((0-b)+(sqrt(D)))/2)/a;

  s1=atand(s1);
  s2=atand(s2);
  
  %findrange function calculates valid range corresponding to root
  disp("Solution to case 1 is :");
  [pq1,pq2]=findrange(diffx,diffy,v,s1);
  printf("( %.2f,%.2f )\n",pq1,pq2);
  
  [pq1,pq2]=findrange(diffx,diffy,v,s2);
  printf("( %.2f,%.2f )\n",pq1,pq2);
  

else
  % repeated roots case
  if D==0

    s1=(((0-b)/2)/a);
    s1=atand(s1);
    
     %findrange function calculates valid range corresponding to root
     disp("Solution to case 1 is :");
    [pq1,pq2]=findrange(diffx,diffy,v,s1);
    printf("( %.2f,%.2f )\n",pq1,pq2);
    disp("ranges above");
    
  else
   %cant hit centre of bulls eye. so calculating for lower end of bullseye.
    if D1>=0
    
      s1=(((0-b)-(sqrt(D1)))/2)/a;
      s1=atand(s1);
      
      %findrange function calculates valid range corresponding to root
      disp("Solution to case 1 is :");
      [pq1,pq2]=findrange(diffx,diffy,v,s1);
      printf("( %.2f,%.2f )\n",pq1,pq2);
      disp("ranges above");
      
    else
    %No solution
      disp(D1);
      disp("no solution");
    endif
  endif
endif

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%------------------CASE 1-------------------%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%------------------CASE 2-------------------%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%calculatingrange of theta for which function are valid 
thetavalid=asecd(((v/k)/diffx));

theta=90;
while theta>=thetavalid

  theta=theta-0.01;

endwhile

thetavalid=theta;
theta=0-thetavalid;

% A array to store ranges
% nrange no. of ranges obtained
% c indicates if traversing in a range or not
A=zeros(100,1);
nrange=0;
c=0;

% theta must be between valid range and increase theta by 0.01

while ((thetavalid>=theta)&&((0-thetavalid)<=(0-theta)))&&(theta<90)

y=f_2(diffx,diffy,v,theta);

if(((y<=0.03)&&(y>=(0-0.03)))&&(c==0))
  
  % case 1 start of a new range
  c=1;
  A((2*nrange)+1,1)=theta;
  theta=theta+0.01;
  
continue;
endif


if(((y<=0.03)&&(y>=(0-0.03)))&&(c==1))

  % case 2 traversing through a range.
  theta=theta+0.01;

continue;
endif


if(((y>0.03)||(y<(0-0.03)))&&(c==0))

  % case 3 not traversing through a range 
  theta=theta+0.01;

continue;

endif

if(((y>0.03)||(y<(0-0.03)))&&(c==1))

  % end of a range
  c=0;
  A((2*nrange)+2,1)=theta-0.01;
  nrange++;
  theta=theta+0.01;
  
continue;
endif
endwhile

% completing of an incompleted range
if c==1
A((2*nrange)+1,1)=theta-0.01;
nrange++;
endif

%Printing ranges if soltuion found
i=0;
if nrange==0

  %No solution for given least count
  disp("solution not found for case 2")


else
  disp("Solution for case 2 is: ")
  
  while i<nrange
    % printing values in required format
    printf("(%.2f,%.2f)\n",A((2*i)+1,1),A((2*i)+2,1));
    i++;
  endwhile
endif

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%------------------CASE 2-------------------%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%%%% Method of finding roots first then range around it

%
% 
%
%W=zeros(1000,1);
%ncs=0;
%theta=0-thetavalid;

%while (((thetavalid-0.01)>=theta)&&((0-thetavalid)<=(0-theta)))&&(theta<90)
%
%  if((f_2(diffx,diffy,v,theta))*(f_2(diffx,diffy,v,theta+0.01))<0)
%    W(ncs+1,1)=theta;
%    ncs++;
%  endif
%  theta=theta+0.01;
%endwhile
%
%i=1;
%disp("Ranges by root method");

%while i<(ncs+1)
%
%  [pr1,pr2]=findrange_2(diffx,diffy,v,W(i,1));
%  printf("(%.2f,%.2f)\n",pr1,pr2);
%  i++;
%
%endwhile

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%------------------CASE 3-------------------%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Initialization
% B stores ranges
% nrrange1 stores no. of ranges
% c stores if traversing in a range or not in a range
theta=0-89.99;
B=zeros(100,1);
nrange1=0;
c=0;

% theta must be between valid range and increase theta by 0.01

while ((90>theta)&&((0-90)<(0-theta)))&&(theta<90)

y=f_3(diffx,diffy,v,theta);


if(((y<=0.03)&&(y>=(0-0.03)))&&(c==0))

% case 1 start of a new range
c=1;
B((2*nrange1)+1,1)=theta;
theta=theta+0.01;

continue;
endif

if(((y<=0.03)&&(y>=(0-0.03)))&&(c==1))
  
  % case 2 traversing through a range.
  theta=theta+0.01;

  continue;
endif

if(((y>0.03)||(y<(0-0.03)))&&(c==0))

   % case 3 not traversing through a range 
  theta=theta+0.01;

continue;
endif

if(((y>0.03)||(y<(0-0.03)))&&(c==1))

% end of range
  c=0;
  B((2*nrange1)+2,1)=theta-0.01;
  nrange1++;
  theta=theta+0.01;

continue;
endif
endwhile

% completing of an incompleted range
if c==1
  B((2*nrange1)+2,1)=theta-0.01;
  nrange1++;
endif

% printing values in required format
i=0;
if nrange1==0

  disp("solution not found for case 3");

else

  disp("Ranges for case 3 are: ")
  while i<nrange1
  
  printf("(%.2f,%.2f)\n",B((2*i)+1,1),B((2*i)+2,1));
  i++;

  endwhile
endif


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%------------------CASE 3-------------------%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%