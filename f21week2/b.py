from sys import stdin
s = [0] * 2**18 

lines = stdin.readlines()[1:]
for line in lines:
    op, val = line.strip().split()
    val2 = ''.join(str(int(d)%2) for d in val)

    if op in "+-":
        s[int(val2,2)] += 1 if op == "+" else -1
    else:
        print(s[int(val2,2)])
    
