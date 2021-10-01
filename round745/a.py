#!/usr/bin/env pypy3
from sys import stdin

lines = [int(line.strip()) for line in stdin]
t = lines[0]
for ln in range(1, t+1):
    n = lines[ln]
    s = 1
    # div by 2 by skipping 2
    for i in range(3, 2*n+1):
        s = (s * i) % 1000000007

    print(s)

