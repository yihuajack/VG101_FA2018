fid = fopen('example_fgetl.m', 'r');
n = 0;
while feof(fid) == 0
   tline = fgetl(fid);
   n = n+1;
   fprintf('%d: %s\n',n,tline);
end
fclose(fid);