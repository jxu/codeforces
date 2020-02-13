def f(m, n):
    for i in range(2**n):
        bs = bin(i)[2:].zfill(n)
        if bs.count("1") == m:
            count = 0
            for j in range(n):
                for k in range(j,n):
                    if "1" in bs[j:k+1]: count += 1
            print(bs, count)

f(2,8)


