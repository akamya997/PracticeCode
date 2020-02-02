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
bool ask(ll x)
{
    cout<<"? "<<x<<endl;
    string ret;
    cin>>ret;
    return ret=="Y";
}
void answer(ll x)
{
    cout<<"! "<<x<<endl;
}
int main()
{
    ll var=1e9;
    if(ask(var))
    {
        while(var/10&&ask(2*var/10))
            var/=10;
        answer(var);
    }
    else{
        var/=10;
        while(!ask(var))
            var/=10;
        ll L=var,R=var*10-1,ans=-1;
        while(L<=R)
        {
            ll mid=L+R>>1;
            if(ask(10*mid))
            {
                R=mid-1;
                ans=mid;
            }
            else L=mid+1;
        }
        answer(ans);
    }
}