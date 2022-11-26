EndIt = false;

while not(EndIt)
    clc
    disp('Chosose a Fruit:');
    disp('1. Orange');
    disp('2. Grape');
    disp('3. Cherry');
    disp('4. Quit');

    Select = input('Choose an option: ', 's');
    if isnan(str2double(Select))
        disp('Invalid input. Press Enter to continue..');
        pause
        continue;
    end

    if Select == '4'
        disp('Exiting...');
        EndIt = true;
    else
        ProcessInput(Select)
    end
end

function [] = ProcessInput(Option)
    switch Option
        case '1'
            disp('Selected: orange.');
        case '2'
            disp('Selected: grape.');
        case '3'
            disp('Selected: cherry.');
    
        otherwise
            disp('Invalid option.')
            return;
    end
    pause(2)
end