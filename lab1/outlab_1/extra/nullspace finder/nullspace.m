% this function assumes that A has a null space of dimension 1 ,
% and calculate a corresponding vector
% matrix a is defined using two matrices , Anum and Aden storing numerator and denomenator
% of different elements of A.
function [xnum,xden] = nullspace(Anum,Aden,n)%Anum contains numerators and Aden contains denominator

  i=1;
  while i<=n%converting A into upper triangular matrix
    if Anum(i,i)==0%if pivot point is zero exchange it with a row having non zero pivot point
      for j=i:n 
        if Anum(j,i)!=0  
          for k=i:n
            tmp=Anum(j,k);
            Anum(j,k)=Anum(i,k);
            Anum(i,k)=tmp;
            
            tmp=Aden(j,k);
            Aden(j,k)=Aden(i,k);
            Aden(i,k)=tmp;
          endfor
          break;  
        endif 
      endfor 
    endif
    
    %now Anum(i,i)!=0
    
    for j=i+1:n%making all elements below pivot point zero
      facnum=Anum(j,i)*Aden(i,i);
      facden=Aden(j,i)*Anum(i,i);
      if facden<0
        facden=(-1)*facden;
        facnum=(-1)*facnum;    
      endif
      g=gcd(facden,abs(facnum));
      facnum=facnum/g;
      facden=facden/g;
      
      Anum(j,i)=0;
      Aden(j,i)=1;
      for k=i+1:n
         Anum(j,k)=facden*Aden(i,k)*Anum(j,k)-facnum*Anum(i,k)*Aden(j,k);
         Aden(j,k)=Aden(i,k)*facden*Aden(j,k);
         if Aden(j,k)<0
           Aden(j,k)=(-1)*Aden(j,k);
           Anum(j,k)=(-1)*Anum(j,k);    
         endif
         g=gcd(Aden(j,k),abs(Anum(j,k)));
         Anum(j,k)=Anum(j,k)/g;
         Aden(j,k)=Aden(j,k)/g;
      endfor
      
    endfor
    
    i++;
  endwhile
  
  
  if Anum(n,n)!=0
    disp("error1");
  endif
  
  %x is vector belonging to null space
  xnum=zeros(n,1);
  xden=ones(n,1);
  xnum(n,1)=1;
  i=n-1;
  while i>=1%back substituition
     snum=0;
     sden=1;
     j=i+1;
     while j<=n
       snum=snum*Aden(i,j)*xden(j,1)+sden*Anum(i,j)*xnum(j,1);
       sden=sden*Aden(i,j)*xden(j,1);
       
       if sden<0
          sden=(-1)*sden;
          snum=(-1)*snum;
       endif
       g=gcd(sden,abs(snum));
       snum=snum/g;
       sden=sden/g;
       
       j++;
     endwhile
     
     xnum(i,1)=(-1)*snum*Aden(i,i);
     xden(i,1)=sden*Anum(i,i);
     if xden(i,1)<0
        xden(i,1)=(-1)*xden(i,1);
        xnum(i,1)=(-1)*xnum(i,1);
     endif
     g=gcd(xden(i,1),abs(xnum(i,1)));
     xnum(i,1)=xnum(i,1)/g;
     xden(i,1)=xden(i,1)/g;
  
     i--;  
  endwhile
  % x is basis of null space(since null space of A has dimension 1)
  return;
endfunction