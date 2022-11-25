function [] = SimpleWhile(Times)
%SIMPLEWHILE Demos the while loop
%   Prints a greeting Times using a while loop

if nargin < 1
    Times = 3;
end

SayIt = 1;
while SayIt <= Times
    disp('Howdy!');
    SayIt = SayIt + 1;
end

end

