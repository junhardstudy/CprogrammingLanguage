function result = taylorforsin(phase, x)
   %테일러 급수를 이용하여 phase단계까지 sin함수에 대한
   %여러 계산값들을 계산합니다.
   
   result_tmp = 0;
   pivot = 1:2:(2*(phase-1) + 1);
   true = sin(x);
   
   fprintf("계산해야 하는 각텀의 제곱은 다음과 같습니다.\n");
   disp(pivot);
   fprintf("\n");
   
   for i = 1:phase
       if(mod(i, 2) == 0)
           %짝수 승수인 경우, 항의 마이너스를 더해줘야함
           result_tmp = result_tmp - (x^pivot(i))/factorial(pivot(i)); 
       else
           %그렇지 않을 경우, 항의 플러스를 더해줘야함
           result_tmp = result_tmp + (x^pivot(i))/factorial(pivot(i));
       end
       fprintf("At %d sequence, approximation value = %f\n", i, result_tmp);
       error = ((true - result_tmp)/true)*100;
       fprintf("true value = %f\n", true);
       fprintf("error percentage = %f\n\n\n", error);
   end
   result = result_tmp;
   

end

