function prob7()
    x = [0 5 8 12 16 18];
    y = [20 36.2 52 60 69.2 70];
    
    options = optimset('PlotFcns',@optimplotfval);        
    a = fminsearch(@targetfunc, [1, 1, 1], options, x, y);
    
    disp(a);
    
    x_plot = 0:0.1:18;
    y_plot = a(1)./( 1 + a(2)*exp(-a(3)*x_plot) );
    figure();
    hold on
    scatter(x, y);
    plot(x_plot, y_plot);
    
    legend('Measure Data', 'Nonlinear Function');
    hold off

end

function f = targetfunc(a, x, y)
    b = a(1)./( 1 + a(2)*exp(-a(3)*x) );
    f = sum((y - b).^2);
end