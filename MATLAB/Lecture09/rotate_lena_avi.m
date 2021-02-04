% rotate lena - avi
clear all; clc;

writerObj = VideoWriter('lena_rotate.avi');
open(writerObj);
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
    writeVideo(writerObj,img3);
end
close(writerObj);