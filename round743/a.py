from sys import stdin

lines = stdin.readlines()
t= int(lines[0])
for l in range(1, len(lines), 2):
    n = int(lines[l])
    s = lines[l+1].strip()
    #print(n,s)
    sw = (n-1 - s[:-1].count("0"))
    print(sw + sum(int(d) for d in s))


