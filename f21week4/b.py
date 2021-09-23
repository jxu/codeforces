#!/usr/bin/env python3
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
N, M, K = lines[0]
p = lines[1]

s = [0] * (N-M+1)
s[0] = sum(p[0:M])
for i in range(1, N-M+1):
    s[i] = s[i-1] - p[i-1] + p[i+M-1]  # sliding window

dp = [0] * (N-M+1)

for k in range(K):
    new_dp = [0] * (N-M+1)

    for n in range(N-M+1):
        new_dp[n] = max(s[n] + (0 if (n-M < 0 or k-1 < 0) else dp[n-M]), 
                0 if n-1 < 0 else new_dp[n-1])
    dp = new_dp

print(max(dp))

