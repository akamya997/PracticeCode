import math
T=int(input())
kas=0
alphabet=['A','B','C','D','E','F','G','H','I','J','K','L'\
,'M',"N",'O','P','Q','R','S','T','U','V','W','X','Y','Z']
while True :
    if T==0:
        break;
    T-=1;
    line=input()
    line=line.split()
    n=int(line[0])
    L=int(line[1])
    tot=[]
    prime=[]
    line=input()
    for i in line.split():
        tot.append(int(i))
    ans=[0]*(L+1)
    for i in range(1,L):
        GCD=math.gcd(tot[i],tot[i-1])
        if tot[i]!=tot[i-1]:
            prime.append(GCD)
            prime.append(tot[i]/GCD)
            prime.append(tot[i-1]/GCD)
            ans[i]=GCD;
            ans[i-1]=tot[i-1]/GCD
            if i!=L-1:
                ans[i+1]=tot[i+1]/GCD
    prime.sort()
    new_prime=[]
    for i in prime:
        if i not in new_prime:
            new_prime.append(i)
    for i in range(1,L):
        if ans[i]==0:
            if tot[i]==tot[i-1]:
                ans[i]=ans[i-1]
    if ans[L]==0:
        ans[L]=ans[L-1]
    for i in range(L-2,-1,-1):
        if ans[i]==0:
            if tot[i]==tot[i+1]:
                ans[i]=ans[i+1]
    op=""
    for i in ans:
        cnt=-1
        for p in new_prime:
            cnt+=1
            if i==p:
                op+=alphabet[cnt]
                break
    kas+=1
    print("Case #"+str(kas)+": "+op)
            
    
    
