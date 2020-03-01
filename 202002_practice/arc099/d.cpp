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
vc<ll> ans;
inline int S(ll x)
{
    int ret=0;
    while(x)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}
int main()
{
    /*for(int i=1;i<10*maxn;i++)
    {
        int tt=i;
        int s=0;
        while(tt)
        {
            s+=tt%10;
            tt/=10;
        }
        bool ok=1;
        for(int j=i+1;j<i*2;j++)
        {
            tt=j;
            int sj=0;
            while(tt)
            {
                sj+=tt%10;
                tt/=10;
            }
            if(1LL*i*sj>1LL*j*s)
            {
                ok=0;
                break;
            }
            //else break;
        }
        if(ok) dbg(i);
    }*/
    for(int i=1;i<1000;i++)
    {
        ll cur=i;
        for(int j=0;j<15;j++)
        {
            ans.push_back(cur);
            cur=cur*10+9;
        }
    }
    mkuni(ans);
    vc<ll> op;
    for(auto u:ans)
    {
        if(!op.size()) op.push_back(u);
        else{
            while(op.back()*S(u)>S(op.back())*u) op.pop_back();
            op.push_back(u);
        }
    }
    //dbg(op.size());
    int k;
    cin>>k;
    for(int i=0;i<k;i++) print(op[i]);
}