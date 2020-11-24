function control()
    x = 1:1:8;
    y = [2.5 7 38 55 61 122 83 145];
    
    result_a_1 = prob1(x, y);
    result_a_2 = prob2(x, y);
    result_a_3 = prob3(x, y);
    
    disp("summary answer");
    disp(result_a_1);
    disp(result_a_2);
    disp(result_a_3);
    
    x_s = x;
    % scatter에 쓰일 x 변수값들
    
    x = 0:0.1:8;
    
    model1 = result_a_1(1) + result_a_1(2)*x;
    model2 = result_a_2(1)*exp(result_a_2(2)*x);
    model3 = result_a_3(1)*x.^(result_a_3(2));
    
    hold on
    plot(x, model1, x, model2, x, model3);

    
    scatter(x_s, y, 'filled');
    legend('y = a0 + a1*x (linear model)', 'y = ae^(bx) (exp model)',...
        'y = ax^b (power model)', 'Measure data')
    ylim([0 150])
    hold off
    
    
end