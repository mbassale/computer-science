function [] = UsingReturn(Times)
%USINGRETURN Demo of return stmt
%   Return to caller inside a while loop

if nargin < 1
    Times = 3;
end

Result = 'Success!';
SayIt = 1;
while SayIt <= Times
    disp('Howdy!');
    SayIt = SayIt + 1;
    if SayIt > 5
        disp('Sorry, too many Howdies');
        Result = 'Oops!';
        return;
    end
end

disp('End Of Function');

end

