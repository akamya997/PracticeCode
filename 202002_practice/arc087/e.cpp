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
/*const int maxn=105;
int sg[maxn];
int getsg(int x)
{
    if(sg[x]!=-1) return sg[x];
    if(x==0) return 0;
    if(x==1) return 1;
    set<int> all;
    all.insert(0);
    for(int i=1;i<=x-1;i++)
    {
        int cur=0;
        for(int j=x-i;j<=x-1;j++) cur^=getsg(j);
        all.insert(cur);
    }
    for(int i=0;;i++)
    {
        if(!all.count(i))
            return sg[x]=i;
    }
}*/
const int maxn=4e5+7;
int sz[maxn<<2];
int nxt[maxn<<2][2];
int tot=1;
int cnt[105];
void Insert(string s)
{
    int rt=1;
    for(int i=0;i<s.length();i++)
    {
        sz[rt]++;
        if(!nxt[rt][s[i]=='1'])
            nxt[rt][s[i]=='1']=++tot;
        rt=nxt[rt][s[i]=='1'];
    }
    sz[rt]++;
}
ll L;
void dfs(int u,int dep=0)
{
    //dbg(u,dep);
    if(u==0)
    {
        if(dep>L) return ;
        ll val=L-dep+1;
        //dbg(dep);
        int cc=0;
        while(val%2==0&&val)
        {
            val/=2;
            cc++;
        }
        cnt[cc]++;
        return;
    }
    dfs(nxt[u][0],dep+1);
    dfs(nxt[u][1],dep+1);
}
int main()
{
    int n;
    cin>>n>>L;
    /*memset(sg,-1,sizeof(sg));
    for(int i=0;i<maxn;i++)
    {
        dbg(i,getsg(i));
    }*/
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        Insert(s);
    }
    dfs(1);
    bool ok=0;
    for(int i=0;i<100;i++)
    {
        //dbg(i,cnt[i]);
        if(cnt[i]&1) ok=1;
    }
    if(ok) cout<<"Alice\n";
    else cout<<"Bob\n";
}