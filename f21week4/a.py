#!/usr/bin/env python3
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
t = lines[0][0]
ln = 1
for _ in range(t):
    n, a = lines[ln][0], lines[ln+1]
    ln += 2

    d = [0] * n  
    # get away with 0-indexing
    for i in range(n-1,-1,-1):
        d[i] = a[i] + (0 if i+a[i] >= n else d[i+a[i]])

    print(max(d))
