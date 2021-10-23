#!/usr/bin/env pypy3
from sys import stdin

M = 10**9 + 7

lines = [list(map(int, line.strip().split())) for line in stdin]
n, m = lines[0]
s1 = lines[1]
s2 = lines[2]

P, Q = 0, 1

for i in range(n-1, -1, -1):
    d1 = s1[i]
    d2 = s2[i]
    
    if d1 and d2:
        if d1 > d2: P, Q = 1, 1
        elif d1 < d2: P, Q = 0, 1
        else: pass  # d1 == d2

    elif d1 == 0 and d2:
        P, Q = (P + Q*(m-d2)) % M, (Q*m) % M
    elif d1 and d2 == 0:
        P, Q = (P + Q*(d1-1)) % M, (Q*m) % M
    else:  # d1 == 0 and d2 == 0
        P, Q = (2*P + Q*(m-1)) % M, (Q*2*m) % M


print((P * pow(Q, M-2, M)) % M)
