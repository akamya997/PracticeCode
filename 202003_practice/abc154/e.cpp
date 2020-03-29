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
int a[105];
ll dp[105][5];
int k;
ll dfs(int pos,int cnt,bool limit=1)
{
    if(pos==-1) return cnt==k;
    if(cnt>k) return 0;
    if(!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];
    int up=limit?a[pos]:9;
    ll ret=0;
    for(int i=0;i<=up;i++)
        ret+=dfs(pos-1,cnt+(i!=0),limit&&i==up);
    if(!limit) dp[pos][cnt]=ret;
    return ret;
}
ll solve(string s)
{
    int pos=0;
    for(int i=s.length()-1;i>=0;i--)
        a[pos++]=s[i]-'0';
    return dfs(pos-1,0);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string n;
    cin>>n>>k;
    cout<<solve(n)<<'\n';
}