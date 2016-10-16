//values x: 1 y: 0 z: 1 
u = [1; 0; 1]
v = [0;1;1]
//take the alpha in radians and the normalization(magnitude)
alfa = acos(u.*.v / norm(u) / norm(v))
//disp the result on the screen - tranform to degrees
disp(alfa * 180 / %pi)
aa = gca()
//show in 3d graphics
param3d([0,u(1)], [0, u(2)],[0, u(3)])
param3d([0,v(1)], [0, v(2)],[0, v(3)])
