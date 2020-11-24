function result = prob3(x, y)
    disp("���� 1-3�� �Դϴ�");
    a = using_pseudo_inverse(x, y);
    using_equation(x, y);
    
    St = sum( (y - mean(y)).^2 );
    Sr = sum( (y - a(1)*x.^(a(2)) ).^2 );
    
    r2 = (St - Sr)/St;
    
    disp("Coefficients of determination�� ");
    disp(r2);
    disp("=============================")
    
    result = a;
end

function result = using_pseudo_inverse(real_x, real_y)
    y = log10(real_y)';
    x = log10(real_x)';
    
    Z = [ones(size(x)) x];
    
    a = Z\y;
    
    a(1) = 10^(a(1));
    % alpha��
    % a(2)���� ��Ÿ
    
    disp("linearization�� ����, pseudo inverse �̿��ϱ�");
    disp("Alpha�� Beta�� ���� �Ʒ��� �����ϴ�")
    disp(a);     
    
    result = a;

end

function using_equation(real_x, real_y)
    x = log10(real_x);
    y = log10(real_y);
    a1 = (numel(real_x)*sum(x.*y) - sum(x)*sum(y)) / (numel(x)*sum(x.^2)...
        - (sum(x))^2 );
    a0 = mean(y) - a1*mean(x);
    
    a0 = 10^(a0);
    a = [a0; a1];
    
    disp("------------------------------")
    disp("linearization�� ����, equation �̿��ϱ�");
    disp("Alpha�� Beta�� ���� �Ʒ��� �����ϴ�")
    disp(a);
    
end