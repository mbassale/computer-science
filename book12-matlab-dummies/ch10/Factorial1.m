function [Result] = Factorial1(Value, Level)
%FACTORIAL1 Recursive factorial calculation
%   Factorial calculation using recursive function calls
if nargin < 2
    Level = 1;
end

fprintf('Value = %d Level = %d\n', Value, Level);

if Value > 1
    Result = Factorial1(Value - 1, Level + 1) * Value;
    
else
    Result = 1;
end

disp(['Result = ', num2str(Result)])

end


