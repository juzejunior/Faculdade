set title "Calculo do tempo medio de multiplicacao de matrizes quadradas" 
set ylabel "Tempo (segundos)"
set xlabel "Ordem N x N"

#[eps figure] 
set style line 1 lt 2 lc rgb "cyan"   lw 2 
set style line 2 lt 2 lc rgb "red"    lw 2
set style line 3 lt 2 lc rgb "gold"   lw 2
set style line 4 lt 2 lc rgb "green"  lw 2
set style line 5 lt 2 lc rgb "blue"   lw 2
set style line 6 lt 2 lc rgb "black"  lw 2
set style line 7 lt 1 lc rgb "blue"  lw 2
set terminal postscript eps enhanced color
#set output 'grafico-golub-tetra-threads.eps'
set output 'graphicMatrixMult.eps'

#[png figure]
#set style line  1 linetype  1 linewidth 2
#set style line  2 linetype  2 linewidth 2
#set style line  3 linetype  3 linewidth 2
#set style line  4 linetype  4 linewidth 2
#set style line  5 linetype  5 linewidth 2
#set style line  6 linetype  6 linewidth 2
#set terminal png
#set output "grafico-golub-tetra-threads.png"

set xtics nomirror
set ytics nomirror
set key top left
set key box
set style data lines

plot "file.data" using 1:2 title "Mult" ls 7 with linespoints

# daqui pra baixo eh meu
#set title "Calculo do tempo medio de multiplicacao de matrizes quadradas" 

#set ylabel "Tempo (segundos)"
#set xlabel "Ordem N x N"

#set xtics nomirror
#set ytics nomirror
#set key top left
#set key box
#set style data lines

#set style line 1 linetype 1 linewidth 1 linecolor rgb "red" pointtype 7 pointsize 1
#set style line 2 linetype 1 linewidth 1 linecolor rgb "blue" pointtype 7 pointsize 1

#set terminal postscript eps enhanced color
#set output 'graphicMatrixMult.eps'

#plot "file.data" using 1:2 title "Multiplicacao" ls 7 with linespoints

#plot "saidaUsoMemoriaComPrograma.txt" using 1:2 title "Uso Memoria com programa" ls 1 with linespoints
