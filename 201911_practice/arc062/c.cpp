#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const ll MX=1e18+7;
int main()
{
	int n;
	cin>>n;
	ll tcnt=0,acnt=0;
	for(int i=1;i<=n;i++)
	{
		ll t,a;
		cin>>t>>a;
		int g=__gcd(t,a);
		t/=g;a/=g;
		ll L=1,R=MX,j=-1;
		while(L<=R)
		{
			ll mid=L+R>>1;
			if((__int128)t*mid>=tcnt&&(__int128)a*mid>=acnt)
			{
				R=mid-1;
				j=mid;
			}
			else L=mid+1;
		}
		tcnt=t*j;
		acnt=a*j;
		assert(j!=-1);
	}
	cout<<tcnt+acnt<<endl;
}
