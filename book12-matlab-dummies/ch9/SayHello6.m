function [] = SayHello6(name)
%SAYHELLO2 Prints a greeting with a custom name
%   Prints a greeting with a custom name
    if nargin < 1
        name = 'Good Looking';
    end
    HelloString = [GetGreeting(), name, '!'];
    disp(HelloString);

    function [Greeting] = GetGreeting()
        Greeting = 'Hello There ';
    end
end

