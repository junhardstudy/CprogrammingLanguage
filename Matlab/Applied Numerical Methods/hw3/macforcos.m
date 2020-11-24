function macforcos(x, es, maxnumofiteration)
    % es is pre-specified tolerance
    % calculate cos(x) value using by Maclaurin-series expansion
    
    ea = 100;
    % ea is approximation relative error
    
    i = 0;
    % i is number of iteration for now

    tmp_result = 0;
    % temporary result of calculation
    i = 0;
    disp("|-------|--------------------|--------------------------------|")
    disp("| count |    approximation   |   approximation error relative |")
    disp("|-------|--------------------|--------------------------------|")
    while(1)
       tmp_result = tmp_result + ( (-1)^i * (x)^(2*i)/factorial(2*i) );
       if i ~= 0
        ea = abs((tmp_result - previous_approximation)/tmp_result)*100;
       end
       fprintf("| %3d   |  %15.10f   |        %15.10f         |\n", i+1, tmp_result, ea)
       disp("|-------|--------------------|--------------------------------|")
       i = i+1;
       if (ea < es | i > maxnumofiteration),break,end
       % pre-specified tolerance 값보다 작다면 반복 중지
       
       previous_approximation = tmp_result;
    end
end