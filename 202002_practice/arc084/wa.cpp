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
vvc<int> all;
int n,k;
void dfs(int x,vi c)
{
    if(x==0) 
    {
        all.push_back(c);
        return;
    }
    for(int i=1;i<=k;i++)
    {
        c.push_back(i);
        dfs(x-1,c);
        c.pop_back();
    }

}
vi ans;
const int maxn=3e5+7;
const ll INF=0x3f3f3f3f;
ll rem[maxn];
void getans(int x,int d)
{
    dbg(x,d);
    if(x==n)
        return;
    if(d==rem[n-x])
        return;
    d++;
    int t=d/(2*(rem[n-x-1]+1));
    d-=t*2*(rem[n-x-1]+1);
    ans.push_back((k+1)/2-t);
    if(x==n-1){
        if(d)
            ans[n-1]--;
    }
    getans(x+1,d);
}
int main()
{
    cin>>k>>n;
    rem[0]=0;
    rem[1]=k;
    for(int i=2;i<maxn;i++) rem[i]=min(rem[i-1]*k,INF);
    /*for(int i=1;i<=n;i++) dfs(i,vi());
    sort(all.begin(),all.end());
    //dbg(all.size());
    for(auto u:all) print(u);
    dbg(all[all.size()/2]);*/
    if(k%2==0)
    {
        ans=vi(n);
        ans[0]=k/2;
        for(int i=1;i<n;i++) ans[i]=k;
    }
    else {
        if(k==1) ans=vi((n+1)/2,1);
        else getans(0,0);
    }
    print(ans);
}
