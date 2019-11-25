import math
class pair:
    def __init__(self,a,b):
        self.x=a
        self.y=b
    def sim(self):
        g=math.gcd(self.x,self.y)
        self.x//=g
        self.y//=g
    def add(self,a):
        ret=pair(self.x*a.y+self.y*a.x,a.y*self.y);
        self.x=ret.x
        self.y=ret.y
        self.sim()
    def check(self):
        if self.y>3*self.x:
            self.x=1
            self.y=3
maxn=10007
mp=[0]*maxn
gp=[0]*maxn
bye=[0]*maxn
match=[0]*maxn
game=[0]*maxn
vis=[0]*maxn
oppo=[]
def getmp(x):
    return mp[x]+bye[x]*3
def getgp(x):
    return gp[x]+bye[x]*6
def getmw(x):
    ret=pair(getmp(x),3*(match[x]+bye[x]))
    ret.check()
    ret.sim()
    return ret
def getgw(x):
    ret=pair(getgp(x),3*(game[x]+bye[x]*2))
    ret.check()
    ret.sim()
    return ret
def getomw(x):
    if match[x]==0:
        return pair(1,3)
    ret=pair(0,1)
    for i in range(1,len(oppo[x])):
        ret.add(getmw(oppo[x][i]))
    sz=len(oppo[x])-1
    ret.y*=sz
    ret.sim()
    return ret
def getogw(x):
    if match[x]==0:
        return pair(1,3)
    ret=pair(0,1)
    for i in range(1,len(oppo[x])):
        ret.add(getgw(oppo[x][i]))
    sz=len(oppo[x])-1
    ret.y*=sz
    ret.sim()
    return ret
def calc(n,m):
    for i in range(1,n+1):
        print(getmp(i),end=' ')
        omw=getomw(i)
        print(str(omw.x)+'/'+str(omw.y),end=' ')
        gw=getgw(i)
        print(str(gw.x)+'/'+str(gw.y),end=' ')
        ogw=getogw(i)
        print(str(ogw.x)+'/'+str(ogw.y))
def solve():
    n,m=list(map(int,input().split()))
    global oppo
    oppo=[]
    for i in range(n+1):
        oppo.append([0])
        mp[i]=0
        gp[i]=0
        match[i]=0
        game[i]=0
        bye[i]=0
    a=list(map(int,input().split()))
    for i in range(m):
        for j in range(n+1):
            vis[j]=0
        for j in range(a[i]):
            p1,p2,w1,w2,d=list(map(int,input().split()))
            oppo[p1].append(p2)
            oppo[p2].append(p1)
            match[p1]+=1
            match[p2]+=1
            game[p1]+=w1+w2+d
            game[p2]+=w1+w2+d
            vis[p1]=1
            vis[p2]=1
            gp[p1]+=d
            gp[p2]+=d
            gp[p1]+=w1*3
            gp[p2]+=w2*3
            if w1>w2:
                mp[p1]+=3
            elif w2>w1:
                mp[p2]+=3
            else:
                mp[p1]+=1
                mp[p2]+=1
        for j in range(1,n+1):
            if vis[j]==0:
                bye[j]+=1
        print("Round "+str(i+1))
        calc(n,m)
def main():
    T=int(input())
    while True:
        solve()
        T-=1
        if T==0:
            break

main()


