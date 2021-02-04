% Plot the Sierpinski triangle
function PlotSierpinskiTriangle
figure; hold on;
SierpinskiTriangle(0, 0, 1, 0.01);
end
%%%%%%%%%%%%%%%%%%%%%%
function SierpinskiTriangle(x, y, max_side, min_side)
% (x, y) - the coordinates of lower left vertex
% max_side - maximal side length
% min_side - minimal side length
if max_side >= min_side && max_side < min_side * 2,
    plotELtriangle(x, y, max_side);
    return;
end
SierpinskiTriangle(x, y, max_side / 2, min_side);
SierpinskiTriangle(x + max_side / 2, y, max_side / 2, min_side);
SierpinskiTriangle(x + max_side / 2 * cosd(60), y + max_side / 2 * sind(60), max_side / 2, min_side);
end

%%%%%%%%%%%%%%%%%%%%%%
function plotELtriangle(x, y, side)
% plot a equilateral triangle
% (x, y) - the coordinates of lower left vertex
% side - the side length of the triangle
N = 500; % N points for a side
Tri = zeros(1, 3*N);
steps = linspace(0, side, N);
Tri(1:N) = steps;
Tri(N+1:2*N) = side - steps * cosd(60) + 1i * steps * sind(60);
Tri(2*N+1:3*N) = (side - steps) * cosd(60) + 1i * (side - steps) * sind(60);
Tri = Tri + x + 1i * y; % offset
plot(Tri);
end