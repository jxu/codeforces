#!/usr/bin/env pypy3
from sys import stdin
from collections import deque


lines = [list(map(int, line.strip().split())) for line in stdin]
t = lines[0][0]
ln = 1
for _ in range(t):
    n, a = lines[ln][0], lines[ln+1]
    ln += 2

    d = deque()
    for x in a:
        if len(d) == 0 or x < d[0]:
            d.appendleft(x)
        else:
            d.append(x)


    print(" ".join(map(str,d)))

