function matlin()
equation_1 = [0 -7 5];
equation_2 = [0 4 7];
equation_3 = [-4 3 -7];
b = [50; -30; 40];

A = [equation_1 ; equation_2; equation_3];

solution = A\b;

disp("solution is below");
disp(solution);
disp("Transpose matrix is below");
disp(A');
disp("Inverse of the coefficient matrix is below");
disp(inv(A));

end