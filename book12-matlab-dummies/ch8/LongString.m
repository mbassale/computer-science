% Prompt to display on screen
prompt = [
    'Type your own name, but only if it isn''t ',...
    'Wednesday.\nType the name of the neighbor ',...
    'on your right on Wednesday.\n',...
    '"Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n',...
    'sed do eiusmod tempor incididunt ut labore et dolore magna\n',...
    'aliqua. Ut enim ad minim veniam, quis nostrud exercitation\n',...
    'ullamco laboris nisi ut aliquip ex ea commodo consequat.\n',...
    '? '
];
% read a name
name = input(prompt, 's');
% print a greeting
disp(['Hello ', name])