%����������string���������Ա�����cell���鴢��
%ͨ���۸����ֱ���߼��������������ڣ�����ע��Ҫ��cell��Ԫ��ȡ��

function analyse()
    fid = fopen('Price.txt', 'r');
    fgetl(fid);
    count = 0;
    
    while ~feof(fid)
        count = count + 1;
        data = fgetl(fid);
        dataL = split(data, ' ');
        date{count} = dataL(1);
        price(count) = str2double(dataL(2));
    end
    
    fclose(fid);
    
    m = mean(price);
    v = var(price);
    lp = min(price);
    hp = max(price);
    
    ld = date{price == lp};
    hd = date{price == hp};
    
    fid = fopen('Analysis.txt', 'w');
    
    fprintf(fid, 'The mean of prices is %f.\n', m);
    fprintf(fid, 'The variance of prices is %f.\n', v);
    fprintf(fid, '%s has highest price: %f.\n', hd{1}, hp);
    fprintf(fid, '%s has lowest price: %f.', ld{1}, lp);
    
    fclose(fid);
end