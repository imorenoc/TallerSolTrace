reset
set palette @MATLAB
set size square
unset colorbox

unset border
unset xtics
unset ytics
unset ztics


set pm3d
unset surface

lrec= 0.0093
hrec= 0.0093
midx = lrec/2
midy = hrec/2
dx = lrec/35
dy = hrec/35

splot "01_DiscoStirling.flx" matrix using ((-midx+dx*$1)*1000):((-midy+dy*$2)*1000):($3/1000) notitle
