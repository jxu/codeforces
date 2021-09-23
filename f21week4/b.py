#!/usr/bin/env python3
from collections import defaultdict
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
n, m, k = lines[0]
p = lines[1]

s = [0] * (n-m+1)
s[0] = sum(p[0:m])
for i in range(1, n-m+1):
    s[i] = s[i-1] - p[i-1] + p[i+m-1] 

dp = [[0] * (n-m+1) for _ in range(k)]

for kk in range(k):
    for nn in range(n-m+1):
        dp[kk][nn] = max(s[nn] + (0 if (nn-m < 0 or kk-1 < 0) else dp[kk-1][nn-m]), 
                0 if nn-1 < 0 else dp[kk][nn-1])

print(max(dp[k-1]))

