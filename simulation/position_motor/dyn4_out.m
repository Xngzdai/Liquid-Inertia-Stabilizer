% Dynamics_4 plot generating
Tf = 15;

out = sim('dynamics_7.slx', [0 Tf]);
figure(1);
plot(out.inp, 'b--', LineWidth=2);hold on;
plot(out.simp, 'r-', LineWidth=2);hold on;
%ylim([0 0.6])
xlabel('Time (sec)');
ylabel('Angle (rad)');
legend('Sinusoidal Input: Pitch', 'Output Signal: Pitch');
figure(2);
plot(out.inr, 'g--', LineWidth=2);hold on;
plot(out.simr, 'm-', LineWidth=2);
%title('Dynamics Verification');
%ylim([0 0.4])
xlabel('Time (sec)');
ylabel('Angle (rad)');
legend('Sinusoidal Input: Roll', 'Output Signal: Roll');
