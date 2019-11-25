#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac;
const int maxn=1e6+7;
vector<int> prime;
bool vis[maxn];
void db()
{
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i]) prime.push_back(i);
		for(int j=i;j<maxn;j+=i)
			vis[j]=1;
	}
}
void factor(ll n)
{
	fac.clear();
	for(auto i:prime)
	{
		if(i>n) break;
		if(n%i==0)
		{
			ll num=1;
			while(n%i==0) n/=i,num*=i;
			fac.push_back(num);
		}
	}
	if(n>1) fac.push_back(n);
}
ll ans=1e18;
ll exgcd(ll a,ll b,ll& x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
void dfs(int x,ll a,ll b)
{
	if(x==fac.size())
	{
		ll p,q;
		ll d=exgcd(a,-b,p,q);
	//	cout<<a<<" "<<b<<" "<<p<<" "<<q<<" "<<d<<endl;
		q/=d;
		q%=a;
		if(q<=0) q+=a;
		ans=min(ans,q*b);
		return;
	}
	dfs(x+1,a*fac[x],b);
	dfs(x+1,a,b*fac[x]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	db();
	int T;
	cin>>T;
	while(T--)
	{
		ans=1e18;
		ll n;
		cin>>n;
		n*=2;
		factor(n);
	//	cout<<fac.size()<<endl;
		dfs(0,1,1);
		cout<<ans<<endl;
	}
}
