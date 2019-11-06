#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
const int mod=1e9+7;
vector<int> G[maxn];
long long tree[maxn];
int st[maxn],ed[maxn];
int tot=0;
int far[maxn];
long long minu[maxn];
void dfs(int u)
{
	st[u]=++tot;
	for(int i=0;i<G[u].size();i++)
	{
		dfs(G[u][i]);
	}
	ed[u]=tot;
}
void add(long long x,long long val)
{
	while(x<maxn)
	{
		tree[x]=(tree[x]+val+mod)%mod;
		x+=x&-x;
	}
}
long long query(long long x)
{
	long long ret=0;
	while(x>0)
	{
		ret=(ret+tree[x])%mod;
		x-=x&-x;
	}
	return ret;
}
long long cal(int cur,int dep)
{
	if(cur<=0) return 0;
	long long ret=0;
	ret=cal(far[cur],dep+1)+minu[cur]*dep%mod;
	return ret%mod;
}
int main()
{
	far[1]=-1;
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	for(int i=0,u,v;i<n-1;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		far[v]=u;
	}
	dfs(1);
	int op;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			long long v,x,k;
			cin>>v>>x>>k;
			add(st[v],x);
			add(ed[v]+1,-x);
			minu[v]=(minu[v]+k)%mod;
		}
		else{
			int v;
			cin>>v;
			cout<<(mod-cal(v,0)+query(st[v]))%mod<<endl;
		}
	}
}
