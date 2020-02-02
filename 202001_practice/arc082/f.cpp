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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,k;
    cin>>x>>k;
    vi r(k);
    for(int i=0;i<k;i++) cin>>r[i];
    int q;
    cin>>q;
    int t,a,p=0;
    int L=0,lv=0,rv=x;
    int tp=-1;
    int curt=0;
    for(int i=0;i<q;i++) 
    {
        cin>>t>>a;
        while(p<k&&r[p]<t)
        {
            if(tp==-1)
            {
                if(lv<=r[p]-curt)
                {
                    L+=r[p]-curt-lv;
                    lv=0;
                }
                else
                    lv-=(r[p]-curt);
                rv-=r[p]-curt;
            }
            else{
                rv+=r[p]-curt;
                lv+=r[p]-curt;
            }
            rv=min(max(0,rv),x);
            lv=min(max(0,lv),x);
            tp*=-1;
            curt=r[p];
            p++;
        }
        if(tp==-1)
        {
            if(lv<=t-curt)
            {
                L+=t-curt-lv;
                lv=0;
            }
            else
                lv-=(t-curt);
            rv-=t-curt;
        }
        else{
            rv+=t-curt;
            lv+=t-curt;
        }
        rv=min(max(0,rv),x);
        lv=min(max(0,lv),x);
        curt=t;
        if(a<=L) print(lv);
        else print(min(rv,lv+a-L));
        //dbg(i,L,lv,rv);
    } 
}