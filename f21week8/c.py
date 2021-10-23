#!/usr/bin/env pypy3
from sys import stdin

M = 10**9 + 7
INV2 = 500000004

lines = [list(map(int, line.strip().split())) for line in stdin]
n, m = lines[0]
s1 = lines[1]
s2 = lines[2]

P, Q = 0, 1

for d1, d2 in reversed(list(zip(s1, s2))):
    if d1 and d2:
        if d1 != d2: P, Q = (d1 > d2), 1

    else:
        if not d1 and d2:
            P = (P + Q*(m-d2)) % M
        elif d1 and not d2:
            P = (P + Q*(d1-1)) % M
        else:  # d1 == d2 == 0
            P = (P + Q*(m-1)*INV2) % M
        Q = (Q*m) % M

print((P * pow(Q, M-2, M)) % M)
