#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
struct friends{
	long long A,E,D;
	int id;
	bool operator<(const friends b)const{
		return D<b.D;
	}
}fri[maxn];
bool cmp(const friends &a,const friends &b){return a.A<b.A;}
bool vis[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&fri[i].A,&fri[i].E,&fri[i].D);
		fri[i].id=i;
	}
	sort(fri,fri+n,cmp);
	priority_queue<int> q;
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<n;i++)
	{
		int mx=fri[i].E;
		while(!q.empty()) q.pop();
		for(int j=0;j<n;j++)
		{
			if(fri[j].E>mx) continue;
			q.push(fri[j].D);
			if(q.size()>k)
				q.pop();
			if(q.size()==k) 
				ans=min(ans,fri[j].A+mx+q.top());
		}
	}
	printf("%lld\n",ans);
}
