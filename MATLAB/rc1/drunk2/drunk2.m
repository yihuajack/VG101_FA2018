%与醉汉1一样，取随机数，只是这次在-1和1中取，简单映射一下即可
%醉汉永远不会走出100格的范围，为了减少耗时（计算这种玩意真的很耗时），就固定几个数组来储存数据

P = 2 * floor(rand(1,100)*2) - 1;
A = 0;

ZC = 0;%零点处数量
NY = zeros(1,100);%负数点处数量
PY = zeros(1,100);%正数点处数量

figure;hold on;
for ele = P
    A = A + ele;
    if A>0
    	PY(A) = PY(A) + 1;
    elseif A ==0
        ZC = ZC + 1;
    else
        NY(-A) = NY(-A) + 1;
    end
end

plot(-100:100,[NY ZC PY]/(sum(NY)+ZC+sum(PY)));