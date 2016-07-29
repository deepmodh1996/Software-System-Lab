function value = f_3(diffx,diffy,v,theta)

 g=9.80665;
  k=0.05;
  
    %value1 is time for required angles
 value1 = (exp((diffx)*k)-1)/(k*(v*cosd(theta)));
 
 %value is the  (yf-rhs) for time=value1 ,theta as provided.
 value = diffy - (log(abs((cos((sqrt(g*k)*value1)-(atan(sqrt(k/g)*v*sind(theta)))))/cos(atan(sqrt(k/g)*v*sind(theta)))))/k);

  %checks the validity of function and returns a specific id .
 if  cos((sqrt(g*k)*value1)-(atan(sqrt(k/g)*v*sind(theta))))<0
 value=1000;
 
 
 endif
  return ;
  endfunction