function result = prob1(x, y)
    disp("���� 1-1�� �Դϴ�");
    disp("pseudoo inverse matrix �̿��ϱ�")
    a = use_pseudo_inverse(x, y);
    
    disp("a0 �� a1�� ���� �Ʒ��� �����ϴ�")
    disp(a)
    
    disp("------------------------------")
    disp("equation �̿��ϱ�")
    a = use_equation(x, y);
    
    disp("a0 �� a1�� ���� �Ʒ��� �����ϴ�")
    disp(a)
    
    disp("Coefficients of determination ���� ")
    r2 = COD(x, y, a);
    disp(r2);
    disp("=============================")
    
   result = a;
   % ���� 4������ ��� fitting model�� ���� �׷��� �׸���
   % ����� ��� return ��
    
end

function solution = use_pseudo_inverse(x, y)
% Pseudo inverse matrix�� �̿��Ͽ�
% a0�� a1�� ������ִ� �Լ��Դϴ�.

    A = [numel(x) sum(x); sum(x) sum(x.^2)];
    b = [sum(y); sum(x.*y)];
    
    x = A\b;
    
    solution = x;
end

function solution = use_equation(x, y)
% Sum of squared error���� �̺��Ͽ� 0�� �Ǵ� ����
% ������������ ���� ������ ���� �̿��Ͽ� a0, a1����
% ���ϴ� �Լ��Դϴ�.
n = numel(x);

a1 = ( n*sum(x.*y) - sum(x)*sum(y) )/( n*sum(x.^2) - (sum(x))^2 );

a0 = sum(y)/n - a1*(sum(x)/n);

solution = [a0; a1];
end

function r2 = COD(x, y, a)
% �ְ������� 1�� ���� �𵨿� ����
% Coefficients of determination�� ������ִ� �Լ��Դϴ�.
% a���� ����� �̷���� ���Ͱ��̾�� �մϴ�.
a0 = a(1);
a1 = a(2);

Sr = sum((y - a0 - a1*x).^2);

y_mean = sum(y)/numel(y);

St = sum( (y - y_mean).^2 );

r2 = (St - Sr)/St;

end