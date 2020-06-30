s=input()
s=s.split('+')
ans=0
for u in s:
    if u.find('d')==-1:
        ans=ans+(int)(u)*2
    else:
        n,x=u.split('d')
        n=int(n)
        x=int(x)
        ans=ans+(1+x)*n
print(ans//2,end='')
if ans%2==1:
    print('.5')