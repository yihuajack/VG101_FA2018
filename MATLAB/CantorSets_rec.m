function CantorSets_rec(n)
    left=0;
    right=1;
    d=1;
    plot([0,1], [n,n],'-');
    hold on
    everycantor(left, right, d,n);
end

function everycantor(left, right, d,n)
    if d<=n
    leftright=left+(right-left)/3;
    rightleft=right-(right-left)/3;
    hold on
    plot([left, leftright], [n-d,n-d],'-');
    plot([rightleft, right],[n-d,n-d],'-');
    everycantor(left, leftright, d+1,n)
    everycantor(rightleft, right, d+1,n)
    end
end
    
