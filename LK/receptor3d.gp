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

lrec= 3.0
hrec= 3.0
midx = lrec/2
midy = hrec/2
dx = lrec/40
dy = hrec/40

splot "matriz.dat" matrix using (-midx+dx*$1):(-midy+dy*$2):($3/1000) notitle
