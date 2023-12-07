G = tf([4.464 -1.361 728.6], [1 14.04 166.2 719.5]);
wL = 1.0;
Kg = -1/abs(evalfr(G, 1j*wL));
wb = wL; 
betab = sqrt(10); 
Kb = tf([betab wb],[1 0])/sqrt(betab^2+1); 
wl = wL;
betal = 8;
Kl = tf([betal wl],[1 betal*wl]);
K = Kg*Kb*Kl;
L3 = G*K;
S = feedback(1,L3);
isstable(S)
allmargin(L3)
