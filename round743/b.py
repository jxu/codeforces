from sys import stdin
lines = [list(map(int, line.strip().split())) for line in stdin]
t = lines[0][0]
ln = 1
for t_ in range(t):
    n, a, b = lines[ln][0], lines[ln+1], lines[ln+2]
    ln += 3
    dist = [0]*(2*n+1)
    for i in range(n):
        dist[a[i]] = i
        dist[b[i]] = i

    best = [1e7]*(n+1)

    for i in range(1, n+1):
        best[i] = min(dist[2*i-1], best[i-1])

    for i in range(1, n+1):
        best[i] += dist[2*i]

    print(min(best))

