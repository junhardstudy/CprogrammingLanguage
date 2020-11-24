function prob6()
    % Mulitiple Linear Regression

    x = 1 : 1: 10;
    % 문제에서 주어진 건 degree값 같음
    
    y = [1.17 0.93 -0.71 -1.31 2.01 3.42 1.53 1.02 -0.08 -1.51];
    %x = rad2deg(x);
    x = x';
    y = y';
    
    Z = [ones(size(x)) cos(x) sin(2*x)];
    
    a = Z\y;
    
    disp(a);
    x_plot = 1:0.1:10;
    y_plot = a(1) + a(2)*cos(x_plot) + a(3)*sin(2*x_plot);
    
    hold on
    scatter(x, y)
    plot(x_plot ,y_plot);
    legend('Measure Data', 'Multiple Linear');
    
    hold off
    
    St = sum((y - mean(y)).^2);
    
    Sr = sum((y - a(1) - a(2)*cos(x) - a(3)*sin(2*x)).^2);
    
    r2 = (St - Sr)/St;
    
    disp("Coefficients of determination 은")
    disp(r2);
    
    
end

