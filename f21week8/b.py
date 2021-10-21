n = int(input())

s = 1
for k in range(n, 5+n):
    s *= k
s //= 120
for k in range(n, 3+n):
    s *= k
s//=6
print(s)
