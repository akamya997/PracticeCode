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
const int maxn=1e7+7;
vi prime;
bool vis[maxn];
void db()
{
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
            prime.push_back(i);
        for(auto p:prime)
        {
            if(i*p>=maxn) break;
            vis[i*p]=1;
            if(i%p==0) break;
        }
    }
    vis[1]=1;
    vis[2]=1;
}
int x[105];
bool b[maxn];
int pp[205];
bool vv[205];
vi even,odd;
bool dfs(int u)
{
    if(vv[u]) return false;
    vv[u]=1;
    for(int i=0;i<odd.size();i++)
    {
        if(!vis[abs(even[u]-odd[i])])
        {
            if(pp[i]==-1||dfs(pp[i]))
            {
                pp[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    db();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        b[x[i]]^=1;
        b[x[i]+1]^=1;
    }
    for(int i=1;i<maxn;i++)
    {
        if(b[i])
        {
            if(i&1) odd.push_back(i);
            else even.push_back(i);
        }
    }
    memset(pp,-1,sizeof(pp));
    int ans=0;
    for(int i=0;i<even.size();i++)
    {
        memset(vv,0,sizeof(vv));
        if(dfs(i))
            ans++;
    }
    ans=ans+((even.size()-ans)/2+(odd.size()-ans)/2)*2+(even.size()-ans)%2*3;
    print(ans);
}