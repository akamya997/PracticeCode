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
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    pi ans={0,a*100};
    for(int x=0;x<=30;x++)
    {
        for(int y=0;y<=30;y++)
        {
            for(int u=0;u<=3000;u++)
            {
                for(int v=0;v<=3000;v++)
                {
                    int tot=x*a*100+y*b*100+u*c+v*d;
                    if(tot>f) break;
                    int s=u*c+v*d;
                    if(tot>f||s*100>(tot-s)*e) continue;
                    if(tot*ans.first<s*ans.second) ans=make_pair(s,tot);
                }
            }
        }
    }
    cout<<ans.second<<" "<<ans.first<<'\n';
}