#!/usr/bin/env pypy3
from sys import stdin
from itertools import accumulate  # scan

lines = [list(map(int, line.strip().split())) for line in stdin]
n, k = lines[0]
a = lines[1]

pre = list(accumulate(a, min))
post = list(reversed(list(accumulate(reversed(a), min))))

if k == 1:
    print(min(a))
elif k == 2:
    print(max(max(pre[i-1], post[i]) for i in range(1, len(a))))
else:
    print(max(a))

