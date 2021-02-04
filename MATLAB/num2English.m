function str=num2English(n)
if n<=20
    switch n
        case 0
            str='zero';
        case 1
            str='one';
        case 2
            str='two';
        case 3
            str='three';
        case 4
            str='four';
        case 5
            str='five';
        case 6
            str='six';
        case 7
            str='seven';
        case 8
            str='eight';
        case 9
            str='nine';
        case 10
            str='ten';
        case 11
            str='eleven';
        case 12
            str='twelve';
        case 13
            str='thirteen';
        case 14
            str='fourteen';
    end
    
elseif n==100
    str='one hundred';
elseif n<1000 % 101-999
    