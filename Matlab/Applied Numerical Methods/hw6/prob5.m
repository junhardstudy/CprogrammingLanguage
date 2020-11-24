function prob5()
    x = 1:1:8;
    x = x';
    y = [2.5 7 38 55 61 122 83 145];
    y = y';
    
    Z1 = [ones(size(x)) x x.^2 x.^3 ];
    Z2 = [ones(size(x)) x x.^2 x.^3 x.^4 x.^5];
    Z3 = [ones(size(x)) x x.^2 x.^3 x.^4 x.^5 x.^6];
    
    first_a = Z1\y;
    second_a = Z2\y;
    third_a = Z3\y;
    
    x_s = x;
    x = 1:0.1:8;    
    
    y1 = first_a(1) + first_a(2)*x + first_a(3)*x.^2 + first_a(4)*x.^3;
    
    y2 = second_a(1) + second_a(2)*x + second_a(3)*x.^2 +...
        second_a(4)*x.^3 + second_a(5)*x.^4 + second_a(6)*x.^5;
    
    y3 = third_a(1) + third_a(2)*x + third_a(3)*x.^2 + ...
        third_a(4)*x.^3 + third_a(5)*x.^4 + third_a(6)*x.^5 + ...
        third_a(7)*x.^6;

    
    hold on;
    
    plot(x, y1, x, y2, x, y3);
    scatter(x_s, y, 'filled');
    legend('m=3', 'm=5', 'm=6', 'Measure Data');
    ylim([-40 160]);
    hold off;
    
    disp("m=3 일 때, coefficients는")
    disp(first_a);
    
    disp("m=5 일 때, coefficients는")
    disp(second_a);
    
    disp("m=6 일 때, coefficients는")
    disp(third_a);
    
    

end