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
const int mod=1e9+7;
ll dp[17][1<<16];
ll quick(ll a,ll b)
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
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1<<17;
ll fac[maxn];
ll facinv[maxn];
void init()
{
    fac[0]=facinv[0]=1;
    for(int i=1;i<maxn;i++) 
    {
        fac[i]=fac[i-1]*i%mod;
        facinv[i]=inv(fac[i]);
    }
}
inline ll C(int n,int m)
{
    if(n<m) return 0;
    return fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int main()
{
    init();
    int n,m;
    cin>>n>>m;
    vi a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    dp[m][0]=1;
    for(int i=m-1;i>=0;i--)
    {
        for(int S=0;S<(1<<n);S++)
        {
            if(!dp[i+1][S]) continue;
            dp[i][S]=(dp[i][S]+dp[i+1][S])%mod;
            for(int j=0;j<n;j++)
            {
                if(S&(1<<j)) continue;
                int tot=(1<<n)-a[i]-S;
                dp[i][S|(1<<j)]=(dp[i][S|(1<<j)]+C(tot,(1<<j)-1)*dp[i+1][S]%mod*fac[1<<j]%mod)%mod;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        dbg(i,dp[0][i]*fac[(1<<n)-1-i]);
        int cc=__builtin_popcount(i);
        if(cc&1) ans=(ans-dp[0][i]*fac[(1<<n)-1-i]%mod+mod)%mod;
        else ans=(ans+dp[0][i]*fac[(1<<n)-1-i]%mod)%mod;
    }
    ans=ans*(1<<n)%mod;
    print(ans);
}