%given root r of function f this function
%returns range [a,b] so that |f(x)|<0.003

function [a,b]= findrange (diffx,diffy,v,r)%input is root r and parameters used to calculate f2

   %------ finding upper limit -----%
   i=r;
   j=r+0.01;
   d=0.01;
   
   %we want i,j so that |f(i)|<=0.03&& |f(j)|>0.03
   %so we iterate till |f(j)|<=0.03 
   while abs(f_1(diffx,diffy,v,j))<=0.03
     d=d*2;
     i=j;
     j=j+d;
     
   endwhile
   
   % |f(i)|<=0.03&& |f(j)|>0.03
   while(j>i+0.01)%binary search to find i,j such that |f(i)|<=0.03&& |f(j)|>0.03&&j==i+0.01
      mid=(j+i)/2;
      if abs(f_1(diffx,diffy,v,mid))<=0.03
         i=mid;
      else
         j=mid;
      endif
   endwhile
   b=i;
   %here b=i is our upper limit
   
   %------- finding lower limit ------%
   
   i=r;
   j=r-0.01;
   d=0.01;
   %we want i,j so that |f(i)|<=0.03&& |f(j)|>0.03
   %so we iterate till |f(j)|<=0.03 
   while abs(f_1(diffx,diffy,v,j))<=0.03
     d=d*2;
     i=j;
     j=j-d;   
   endwhile
   
   % f(i)<=0.03&& f(j)>0.03
   while(j<i-0.01)%binary search to find i,j such that |f(i)|<=0.03&& |f(j)|>0.03&&j==i-0.01
      mid=(j+i)/2;
      if abs(f_1(diffx,diffy,v,mid))<=0.03
         i=mid;
      else
         j=mid;
      endif
   endwhile
   a=i;
   %here a=i is our lower limit
   return;
   
endfunction