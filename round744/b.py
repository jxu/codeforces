#!/usr/bin/env pypy3
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
t = lines[0][0]
ln = 1
for _ in range(t):
    n, a = lines[ln][0], lines[ln+1]
    ln += 2
    
    sol = []
    for l in range(n):
        na = a[l:]
        d = na.index(min(na))
        if d != 0:
            sol.append(f"{l+1} {n} {d}")
            a = a[:l] + na[d:] + na[:d]

            #print(a)

    print(len(sol))
    print("\n".join(sol))



