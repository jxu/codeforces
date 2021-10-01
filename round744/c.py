#!/usr/bin/env pypy3
from sys import stdin

lines = [line.strip() for line in stdin]
t = int(lines[0])
ln = 1
for _ in range(t):
    n, m, k = map(int, lines[ln].split())
    ln += 1
    g = [[int(c == "*") for c in lines[ln+i]] for i in range(n)]
    ln += n

    # reachable
    r = [[0]*m for i in range(n)]

    for i in range(k, n):
        for j in range(k, m-k):
            # check size k tick
            if not all((g[i-h][j-h] and g[i-h][j+h]) for h in range(k+1)):
                continue

            # mark size k tick
            for h in range(k+1):
                r[i-h][j-h] = r[i-h][j+h] = 1

            # try increasing d from k
            d = k+1
            while i - d >= 0 and j - d >= 0 and j+d < m and \
                g[i-d][j-d] and g[i-d][j+d]:
                    r[i-d][j-d] = r[i-d][j+d] = 1
                    d += 1


    print("YES" if g == r else "NO")

