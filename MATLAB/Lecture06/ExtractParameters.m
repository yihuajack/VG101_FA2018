clear all; clc;
fid = fopen('ExtractParameters.txt', 'r');
n = 0;
while feof(fid) == 0
   tline = fgetl(fid);
   n = n + 1;
   strrep(tline,' ',''); % remove the spaces
   pos = strfind(tline, '='); % find the position of '='
   % extract the variable name and value
   var(n).name = tline(1:pos-1);
   var(n).value = str2double(tline(pos+1:end-1));
end
fclose(fid);