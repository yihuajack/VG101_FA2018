clear;clc;
cri=input('');
x=input('');
x=str2num(x);
t=0;i=1;y=0;
if cri==2
    while x~=0
        r(i)=mod(x,10);
        x=floor(x/10);
        t=t+1;i=i+1;
    end
    i=1;
    r(i)=flip(r(i));
    for i=1:t
        y=y+r(i)*2^(i-1);
    end
end
if cri==10
    while x~=0
       r(i)=mod(x,2);
       x=floor(x/2);
       t=t+1;i=i+1;
    end
    i=1;
    r(i)=flip(r(i));
    for i=1:t
       y=y+r(i)*10^(i-1);
    end
end
y=num2str(y);
disp(y);