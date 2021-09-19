#!/usr/bin/env python3
from sys import stdin
lines = [list(map(int, line.strip().split())) for line in stdin]

t = lines[0][0]
ln = 1
for _ in range(t):
    n, a, b = lines[ln][0], lines[ln+1]
    ln += 2

