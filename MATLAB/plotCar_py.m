function plotCar(carNumber,w,direction,t,state)
n=carNumber;
for count=1:n
    switch direction
        case 'right'
            position=t-3*w-8*(count-1);
            if position==-0.5*w-6&&state==3
                if position(count-1)~=-0.5*w-6
                    position(count)=-0.5*w-6
                else
                    position(count)=position(count-1)-8;
                end
            else
            end
            carr(count)=rectangle('Position',[position(count) -1.5-0.25*w 6 3],'FaceColor',[0.2 0.5 0.7],'Edgecolor','k');
        case 'left'
            carl(count)=rectangle('Position',[-t+3*w+8*(count-1) -1.5+0.25*w 6 3],'FaceColor',[0.4 0.8 0.8],'Edgecolor','k');
        case 'up'
            caru(count)=rectangle('Position',[-1.5+0.25*w t-3*w-8*(count-1) 3 6],'FaceColor',[0.8 0.3 0.4],'Edgecolor','k');
        case 'down'
            caru(count)=rectangle('Position',[-1.5-0.25*w -t+3*w+8*(count-1) 3 6],'FaceColor',[1 0.7 0.6],'Edgecolor','k');
    end
end
end