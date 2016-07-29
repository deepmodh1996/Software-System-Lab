
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%      THIS FUNCTION CALCULATES SOLUTION IN OPTIMIZED FORMAT    %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function [a1,a2] = case2_code (x,y,v)

%solution stores roots of function      
sol=[1,2,3];
% size-1 indicates no. of roots 
size=1;
% d tells about precision
d=10;
% b ensures to delete roots of overlapping range
b=-89.99;

while size<3&&d>=0.01
  val=-88;
  while val+d<89.9
   
    t1=f_2(x,y,v,val);
    t2=f_2(x,y,v,val+d);
    
    % condtion for root to exist btw val and val +d  
      
    if t1*t2<=0
    
      r=search(val,val+d,x,y,v);
       
       % condition to ignore overlapping roots
      if r>b
    
        sol(size)=r;
        size++;
        [a,m] = findrange_2(r,x,y,v);
        b=m;
      endif
    endif
    val=val+d;
    if size>=3
      break;
    endif
    
  endwhile
  d=d/10;
endwhile

a1=sol(1);
a2=sol(2);
return;
   
endfunction