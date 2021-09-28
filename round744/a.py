#!/usr/bin/env pypy3
from sys import stdin

lines = [line.strip() for line in stdin]; t = int(lines[0])  # one string per line
for i in range(1,t+1):
    l = lines[i]
    print("YES" if l.count("B") == l.count("A") + l.count("C") else "NO")
