function dctshow()
v = 1;
fv = 0:1:7

for i = 1:1:8
    fv(i) = cos((2*(i-1) +1)*v*pi)/16;
end


plot(i, fv ,"mark")


end