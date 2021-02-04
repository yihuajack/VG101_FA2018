% rotate lena - gif
clear all; clc;

img = imread('lena_gray.jpg');
sz = size(img);
max_sz = ceil(sqrt(sz(1)^2 + sz(2)^2));
for theta = 0:10:360
    img2 = imrotate(img, theta);
    img2_sz = size(img2);
    % zero padding
    img3 = uint8(zeros(max_sz));
    img3(round(max_sz/2 - img2_sz(1)/2):round(max_sz/2 - img2_sz(1)/2) + img2_sz(1) - 1,...
        round(max_sz/2 - img2_sz(2)/2):round(max_sz/2 - img2_sz(2)/2) + img2_sz(2) - 1) = img2;
    if theta == 0
        imwrite(img3,'rotate_lena.gif','LoopCount',Inf,'DelayTime',0.1);
    else
        imwrite(img3,'rotate_lena.gif','WriteMode','append','DelayTime',0.1);
    end
end