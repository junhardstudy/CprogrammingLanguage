function impedence(bracket)
    % ����, �δ���, Ŀ�н��Ͱ� ���ķ� ����� ȸ�ο���
    % �� ���ļ�(w)�� ���ϴ� �Լ� �Դϴ�.
    % R, L, C���� �̹� �־��� �ֽ��ϴ�.
    R = 225;
    L = 0.5;
    C = 0.6 * 10^-6;
    
    func = @(w) sqrt(R^-2 + (w*C - 1/(w*L))^2) - 0.01;
    
    [w_result, fw] = fzero(func, bracket);
    
    disp(w_result);
    disp(fw);
    
end