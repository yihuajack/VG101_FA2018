%����1һ����ȡ�������ֻ�������-1��1��ȡ����ӳ��һ�¼���
%����Զ�����߳�100��ķ�Χ��Ϊ�˼��ٺ�ʱ����������������ĺܺ�ʱ�����͹̶�������������������

P = 2 * floor(rand(1,100)*2) - 1;
A = 0;

ZC = 0;%��㴦����
NY = zeros(1,100);%�����㴦����
PY = zeros(1,100);%�����㴦����

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