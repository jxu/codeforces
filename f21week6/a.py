#!/usr/bin/env pypy3
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
n, m = lines[0]
g = [[] for _ in range(n+1)]

for ln in range(1, m+1):
    a, b, w = lines[ln]
    g[a].append((w, b))
    g[b].append((w, a))


