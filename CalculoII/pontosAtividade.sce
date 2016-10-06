//Eixo x 
x = [0:0.1:4]
//3 retas
y1 = (-2*x + 5) / 3
y2 = (-4*x + 9) / 5
y3 = (-6*x + 13) / 7

//transformacao
A = [4+16+36, 6+20+42; 6+20+42, 9+25+49]
B = [10+36+78; 15+45+91]
//multiplicacao da inversa
result = inv(A)*B
//exibe o resultado
disp(result)
//desenha o grafico
plot2d(x, y1, 6)
plot2d(x, y2, 2)
plot2d(x, y3, 3)
plot(result, result,'bo')
