#!/bin/bash

echo "Apagando arquivo anteriores gerados: (*.txt + *.data + *.eps)..."
rm -rf saidaUsoMemoriaComPrograma.txt saidaUsoMemoriaSemPrograma.txt saidaUsoCpu.txt saidaVmstat.txt file.data *.eps

echo "[Inicioe vmstat]"


# dessa forma testamos se o primeiro caracter do primeiro campo
# é diferente ('!~') de 'p' e 'r'.
# o comando 'vmstat 1' tira amostras de um em um segundo indefinidamente

vmstat 1 | awk '{if ($1 !~ /p/ && $1 !~ /r/) print $0}' >> saidaVmstat.txt &

echo "Compilando arquivo..."
gcc $1.c -o $1
echo "Fazendo multiplicacao de matrizes..."

rm -rf file.data # apaga arquivo anterior

for ((i = 50; i <= 900; i+=50))
do
    ./$1 "$i" "$i" >> file.data 
    echo "$i x $i"
done

echo "Vmstat finalizado com o comando 'killall'."
# essa parte usa o comando killall para finalizar um processo pelo seu nome
killall vmstat

echo "Gerando a saída do uso de memória free..."
# agora retiro a 4ª coluna da entrada para gerar o arquivo de memória livre (free)
# o FNR gera a saída com as linhas numeradas, são usadas como segundos para o eixo 'x' do gnuplot
awk '{print FNR " " $4}' saidaVmstat.txt >> saidaUsoMemoriaComPrograma.txt

echo "Gerando a saída do uso de cpu..."
# agora retiro a 15ª coluna da entrada para gerar o arquivo de uso de cpu durante a execução do programa
# o FNR gera a saída com as linhas numeradas, são usadas como segundos para o eixo 'x' do gnuplot
awk '{print FNR " " $15}' saidaVmstat.txt >> saidaUsoCpu.txt


echo "Arquivos gerados com sucesso."
# echo "Fim."

# aqui esse comando soma todos os dados da coluna 2 do arquivo file.data gerado pelo programa
# da execução das multiplicações e atribui para a variável shell qtd, depois a imprime
qtd=`awk '{n+=$2} END {print n}' file.data`


echo "Gerando grafico da ordem no tempo..."
gnuplot matrixM.plt
#evince graphicMatrixMult.eps &


echo "Gerando grafico de memórias..."
gnuplot memPlot.plt
#evince graphicUsoMemoriaMult.eps &

echo "Gerando grafico de uso de CPU..."
gnuplot cpuPlot.plt
#evince graphicUsoCpuMult.eps &


# echo $qtd
echo "[Fim]" 
 

