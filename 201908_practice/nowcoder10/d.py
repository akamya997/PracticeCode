def exgcd(a,b):
    if b==0:
        return [a,1,0]
    d=exgcd(b,a%b)
    return [d[0],d[2],d[1]-d[2]*(a//b)]

n,tar=list(map(int,input().split()))
m=[]
r=[]
for i in range(n):
    a,b=list(map(int,input().split()))
    m.append(a)
    r.append(b)
M=m[0]
R=r[0]
ok=1
for i in range(1,n):
    d=exgcd(M,m[i])
    if (r[i]-R)%d[0]!=0:
        ok=-1
        break
    x=(r[i]-R)//d[0]*d[1]%(m[i]//d[0])
    R+=x*M
    M=M//d[0]*m[i]
    R=R%M
if R<0:
    R=R+M
if ok==-1:
    print('he was definitely lying')
elif R>tar:
    print('he was probably lying')
else :
    print(R)
