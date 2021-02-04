fid=fopen('input4.txt','r')
FID=fopen('output.txt','w')
A = fscanf(fid,'%s',1)
A = fscanf(fid,'%d',[3,3])
A = A'
cube=['    ________   ';'  /          /|';' /________  / |';'|          |  |';'|          | / ';'| ________ |/  ']
down=['|          | /|';'| ________ |/ |';'|          |  |';'|          | / ';'| ________ |/  ']
right=['  ________   ';'/          /|';'________  / |';'         |  |';'         | / ';'________ |/  ']
M = zeros(100);
M = char(M+32);
sup = 0
for m = 1:3
for n = 1:3
    if A(m,n) > sup
     sup = A(m,n)   
    end
end
end
inf = 0
for m = 1:3
for n = 1:3
    if A(m,n) < inf
     inf = A(m,n)   
    end
end
end
B = sup - A

if A(1,1)~=0
    i = min(B(1,1),sup)
    j = max(B(1,1),sup)
    M(i * 3 + 1:i * 3 + 6,19:33) =cube
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 2:i * 3 + 6,19:33) = down
    end
end
if A(1,2)~=0
    i = min(B(1,2),sup)
    j = max(B(1,2),sup)
    M(i * 3 + 1,34:44) =cube(1,5:15)
    M(i * 3 + 2,32:44) =cube(2,3:15)
    M(i * 3 + 3,31:44) =cube(3,2:15)
    M(i * 3 + 4:i * 3 + 6,30:44) =cube(4:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 2:i * 3 + 6,30:44) = down
    end
end

if A(2,1)~=0
    i = min(B(2,1),sup)
    j = max(B(2,1),sup)
    M(i * 3 + 3,21:28) =cube(1,5:12)
    M(i * 3 + 4:i * 3 + 8,16:30) =cube(2:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 4:i * 3 + 8,16:30) = down
    end
end

if A(3,1)~=0
    i = min(B(3,1),sup)
    j = max(B(3,1),sup)
    M(i * 3 + 5,18:25) =cube(1,5:12)
    M(i * 3 + 6:i * 3 + 10,13:27) =cube(2:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 6:i * 3 + 10,13:27) = down
    end
end

if A(2,2)~=0
    i = min(B(2,2),sup)
    j = max(B(2,2),sup)
    M(i * 3 + 3,31:38) =cube(1,5:12)
    M(i * 3 + 4,27:41) =cube(2,1:15)
    M(i * 3 + 5,29:41) =cube(3,3:15)
    M(i * 3 + 6,28:41) =cube(4,2:15)
    M(i * 3 + 7,27:40) =cube(5,1:14)
    M(i * 3 + 8,27:39) =cube(6,1:13)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 4:i * 3 + 8,27:41) = down
    end
end

if A(1,3)~=0
    i = min(B(1,3),sup)
    j = max(B(1,3),sup)
    M(i * 3 + 1,46:53) =cube(1,5:12)
    M(i * 3 + 2,43:55) =cube(2,3:15)
    M(i * 3 + 3,42:55) =cube(3,2:15)
    M(i * 3 + 4:i * 3 + 6,41:55) =cube(4:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 2:i * 3 + 6,41:55) = down
    end
end

if A(2,3)~=0
    i = min(B(2,3),sup)
    j = max(B(2,3),sup)
    M(i * 3 + 3,43:50) =cube(1,5:12)
    M(i * 3 + 4,40:52) =cube(2,3:15)
    M(i * 3 + 5,39:52) =cube(3,2:15)
    M(i * 3 + 6:i * 3 + 8,38:52) =cube(4:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 4:i * 3 + 8,38:52) = down
    end
end

if A(3,2)~=0
    i = min(B(3,2),sup)
    j = max(B(3,2),sup)
    M(i * 3 + 5,28:35) =cube(1,5:12)
    M(i * 3 + 6,26:38) =cube(2,3:15)
    M(i * 3 + 7,25:38) =cube(3,2:15)
    M(i * 3 + 8:i * 3 + 10,24:38) =cube(4:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 6:i * 3 + 10,24:38) = down
    end
end

if A(3,3)~=0
    i = min(B(3,3),sup)
    j = max(B(3,3),sup)
    M(i * 3 + 5,39:46) =cube(1,5:12)
    M(i * 3 + 6,37:49) =cube(2,3:15)
    M(i * 3 + 7,36:49) =cube(3,2:15)
    M(i * 3 + 8:i * 3 + 10,35:49) =cube(4:6,1:15)
    for k =  1:(j-i)-1
        i = i + 1
        M(i * 3 + 6:i * 3 + 10,35:49) = down
    end
end
for x = 1:100
    M(x,97)='\'
    M(x,98)='r'
    M(x,99)='\'
    M(x,100)='n'
end
for y = 1:100
    fprintf(FID,M(y,:))
end
fclose(fid)
fclose(FID)