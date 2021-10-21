#!/usr/bin/env pypy3
from sys import stdin

M = 10**9 + 7

lines = [list(map(int, line.strip().split())) for line in stdin]
n, m = lines[0]
s1 = lines[1]
s2 = lines[2]


P = 0
Q = 1


for i in range(n-1, -1, -1):
    d1 = s1[i]
    d2 = s2[i]
    b = (i != n-1)
    
    if d1 and d2:
        if d1 > d2: P = Q = 1
        elif d1 == d2: P = P*b
        else: P, Q = 0, 1


    elif d1 == 0 and d2:
        P, Q = (P + Q*(m - d2)) % M, (Q * m) % M
    elif d1 and d2 == 0:
        P, Q = (P + Q*(d1 - 1)) % M, (Q*m)%M

    else:
        P,Q = (2*P + Q*(m-1)) % M, (Q*2*m)%M

    #print(P,Q)

print((P * pow(Q, M-2, M)) % M)
