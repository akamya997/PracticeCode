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
const int maxn=505;
const double eps=1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;
vec gauss_jordan(const mat& A, const vec& b)
{
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];

    for(int i=0;i<n;i++) 
		B[i][n]=b[i];
    for(int i=0;i<n;i++)
    {
        int pivot=i;
        for(int j=i;j<n;j++)
            if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;
        swap(B[i],B[pivot]);
        if(abs(B[i][i])<eps) return vec();
        for(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                for(int k=i+1;k<=n;k++)
                    B[j][k]-=B[j][i]*B[i][k];
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;i++)
        x[i]=B[i][n];
    return x;
}
vector<int> G[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	mat A(n,vec(n));
	for(int i=0;i<n;i++)
	{
		for(auto v:G[i])if(v!=n-1)
			A[i][v]=1.0/G[v].size();
		A[i][i]=-1;
	}
	vec b=vec(n);
	b[0]=-1;
	vec x=gauss_jordan(A,b);
	vec ans;
	for(int i=0;i<n;i++)
	{
		for(auto v:G[i])if(v>i)
		{
			double cur=0;
			if(i!=n-1) 
				cur+=x[i]/G[i].size();
			if(v!=n-1)
				cur+=x[v]/G[v].size();
			ans.push_back(cur);
		}
	}
	sort(ans.begin(),ans.end());
	double op=0;
	for(int i=1;i<=m;i++)
		op+=ans[i-1]*(m-i+1);
	printf("%.3f\n",op);
}
