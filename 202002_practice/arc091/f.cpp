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
const int maxn=1e5+7;
int sg[maxn];
/*int k=4;
int getsg(int x)
{
    if(x<k) return 0;
    if(sg[x]!=-1) return sg[x];
    set<int> all;
    int cnt=x/k;
    for(int i=1;i<=cnt;i++)
    {
        all.insert(getsg(x-i));
    }
    for(int i=0;;i++) if(!all.count(i)) return sg[x]=i;
}*/
int getsg(int x,int k)
{
    if(x<k) return 0;
    if(x%k==0) return x/k;
    int var=x/k*k;
    int nxt=-1,L=0,R=k;
    while(L<=R)
    {
        int mid=L+R>>1;
        //dbg(L,R,x-1LL*mid*(x/k+1),var);
        if(x-1LL*mid*(x/k+1)>=var)
        {
            nxt=mid;
            L=mid+1;
        }
        else R=mid-1;
    }
    assert(nxt!=-1);
    x=min(x-x/k-1,x-nxt*(x/k+1));
    return getsg(x,k);
}
int main()
{
    //memset(sg,-1,sizeof(sg));
    //for(int i=1;i<=100;i++) dbg(i,getsg(i),i%k);
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a,k;
        cin>>a>>k;
        sum^=getsg(a,k);
    }
    if(!sum)
        cout<<"Aoki\n";
    else cout<<"Takahashi\n";
}