x=0.0:0.2:1
altura = 0
y = x.^2
for i = 1:5
    altura = altura + ((y(i) + y(i+1)) / 2)
end
disp(altura*0.2)
plot(x,y)
