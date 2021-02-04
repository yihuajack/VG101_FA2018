% Whatever follwed '%' in the line is a comment
% This script will compute H from H^2 = A^2 + B^2
clear, clc % ',' separate different commands
% clear will clear variables and functions from memory
% clc will clear the command window and home the cursor
A = 3; % the first side of the triangle
B = 4; % the second side of the triangle
h_sqr = A^2 + B^2; % H^2, semicolon suppress the output
H = sqrt(h_sqr) % H, display the output