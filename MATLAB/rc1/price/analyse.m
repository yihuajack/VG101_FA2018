%由于日期是string变量，所以必须用cell数组储存
%通过价格可以直接逻辑索引至最大的日期，但是注意要把cell中元素取出

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