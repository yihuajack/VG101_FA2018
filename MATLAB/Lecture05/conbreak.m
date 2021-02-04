clear all; clc;
n = 1;
while true
    fprintf('n=%d\n', n);
    str = input('User input: ', 's');
    switch str
        case 'a'
            n = n+1;
        case 'b'
            continue;
        otherwise
            break;
    end
end