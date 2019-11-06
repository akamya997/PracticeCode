import math
T=int(input())
while True:
    if T==0:
        break
    T-=1
    n,m=int(input().split())
    print(math.gcd(5**n+7**n,5**m+7**m))
