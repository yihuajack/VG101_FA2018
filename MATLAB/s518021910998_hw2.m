function A=computeArea(fx)
    x1=0;x2=0;x3=0;t=0;
    fx=strrep(fx,' ','');
    fx=strrep(fx,'+x','+1x');
    if contains(fx,'x3')
        t=t+1;
        pos(1)=strfind(fx,'x3');
        if pos(1)-1==0
            fx=strcat('1',fx);
            pos(1)=strfind(fx,'x3');
        end
        x3=str2num(fx(1:pos(1)-1));
    end
    if contains(fx,'x2')
        t=t+1;
        pos(2)=strfind(fx,'x2');
        if pos(2)-1==0
            fx=strcat('1',fx);
            pos(2)=strfind(fx,'x2');
        end
        if contains(fx,'x3')
            x2=str2num(fx(pos(1)+3:pos(2)-1));
        else
            x2=str2num(fx(1:pos(2)-1));
        end
    end
    ind=count(fx,'+');
    if ind==t
        if length(fx)==1
            fx=strcat('1',fx);
        end
        if contains(fx,'x2')
            x1=str2num(fx(pos(2)+3:end-1));
        elseif contains(fx,'x3')
            x1=str2num(fx(pos(1)+3:end-1));
        else
            x1=str2num(fx(1:end-1));
        end
    end
    syms x
    pol=x3*x^3+x2*x^2+x1*x;
    A=int(pol,x,[0 1]);
end