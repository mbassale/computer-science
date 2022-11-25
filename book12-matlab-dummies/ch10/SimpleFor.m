function [] = SimpleFor(Times)
%SIMPLEFOR Demo of a for loop
%   Uses a for loop to print Times a greeting

if nargin < 1
    Times = 3;
end

for SayIt = 1:Times
    disp('Howdy!')
end

end

