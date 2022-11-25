function [] = SimpleSwitch(Value)
%SIMPLESWITCH Switch stmt demo
%   Switch stmt demo

switch Value
    case 1
        disp('You typed 1.');
    case 2
        disp('You typed 2.');
    case 3
        disp('You typed 3.');
    otherwise
        disp('You typed an alternative value.');
end

end