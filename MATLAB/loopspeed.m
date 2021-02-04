clear;clc;
%speed for loop
N=5000;
A=rand(N);
tic;
for m=1:N
    for n=1:N
        x=A(n,m)^5;
    end
end
fprintf('column first:\n');
toc;
tic;
for m=1:N
    for n=1:N
        x=A(m,n)^5;
    end
end
fprintf('row first:\n');
toc;