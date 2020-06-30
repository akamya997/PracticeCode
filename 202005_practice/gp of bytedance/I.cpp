#include<bits/stdc++.h>
#define co const
#define il inline
using namespace std;
typedef unsigned long long ULL;

co int N=(1<<20)+10;
co ULL base=131;
char str[N];int n;
ULL pw[N],hs[N];

il ULL calc(int l,int r){
	return hs[r]-hs[l-1]*pw[r-l+1];
}
int lcp(int x,int y){ // str[x:],str[y:]
	int l=0,r=n-max(x,y)+1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(calc(x,x+mid-1)==calc(y,y+mid-1)) l=mid;
		else r=mid-1;
	}
	return l;
}
il bool cmp(int x,int y){ // str[x:]<str[y:]
	int len=lcp(x,y);
	if(len==n-max(x,y)+1) return x>y; // partition by >=
	return str[x+len]<str[y+len];
}

int r[N],st[N],top;
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",str+1);
        top=0;
        pw[0]=1;
        for(int i=1;i<=n;++i){
            pw[i]=pw[i-1]*base;
            hs[i]=hs[i-1]*base+str[i];
        }
        for(int i=1;i<=n;++i){
            while(top&&cmp(i,st[top])) r[st[top--]]=i;
            st[++top]=i;
        }
        while(top) r[st[top--]]=n+1;
        for(int i=1;i<=n;i++) printf("%d ",r[i]-i);
        puts("");
    }
	return 0;
}