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
struct D{
    int cc,id;
    bool operator<(const D&a) const{
        if(cc==a.cc) return id<a.id;
        return cc>a.cc;
    }
};
int main()
{
    int n;
    cin>>n;
    vi a(n+1);
    vi cnt(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vi ans(n);
    if(n<=2)
        cout<<"-1\n";
    else{
        set<D> all;
        set<int> alln;
        for(int i=1;i<=n;i++)
            cnt[a[i]]++,alln.insert(i);
        for(int i=1;i<=n;i++)
            all.insert({cnt[i],i});
        int pre=0;
        for(int i=1;i<=n-3;i++)
        {
            if((*all.begin()).cc==n-i)
                ans[i-1]=(*all.begin()).id;
            else {
                for(auto u:alln){
                    if(u!=a[pre])
                    {
                        ans[i-1]=u;
                        break;
                    }
                }
            }
            all.erase({cnt[ans[i-1]],ans[i-1]});
            alln.erase(ans[i-1]);
            int tar=a[ans[i-1]];
            if(alln.count(tar))
            {
                all.erase({cnt[tar],tar});
                cnt[tar]--;
                all.insert({cnt[tar],tar});
            }
            pre=ans[i-1];
            //dbg(i);
            //for(auto u:all) dbg(u.cc,u.id);
        }
        vi remain;
        for(auto u:alln) remain.push_back(u);
        do
        {
            bool ok=1;
            int cc=pre;
            for(int i=0;i<3;i++)
            {
                if(a[cc]==remain[i])
                {
                    ok=0;
                    break;
                }
                cc=remain[i];
            }
            if(ok) break;
        } while (next_permutation(remain.begin(),remain.end()));
        for(int i=0;i<3;i++) ans[n-3+i]=remain[i];
        print(ans);
    }
}