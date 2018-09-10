reset

set xzeroaxis
set xtics axis
set xrange [-2:2]
set arrow 1 from -1.8,0 to -2,0
set arrow 2 from  1.8,0 to  2,0

set yzeroaxis
set ytics axis
set yrange [-2:2]
set arrow 3 from 0,-1.8 to 0,-2
set arrow 4 from  0,1.8  to 0,2

set border 0

unset xtics
unset ytics

f = 0.76
f(x) = x**2/(4*f) - f


plot f(x) notitle
