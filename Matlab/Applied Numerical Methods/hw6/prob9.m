function prob9()
    

    [indep_var, dep_var] = fminsearch(@targetfunc, [1 0]);
    disp("최소값을 가지는 x, y")
    disp(indep_var)
    disp("그 때의 함수값")
    disp(dep_var)
    
 

    [indep_var, dep_var] = fminsearch(@targetfunc, [-1 -2]);
    disp("최소값을 가지는 x, y")
    disp(indep_var)
    disp("그 때의 함수값")
    disp(dep_var)
    
    x=linspace(-1,3,500) ;
    y=linspace(-3,4,500) ;
    [X,Y] = meshgrid(x,y);
    Z=-0.02*sin(X+4*Y)-0.2*cos(2*X+3*Y)-0.3*sin(2*X-Y)+0.4*cos(X-2*Y);
    h = surfc(X,Y,Z);
    %set(h, 'LineStyle', 'none')
    xlabel('x'); 
    ylabel('y'); 
    zlabel('f(x,y)');

end

function f = targetfunc(x)
    f = -0.02*sin(x(1) + 4*x(2)) - 0.2*cos(2*x(1) + 3*x(2)) -...
        0.3*sin(2*x(1) - x(2)) + 0.4*cos(x(1) - 2*x(2));
end