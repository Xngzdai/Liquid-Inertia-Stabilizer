clc; close all; clear;

mat = readmatrix('step_full_range_1.txt');
t1 = mat(1:end, 1);
pwm1 = mat(1:end, 2);
angle1 = mat(1:end, 3);

mat2 = readmatrix('square_500ms.txt');
t2 = mat2(1:end, 1);
pwm2 = mat2(1:end, 2);
angle2 = mat2(1:end, 3);

mat3 = readmatrix('square_5000ms.txt');
t3 = mat3(1:end, 1);
pwm3 = mat3(1:end, 2);
angle3 = mat3(1:end, 3);

data1 = iddata(angle1(1:173), pwm1(1:173), 0.012);
data2 = iddata(angle2(1:165), pwm2(1:165), 0.012);
data3 = iddata(angle3(1:154), pwm3(1:154), 0.012);

% data1 = iddata(angle1(89:134), pwm1(89:134), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
% data2 = iddata(angle2(1:165), pwm2(1:165), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
% data3 = iddata(angle3(71:111), pwm3(71:111), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');

figure(1);
plot(t1,angle1);hold on;
plot(t1, pwm1/10);
legend('angular position(deg)', 'pwm signal', Location='southeast');

figure(2);
plot(t2, angle2);hold on;
plot(t2, pwm2/10);
legend('angular position(deg)', 'pwm signal', Location='southeast');

figure(3);
plot(t3, angle3);hold on;
plot(t3, pwm3/10);
legend('angular position(deg)', 'pwm signal', Location='southeast');

%data_all = merge(data1, data2);
data_all = merge(data1, data3);
%data_all = merge(data1, data2, data3);

nf = 3;
nb = 2;
%sys = tfest(data1,nf)
sys = tfest(data_all,nf)
figure(4);
bode(sys)
damp(sys)
error = getcov(sys);
%allmargin(sys)
