#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+7;

vector<pair<char,int>> G[N];
int dis[N];
bool vis[N];
struct D
{
	int x,d;
	bool operator<(const D &t)const
	{
		return d>t.d;
	}
};

void DJ(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<D> q;
	q.push(D{s,0});
	while(!q.empty())
	{
		D cur=q.top();q.pop();
		if(vis[cur.x])
			continue;
		vis[cur.x]=1;
		for(auto &e:G[cur.x])
			if(!vis[e.second]&&dis[cur.x]+1<dis[e.second])
			{
				dis[e.second]=dis[cur.x]+1;
				q.push(D{e.second,dis[e.second]});
			}
	}
}
int pre[N];
vector<int> ans;
int n,m;
string bfs()
{
	string ans;
    vector<int> cur;
    cur={1};
    for(int i=0;i<dis[1];i++)
    {
        char mi='z';
        vector<int> nxt;
        for(auto u:cur)
        {
            for(auto &e:G[u])
            {
                if(dis[e.second]==dis[u]-1)
                    mi=min(mi,e.first);
            }
        }
        for(auto u:cur)
        {
            for(auto &e:G[u])
            {
                if(dis[e.second]==dis[u]-1&&e.first==mi)
                {
                    nxt.push_back(e.second);
                    pre[e.second]=u;
                }
            }
        }
        ans+=mi;
        sort(nxt.begin(),nxt.end());
        nxt.erase(unique(nxt.begin(),nxt.end()),nxt.end());
        cur=nxt;
    }
    return ans;
}
int main()
{
	cin>>n>>m;
	int u,v;
	char c;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>c;
		G[u].emplace_back(c,v);
		G[v].emplace_back(c,u);
	}
	for(int i=1;i<=n;++i)
		sort(G[i].begin(),G[i].end());
	DJ(n);
	string op=bfs();
    vector<int> path;
	cout<<dis[1]<<endl;
    path.push_back(n);
    while(path.back()!=1)
        path.push_back(pre[path.back()]);
    reverse(path.begin(),path.end());
    for(int i=0;i<=dis[1];i++)
        cout<<path[i]<<" \n"[i==dis[1]];
    cout<<op<<'\n';
}