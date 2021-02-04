function output = scale(input, smin, smax)
output = input;
% first method
% for ii = 1:length(input)
%     if input(ii) < smin
%         output(ii) = 0;
%     elseif input(ii) > smax;
%         output(ii) = 255;
%     else
%         output(ii) = 255 * (output(ii)-smin) / (smax - smin);
%     end
% end

% second method
% output(output<smin) = smin;
% output(output>smax) = smax;
% output = 255 * (output - smin) / (smax - smin);

% third method
output(output<smin) = 0;
output(output>smax) = 255;
A = (output >= smin & output <=smax);
output(A) = ...
    255 * (output(A) - smin) / (smax - smin);