function charge()
    e0 = 8.85 * 10^-12;
    Q = 2 * 10^-5;
    a = 0.9;
    
    x = 0 : 0.01 : 8;
    func = @(x) -1/(4 * pi * e0) * (Q * Q * x)./((x.^2 + a^2).^1.5);

    
    plot(x, -func(x));
    
    [xmin, fval] = fminbnd(func, 0, 8);
    fprintf("F(x) = %f when minimu x value is %f\n", -fval, xmin);
    % 원래 함수의 그래프는 최대값을 찾는 문제이므로
    % 최소값을 찾는 fminbnd bulit-in 함수를 사용하였고
    % 그 때의 값은 - 를 곱해야함.
    
end