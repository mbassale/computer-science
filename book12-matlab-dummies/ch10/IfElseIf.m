function [] = IfElseIf(Value)
%IFELSEIF If-Else-If statements demo
%   If-Else-If statement demo

if Value > 5
    disp('The input value is greater than 5!');
elseif Value == 5
    disp('The input value is equal to 5!');
else
    disp('The input value is less than 5!');
end

end

