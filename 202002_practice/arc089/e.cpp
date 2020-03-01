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
const int maxn=105;
int d[15][15];
int cd[15][15];
int f[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A,B;
    cin>>A>>B;
    for(int i=1;i<=A;i++)
    {
        for(int j=1;j<=B;j++)
            cin>>d[i][j];
    }
    for(int a=0;a<maxn;a++)
    {
        for(int b=0;b<maxn;b++)
        {
            for(int x=1;x<=A;x++)
            {
                for(int y=1;y<=B;y++)
                    f[a][b]=max(f[a][b],d[x][y]-a*x-b*y);
            }
        }
    }
    memset(cd,0x3f,sizeof(cd));
    for(int a=0;a<maxn;a++)
    {
        for(int b=0;b<maxn;b++)
        {
            for(int x=1;x<=A;x++)
            {
                for(int y=1;y<=B;y++)
                    cd[x][y]=min(cd[x][y],a*x+b*y+f[a][b]);
            }
        }
    }
    bool ok=1;
    for(int i=1;i<=A;i++)
        for(int j=1;j<=B;j++)
            if(cd[i][j]!=d[i][j])ok=0;
    if(!ok) cout<<"Impossible\n";
    else{
        cout<<"Possible\n";
        cout<<maxn*2<<" "<<2*maxn-2+maxn*maxn<<'\n';
        for(int i=1;i<maxn;i++)
            cout<<i<<" "<<i+1<<" X\n";
        for(int i=maxn+1;i<maxn+maxn;i++)
            cout<<i<<" "<<i+1<<" Y\n";
        for(int i=1;i<=maxn;i++)
        {
            for(int j=maxn+1;j<=maxn*2;j++)
            {
                cout<<i<<" "<<j<<" "<<f[i-1][2*maxn-j]<<'\n';
            }
        }
        cout<<1<<" "<<maxn+maxn<<'\n';
    }

}