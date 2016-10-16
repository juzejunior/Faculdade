// Cálculo B  exemplo 1
//   z=3*x*y^2+x^3-3*x
// desenha a função e calcula 
// um mínimo partindo de (2,-2)
//==============================
x = [2:0.2:-2]
y = x.^2

ex462()

function ex462()
   cont=0;clf()// limpa tela grafica
    x=[-2:0.2:2]';y=x;z=f(x,y)
    plot3d(x,y,z)
    xo=2;yo=-2;zo=f(xo,yo)// ponto inicial
    while norm(g(xo,yo))>0.001
        grad=g(xo,yo)
        xn=xo-grad(1)/100; yn=yo-grad(2)/100
        zn=f(xn,yn)
        cont=cont+1; disp(cont,' cont ')
        // desenha segmento de reta no espaco
        param3d([xo,xn],[yo,yn],[zo,zn])
        xo=xn; yo=yn; zo=zn// atualiza ponto inicial
    end
    disp(xo, ' x');disp(yo, ' y')
    hess=h(xo,yo);disp(hess,' hessiano')

endfunction

// z para cada ponto do plano cartesiano
function z=f(x,y)
    z=3*x*y'.^2+x.^3*ones(y')-3*x*ones(y')
endfunction

function gr=g(x,y)// gradiente
    gr=[3*y^2+3*x.^2-3;
         6*x*y]
endfunction

function hh=h(x,y)// hessiano
    h=[6*x 6*y;
       6*y 6*x]// matriz
    hh=det(h)// determinante
endfunction
