clear
fid = fopen('input.txt', 'r');
fgetl(fid);
date_max = [];
date_min = [];
price_max = -Inf;
price_min = Inf;
price_list = [];
while feof(fid) == 0
    date = fscanf(fid, '%s', 1);
    price = fscanf(fid, '%f', 1);
    price_list = [price_list, price];
    if price > price_max
        price_max = price;
        date_max = date;
    end
    if price < price_min
        price_min = price;
        date_min = date;
    end    
end
fclose(fid);
price_mean = mean(price_list);
price_var = var(price_list, 1);

fprintf('The mean of prices is %f.\n', price_mean);
fprintf('The variance of prices is %f.\n', price_var);
fprintf('%s has highest price: %.1f\n', date_max, price_max);
fprintf('%s has lowest price: %.1f\n', date_min, price_min);
