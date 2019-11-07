#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long quick(long long a,long long b,long long mod)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll BSGS(ll a, ll b, ll p) // a^x = b (mod p)
{
	a %= p;
	if (!a && !b) return 1;
	if (!a) return -1;
	static map<ll, ll> mp; mp.clear();
	ll m = sqrt(p + 1.5);
	ll v = 1;
	for (int i=1;i<m+1; ++i) 
	{
		v = v * a % p;
		mp[v * b % p] = i;
	}
	ll vv = v;
	for (int i=1 ;i<m+1;++i) 
	{
		auto it = mp.find(vv);
		if (it != mp.end()) return i * m - it->second;
		vv = vv * v % p;
	}
	return -1;
}
ll mul(ll a,ll b,ll m)
{
	ll ret=0;
	while(b)
	{
		if(b&1)
		{
			ret+=a;
			if(ret>=m) ret-=m;
		}
		a+=a;
		if(a>=m) a-=m;
		b>>=1;
	}
	return ret;
}
ll mul(ll a,ll b,ll m)
{
	return (a * b-ll((long double) a * b / m) * m + m) % m;
}
ll mul(ll a,ll b,ll m)
{
	ll t = a * b - ll((long double) a * b / m) * m;
	return t < 0 ? t + m : t;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<mul(a,b,100)<<endl;
	}
}
