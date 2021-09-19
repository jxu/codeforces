from sys import stdin
lines = [line.strip() for line in stdin]
t = int(lines[0])
ln = 1
for _ in range(t):
    n, s = int(lines[ln]), lines[ln+1]
    ln += 2
    sw = (n-1 - s[:-1].count("0"))
    print(sw + sum(map(int, s)))

