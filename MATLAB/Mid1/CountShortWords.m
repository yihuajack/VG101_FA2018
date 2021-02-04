function ret = CountShortWords(N, str)
    A=strsplit(str);ret=0;
    for i=1:length(A)
        if length(cell2mat(A(i)))<=N
            ret=ret+1;
        end
    end
end