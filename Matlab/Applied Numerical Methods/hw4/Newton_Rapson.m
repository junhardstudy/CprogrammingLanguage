function result = Newton_Rapson(func, dfunc, xi, es, maxit)
    % func =  x^3 - 6x^2 + 11x - 6.1

    iteration = 0;
    display();
    while(1)
    
        xi_1 = xi - func(xi)/dfunc(xi);
        
        ea = abs((xi_1 - xi)/xi_1)*100;

        xi = xi_1;
        iteration = iteration + 1;
        
        display(iteration, xi, ea);
        
        % loopπÆ ≈ª√‚ ¡∂∞«
        if ea <= es, break, end
        if iteration >= maxit, break, end
    end
    disp(xi);
    result_2 = roots([0.0074 -0.284 3.355 -12.183 5]);
    display_answer(xi, result_2);
    
    result = xi;
    
    
    
end
function display_answer(result1, result2)
    fprintf("root by using Newton-Rapson method : %f \n", result1);
    fprintf("root by buil-in root function : %f \n", result2);
end

function display(number, x1, x2)
if nargin==0
    disp("|------|-----------------------------|------------------------------|");
    disp("|number|            x_i              | approximation relative error |");
    disp("|------|-----------------------------|------------------------------|");
    
else
    fprintf("|%3d   |%20.10f         |      %15.10f         |\n", number, x1, x2);
    disp("|------|-----------------------------|------------------------------|");
end

end