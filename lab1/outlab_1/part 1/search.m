function val = search( a , b , x , y , v )% this function does a binary search to find root between a and b
  i=0;
  
  if f_2(x,y,v,a)==0
    val=a;
    return;
  endif
  
  if f_2(x,y,v,b)==0
    val=b;
    return;
  endif
  
  if f_2(x,y,v,a)<=0
    i=1 ; %in this case invariant is f(a)<=0 && f(b)>0
  else
    i=2 ; %in this case invariant is f(a)>0 && f(b)<=0
  endif
  
  
  while b>a+0.001
    mid=(a+b)/2;
    if i==1
      %f(a)<=0 && f(b)>0
      if f_2(x,y,v,mid)<=0
        %f(mid)<=0 && f(b)>0
        a=mid;
      else
        %f(a)<=0 && f(mid)>0
        b=mid;
      endif
      %f(a)<=0 && f(b)>0
      
    endif
    
    if i==2
      %f(a)>0 && f(b)<=0
      if f_2(x,y,v,mid)<=0
        %f(a)>0 && f(mid)<=0
        b=mid;
      else
        %f(mid)>0 && f(b)<=0
        a=mid;
      endif
      %f(a)>0 && f(b)<=0
    endif
    
  endwhile
  
  if i==1
    val=a;
  else
    val=b;
  endif
  
  return ;
  
  
endfunction