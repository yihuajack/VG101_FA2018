%使用随机数，0-n的随机整数的取法是floor(rand(1,100) * n)
%之后根据随机数的值一步步推演A，然后将它画出来即可

% P = floor(rand(1, 100) * 4);
% A = [0,0];
% 
% figure;hold on;
% for ele = P
%     temp = A;
%     A = A + [0,1] * (ele==0) + [0,-1] * (ele==1) + [1,0] * (ele==2) + [-1,0] * (ele==3);
%     line([temp(1),A(1)],[temp(2),A(2)]);
% end

P = rand(1,1000) * 2 * pi * 1i;
A = 0;

figure;hold on;
for ele = P
    temp = A;
    A = A + exp(ele);
    line([real(temp),real(A)],[imag(temp),imag(A)]);
end