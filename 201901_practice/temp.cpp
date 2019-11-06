#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> G[maxn];
int arr[maxn];
int n;
bool vis[maxn];
int dep[maxn];
int dfs(int u)
{
	if(vis[u]) return dep[u];
	vis[u]=1;
	if(!G[u].size()) dep[u]=1;
	else{	
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			dep[u]=max(dep[u],dfs(v)+1);
		}
	}
	return dep[u];
}
void solve()
{
	memset(dep,0,sizeof(dep));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
//		ans+=arr[i]-dep[i];
		cout<<dep[i]<<" ";
	}
	cout<<endl;
//	if(ans%2!=0) cout<<"CSL"<<endl;
//	else cout<<"ybmj"<<endl;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int pre=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(i==1) continue;
		if(arr[i]>arr[i-1]) G[i].push_back(i-1);
		else G[i-1].push_back(i);
	}
	solve();

}
