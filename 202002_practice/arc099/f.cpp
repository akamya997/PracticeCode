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
const int ptr=3;
int c[ptr],r[ptr];
ll quick(ll a,ll b=mod-2)
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
int main()
{
    srand(time(NULL));
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<ptr;i++)
    {
        c[i]=rand()%998244353+10000;
        r[i]=quick(c[i]);
    }
    vc<ll> C(ptr);
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ptr;j++)
        {
            if(s[i]=='+')
                C[j]=(C[j]+1)%mod;
            else if(s[i]=='-')
                C[j]=(C[j]-1+mod)%mod;
            else if(s[i]=='>')
                C[j]=C[j]*c[j]%mod;
            else C[j]=C[j]*r[j]%mod;
        }
    }
    map<vc<ll>,int> cnt;
    vc<ll> A(ptr,1),cur(ptr);
    ll ans=0;
    cnt[cur]++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ptr;j++)
        {
            if(s[i]=='+')
                cur[j]=(cur[j]-A[j]+mod)%mod;
            else if(s[i]=='-')
                cur[j]=(cur[j]+A[j])%mod;
            else if(s[i]=='>')
            {
                A[j]=A[j]*r[j]%mod;
            }
            else{
                A[j]=A[j]*c[j]%mod;
            }
        }
        vc<ll> tar=C;
        for(int j=0;j<ptr;j++) tar[j]=(cur[j]+tar[j]*A[j]%mod)%mod;
        ans+=cnt[tar];
        //dbg(i,cur,tar);
        cnt[cur]++;
    }
    print(ans);
}
