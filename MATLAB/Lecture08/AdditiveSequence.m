function f = AdditiveSequence (n, t0, t1 )
if n ==1
    f = t0;
else
    f = AdditiveSequence(n-1, t1, t0 + t1);
end
