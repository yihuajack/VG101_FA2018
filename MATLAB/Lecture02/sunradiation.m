% calculate the mass consumed
% in one day of the sun
E = 385e24; % radiation rate
E = E * 3600 * 24; % radiation in one day
c = 3e8; % speed of light
m = E / c^2; % mass consumed in one day
fprintf('mass consumed in one day is %g\n', m);