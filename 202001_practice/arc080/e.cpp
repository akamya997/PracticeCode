#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
const int maxn=2e5+7;
int p[maxn];
int n;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct sgt{
    pi mx[maxn<<2];
    pi query(int l,int r,int L=1,int R=n,int o=1)
    {
        if(l>r) return {0x3f3f3f3f,0x3f3f3f3f};
        if(l<=L&&r>=R)
            return mx[o];
        int mid=L+R>>1;
        pi ret={0x3f3f3f3f,0x3f3f3f3f};
        if(l<=mid) ret=min(ret,query(l,r,Lson));
        if(r>mid) ret=min(ret,query(l,r,Rson));
        return ret;
    }
}mx,odd,even;
void build(int L=1,int R=n,int o=1)
{
    if(L==R)
    {
        mx.mx[o].first=p[L];
        mx.mx[o].second=odd.mx[o].second=even.mx[o].second=L;
        odd.mx[o].first=even.mx[o].first=0x3f3f3f3f;
        if(L&1) odd.mx[o].first=p[L];
        else even.mx[o].first=p[L];
        return;
    }
    int mid=L+R>>1;
    build(Lson);
    build(Rson);
    mx.mx[o]=min(mx.mx[lson],mx.mx[rson]);
    odd.mx[o]=min(odd.mx[lson],odd.mx[rson]);
    even.mx[o]=min(even.mx[lson],even.mx[rson]);
}
struct D{
    int l,r,val;
    bool operator<(const D&a)const{
        return val>a.val;
    }
};
D getd(int l,int r)
{
    return D{l,r,(l&1)?odd.query(l,r).first:even.query(l,r).first};
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    build();
    vi ans;
    priority_queue<D> q;
    q.push(D{1,n,odd.query(1,n).first});
    while(!q.empty())
    {
        auto u=q.top();q.pop();
        if(u.l>u.r) continue;
        int L,R;
        if(u.l&1)
        {
            L=odd.query(u.l,u.r).second;
            R=even.query(L,u.r).second;
        }
        else{
            L=even.query(u.l,u.r).second;
            R=odd.query(L,u.r).second;
        }
        ans.push_back(p[L]);
        ans.push_back(p[R]);
        q.push(getd(u.l,L-1));
        q.push(getd(L+1,R-1));
        q.push(getd(R+1,u.r));
    }
    print(ans);
}