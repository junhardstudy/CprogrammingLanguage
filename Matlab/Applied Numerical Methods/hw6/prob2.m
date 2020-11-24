function result = prob2(x, y)
    disp("문제 1-2번 입니다");
    using_linearization(x, y);
    result = using_pseudo_inverse(x, y);
end

function result = using_pseudo_inverse(x, real_y)
y = log(real_y)';

Z = [ones(size(x')) x'];
% 주의 Z matrix생성하려면 x, y를 column 벡터로 고려해야함
a = Z\y;
a(1) = exp(a(1));
disp("linearization한 다음, pseudo inverse 이용하기");
disp("Alpha와 Beta는 각각 아래와 같습니다")
disp(a);

St = sum((real_y - mean(real_y)).^2);
Sr = sum((real_y - a(1)*exp(a(2)*x)).^2);

r2 = (St - Sr)/St;

disp("Coefficients of determination 값은 ");
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
disp("linearization한 다음, equation 이용하기")
disp("Alpha와 Beta는 각각 아래와 같습니다")
disp(a)
disp("------------------------------")
end