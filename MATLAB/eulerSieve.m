function pr=eulerSieve(n)
prime=zeros(1,n);
pNum = 1;
p = true(1,n);
for i=2:n
    if p(i)
        prime(pNum) = i;
        pNum=pNum+1;
    end
    for j = 1:pNum
        if (i * prime(j) > n)
            break;
        end
        p(i * prime(j)) = 0;
        if mod(i,prime(j)) == 0
            break;
        end
    end
end
p(1)=0;
pr=find(p);
end