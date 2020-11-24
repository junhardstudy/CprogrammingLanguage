function result = prob1(x, y)
    disp("문제 1-1번 입니다");
    disp("pseudoo inverse matrix 이용하기")
    a = use_pseudo_inverse(x, y);
    
    disp("a0 와 a1은 각각 아래와 같습니다")
    disp(a)
    
    disp("------------------------------")
    disp("equation 이용하기")
    a = use_equation(x, y);
    
    disp("a0 와 a1은 각각 아래와 같습니다")
    disp(a)
    
    disp("Coefficients of determination 값은 ")
    r2 = COD(x, y, a);
    disp(r2);
    disp("=============================")
    
   result = a;
   % 문제 4번에서 모든 fitting model에 대해 그래프 그릴때
   % 사용할 계수 return 값
    
end

function solution = use_pseudo_inverse(x, y)
% Pseudo inverse matrix를 이용하여
% a0와 a1을 계산해주는 함수입니다.

    A = [numel(x) sum(x); sum(x) sum(x.^2)];
    b = [sum(y); sum(x.*y)];
    
    x = A\b;
    
    solution = x;
end

function solution = use_equation(x, y)
% Sum of squared error값을 미분하여 0이 되는 식을
% 연립방정식을 통해 유도한 식을 이용하여 a0, a1값을
% 구하는 함수입니다.
n = numel(x);

a1 = ( n*sum(x.*y) - sum(x)*sum(y) )/( n*sum(x.^2) - (sum(x))^2 );

a0 = sum(y)/n - a1*(sum(x)/n);

solution = [a0; a1];
end

function r2 = COD(x, y, a)
% 최고차항이 1인 선형 모델에 대한
% Coefficients of determination을 계산해주는 함수입니다.
% a값은 계수로 이루어진 벡터값이어야 합니다.
a0 = a(1);
a1 = a(2);

Sr = sum((y - a0 - a1*x).^2);

y_mean = sum(y)/numel(y);

St = sum( (y - y_mean).^2 );

r2 = (St - Sr)/St;

end