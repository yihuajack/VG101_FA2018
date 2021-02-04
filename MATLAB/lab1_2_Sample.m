a=input('');
if a==2
    num=input('');
    t=1;
    ans=0;
    for i=1:length(num)
        ans=ans+(num(length(num)-i+1)-48)*t;
        t=t*2;
    end
    num2str(ans)
else
    num=input('');
    t=str2num(num);
    k=[];
    while t~=0
        if mod(t,2)==0
            k=['0',k];
        else
            k=['1',k];
        end
        t=floor(t/2);
    end
    k
end