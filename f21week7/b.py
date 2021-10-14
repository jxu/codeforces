#!/usr/bin/env pypy3
from sys import stdin

lines = [list(map(int, line.strip().split())) for line in stdin]
n, k = lines[0]
a = lines[1]
n = len(a)
a_pre = [None]*n
a_post = [None]*n
a_pre[0] = a[0]
a_post[n-1] = a[n-1]
for i in range(1, len(a)):
    a_pre[i] = min(a_pre[i-1], a[i])
for i in range(n-2, 0, -1):
    a_post[i] = min(a_post[i+1], a[i]) 


if k == 1:
    print(min(a))
elif k == 2:
    print(max(max(a_pre[i-1], a_post[i]) for i in range(1, len(a))))
else:
    print(max(a))

