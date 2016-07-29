%this file is used to demonstrate the function nullspace
%matrix used is:-
%  |-1   1  1/2|
%A=|1/2 -1  1/2|
%  |1/2  0  -1 |

Anum=[-1,1,1;1,-1,1;1,0,-1];
Aden=[1,1,2;2,1,2;2,1,1];

[xnum,xden]=nullspace(Anum,Aden,3);
%xnum and xden represent numerator and denominator of nullspace vector
disp(xnum);
disp(xden);