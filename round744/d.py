#!/usr/bin/env pypy3
from sys import stdin
import heapq

lines = [list(map(int, line.strip().split())) for line in stdin]
t = lines[0][0]
ln = 1
for _ in range(t):
    n, a = lines[ln][0], lines[ln+1]
    ln += 2
    s = []
    m = [[-a[i], i+1] for i in range(n)]
    heapq.heapify(m)

    while True:
        a = heapq.heappop(m)
        b = heapq.heappop(m)
        if b[0] == 0: break

        s.append((a[1], b[1]))       

        a[0] += 1
        b[0] += 1
        heapq.heappush(m, a)
        heapq.heappush(m, b)
        
    print(len(s))
    if len(s): print("\n".join(f"{p[0]} {p[1]}" for p in s))

