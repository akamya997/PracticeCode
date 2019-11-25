#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
int n;
string s,t;
bool ok=0;
bool check(string cur)
{
	for(int i=1;i<cur.length();i++)
	{
		if((cur[i]==s[1]&&cur[i-1]==s[0])||(cur[i]==t[1]&&cur[i-1]==t[0])) return false;
	}
	return true;
}
string solve1()
{
	string ret="abc";
	do
	{
		ok=check(ret);
		if(ok) break;
	}while(next_permutation(ret.begin(),ret.end()));
	return ret;
}
string solve2()
{
	string ret="abc";
	string cc=ret+ret;
	do
	{
		cc=ret+ret;
		ok=check(cc);
		if(ok) break;
	}while(next_permutation(ret.begin(),ret.end()));
	return ret;
}
int main()
{
	cin>>n;
	cin>>s>>t;
	if(n==1)
	{
		string ans=solve1();
		if(ok){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else cout<<"NO"<<endl;
	}
	else{
		string ans=solve2();
		if(ok)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++) cout<<ans;
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
