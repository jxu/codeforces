t = int(input())
for _ in range(t):
    l = input()
    print("YES" if l.count("B") == l.count("A") + l.count("C") else "NO")
