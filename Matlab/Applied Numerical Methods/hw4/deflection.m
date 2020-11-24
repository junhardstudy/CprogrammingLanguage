function deflection(bracket, maxit, es)
    L = 600;
    E = 50000;
    I = 30000;
    w = 2.5;
    
    xi = 0 : 0.1 : 600;
    
    func = @(x)w/(120 * E * I * L) *(-x^5 + 2 * L^2 * x^3 - L^4 * x);
    f = w/(120 * E * I * L) *(-xi.^5 + 2 * L^2 * xi.^3 - L^4 * xi);
   
    plot(xi, f);
    
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