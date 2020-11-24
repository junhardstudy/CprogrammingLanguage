function circuitcal2()
A = [1 1 1 0 0 0 0; -1 0 0 1 1 0 0; 0 0 0 -1 0 -1 0; ...
    0 0 -1 0 -1 1 1; 0 0 0 8 -7 -15 0; 30 0 -10 0 7 0 0; ...
    0 -35 10 0 0 0 5];
disp("coefficient matrix is below");
disp(A);
b = [0; 0; 0; 0; 0; 0; 120];

solution = A\b; % solution is x when the equation form is like to be the form Ax = b
disp("solution is below");
disp(solution)
end