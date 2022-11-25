function [] = SayHello4(name)
%SAYHELLO2 Prints a greeting with a custom name
%   Prints a greeting with a custom name
    global HelloString
    if nargin < 1
        name = 'Good Looking';
    end
    HelloString = ['Hello There ', name, '!'];
    disp(HelloString);
end
