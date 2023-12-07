clc; close all; clear;
mat1 = readmatrix('ramp_10_11.txt');
mat2 = readmatrix('ramp_10_21.txt');

t1 = mat1(1:end,1)./1000;
t2 = mat2(1:end,1)./1000;
pwm1 = mat1(1:end,2);
pwm2 = mat2(1:end,2);
angle1 = mat1(1:end,3);
[angle1,index1] = rmoutliers(angle1,'movmedian',5);
angle2 = mat2(1:end,3);
[angle2,index2] = rmoutliers(angle2,'movmedian',5);

% figure(1);
% plot(t1, angle1);
% figure(2);
% plot(t2, angle2);

data1 = iddata(angle1, pwm1(~index1), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');
data2 = iddata(angle2, pwm2(~index2), 0.012, 'OutputName', 'Angle', 'InputName', 'PWM', 'OutputUnit', 'Degree', 'InputUnit', 'microseconds');

data1_d = detrend(data1);
data2_d = detrend(data2);

data_all = merge(data1_d, data2_d);
nf = 3;
nb = 2;
sys = tfest(data_all,nf)
figure(4);
bode(sys)
damp(sys)
%error = getcov(sys);
%allmargin(sys)