#!/usr/bin/env pypy3
from sys import stdin
from collections import defaultdict

lines = [line.strip().split() for line in stdin]
t = int(lines[0][0])

g = defaultdict(list)
visited = defaultdict(bool)
depth = dict()

for ln in range(1, t+1):
    name1, name2 = lines[ln][0].lower(), lines[ln][2].lower()
    g[name2].append(name1)


def dfs(v, d):
    visited[v] = True
    depth[v] = d
    for w in g[v]:
        if not visited[w]:
            dfs(w, d+1)

dfs("polycarp", 1)
print(max(depth.values()))
