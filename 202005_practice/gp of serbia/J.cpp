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
const int mxlen=64;
typedef bitset<mxlen> bs;
bitset<mxlen> x,a[7];
bs gcd(bs& a,bs& b)
{
    //dbg(a,b);
    int la=-1,lb=-1;
    for(int i=0;i<4000;i++) 
    {
        if(a[i]) la=i;
        if(b[i]) lb=i;
    }
    if(lb>la) swap(a,b);
    if(lb==-1) return a;
    a^=(b<<(la-lb));
    return gcd(a,b);
}
const int maxn=1e5+7;
const int mod=998244353;
ll two[maxn];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mx=s.length()-1;
    for(int i=s.length()-1;i>=0;i--)
        x[s.length()-1-i]=s[i]=='1';
    //dbg(x);
    bs g;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=s.length()-1;j>=0;j--)
            a[i][s.length()-1-j]=s[j]=='1';
        g=gcd(g,a[i]);
    }
    cout<<g<<endl;
    return 0;
    //dbg(g);
    int lg=-1;
    for(int i=0;i<mxlen;i++) if(g[i]) lg=i;
    //dbg(mx,lg);
    two[0]=1;
    for(int i=1;i<maxn;i++) two[i]=two[i-1]*2%mod;
    ll ans=1;
    bs last;
    for(int i=mx;i>=lg;i--)
    {
        if(x[i]) 
            ans=(ans+two[i-lg])%mod;
        if(x[i]^last[i]) last^=g<<(i-lg); 
    }
    for(int i=mx;i>=0;i--)
    {
        if(x[i]>last[i])
            break;
        if(x[i]<last[i]) 
        {
            ans--;
            break;
        }
    }
    print(ans);

}
