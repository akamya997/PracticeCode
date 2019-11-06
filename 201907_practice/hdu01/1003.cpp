#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=998244353;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
vector<int> row,col;
inline int getid(int x,int type)
{
	if(type==1)
		return lower_bound(row.begin(),row.end(),x)-row.begin();
	return lower_bound(col.begin(),col.end(),x)-col.begin();
}
const int maxn=1e4+7;
struct Point{
	int r,c,t;
	bool operator<(const Point a)const{
		return c<a.c;
	}
}pt[maxn];
typedef vector<ll> vi;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		row.clear();col.clear();
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		vi ans(k+1,INF);
		int midline=(m+1)/2;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&pt[i].r,&pt[i].c,&pt[i].t);
			row.push_back(pt[i].r);
			col.push_back(pt[i].c);
		}
		col.push_back(1);
		row.push_back(1);
		col.push_back(midline);
		sort(row.begin(),row.end());
		sort(col.begin(),col.end());
		row.erase(unique(row.begin(),row.end()),row.end());
		col.erase(unique(col.begin(),col.end()),col.end());
		//dbg(row,col);
		vector<Point> ext[row.size()];
		midline=getid(midline,2);
		for(int i=0;i<k;i++) 
		{
			pt[i].r=getid(pt[i].r,1),pt[i].c=getid(pt[i].c,2);
			ext[pt[i].r].push_back(pt[i]);
		}
		vi dp(k+1,INF),dpback(k+1,INF);
		int tot=0;
		for(int i=0;i<row.size();i++)
		{
			tot+=ext[i].size();
			if(i==0&&ext[i].size())
			{
				sort(ext[i].begin(),ext[i].end());
				dp[0]=0;dpback[0]=col[midline]-1;
				vi cost(tot+1,INF);
				cost[0]=0;
				for(auto p:ext[i])
				{
					for(int i=tot;i>=1;i--)
						cost[i]=min(cost[i],cost[i-1]+p.t);
					for(int i=tot;i>=1;i--)
					{
						dp[i]=min(dp[i],cost[i]+abs(col[0]-col[p.c]));
						dpback[i]=min(dpback[i],dp[i]+abs(col[midline]-col[p.c]));
					}
				}
				dbg(dp);
				dbg(dpback);
				//dbg(dp);
			}
			else if(!i){
				dp[0]=0;
				dpback[0]=col[midline]-1;
			}
			else{
				int ki=ext[i].size()+1;
				vi cost(ki,INF);
				vi le(ki,INF),leback(ki,INF),ri(ki,INF),riback(ki,INF);
				vector<Point> l,r;
				for(auto u:ext[i])
				{
					if(u.c<midline) l.push_back(u);
					else r.push_back(u);
				}
				sort(l.begin(),l.end());
				sort(r.begin(),r.end());
				reverse(l.begin(),l.end());
				le[0]=0;leback[0]=0;
				ri[0]=0,riback[0]=0;
				cost[0]=0;
				for(auto p:l)
				{
					for(int j=ki-1;j>=1;j--)
						cost[j]=min(cost[j],cost[j-1]+p.t);
					for(int j=ki-1;j>=1;j--)
					{
						le[j]=min(le[j],cost[j]+abs(col[midline]-col[p.c]));
						leback[j]=min(leback[j],le[j]+abs(col[midline]-col[p.c]));
					}
					//dbg(p.c,le);
				}
				cost=vi(ki,INF);
				cost[0]=0;
				for(auto p:r)
				{
					for(int j=ki-1;j>=1;j--)
						cost[j]=min(cost[j],cost[j-1]+p.t);
					for(int j=ki-1;j>=1;j--)
					{
						ri[j]=min(ri[j],cost[j]+abs(col[midline]-col[p.c]));
						riback[j]=min(riback[j],ri[j]+abs(col[midline]-col[p.c]));
					}
				}
				vi curline(ki,INF),curlineback(ki,INF);
				curline[0]=0;curlineback[0]=0;
				for(int i=0;i<ki;i++)
				{
					for(int j=0;i+j<ki;j++)
					{
						curline[i+j]=min(leback[i]+ri[j],curline[i+j]);
						curline[i+j]=min(curline[i+j],le[i]+riback[j]);
						curlineback[i+j]=min(curlineback[i+j],leback[i]+riback[j]);
					}
				}
				dbg(curline);dbg(curlineback);
				dbg(dp);
				dbg(dpback);
				for(int j=tot;j>=0;j--) 
				{
					if(dp[j]==INF) continue;
					dpback[j]+=row[i]-row[i-1];
					dp[j]=dpback[j];
				}
				dbg(dp);
				vi newdp(k+1,INF),newdpback(k+1,INF);
				for(int j=0;j<=tot;j++)
				{
					for(int l=0;l<ki&&l+j<=tot;l++)
					{
						newdp[j+l]=min(newdp[l+j],dp[j]+curline[l]);
						newdpback[l+j]=min(newdpback[l+j],dpback[j]+curlineback[l]);
					}
				}
				dp=newdp;dpback=newdpback;
				dbg(dp);
				dbg(dpback);
			}
	//		dbg(i,ans);
			for(int j=1;j<=tot;j++)
				ans[j]=min(ans[j],dp[j]);
		}
		for(int i=1;i<=k;i++)
			printf("%lld%c",ans[i],i==k?'\n':' ');
	}
}
