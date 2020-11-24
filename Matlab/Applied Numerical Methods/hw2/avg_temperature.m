function avg_temp = avg_temperature(mean_ann_temp, ...
        peak_temp, t)
%특정 지역의 평균 하루 온도를 계산해주는 함수입니다.

%For initialize some parameters, and variables
day_peak_temp = 205;
freq_ann_vari = (2*pi)/365;
sum_temp = 0;

%하루 평균 온도이므로 일단 다 더해야함.
for i = 1 : numel(t)
    sum_temp = sum_temp + mean_ann_temp + (peak_temp - mean_ann_temp)* ...
        cos(freq_ann_vari * (t(i) - day_peak_temp));
end
        
avg_temp = sum_temp/numel(t);

end