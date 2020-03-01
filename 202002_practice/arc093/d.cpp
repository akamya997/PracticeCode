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
char ans[100][100];
inline void nxt(int &x,int &y)
{
    y+=2;
    if(y>=100)
    {
        x+=2;
        y=0;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<100<<" "<<100<<'\n';
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i>=50) ans[i][j]='#';
            else ans[i][j]='.';
        }
    }
    int x=0,y=0;
    for(int i=1;i<b;i++,nxt(x,y))
        ans[x][y]='#';
    x=52,y=0;
    for(int i=1;i<a;i++,nxt(x,y))
        ans[x][y]='.';
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
            cout<<ans[i][j];
        cout<<'\n';
    }

}