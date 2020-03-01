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
deque<int> pos[30];
const int maxn=2e5+7;
int tree[maxn];
void add(int x)
{
    x++;
    while(x<maxn)
    {
        tree[x]++;
        x+=x&-x;
    }
}
int query(int x)
{
    x++;
    int ret=0;
    while(x>0)
    {
        ret+=tree[x];
        x-=x&-x;
    }
    return ret;
}
inline int query(int l,int r)
{
    return query(r)-query(l-1);
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
        pos[s[i]-'a'].push_back(i);
    int odd=0;
    for(int i=0;i<26;i++)
        odd+=pos[i].size()&1;
    if(odd>1||(odd==1&&(s.length()%2==0))) print(-1);
    else{
        ll ans=0;
        for(int i=0;i<s.length()/2;i++)
        {
            int tar=-1,cost=0x3f3f3f3f;
            for(int j=0;j<26;j++)
            {
                if(pos[j].size()<2) continue;
                int cur=pos[j].front()-query(0,pos[j].front())+s.length()-1-pos[j].back()-query(pos[j].back(),s.length()-1);
                if(cur<cost)
                {
                    cost=cur;
                    tar=j;
                }
            }
            add(pos[tar].back());
            add(pos[tar].front());
            pos[tar].pop_back();
            pos[tar].pop_front();
            ans+=cost;
        }
        print(ans);
    } 
}