reset

set xzeroaxis
set xtics axis
set xrange [-5:5]
set arrow 1 from -4,0 to -5,0
set arrow 2 from  4,0 to  5,0

set yzeroaxis
set ytics axis
set yrange [-3:3]
set arrow 3 from 0,-2 to 0,-3
set arrow 4 from  0,2  to 0,3

set border 0

unset xtics
unset ytics

f = 1
f(x) = x**2/(4*f) - f

plot f(x) notitle
