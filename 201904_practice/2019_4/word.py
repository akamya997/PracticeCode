import time
words={}
tot=[]
pre={}
def dfs(s):
    if len(s)==0:
        return True;
    if words.get(s,0)==0:
        return False
    ret = 0
    for i in range(len(s)):
        nxt = s[0:i]+s[i+1:len(s)]
        if dfs(nxt):
            pre.update({s:nxt})
            return True;
    return False

def main():
    In=open("words.txt","r")
    for i in In:
        i=i.strip()
        words.update({i:1})
        tot.append(i)
    maxlen=0
    ans=''
    for word in tot:
        if len(word)>maxlen and dfs(word):
            maxlen=len(word)
            ans=word
    while len(ans)!=1:
        print(ans)
        ans=pre[ans]

st=time.time()
main()
print(time.time()-st)
