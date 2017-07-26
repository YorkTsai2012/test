#!/bin/gnuplot
reset
set key top left
#set key box
set title 'Recent 30-Day UFile Request Count'
set terminal png  size 600,400
set output "./plot/request_count.png"
#set bar 1
#set style rectangle back fc lt -3 fillstyle  solid 1.00 border -1
#set key inside right top vertical Right noreverse enhanced autotitles columnhead nobox
#set xtics border in scale 1,0.5 rotate by -45 offset -8, -8
#set xlabel "Date"
set ylabel "Request Count ( x 10000)"
set xtics rotate by -45 offset -1, -1
set xtics out offset 0, -5
unset mxtics
set tics nomirror
set border 3  # bottom 1 left 2 top 4 right 8
set bmargin 8
#set ylabel  offset character 0, 0, 0 font "" textcolor lt -1 rotate by 90
set xdata time
set timefmt "%Y-%m-%d"
set format x "%Y-%m-%d"
#xstart = "2015-01-18"
#xend = "2015-02-16"
set xrange [xstart:xend]
set xtics xstart, 86400, xend
plot "./plot/request_count.month" using 1:2 with lp title "request count" #,'' using 1:3 with lp title "volume increment"
