function Mannings_equation(data_mat)
    tmp = size(data_mat);
    fprintf("|-----------|-----------|-----------|-----------|-----------|\n");
    fprintf("|     n     |     s     |     B     |     H     |     U     |\n");
    fprintf("|-----------|-----------|-----------|-----------|-----------|\n");
    for i = 1:tmp(1)
        
        for j = 1:tmp(2)
            fprintf("| %9f ", data_mat(i, j));
        end
        tmp_result = sqrt(data_mat(i, 2))/data_mat(i, 1) * ((data_mat(i, 3)...
            * data_mat(i, 4))/(data_mat(i, 3) + 2* data_mat(i, 4)))^(2/3);
        fprintf("| %9f |\n", tmp_result);
        fprintf("|-----------|-----------|-----------|-----------|-----------|\n");
        
    end
    
end

