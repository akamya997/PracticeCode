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
const int maxn=1e5+7;
int tree[maxn];
void add(int x)
{
    while(x<maxn)
    {
        tree[x]++;
        x+=x&-x;
    }
}
int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int L=1,R=1e9,ans=-1;
    ll tot=(ll)n*(n+1)/2;
    ll tar=tot/2+1;
    while(L<=R)
    {
        int mid=L+R>>1;
        memset(tree,0,sizeof(tree));
        vi cur(n),pre(n);
        vi all;
        auto getid=[&](int x){
            return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
        };
        all.push_back(0);
        for(int i=0;i<n;i++)
        {
            if(a[i]<=mid) cur[i]=1;
            else cur[i]=-1;
            if(!i) pre[i]=cur[i];
            else pre[i]=pre[i-1]+cur[i];
            all.push_back(pre[i]);
        }
        mkuni(all);
        add(getid(0));
        ll cnt=0;
        for(int i=0;i<n;i++)
        {
            int id=getid(pre[i]);
            cnt+=query(id-1);
            add(id);
        }
        if(cnt>=tar)
        {
            R=mid-1;
            ans=mid;
        }
        else L=mid+1;
    }
    assert(ans!=-1);
    print(ans);
}