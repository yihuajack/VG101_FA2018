%�Ƚϼ򵥵ķ����ǽ�����2����ȡ�����ж��Ƿ�Ϊ����������ʱ�临�Ӷ�ΪO(n^2)
%���Ǵ���֮ǰ������������Ϳ��Խ���������O(n^pi(n))����pi(n)Ϊ����������ʽ
%���ң���2�����ż����������

function prime()
    for ii = [2 3:2:99]
        if isprime(ii)
            fprintf('%d\n', ii);
        end
    end
end

function R = isprime(A)
    global primeList;%�����б�
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