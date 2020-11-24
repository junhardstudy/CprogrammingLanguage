function hardproblem()
A = zeros(9);
disp(A);

A(1, 1) = -3.2;
A(1, 2) = 1;

disp(A);
j = 1;
for i = 2:1:8
    A(i, j) = 2;
    A(i, j + 1) = -3.2;
    A(i, j + 2) = 1;
    j = j + 1;
end
A(9, 8) = 2;
A(9, 9) = -3.2;

disp(j);
disp(A);
b = [-160; 0; 0; 0; 0; 0; 0; 0; -20];
solution = A\b;
disp(solution);

x = 0:1:10;
y = [80 solution' 20];

plot(x, y, 'or', 'MarkerFaceColor', 'red');
end