%利用矩阵乘法可以避免使用循环

img = uint8(zeros(256,256,3));
img(:,:,1) = ones(256,1) * (255:-1:0);
img(:,:,3) = ones(256,1) * (0:255);
image(img);
imwrite(img,'map.jpg');
