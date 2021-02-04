fidi=fopen('input4.txt','r');fido=fopen('output.txt','w');
fseek(fidi,3,'bof');m=fscanf(fidi,'%f',[3,3]);
mdv=max(max(m));mxv=abs(min(min(m)));
can=[];c=[];
for p=1:41
    can=[can,' '];
end
for q=1:3*(mdv+mxv)+10
    c=[c;can];
end
for j=1:3
    for i=1:3
        vr=4+10*i-3*j;
        vc=3*mdv+3*j-2;
        if m(i,j)>0
            vcr=vc;
            for k=1:m(i,j)
                vc=vcr-3*k;
                c(vc,vr:vr+10)='+---------+';
                c(vc+1,vr-1:vr+10)='/         /|';
                c(vc+2,vr-2:vr+10)='/         / |';
                c(vc+3,vr-3:vr+10)='+---------+  +';
                c(vc+4,vr-3:vr+9)='|         | /';
                c(vc+5,vr-3:vr+8)='|         |/';
                c(vc+6,vr-3:vr+7)='+---------+';
            end
        elseif m(i,j)<0
            vcr=vc;
            for k=abs(m(i,j)):-1:1
                vc=vcr+3*k-3;
                c(vc,vr:vr+10)='+---------+';
                c(vc+1,vr-1:vr+10)='/         /|';
                c(vc+2,vr-2:vr+10)='/         / |';
                c(vc+3,vr-3:vr+10)='+---------+  +';
                c(vc+4,vr-3:vr+9)='|         | /';
                c(vc+5,vr-3:vr+8)='|         |/';
                c(vc+6,vr-3:vr+7)='+---------+';
            end
        end
    end
end
for r=1:3*(mdv+mxv)+10
    fprintf(fido,'%s\r\n',c(r,:));
end
fclose(fidi);fclose(fido);