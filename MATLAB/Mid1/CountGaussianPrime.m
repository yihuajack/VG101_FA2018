function ret = CountGaussianPrime(N)
    ret=0; %initialize the value of ret
    for n=0:fix((N-3)/4) %fix n to determine the general pattern of a or b
    for a=0:N
        for b=0:N
            if (a==0)&&(b==4*n+3)&&isprime(b)
                ret=ret+1;
            elseif (b==0)&&(a==4*n+3)&&isprime(a)
                ret=ret+1;
            elseif (a~=0)&&(b~=0)&&isprime(a^2+b^2)
                ret=ret+1;
            end
        end
    end
    end
end