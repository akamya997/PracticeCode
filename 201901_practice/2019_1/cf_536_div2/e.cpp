#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long dp[100005][205];
int nxt[100005];
long long gain[maxn];
const long long INF=0x3f3f3f3f3f3f3f3f;
struct package{
	int s,t,d;
	long long w;
	bool operator <(const package &b)const{
		if(w==b.w) return d<b.d;
		return w<b.w;
	}
}pa[maxn];
int n,m,k;
bool cmp(package a,package b)
{
	return a.s<b.s;
}
int main()
{
	memset(dp,-0x3f,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d%lld",&pa[i].s,&pa[i].t,&pa[i].d,&pa[i].w);
	sort(pa+1,pa+1+k,cmp);
	int cur=1,l=1;
	priority_queue<package> q;
	while(cur<=n)
	{
		while(l<=k&&pa[l].s<=cur)
		{
			q.push(pa[l]);
			l++;
		}
		package fi={-1,-1,-1,-1};
		while(!q.empty())
		{
			fi=q.top();
			q.pop();
			if(fi.s<=cur&&fi.t>=cur) break;
		}
		if(!(fi.s<=cur&&fi.t>=cur)) nxt[cur]=0;
		else {nxt[cur]=fi.d+1;gain[cur]=fi.w;q.push(fi);}
		//printf("%d:%d\n",cur,gain[cur]);
		cur++;
	}
	printf("%lld\n",dp[n][0]);
}
