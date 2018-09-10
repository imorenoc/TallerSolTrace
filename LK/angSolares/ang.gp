reset
set style data l
set key out horiz
set key bottom
set xlabel "\\'Angulo acimutal, ($\\gamma_s$)"
set ylabel "\\'Angulo de elevaci\\'o, ($\\alpha_s$)"
set xrange[-150:150]
set yrange[0:90]
set grid

# line styles
set style line 1 lw 0.3 dashtype 1 lc rgb '#000000'
set style line 2 dashtype 2 lc rgb '#252525'
set style line 3 dashtype 3 lc rgb '#525252'
set style line 4 dashtype 4 lc rgb '#737373'
set style line 5 dashtype 5 lc rgb '#969696'
set style line 6 dashtype 6 lc rgb '#bdbdbd'
set style line 7 dashtype 7 lc rgb '#d9d9d9'
set style line 8 dashtype 8 lc rgb '#000000'
set style line 9 dashtype 9 lc rgb '#252525'
set style line 10 dashtype 10 lc rgb '#525252'
set style line 11 dashtype 11 lc rgb '#737373'
set style line 12 dashtype 12 lc rgb '#969696'

plot "data.dat" index 0 u 2:(90-$3) title "Ene" ls 1,\
     '' index 1 u 2:(90-$3) title "Feb" ls 2,\
     '' index 2 u 2:(90-$3) title "Mar" ls 3,\
     '' index 3 u 2:(90-$3) title "Abr" ls 4,\
     '' index 4 u 2:(90-$3) title "May" ls 5,\
     '' index 5 u 2:(90-$3) title "Jun" ls 6,\
     '' index 6 u 2:(90-$3) title "Jul" ls 7,\
     '' index 7 u 2:(90-$3) title "Ago" ls 8,\
     '' index 8 u 2:(90-$3) title "Sep" ls 9,\
     '' index 9 u 2:(90-$3) title "Oct" ls 10,\
     '' index 10 u 2:(90-$3) title "Nov" ls 11,\
     '' index 11 u 2:(90-$3) title "Dic" ls 12, \
     "<awk '{ if($1 == 7) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 8) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 9) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 10) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 11) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 12) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 13) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 14) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 15) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "",\
     "<awk '{ if($1 == 16) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "", \
     "<awk '{ if($1 == 17) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t "", \
     "<awk '{ if($1 == 18) print }' data.dat | sort -k 3,3" u 2:(90-$3) w l t ""
