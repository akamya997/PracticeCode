#include<bits/stdc++.h>
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+7;
vector<long long> posa,posb;
long long Finda(long long  x,int type)
{
	int ret=lower_bound(posa.begin(),posa.end(),x)-posa.begin();
	if(type) return posa[ret];
	else return posa[ret-1];
}
long long Findb(long long x,int type)
{
	int ret=lower_bound(posb.begin(),posb.end(),x)-posb.begin();
	if(type) return posb[ret];
	return posb[ret-1];
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,q;
	long long temp;
	cin>>a>>b>>q;
	posa.push_back(-0x3f3f3f3f);
	posb.push_back(-0x3f3f3f3f);
	for(int i=0;i<a;i++)
	{
		cin>>temp;
		posa.push_back(temp);
	}
	for(int i=0;i<b;i++)
	{
		cin>>temp;
		posb.push_back(temp);
	}
	posa.push_back(0x3f3f3f3f3f3f3f3f);
	posb.push_back(0x3f3f3f3f3f3f3f3f);
	while(q--)
	{
		long long x;
		long long ans=INF;
		cin>>x;
		long long cur=0;
		long long pos=Finda(x,0);
		if(pos>0&&pos<INF) 
		{
			cur=x-pos;
			long long nxt=Findb(pos,0);
			if(nxt>0&&nxt<INF)
			{
				cur+=pos-nxt;
				ans=min(ans,cur);
			}
			cur=x-pos;
			nxt=Findb(pos,1);
			if(nxt>0&&nxt<INF)
			{
				cur+=nxt-pos;
				ans=min(ans,cur);
			}
		}
		cur=0;
		pos=Findb(x,0);
		if(pos>0&&pos<INF) 
		{
			cur=x-pos;
			long long nxt=Finda(pos,0);
			if(nxt>0&&nxt<INF)
			{
				cur+=pos-nxt;
				ans=min(ans,cur);
			}
			cur=x-pos;
			nxt=Finda(pos,1);
			if(nxt>0&&nxt<INF)
			{
				cur+=nxt-pos;
				ans=min(ans,cur);
			}
		}
		cur=0;
		pos=Finda(x,1);
		if(pos>0&&pos<INF)
		{
			cur=pos-x;
			long long nxt=Findb(pos,0);
			if(nxt>0&&nxt<INF)
			{
				cur+=pos-nxt;
				ans=min(ans,cur);
			}
			cur=pos-x;
			nxt=Findb(pos,1);
			if(nxt>0&&nxt<INF)
			{
				cur+=nxt-pos;
				ans=min(ans,cur);
			}
		}
		cur=0;
		pos=Findb(x,1);
		if(pos>0&&pos<INF)
		{
			cur=pos-x;
			long long nxt=Finda(pos,0);
			if(nxt>0&&nxt<INF)
			{
				cur+=pos-nxt;
				ans=min(ans,cur);
			}
			cur=pos-x;
			nxt=Finda(pos,1);
			if(nxt>0&&nxt<INF)
			{
				cur+=nxt-pos;
				ans=min(ans,cur);
			}
		}
		cout<<ans<<endl;
	}
}
