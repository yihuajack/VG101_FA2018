function s=reverse(str)
len=length(str);
if len==0
    s='';
else
    s1=str(len);
    s2=reverse(str(1:len-1));
    s=strcat(s1,s2);
end
end