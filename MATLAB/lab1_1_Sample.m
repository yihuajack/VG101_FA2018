a=input('');
m=[];
for i=1:a(1)
    s=input('');
    m=[m;s];
end
col=[1:a(1)]';
row=[1:a(2)];
for i=1:a(3)
    t=input('');
    if t==1
        b=input('');
        col=m(1:a(1),b(1));
        m(1:a(1),b(1))=m(1:a(1),b(2));
        m(1:a(1),b(2))=col;
    elseif t==2
        c=input('');
        m(c(1):c(2),c(3):c(4))=m(c(1):c(2),c(3):c(4))+c(5);
    elseif t==3
        d=input('');
        m(d(1):d(1)+d(3)-1,d(2):d(2)+d(3)-1)=m(d(1):d(1)+d(3)-1,d(2):d(2)+d(3)-1)';
    else
        e=input('');
        m(e(2),1:a(2))=m(e(2),1:a(2))+m(e(1),1:a(2));
    end
end
disp(m);
