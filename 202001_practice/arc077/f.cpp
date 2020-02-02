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
typedef vector<ll> vi;
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
const int maxn=2e5+7;
// z[i] = len of lcp of s, s[i..]; lcp(longest common prefix)
int z[maxn];
void z_fn(const string& s) {
    int n = s.size();
    for(int i=0;i<n;i++) z[i]=0;
    for (int i = 1, l = 0, r = 0; i < n; i++) 
    {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) 
            z[i]++;
        if (i+z[i]-1 > r) 
        {
            l = i;
            r = i+z[i]-1;
        }
    }
}
int p;
string t;
vi getans(ll x)
{
    string T(t.begin(),t.begin()+p);
    vi u(26);
    vi ret(26);
    for(auto v:T) u[v-'a']++;
    for(int i=0;i<min(x,(ll)t.length());i++) ret[t[i]-'a']++;
    if(x>t.length()){
        x-=t.length();
        ll tt=x/p;
        for(int i=0;i<26;i++) ret[i]+=u[i]*tt;
        for(int i=0;i<x%p;i++)
            ret[T[i]-'a']++;
    }
    return ret;
}
ll cnt[102][26];
ll len[102];
vi getans2(ll x)
{
    vi ret(26);
    for(int i=100;i>=0;i--)
    {
        if(x>=len[i])
        {
            for(int j=0;j<26;j++)
                ret[j]+=cnt[i][j];
            x-=len[i];
        }
    }
    for(int i=0;i<x;i++) ret[t[i]-'a']++;
    return ret;
}
int main()
{
    string s;
    cin>>s;
    t=string(s.begin(),s.begin()+s.length()/2);
    z_fn(t);
    p=t.length();
    for(int i=1;i<t.length();i++)
    {
        if(z[i]==t.length()-i)
        {
            p=i;
            break;
        }
    }
    ll l,r;
    cin>>l>>r;
    l;r;
    vi L,R;
    if(t.length()%p==0)
    {
        R=getans(r);
        L=getans(l-1);
    }
    else{
        for(int i=0;i<p;i++) cnt[0][t[i]-'a']++;
        len[0]=p;
        len[1]=t.length();
        for(int i=0;i<t.length();i++) cnt[1][t[i]-'a']++;
        for(int i=2;i<100;i++)
        {
            for(int j=0;j<26;j++)
                cnt[i][j]=min(1LL<<60,cnt[i-1][j]+cnt[i-2][j]);
            len[i]=min(1LL<<60,len[i-1]+len[i-2]);
        }
        R=getans2(r);
        L=getans2(l-1);
    }
    for(int i=0;i<26;i++) R[i]-=L[i];
    print(R);
}
