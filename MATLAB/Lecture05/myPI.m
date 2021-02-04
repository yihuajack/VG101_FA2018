function ret = myPI(N)
% comput PI with Monte
% Carlo method
d2 = rand(1,N).^2 + rand(1,N).^2;
ret = sum(d2 < 1) / N * 4;