set term png
set output 'plot.png'
DATAFILE="temp.dat"
set macro
TI='`head -1 '.DATAFILE.'`' 
splot "output.dat" u 1:2:3 with lines, \
@TI
