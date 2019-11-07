#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
const int INF=0x3f3f3f3f;
int arr[maxn];
int dp[maxn][2],dpr[maxn][2];
int n;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct Seg{
	int mx[maxn<<2];
	void init()
	{
		for(int i=0;i<((n+1)<<2);i++)
			mx[i]=0;
	}
	void pushup(int o)
	{
		mx[o]=max(mx[lson],mx[rson]);
	}
	void update(int x,int val,int L=1,int R=n+1,int o=1)
	{
		if(L==R)
		{
			mx[o]=max(mx[o],val);
			return;
		}
		int mid=L+R>>1;
		if(x<=mid)
			update(x,val,Lson);
		else update(x,val,Rson);
		pushup(o);
	}
	int query(int l,int r,int L=1,int R=n+1,int o=1)
	{
		if(l<=L&&r>=R)
			return mx[o];
		int mid=L+R>>1;
		int ret=0;
		if(l<=mid) ret=max(ret,query(l,r,Lson));
		if(r>mid) ret=max(ret,query(l,r,Rson));
		return ret;
	}
}zero,one;
vector<int> all;
vector<int> ans[2];
vector<int> up[10],down[10];
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
bool cmp(int i,int j){return arr[i]>arr[j];}
bool cmp2(int i,int j){return arr[i]<arr[j];}
int main()
{
	while(~scanf("%d",&n))
	{
		all.clear();
		zero.init();one.init();
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&arr[i]);
			all.push_back(arr[i]);
		}
		all.push_back(0);
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=1;i<=n;i++)
			arr[i]=getid(arr[i]);
		int mxlen=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=zero.query(1,arr[i]-1)+1;
			dp[i][1]=max(one.query(arr[i]+1,n+1)+1,dp[i][0]);
			zero.update(arr[i],dp[i][0]);
			one.update(arr[i],dp[i][1]);
	//		cout<<i<<":"<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		zero.init();
		one.init();
		for(int i=n;i>=1;i--)
		{
			dpr[i][0]=zero.query(1,arr[i]-1)+1;
			dpr[i][1]=max(one.query(arr[i]+1,n+1)+1,dpr[i][0]);
			zero.update(arr[i],dpr[i][0]);
			one.update(arr[i],dpr[i][1]);
		}
		for(int i=1;i<=n;i++) mxlen=max(mxlen,dp[i][0]+dpr[i][1]-1);
		for(int i=0;i<=n;i++)
		{
			up[i].clear();
			down[i].clear();
		}
		for(int i=1;i<=n;i++) 
		{
			//cout<<i<<":"<<dpr[i][0]<<" "<<dpr[i][1]<<endl;
			if(dp[i][0]+dpr[i][1]-1==mxlen) 
			{
				up[dp[i][0]].push_back(i);
			}
			if(dp[i][1]+dpr[i][0]-1==mxlen) down[dpr[i][0]].push_back(i);
		}
		ans[0].clear();
		ans[1].clear();
		int cur=0,o=0;
		for(int i=0;i<mxlen;i++)
		{
			arr[0]=0;
			int mi[2]={n+1,n+1};
			if(!o)
			{
				auto& v=up[i+1];
				int p=upper_bound(v.begin(),v.end(),cur)-v.begin();
				if(p<v.size()&&arr[cur]<arr[v[p]]) mi[0]=v[p];
			}
			arr[0]=INF;
			auto &v=down[mxlen-i];
			int p=upper_bound(v.begin(),v.end(),cur)-v.begin();
			if(p<v.size()&&arr[cur]>arr[v[p]]) mi[1]=v[p];
			if(mi[0]<mi[1]) cur=mi[0];
			else cur=mi[1],o=1;
			ans[0].push_back(cur);
		}
		cur=o=0;
		for(int i=0;i<mxlen;i++)
		{
			arr[0]=0;
			int mx[2]={0,0};
			if(!o)
			{
				auto &v=up[i+1];
				int p=lower_bound(v.begin(),v.end(),cur,cmp)-v.begin()-1;
				if(p>=0&&arr[cur]<arr[v[p]]) mx[0]=v[p];
			}
			arr[0]=INF;
			auto &v=down[mxlen-i];
			int p=lower_bound(v.begin(),v.end(),cur,cmp2)-v.begin()-1;
			if(p>=0&&arr[cur]>arr[v[p]]) mx[1]=v[p];
			if(mx[0]>mx[1]) cur=mx[0];
			else cur=mx[1],o=1;
			ans[1].push_back(cur);

		}
		for(int t=0;t<2;t++)
		for(int i=0;i<mxlen;i++) printf("%d%c",ans[t][i],i==mxlen-1?'\n':' ');
	}
}
