%given root r of function f this function
%returns range [a,b] so that |f(x)|<0.003

function [a,b]= findrange_2 (diffx,diffy,v,r)


   i=r;
   j=r+0.01;
   d=0.01;
     
   while abs(f_2(diffx,diffy,v,j))<=0.03
     d=d*2;
     i=j;
     j=j+d;
     
   endwhile
   
   % f(i)<=0.03&& f(j)>0.03
   while(j>i+0.01)
      mid=(j+i)/2;
      if abs(f_2(diffx,diffy,v,mid))<=0.03
         i=mid;
      else
         j=mid;
      endif
   endwhile
   b=i;
   
   i=r;
   j=r-0.01;
   d=0.01;
   while abs(f_2(diffx,diffy,v,j))<=0.03
     d=d*2;
     i=j;
     j=j-d;   
   endwhile
   
   % f(i)<=0.03&& f(j)>0.03
   while(j<i-0.01)
      mid=(j+i)/2;
      if abs(f_2(diffx,diffy,v,mid))<=0.03
         i=mid;
      else
         j=mid;
      endif
   endwhile
   a=i;
  
   return;
   
endfunction