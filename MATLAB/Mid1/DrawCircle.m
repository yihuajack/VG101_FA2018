function DrawCircle(x, y, radius)
    canvas=zeros(512,512);
    for i=1:512
        for j=1:512
            if (i-x)^2+(j-y)^2==radius^2
                canvas(i,j)=255;
            end
        end
    end
    imwrite(canvas,'circle.bmp');
    % my MATLAB function can only output some points of the circle
    % the others are lost
    % while the output points actually approximately constructs a shape of a circle
end