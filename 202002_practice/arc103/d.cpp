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
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main()
{
    int n;
    cin>>n;
    vc<pi> p(n);
    int odd=0,even=0;
    for(int i=0;i<n;i++) 
    {
        cin>>p[i].first>>p[i].second;
        if((p[i].first+p[i].second)&1) odd++;
        else even++;
    }
    if(odd&&even) print(-1);
    else{
        if(even)
            for(int i=0;i<n;i++) p[i].first--;
        if(even) cout<<33<<'\n';
        else cout<<32<<'\n';
        for(int i=31;i>=0;i--) cout<<(1LL<<i)<<' ';
        if(even) cout<<1;
        cout<<'\n';
        for(int i=0;i<n;i++)
        {
            ll cx=0,cy=0;
            for(int j=31;j>=0;j--)
            {
                for(int k=0;k<4;k++)
                {
                    ll nx=cx+dx[k]*(1LL<<j),ny=cy+dy[k]*(1LL<<j);
                    ll dis=abs(p[i].first-nx)+abs(p[i].second-ny);
                    if(dis<=(1LL<<j)-1)
                    {
                        cx=nx,cy=ny;
                        if(k==0)
                            cout<<'U';
                        else if(k==1) cout<<'R';
                        else if(k==2) cout<<'D';
                        else cout<<'L';
                        break;
                    }
                }
            }
            if(even) cout<<'R';
            cout<<'\n';
        } 
    }

}