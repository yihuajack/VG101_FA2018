function ret = HexDigitSum(str)
    for i=1:length(str)
        cell(i)=str(i);
        dec(i)=hex2dec(cell(i));
    end
    s=sum(dec);
    ret=dec2hex(s);
end