function initialize(carNumber,width,timeCycle,possibility)
w=width;
p=possibility;
timeG=timeCycle(1);
timeO=timeCycle(2);
timeR=timeCycle(3);
[nright,nleft,nup,ndown]=randCar(carNumber);
maxCar=max([nright,nleft,nup,ndown]);
for t=0:6*w+8*(marCar-1)
    crossRoad(w);
    if mod(t,(timeG+timeO+timeR)*20)<=timeG*20
        state=1;
    elseif mod(t,(timeG+timeO+timeR)*20)<=timeO*20
        state=2;
    else
        state=3;
    end
    plotCar(nleft,w,'left',t,state);
    plotCar(nright,w,'right',t,state);
    plotCar(nup,w,'up',t,state);
    plotCar(ndown,w,'down',t,state);
    trafLight(state,w);
    hold on;
    pause(0.05);
    clf;
end
end