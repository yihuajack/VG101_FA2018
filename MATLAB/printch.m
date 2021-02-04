function printch(str)
for i=1:length(str)
    disp(str(i));
end
if length(str)~=0
    disp(str(1));
    printch(str(2:end));
end
end