from sys import stdin
from bisect import bisect_left

lines = stdin.readlines()
n = int(lines[0])
b = []
dp = [0]*n

for line in map(str.strip, lines[1:]):
    x, y = map(int, line.strip().split())
    b.append((x,y))

b.sort()

pos = [x[0] for x in b]
pow = [x[1] for x in b]

for i in range(1,n):
    j = bisect_left(pos, pos[i]-pow[i])
    if j == 0: dp[i] = i
    else: dp[i] = dp[j-1] + i-j

#print(dp)

for i in range(n):
    dp[i] += n-i-1

print(min(dp))


