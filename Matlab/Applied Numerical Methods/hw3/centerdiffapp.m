function centerdiffapp(true_value, func, x, step_size)
    displaybytable()
    %보기 좋게 측정값들을 도표 형식으로 표현하기 위해 도표의 머리부분을 출력합니다.
    h = step_size;
    for i = 0:10        
        tmp_result = (func(x + h) - func(x - h))/(2*h);
        tmp_true_error = true_value - tmp_result;
        displaybytable(i, h, tmp_result, tmp_true_error)
        h = h/10;               
    end
    
end

function displaybytable(count, step_size, approximation, true_error)
    if(nargin == 0)
        disp("|-------|-------------------|------------------------|--------------------|")
        disp("| count |     step size     |      approximation     |    true error      |")
        disp("|-------|-------------------|------------------------|--------------------|")
    else
        fprintf("| %3d   |   %13.10f   |     %12.7f       | %17.12f  | \n", count, step_size, approximation, true_error)
        disp("|-------|-------------------|------------------------|--------------------|")
    end
end