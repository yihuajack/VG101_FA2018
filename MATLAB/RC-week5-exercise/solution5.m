clear;
A = zeros(256, 256, 3);
A = uint8(A);
for i = 1: 256
    A(:, i, 1) = 256 - i; % Red: 255 - 0
    A(:, i, 3) = i - 1; % Blue: 0 - 255
end
imshow(A);