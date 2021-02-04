% create matrix
n = 5;
A = zeros(n);
for ii = 1:n
    A(ii,:) = [ii:n, 1:ii-1];
end