function impedence(bracket)
    % 저항, 인덕터, 커패시터가 병렬로 연결된 회로에서
    % 각 주파수(w)를 구하는 함수 입니다.
    % R, L, C값은 이미 주어져 있습니다.
    R = 225;
    L = 0.5;
    C = 0.6 * 10^-6;
    
    func = @(w) sqrt(R^-2 + (w*C - 1/(w*L))^2) - 0.01;
    
    [w_result, fw] = fzero(func, bracket);
    
    disp(w_result);
    disp(fw);
    
end