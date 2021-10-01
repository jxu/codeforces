t = int(input())
for _ in range(t):
    n = int(input())
    s = 1
    # div by 2 by skipping 2
    for i in range(3, 2*n+1):
        s = (s * i) % 1000000007

    print(s)

