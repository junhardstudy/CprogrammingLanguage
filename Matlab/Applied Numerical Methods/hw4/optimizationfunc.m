function optimizationfunc(bracket, func, maxit, es)
    drowfunc();
    
    [x_min, f_val] = fminbnd(func, bracket(1), bracket(2));
    disp(x_min);
    disp(f_val);
    golden_section_search(bracket, func, maxit, es);


end

function golden_section_search(bracket, func, maxit, es)
    xl = bracket(1);
    xu = bracket(2);
    phi = (1+sqrt(5))/2;
    d = (phi - 1)*(xu - xl);
    
    x1 = xl + d;
    x2 = xu - d;
    iteration = 0;
    
    while(1)
        if func(x2) > func(x1)
            xopt = x1;
            xl = x2;
            x2 = x1;
            d = (phi - 1)*(xu - xl);
            x1 = xl + d;           
        else
            xopt = x2;
            xu = x1;
            x1 = x2;
            d = (phi - 1)*(xu - xl);
            x2 = xu - d;            
        end
        iteration = iteration + 1;
        ea = (2 - phi)*abs((xu - xl)/xopt) * 100;
        if iteration >= maxit | ea <= es, break, end             
    end
    
    fprintf("minimum x point by golden section search : %f\n", xopt);

end

function drowfunc()
    x = 2:0.1:20;
    func = sin(x) + sin((2*x)/3);
    plot(x, func);
end