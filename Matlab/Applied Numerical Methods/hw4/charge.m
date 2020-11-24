function charge()
    e0 = 8.85 * 10^-12;
    Q = 2 * 10^-5;
    a = 0.9;
    
    x = 0 : 0.01 : 8;
    func = @(x) -1/(4 * pi * e0) * (Q * Q * x)./((x.^2 + a^2).^1.5);

    
    plot(x, -func(x));
    
    [xmin, fval] = fminbnd(func, 0, 8);
    fprintf("F(x) = %f when minimu x value is %f\n", -fval, xmin);
    % ���� �Լ��� �׷����� �ִ밪�� ã�� �����̹Ƿ�
    % �ּҰ��� ã�� fminbnd bulit-in �Լ��� ����Ͽ���
    % �� ���� ���� - �� ���ؾ���.
    
end