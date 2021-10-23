n = int(input())
# math.comb in python 3.8+
print(n*(n+1)*(n+2)*(n+3)*(n+4)//120 * n*(n+1)*(n+2)//6)
