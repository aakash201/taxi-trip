dat = load('output test.txt');

X = dat(:,2);
Y = dat(:,3);
Z = dat(:,4);
scatter3(X,Y,Z);
