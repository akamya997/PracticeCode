T=int(input())
while True:
    T-=1
    n,a,b,c,d=list(map(int,input().split()))
    ans=-1
    for i in range(62):
        for j in range(40):
            for k in range(30):
                cur=2**i*3**j*5**k
                cost=i*a+b*j+c*k
                cost+=min(cur-n%cur+1,n%cur)*d
                cost+=n//cur*d
                #print(i,j,k,cost)
                if ans==-1:
                    ans=cost
                else :ans=min(ans,cost)
                if cur>n:
                    break
            if 2**i*3**j>n:
                break
        if 2**i > n:
            break
    print(ans)
    if T==0:
        break