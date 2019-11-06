#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
ll inv(ll a){return quick(a,mod-2);}
unordered_map<string,int> mp;
const int maxn=5e5+7;
int val[maxn],w[maxn];
struct node{
    int t;
    bool operator<(const node& a)const{
        return w[t]<w[a.t];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        mp.clear();
        int cur=1;
        int q,m;
        int num=0;
        cin>>q>>m;
        set<node> cache;
        while(q--)
        {
            int op;string s;int v;
            cin>>op>>s>>v;
            if(!mp.count(s)) mp[s]=++num;
            int tt=mp[s];
            if(op==0)
            {
                if(cache.find(node{tt})!=cache.end())
                {
                    cout<<val[tt]<<'\n';
                    cache.erase(node{tt});
                    w[tt]=cur++;
                    cache.insert(node{tt});
                }
                else{
                    w[tt]=cur++;
                    val[tt]=v;
                    cache.insert(node{tt});
                    if(cache.size()>m) cache.erase(*(cache.begin()));
                    cout<<v<<'\n';
                }
            }
            else{
                if(cache.find(node{tt})!=cache.end())
                {
                    auto it=cache.find(node{tt});
                    if(v==-1)
                    {
                        if(it==cache.begin()) cout<<"Invalid\n";
                        else
                        {
                            it=prev(it);
                            cout<<val[(*it).t]<<'\n';
                        }
                    }
                    else if(v==1)
                    {
                        it=next(it);
                        if(it==cache.end()) cout<<"Invalid\n";
                        else {
                            cout<<val[(*it).t]<<'\n';
                        }
                    }
                    else cout<<val[(*it).t]<<'\n';
                }
                else cout<<"Invalid\n";
            }
        }
    }
}
