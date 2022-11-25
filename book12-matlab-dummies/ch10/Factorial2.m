function [Result] = Factorial2(Value)
%FACTORIAL2 Recursive calculation of factorial function
%   Factorial using recursion

if Value > 1
    Result = Factorial2(Value - 1) * Value;
else
    Result = 1;
end

end
