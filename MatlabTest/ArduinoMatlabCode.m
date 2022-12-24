%write a matlab script that will be compiled, loaded onto, and executed on
% the arduino uno. this will be accomplished with the matlab support
%package for arduino hardware
clear
clc
close all

%get some user settings
ledPin = 'D13';
deltaT_blink = 0.5;

%use the matlab support package for arduino hardware to instantiate an
%arduino object that will be used to communicate with the arduino uno board
port = 'COM6';
board = 'Uno';

a = arduino(port, board);

%write a small for loop that flashes the LED on and off several times

for k=1:10
    %turn the arduino LED off
    a.writeDigitalPin(ledPin,0);
    pause(deltaT_blink/2);

    %turn the arduino LED on
    a.writeDigitalPin(ledPin,1);
    pause(deltaT_blink/2);

end