while true
    a = input('Please input the first number,("good luck" to exit):');
     if a == 'good luck'
        exit
    end
    b = input('Please input the second number,("good luck" to exit):');
     if b == 'good luck'
        exit
    end
    m = min(a,b);
    for i = m:-1:1
        if mod(a,i)== 0 && mod(b,i) == 0
            disp(sprintf('%s%d','The greast the common divisor = ',i))
            break
        end
    end
end