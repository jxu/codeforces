n, k = map(int, input().split())
p = (-3 + round((9 + 8*n + 8*k)**0.5))//2 
print(n-p)
