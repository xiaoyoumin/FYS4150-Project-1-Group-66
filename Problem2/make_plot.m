x=load('problem2_x.txt');
u=load('problem2_u.txt');

plot(x,u)
grid on 
xlabel('x')
ylabel('u(x)')
title('u(x) = 1-(1-e^{-10})x-e^{-10x}')
