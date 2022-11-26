function [] = UsingContinue(Times)
%USINGCONTINUE Continue stmt demo
%   Using continue to execute one loop iteration

if nargin < 1
    Times = 3;
end

SayIt = 1;
while SayIt <= Times
    if SayIt == 5
        disp('Welcome to iteration 5!');
        SayIt = SayIt + 1;
        continue;
    end
    disp('Howdy!');
    SayIt = SayIt + 1;
end

end

