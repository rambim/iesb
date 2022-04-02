


f(n) = C + f(n/2);


f(n) = C + C + f(n/2 / 2);

f(n) = C + C + C + f(n/2/2/2)


f(n) = kC + f(n/2^k);



n/2^k = 1
k = log 2 n;

f(n) = log2 n C + 1

O(log2(n));





