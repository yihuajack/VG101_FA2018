function Lab3(str)
    file=dir('lab3_encrypt_image');
    for k=1:length(file)
        if string((file(k).name))==strcat(str,'.bmp')
            cd lab3_encrypt_image;e=imread(file(k).name);cd ..;break;
        end
    end
    [origin,a]=imread('origin.bmp');
    if str(1)~='A'
        if str(2)=='a'
            d=origin;[~,j]=find(e~=origin);j=unique(j);t=1;
            for m=1:length(j)
                for n=1:length(j)   
                    if isequal(e(1:249,j(m)),origin(1:249,j(n)))
                        d(:,j(m))=e(:,j(n));p(t)=j(n);q(t)=j(m);t=t+1;
                    end
                end
            end    
            for t=1:312
                d(:,p(t))=e(:,q(t));
            end
        else
            [~,j]=find(e~=origin);j=unique(j);t=1;d=e;
            for m=1:length(j)
                for n=1:length(j) 
                    if isequal(e(1:249,j(n)),origin(1:249,j(m)))
                        d(:,j(n))=e(:,j(m));
                    end
                end
            end
        end
        e=d;
    end
    if str(2)~='a'
        if str(1)=='A'
            d=e;
            for m=1:1080
                for n=1:1080
                    if isequal(origin(m,1:12:299),d(n,1:12:299))&&isequal(origin(m,1:16),d(n,1:16))
                        e(m,:)=d(n,:);
                    end
                end
            end
        else
            Ba0=imread('lab3_encrypt_image\Ba0.bmp');
            d=origin;[~,j]=find(Ba0~=origin);j=unique(j);t=1;
            for m=1:length(j)
                for n=1:length(j)   
                    if isequal(Ba0(1:249,j(m)),origin(1:249,j(n)))
                        d(:,j(m))=Ba0(:,j(n));p(t)=j(n);q(t)=j(m);t=t+1;
                    end
                end
            end
            d=e;
            for t=1:312
                d(:,p(t))=e(:,q(t));
            end
            e=d;
         	for m=1:1080
                for n=1:1080
                    if isequal(origin(m,1:12:299),d(n,1:12:299))&&isequal(origin(m,1:16),d(n,1:16))
                        e(m,:)=d(n,:);
                    end
                end
            end
        end
    end
    if str(3)~='0'
        e(250:325,1364:1555)=reshape(e(16:11:1061,17:12:1829),[76,192]);
    end
    cd lab3_decrypt_image;
    e=flipud(e(250:325,1364:1555));
    imwrite(e,a,file(k).name);
    cd ..;
end