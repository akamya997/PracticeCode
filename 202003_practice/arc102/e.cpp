#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
const int maxn=4e3+7;
const int mod=998244353;
ll C[maxn][maxn];
ll two[maxn];
void init()
{
    for(int i=0;i<maxn;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    two[0]=1;
    for(int i=1;i<maxn;i++) two[i]=two[i-1]*2%mod;
}
inline ll bno(int n,int m)
{
    if(m>n||n<0||m<0) return 0;
    //dbg(n,m,C[n][m]);
    return C[n][m];
}
int main()
{
    init();
    int k,n;
    cin>>k>>n;
    for(int i=2;i<=2*k;i++)
    {
        ll ans=0;
        if(i&1)
        {
            int tc=(i-1)/2-max(0,i-k-1);
            for(int j=0;j<=tc;j++)
                ans=(ans+bno(tc,j)*bno(n+k-2*tc-1,k-2*tc+j-1)%mod*two[j]%mod)%mod;
        }
        else{
            int tc=(i-1)/2-max(0,i-k-1);
            //dbg(i,tc);
            for(int j=0;j<=tc;j++)
                ans=(ans+(bno(n+k-2*tc-2,k+j-2-2*tc)+bno(n-1+k-2*tc-2,k+j-2-2*tc))%mod*two[j]%mod*bno(tc,j)%mod)%mod;
        }
        print(ans);
    }
}