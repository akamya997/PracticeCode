#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+7,mod=998244353;
pair<int,int> dolls[N];
int n;
int main()
{
	vector<int> seperate;
	cin>>n;	
	for(int i=1;i<=n;++i)
	{
		cin>>dolls[i].first>>dolls[i].second;
		seperate.push_back(dolls[i].first);
		seperate.push_back(dolls[i].second);
	}
	sort(seperate.begin(),seperate.end());
	seperate.erase(unique(seperate.begin(),seperate.end()),seperate.end());
	int m=seperate.size();
	vector<int> empv
	vector<vector<int>> head(m+1,empv),tail(m+1,empv);
	for(int i=1;i<=n;++i)
	{
		dolls[i].first=lower_bound(seperate.begin(),seperate.end(),dolls[i].first)-seperate.begin();
		dolls[i].second=lower_bound(seperate.begin(),seperate.end(),dolls[i].second)-seperate.begin();
		tail[dolls[i].first].push_back(i);
		head[dolls[i].second].push_back(i);
	}
	ll all=1;
	priority_queue<pair<int,int>> q;
	q.push(make_pair(0x3f3f3f3f-1,1));
	vector<int> val(n+1,0);
	for(int i=m-1;i>=0;--i)
	{
		int mm=0x3f3f3f3f;
		for(auto &x:head[i])
		{
			mm=min(dolls[x].first,mm);
			all=(all+val[x])%mod;
			q.push(make_pair(i,val[x]));
		}
		while(!q.empty()&&q.top().first>=mm)
		{
			all=(all+mod-q.top().second)%mod;
			q.pop();
		}
		for(auto &x:tail[i])
			val[x]=all;
	}
	ll ans=0;
	while(!q.empty())
	{
		ans=(ans+q.top().second)%mod;
		q.pop();
	}
	cout<<ans<<endl;
}
