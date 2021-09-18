from sys import stdin

lines = stdin.readlines()
t= int(lines[0])
for l in range(1, len(lines), 3):
    n = int(lines[l])
    a = list(map(int, lines[l+1].strip().split()))
    b = list(map(int, lines[l+2].strip().split()))
    m = [0] * (2*n+1)
    for i in range(n):
        m[a[i]] = i
        m[b[i]] = i

    s = [1e7]*(n+1)
    #print(m)

    for i in range(1,n+1):
        s[i] = min(m[2*i-1], s[i-1])
        
    #print(s[1:])

    for i in range(1, n+1):
        s[i] += m[2*i]

    #print(s[1:])

    print(min(s[1:]))

