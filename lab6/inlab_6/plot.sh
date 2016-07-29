set term png
set output 'boxWhisker.png'
plot 'b2.dat' using 1:3:2:6:5 with candlesticks title '1:ssh 2:noSsh 3:sshX[1,2].dat' whiskerbars