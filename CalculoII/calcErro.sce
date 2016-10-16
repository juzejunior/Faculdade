//calculo B calculo do livro
//tranform into columns
x = [-2: 0.1: 2]'
//working
disp(x)
//y equals x
y = x
//calculate the height
z = 3*x*y'.^2+x.^3*ones(y')-3*x*ones(y')
//exibing the result
plot3d(x,y,z)


