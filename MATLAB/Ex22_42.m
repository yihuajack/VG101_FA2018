clear all
clc
A=magic(4)
fid=fopen('dota.txt','w');
fprintf(fid,'%d\n','int8',A)
fclose(fid);
fid=fopen('dota.txt','r');
frewind(fid); %将指针放在文件开头
if feof(fid)==0 %如果没有到文件结尾，则读取数据
[b,count1]=fscanf(fid,'%d\n') %把数据写入b
position=ftell(fid) %获取当前指针位置
end
if feof(fid)==1 %如果到文件结尾，则重新设置指针
status=fseek(fid,-4,'cof') %把指针从当前位置向文件头移动4个位置
[c,count2]=fscanf(fid,'%d\n')
end
fclose(fid);