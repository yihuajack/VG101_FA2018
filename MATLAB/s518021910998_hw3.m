function myim2bw(filename, threshold)
    I=imread(filename);
    I(I<=threshold)=0;I(I>threshold)=255;
    genfn=strcat('bw_',num2str(threshold),'_',filename);
    imwrite(I,genfn);
end