function myim2bw_c(filename, threshold)
    I=imread(filename);
    BW=im2bw(I,threshold/255);
    genfn=strcat('bw_',num2str(threshold),'_',filename);
    imwrite(BW,genfn);
end