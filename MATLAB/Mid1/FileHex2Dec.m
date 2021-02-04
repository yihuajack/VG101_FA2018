function FileHex2Dec(filename)
    fidi=fopen(filename,'r');
    outputfilename=strcat('dec_',filename);
    fido=fopen(outputfilename,'w');
    cell=textread('hexnumber.txt','%s\r\n');
    for i=1:length(cell)
        mat(i)=hex2dec(cell2mat(cell(i)));
    end
    for i=1:length(cell)
        fprintf(fido,'%d\r\n',mat(i));
    end
    fclose(fidi);fclose(fido);
end