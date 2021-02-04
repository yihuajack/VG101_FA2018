function ret=myabs(x)
if isreal(x)
    if x>=0
        ret=x;
    else
        ret=-x;
    end
else % x is not real
    ret=sqrt(real(x)^2+imag(x));
end