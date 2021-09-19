from sys import stdin
from bisect import bisect_left

lines = [list(map(int, line.strip().split())) for line in stdin]
n = lines[0][0]
dp = [0]*n
pairs = sorted(lines[1:])
pos, pow = zip(*pairs)

for i in range(n):
    j = bisect_left(pos, pos[i]-pow[i])
    dp[i] = i if j == 0 else dp[j-1] + i-j

for i in range(n):
    dp[i] += n-i-1

print(min(dp))


