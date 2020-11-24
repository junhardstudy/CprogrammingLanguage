function result = prob2(x, y)
    disp("���� 1-2�� �Դϴ�");
    using_linearization(x, y);
    result = using_pseudo_inverse(x, y);
end

function result = using_pseudo_inverse(x, real_y)
y = log(real_y)';

Z = [ones(size(x')) x'];
% ���� Z matrix�����Ϸ��� x, y�� column ���ͷ� ����ؾ���
a = Z\y;
a(1) = exp(a(1));
disp("linearization�� ����, pseudo inverse �̿��ϱ�");
disp("Alpha�� Beta�� ���� �Ʒ��� �����ϴ�")
disp(a);

St = sum((real_y - mean(real_y)).^2);
Sr = sum((real_y - a(1)*exp(a(2)*x)).^2);

r2 = (St - Sr)/St;

disp("Coefficients of determination ���� ");
disp(r2);
disp("=============================")

result = a; 

end

function using_linearization(x, real_y)
y = log(real_y);

n = numel(x);

a1 = ( n*sum(x.*y) - sum(x)*sum(y) )/( n*sum(x.^2) - (sum(x))^2 );

a0 = sum(y)/n - a1*(sum(x)/n);

real_a0 = exp(a0);

a = [real_a0 ; a1];
disp("linearization�� ����, equation �̿��ϱ�")
disp("Alpha�� Beta�� ���� �Ʒ��� �����ϴ�")
disp(a)
disp("------------------------------")
end