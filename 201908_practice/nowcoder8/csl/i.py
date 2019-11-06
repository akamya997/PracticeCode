import re
ans = [0]*100000
delta = 32768
mx = 32768+32767
ff=0;
while True:
    try:
        s=input()
    except:
        break
    t=re.findall(r"\d+",s)
    a=list(map(int,t))
    if len(a)==0:
        break
    if len(a)==1:
        if s[3]=='>':
            for i in range(a[0],mx+1):
                ans[i]=1
        else:
            for i in range(0,a[0]+1):
                ans[i]=1
    else:
        for i in range(a[0],a[1]+1):
            ans[i]=1
ou = []
pre = 0
for i in range(0,mx+1):
    if 
