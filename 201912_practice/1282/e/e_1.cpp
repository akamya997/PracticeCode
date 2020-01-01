#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int maxn=1e5+7;
set<int> pt[maxn];
bool vis[maxn];
bool inq[maxn];
bool dvis[maxn];
vi per;
vi G[maxn];
inline void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
	cerr<<u<<" "<<v<<endl;
}
void dfs(int u,int fa=-1)
{
	if(dvis[u]) return;
	dvis[u]=1;
	per.push_back(u);
	for(auto v:G[u])if(v!=fa)
		dfs(v,u);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		per.clear();
		int n;
		cin>>n;
		for(int i=0;i<=n;i++) pt[i].clear(),vis[i]=0,inq[i]=0,G[i].clear(),dvis[i]=0;
		vector<tuple<int,int,int> > all;
		map<pi,int> ext;
		for(int i=1,a,b,c;i<=n-2;i++)
		{
			cin>>a>>b>>c;
			a--,b--,c--;
			if(a>b) swap(a,b);
			if(b>c) swap(b,c);
			if(a>b) swap(a,b);
			ext[make_pair(a,b)]++;
			ext[make_pair(a,c)]++;
			ext[make_pair(b,c)]++; 
			pt[a].insert(i);
			pt[b].insert(i);
			pt[c].insert(i);
			all.emplace_back(a,b,c);
		}
		for(auto u:ext)
		{
			if(u.second==1)
				add(u.first.first,u.first.second);
		}
		vi ans;
		queue<int> q,q2;
		for(int i=1,a,b,c;i<=n-2;i++)
		{
			tie(a,b,c)=all[i-1];
			if(pt[a].size()==1||pt[b].size()==1||pt[c].size()==1)
				q2.push(i);
		}
		q.push(q2.front());q2.pop();
		while(!q.empty())
		{
			auto u=q.front();
			q.pop();
			int a,b,c;
			tie(a,b,c)=all[u-1];
			pt[a].erase(u);
			pt[b].erase(u);
			pt[c].erase(u);
			ans.push_back(u);
			if(pt[a].size()==1)
			{
				if(!inq[*pt[a].begin()])
					q.push(*pt[a].begin());
				inq[*pt[a].begin()]=1;
			}
			if(pt[b].size()==1)
			{
				if(!inq[*pt[b].begin()])
					q.push(*pt[b].begin());
				inq[*pt[b].begin()]=1;
			}
			if(pt[c].size()==1)
			{
				if(!inq[*pt[c].begin()])
					q.push(*pt[c].begin());
				inq[*pt[c].begin()]=1;
			}
			if(q.empty())
			{
				while(!q2.empty()&&inq[q2.front()]) q2.pop();
				if(!q2.empty()) 
				{
					q.push(q2.front());
					q2.pop();
				}
			}
		}
		dfs(0,-1);
		for(auto u:per) cout<<u+1<<" ";
		cout<<'\n';
		for(auto u:ans) cout<<u<<" ";
		cout<<'\n';

	}
}
