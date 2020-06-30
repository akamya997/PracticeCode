#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+7;
int w[N],c[N],id[N],n,W,u;
bool cmp(int i,int j){return (ll)c[i]*w[j]>(ll)c[j]*w[i];}
void solve()
{
    scanf("%d%d",&n,&W);
	for (int i=0;i<n;++i)scanf("%d",w+i),u=max(u,w[i]),id[i]=i;
	sort(id,id+n,cmp);
    int ans=0;
    vector<bool> f(N*N);
    f[0]=1;
	for (int i=1;i<=min(W,u*u);++i)
		for (int j=0;j<min((int)ceil(2.*u*u/i),n);++j)
			if (w[id[j]]<=i)
            {
                if(f[i-w[id[j]]]) f[i]=1;
                if(f[i]) ans=max(i,ans);
            }
	printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
	
	return 0;
}