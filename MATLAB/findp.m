function p=findp(n)   %the output p is a vector that contains all prime numbers not greater than n
    if n<10000
        d=[2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97]; %The list of prime numbers less than 100
    else
        d=findp(floor(sqrt(n)));    %For those large n, use recursion to find all prime numbers smaller than sqrt(n)
    end
    b=true(1,n);    %Assume that all the numbers are prime numbers
    b(1)=0;     %First, one is not a prime number
    for i=1:length(d)
        b(d(i)^2:d(i):n)=0;    %Sift out the multiples of d(i). Notice that those non-prime numbers smaller than d(i)^2 have already been sifted out
    end
    p=find(b);  %The indexes of the remainders are prime numbers
end