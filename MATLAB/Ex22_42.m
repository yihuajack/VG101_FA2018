clear all
clc
A=magic(4)
fid=fopen('dota.txt','w');
fprintf(fid,'%d\n','int8',A)
fclose(fid);
fid=fopen('dota.txt','r');
frewind(fid); %��ָ������ļ���ͷ
if feof(fid)==0 %���û�е��ļ���β�����ȡ����
[b,count1]=fscanf(fid,'%d\n') %������д��b
position=ftell(fid) %��ȡ��ǰָ��λ��
end
if feof(fid)==1 %������ļ���β������������ָ��
status=fseek(fid,-4,'cof') %��ָ��ӵ�ǰλ�����ļ�ͷ�ƶ�4��λ��
[c,count2]=fscanf(fid,'%d\n')
end
fclose(fid);