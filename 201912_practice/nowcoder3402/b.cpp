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
typedef pair<int,int> pi;
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

const int maxn=1e5+7;
int h[maxn];
int st[maxn];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++) cin>>h[i];
		h[n+1]=0;
		stack<int> s;
		ll ans=0,hi=-1,idx=-1;
		for(int i=1;i<=n;i++)
		{
			while(!s.empty()&&h[s.top()]>h[i])
			{
				ll curans=1LL*h[s.top()]*(i-st[s.top()]-1);
			//	dbg(i,s.top(),curans,h[s.top()],st[s.top()]);
				if(curans>=ans)
				{
					if(curans==ans)
					{
						if(st[s.top()]+1<idx)
						{
							idx=st[s.top()]+1;
							hi=h[s.top()];
						}
					}
					else{
						ans=curans;
						idx=st[s.top()]+1;
						hi=h[s.top()];
					}
				}
				s.pop();
			}
			st[i]=(s.size()?s.top():0);
			s.push(i);
		}
		while(!s.empty())
		{
			ll curans=1LL*h[s.top()]*(n-st[s.top()]);
			if(curans>=ans)
			{
				if(curans==ans)
				{
					if(st[s.top()]+1<idx)
					{
						idx=st[s.top()]+1;
						hi=h[s.top()];
					}
				}
				else{
					ans=curans;
					idx=st[s.top()]+1;
					hi=h[s.top()];
				}
			}
			s.pop();
		}
		cout<<hi<<" "<<ans<<'\n';
	}
}
