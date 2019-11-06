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
const int mod=1e9+7;
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
struct Matrix{
	ll a[11][11];
	void init()
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<11;i++) a[i][i]=1;
	}
	Matrix operator*(const Matrix b)const{
		Matrix ret;
		memset(ret.a,0,sizeof(ret.a));
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<11;j++)
			{
				for(int k=0;k<11;k++)
				{
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return ret;
	}
};
const int maxn=5e4+7;
Matrix sum[maxn<<2];
char maze[maxn][15];
int n,m;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void pushup(int o)
{
	sum[o]=sum[rson]*sum[lson];
}
Matrix cur;
void update(int pos,int L=1,int R=n,int o=1)
{
	if(L==R)
	{
		sum[o]=cur;
		return;
	}
	int mid=L+R>>1;
	if(pos<=mid) update(pos,Lson);
	else update(pos,Rson);
	pushup(o);
}
ll getans(int a,int b)
{
	return sum[1].a[b][a];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>maze[i]+1;
		memset(cur.a,0,sizeof(cur.a));
		for(int j=1;j<=m;j++)
		{
			for(int k=j;k>=1;k--)
			{
				if(maze[i][k]=='1') break;
				cur.a[j][k]=1;
			}
			for(int k=j;k<=m;k++)
			{
				if(maze[i][k]=='1') break;
				cur.a[j][k]=1;
			}
		}
		update(i);
	}
	while(q--)
	{
		int op,a,b;
		cin>>op>>a>>b;
		if(op==1)
		{
			if(maze[a][b]=='0')
				maze[a][b]='1';
			else maze[a][b]='0';
			memset(cur.a,0,sizeof(cur.a));
			for(int i=1;i<=m;i++)
			{
				for(int j=i;j>=1;j--)
				{
					if(maze[a][j]=='1') break;
					else cur.a[i][j]=1;
				}
				for(int j=i;j<=m;j++)
				{
					if(maze[a][j]=='1') break;
					else cur.a[i][j]=1;
				}
			}
			update(a);
		}
		else{
			cout<<getans(a,b)<<endl;
		}
	/*	for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<sum[1].a[i][j]<<" ";
			cout<<endl;
		}*/
	}
}

