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
const int INF=0x3f3f3f3f;
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
struct S {
  int x , y;
  S(){}
  S(int x,int y):x(x),y(y){}
  bool operator == (const S &b) const {
    return x == b.x && y == b.y;
  }
  bool operator < (const S &b) const {
    return x * b.y < y * b.x;
  }
  bool operator <= (const S &b) const {
    return *this < b || *this == b;
  }
  
  void output() {cout << x << "/" << y << endl;}
};
const int N=81*81*3;
S inf(0,-1);
int nxt[9],cur[9];
S f[N];
int getstate()
{
	int ret=0;
	for(int i=8;i>=0;i--) ret=ret*3+nxt[i];
	return ret;
}
void updateleft(S &num)
{
	S s=f[getstate()];
	if(num==inf||num<s)
		num=s;
}
void updateright(S &num)
{
	S s=f[getstate()];
	if(num==inf||s<num)
		num=s;
}
S half(S &a,S &b)
{
	ll down=max(a.y,b.y);
	ll up=a.x*(down/a.y)+b.x*(down/b.y);
	down<<=1;
	while(up%2==0) up/=2,down/=2;
	return S(up,down);
}
void db()
{
	for(int i=0;i<N;i++)
	{
		int t=i;
		for(int j=0;j<9;j++) cur[j]=t%3,t/=3;
		S left=inf,right=inf;
		for(int j=0;j<9;j++) if(cur[j]==1)
		{
			int x=j/3,y=j%3;
			for(int k=0;k<9;k++)
				nxt[k]=cur[k];
			nxt[j]=0;
			if(x) nxt[j-3]=0;
			if(x!=2) nxt[j+3]=0;
			updateleft(left);
			if(y) nxt[j-1]=0;
			if(y!=2) nxt[j+1]=0;
			updateleft(left);
			for(int k=0;k<9;k++) nxt[k]=cur[k];
			nxt[j]=0;
			if(y) nxt[j-1]=0;
			if(y!=2) nxt[j+1]=0;
			updateleft(left);
		}
		for(int j=0;j<9;j++) if(cur[j]==2)
		{
			for(int k=0;k<9;k++) nxt[k]=cur[k];
			nxt[j]=0;
			updateright(right);
		}
		if(left==inf&&right==inf) f[i]=S(0,1);
		else if(left==inf) f[i]=S(right.x-1,1);
		else if(right==inf) f[i]=S(left.x+1,1);
		else {
			assert(left<right);
			S l=inf,r=inf,x(0,1);
			while(right<=x||x<=left)
			{
				if(right<=x)
				{
					r=x;
					if(l==inf) x.x--;
					else x=half(l,r);
				}
				else{
					l=x;
					if(r==inf) x.x++;
					else x=half(l,r);
				}
			}
			f[i]=x;
		}
	}
}

int main()
{
	db();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			char s[10];
			string tot;
			for(int i=0;i<3;i++)
			{
				scanf("%s",s);
				for(int j=0;j<3;j++) tot+=s[j*2];
			}
			int bb=0;
			for(int i=8;i>=0;i--)
			{
				int cur=0;
				if(tot[i]=='.'||tot[i]=='#') cur=0;
				else if(tot[i]=='O') cur=1;
				else cur=2;
				bb=bb*3+cur;
			}
			sum+=f[bb].x*(64/f[bb].y);
		}
		if(sum==0) puts("Second");
		else if(sum>0) puts("Alice");
		else if(sum<0)puts("Bob");
	}
}
