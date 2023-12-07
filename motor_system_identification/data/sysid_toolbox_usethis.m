clc; close all; clear;

mat = readmatrix('step_full_range_1.txt');
t1 = mat(1:end, 1);
pwm1 = (mat(1:end, 2)-900)./10;
angle1 = mat(1:end, 3).*120./218;

% mat2 = readmatrix('square_500ms.txt');
% t2 = mat2(1:end, 1);
% pwm2 = mat2(1:end, 2);
% angle2 = mat2(1:end, 3);

mat3 = readmatrix('square_5000ms_1.txt');
t3 = mat3(1:end, 1);
pwm3 = (mat3(1:end, 2)-900)./10;
angle3 = (mat3(1:end, 3)+108).*120./218;

% data1 = iddata(angle1(89:134), pwm1(89:134), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
% data2 = iddata(angle2(1:165), pwm2(1:165), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
% data3 = iddata(angle3(71:111), pwm3(71:111), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');

data1 = iddata(angle1(99:170), pwm1(99:170), 0.015, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
%data2 = iddata(angle2(1:165), pwm2(1:165), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
data3 = iddata(angle3(71:170), pwm3(71:170), 0.014, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
