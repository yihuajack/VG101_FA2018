N = 1000000;
pos = rand(2,N);
M = sum(pos(2,:) < pos(1,:).^2);
M/N % display the result