% animation example by pause
x = [0:0.01:2*pi];
figure;
for ii = 1:100
    y = sin(x + ii / 10 * 2*pi);
    plot(x,y);
    pause(0.1);
end