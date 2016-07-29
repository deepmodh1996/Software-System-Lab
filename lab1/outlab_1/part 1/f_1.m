function value = f_1(diffx,diffy,v,theta)
  
  g=9.80665;
  
  %value1 is time for required angles
  value1=((diffx)/v)*secd(theta);
  
  %value is the  (yf-rhs) for time=value1 ,theta as provided.
  value=diffy+((g*value1*value1)/2)-(v*value1*sind(theta));
  
  return ;
  endfunction