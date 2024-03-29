function f = fibnum(n)
% FIBNUM Fibonacci number.
% FIBNUM(n) generates the nth Fibonacci number.
if n <= 2
    f = n;
else
    f = fibnum(n-1) + fibnum(n-2);
end
