function value = f_2(diffx,diffy,v,theta)
  
  g=9.80665;
  k=0.05;
  
   %value1 is time for required angles
  value1=(((-1)/k)*(log(1-((k*(diffx))/(v*cosd(theta))))));
  
  %value is the  (yf-rhs) for time=value1 ,theta as provided.
  value= diffy - ((v*sind(theta)*(1-exp((-1)*k*value1)))/k) - ((g*(1-(k*value1)-exp((-1)*k*value1)))/(k*k));
  
  return ;
  endfunction