function prob8()
    x = [0 0.5 1 2 3];
    y = [0.95 1.139 0.94 0.298 0.087];

    a = fminsearch(@targetfunc, [1, 1, 1], [], x, y);
    disp("K, a, b�� ���� �Ʒ��� �����ϴ�.")
    disp(a);
    x_plot = 0:0.1:6;
    y_plot = a(1)./( sqrt(x_plot.^4 + (a(2)^2 -2*a(3))*x_plot.^2 + a(3)^2 ) );
    
    hold on;
    scatter(x, y);
    plot(x_plot, y_plot);
    
    legend('Measure Data', 'Nonlinear Function');
    
    hold off;
end

function f = targetfunc(a, x, y)
    % K�� a(1)
    % a�� b�� ���� a(2), a(3)

    b = a(1)./( sqrt(x.^4 + (a(2)^2 -2*a(3))*x.^2 + a(3)^2 ) );
    
    f = sum((y - b).^2);
end