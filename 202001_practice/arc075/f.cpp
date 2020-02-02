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
int a[20];
ll dp[20][20][2][2][2];
ll dfs(int l,int r,int zero=1,int lup=0,int rup=0)
{
    if(l<=r)
    {
        if(l==r)
            return (10*lup-rup==a[l])*10;
        return lup==rup;
    }
    ll &ret=dp[l][r][zero][lup][rup];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=zero;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j-i+lup*10==a[l]&&i-j-rup==a[r])
                ret+=dfs(l-1,r+1,0,0,0);
            else if(j-i+lup*10==a[l]&&i-j+10-rup==a[r])
                ret+=dfs(l-1,r+1,0,0,1);
            else if(j-i+lup*10-1==a[l]&&i-j-rup==a[r])
                ret+=dfs(l-1,r+1,0,1,0);
            else if(j-i+lup*10-1==a[l]&&i-j+10-rup==a[r])
                ret+=dfs(l-1,r+1,0,1,1);
        }
    }
    return ret;
}
ll solve(int len,int D)
{
    memset(dp,-1,sizeof(dp));
    int p=0;
    while(D)
    {
        a[p++]=D%10;
        D/=10;
    }
    return dfs(len-1,0);
}
int main()
{
    int D;
    cin>>D;
    int tmp=D;
    int cc=0;
    while(tmp)
    {
        tmp/=10;
        cc++;
    }
    ll ans=0;
    for(int i=19;i>=cc;i--)
        ans+=solve(i,D);
    cout<<ans<<'\n';
}