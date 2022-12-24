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
s = servo(a, 'D4');
%{
s = 
  Servo with properties:
                Pin: 'D4'
MinPulseDuration: 5.44e-04 (seconds)
MaxPulseDuration: 2.40e-03 (seconds)
%}

clear s;
s = servo(a, 'D4', 'MinPulseDuration', 700*10^-6, 'MaxPulseDuration', 2300*10^-6);
%{
s = 
  Servo with properties:

                 Pin: 'D4'
    MinPulseDuration: 7.00e-04 (seconds)
    MaxPulseDuration: 2.30e-03 (seconds)
%}

for angle = 0:0.2:1
    writePosition(s, angle);
    current_pos = readPosition(s);
    current_pos = current_pos*180;
    fprintf('Current motor position is %d degrees\n', current_pos);
    pause(2);
end

%clear s a