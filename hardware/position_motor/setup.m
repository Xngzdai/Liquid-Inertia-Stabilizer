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

% Simulated motor properties
K = 1;
L = 0.05;
Res = 0.1;
J = 0.006;
b = 0.0004;

% Force input
% N1 = heaviside(;
N2 = 20;
N3 = 20;

% Simulate
% sim("platform_dynamics.slx")