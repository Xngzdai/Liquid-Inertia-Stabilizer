%{
Mar 4th, 2023
Author: Xingze Dai
Course: ME 450
%}

% Simulated platform properties
R = 0.05; % Radius of the force [m]
I = 0.05; % The inertia of the platform and object [m2]
h = 0.05; % The height of the center of mass [m]
g = 9.81; % [m/s2]
m = 1.5;  % Total mass [kg]
exertion_radius = 0.03;

% Simulated motor properties
K = 3.92/(7.4*2.8);
L = 0.005;
Res = 0.1;
J = 0.006;
b = 0.0004;
omega = 1;

% Force input
% N1 = heaviside(;
N2 = 20;
N3 = 20;

% Simulate
% sim("platform_dynamics.slx")