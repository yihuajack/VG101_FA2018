fid = fopen('scores.txt', 'r');
n = 0; % number of names
name = fscanf(fid, '%s', 1);
while ~isempty(name)
    n = n + 1;
    score(n) = fscanf(fid, '%f', 1);
    name = fscanf(fid, '%s', 1);
end
fprintf('Average score = %f\n',...
    mean(score));
fclose(fid);