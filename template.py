#!/usr/bin/env python3
from sys import stdin

#lines = [line.strip() for line in stdin] # one string per line
#t = int(lines[0])
lines = [list(map(int, line.strip().split())) for line in stdin]
t = lines[0][0]
ln = 1
for _ in range(t):
    n, a = lines[ln][0], lines[ln+1]
    ln += 2
    print(n, a)

