% first: import tfs from sid file
Ks = pid(0.1583, 2.6233, -0.0504, 3.1393);
G = tf([4.464 -1.361 728.6], [1 14.04 166.2 719.5]);
loop = Ks*G;
allmargin(loop);
S = feedback(1,loop);
[Smax,w0] = norm(S,inf);
DiskMargin = 1/Smax