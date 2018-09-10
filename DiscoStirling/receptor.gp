reset
set palette @MATLAB
set size square

set pm3d implicit at b
set view map
unset surface

set xlabel "x [mm]"
set ylabel "y [mm]" offset -2.5,0
set cblabel "Potencia \[kW/m$^2$\]" rot offset 1,0

lrec= 0.0093
hrec= 0.0093
midx = lrec/2
midy = hrec/2
dx = lrec/35
dy = hrec/35

splot "01_DiscoStirling.flx" matrix using ((-midx+dx*$1)*1000):((-midy+dy*$2)*1000):($3/1000) notitle
