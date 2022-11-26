function [] = UsingBreak(Times)
%USINGBREAK Demo of break stmt
%   Break the loop after 5 greetings

if nargin < 1
    Times = 3;
end

SayIt = 1;
while SayIt <= Times
    disp('Howdy!');
    SayIt = SayIt + 1;
    if SayIt > 5
        disp('Sorry, too many greetings');
        break;
    end
end

end

