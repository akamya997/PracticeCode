n=int(input())
all=[]
for i in range(n):
    s=input()
    s=s.replace('.','}')
    all.append(s)
ans=0
all.sort()
#print(all)
for i in range(0,len(all)-1):
    cur=all[i]
    if len(cur)>=4 and cur[-4:]=="}eoj":
        cur+='/'
        if len(all[i+1])>=len(cur) and all[i+1][:len(cur)]==cur:
            continue
        else: ans+=1
cur=all[-1]
if len(cur)>=4 and cur[-4:]=="}eoj":
    ans+=1
print(ans)