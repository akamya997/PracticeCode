#include<iostream>
#include<cstring>
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
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b,ll mod)
{
	a%=mod,b%=mod;
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
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll r,t,m;
	while(cin>>r>>t>>m)
	{
		//ll p,q;
		/*for(int i=2;;i++)
		{
			if(r%i==0)
			{
				p=i,q=r/i;
				break;
			}
		}*/
		//ll pq=(p-1)*(q-1),s;
		/*for(int k=1;k<=100;k++)
		{
			ll rhs=pq*k+1;
			if(rhs%t==0)
			{
				s=rhs/t;
				break;
			}
		}*/
	//	dbg(p,q,pq,s);
		cout<<quick(m,t,r)<<endl;
	}

}
