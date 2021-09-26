#!/usr/bin/env pypy3
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
n, s = lines[0]
a = lines[1]

def find_cost(k):
    return sum(sorted(a[i] + (i+1)*k for i in range(n))[:k])

lo, hi = -1, n+1
while hi-lo > 1: 
    mid = (lo + hi) // 2
    if find_cost(mid) <= s: lo = mid
    else: hi = mid

print(lo, find_cost(lo))

