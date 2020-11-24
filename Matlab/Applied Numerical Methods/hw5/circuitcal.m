function circuitcal()
A = [1 -1 0 0 1 0;...
    0 1 -1 0 0 0;...
    0 0 1 -1 0 0;...
    0 0 0 1 -1 -1;...
    0 20 2 5 5 0;...
    10 0 0 0 -5 25;]

disp("coefficient matrix is below");
disp(A);

b = [0; 0; 0; 0; 0; 150];

solution = A\b;

disp("solution is below")
disp(solution);


end