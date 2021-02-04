clear all;clc;
a=input('');
n=a(1);
m=a(2);
k=a(3);
mat=[];
for p=1:n
    c=input('');
    mat=vertcat(mat,c);
end
for q=1:k
    ope=input('');
    par=input('');
    i=par(1);j=par(2);
    switch ope
        case 1
            mat(:,[i,j])=mat(:,[j,i]);
        case 2
            l=par(3);r=par(4);t=par(5);
            mat(i:j,l:r)=mat(i:j,l:r)+t;
        case 3
            t=par(3);
            mat(i:i+t-1,j:j+t-1)=transpose(mat(i:i+t-1,j:j+t-1));
        case 4
            mat(j,:)=mat(j,:)+mat(i,:);
    end
end
disp(mat);