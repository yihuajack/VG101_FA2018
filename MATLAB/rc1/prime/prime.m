%比较简单的方法是将数从2到它取余来判断是否为素数，但是时间复杂度为O(n^2)
%但是储存之前计算出的素数就可以将其缩短至O(n^pi(n))其中pi(n)为素数个数公式
%而且，除2以外的偶数均可跳过

function prime()
    for ii = [2 3:2:99]
        if isprime(ii)
            fprintf('%d\n', ii);
        end
    end
end

function R = isprime(A)
    global primeList;%素数列表
    if A == 2
        primeList = [2];
        R = true;
    else
        R = true;
        for ele = primeList
            R = R && (mod(A,ele) ~= 0);
        end
        if R
            primeList = [primeList A];
        end
    end
end