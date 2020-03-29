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
const int maxn=105;
string maze[maxn];
bool vis[maxn][maxn][7][7];
int h,w;
bool dfs(int x,int y,int up=1,int ft=2,int bt=6,int bk=5,int lf=4,int rt=3)
{
    if(x<0||x>=h||y<0||y>=w) return false;
    if(vis[x][y][up][ft]||maze[x][y]=='#'||maze[x][y]-'0'!=bt) return false;
    if(x==h-1&&y==w-1) return true;
    vis[x][y][up][ft]=1;
    assert(up+bt==7&&ft+bk==7&&lf+rt==7);
    bool ret=0;
    ret|=dfs(x+1,y,bk,up,ft,bt,lf,rt);
    ret|=dfs(x-1,y,ft,bt,bk,up,lf,rt);
    ret|=dfs(x,y+1,lf,ft,rt,bk,bt,up);
    ret|=dfs(x,y-1,rt,ft,lf,bk,up,bt);
    return ret;
}
int main()
{
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>maze[i];
    if(dfs(0,0)) cout<<"YES\n";
    else cout<<"NO\n";
}