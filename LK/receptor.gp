reset
set palette @MATLAB
set size square

set pm3d implicit at b
set view map
unset surface

set xlabel "x [m]"
set ylabel "y [m]" offset -1.0,0
set cblabel "Potencia \[kW/m$^2$\]" rot offset 2,0

lrec= 3.0
hrec= 3.0
midx = lrec/2
midy = hrec/2
dx = lrec/40
dy = hrec/40

splot "matriz.dat" matrix using (-midx+dx*$1):(-midy+dy*$2):($3/1000) notitle
