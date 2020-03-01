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
const int maxn=16000+7;
const int var=8000;
bool dpx[2][maxn],dpy[2][maxn];
int main()
{
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    int p=0;
    int cx=0;
    while(p<s.length()&&s[p]=='F')
    {
        cx++;
        p++;
    }
    p++;
    dpx[0][cx+var]=1;
    dpy[0][var]=1;
    int curx=0,cury=0;
    vi X,Y;
    cx=0;
    int f=1;
    int n=s.length();
    s+='T';
    while(p<s.length())
    {
        if(s[p]=='T')
        {
            if(cx)
            {
                if(f) Y.push_back(cx);
                else X.push_back(cx);
                cx=0;
            }
            f^=1;
        }
        else
            cx++;
        p++;
    }
    //dbg(X,Y);
    for(auto u:X)
    {
        for(int i=0;i<maxn;i++)
        {
            dpx[curx^1][i]=0;
            dpx[curx^1][i]=(i+u<maxn?dpx[curx][i+u]:0)|(i-u>=0?dpx[curx][i-u]:0);
        }
        curx^=1;
    }
    for(auto u:Y)
    {
        for(int i=0;i<maxn;i++)
        {
            dpy[cury^1][i]=0;
            dpy[cury^1][i]=(i+u<maxn?dpy[cury][i+u]:0)|(i-u>=0?dpy[cury][i-u]:0);
        }
        cury^=1;
    }
    if(dpx[curx][var+x]&&dpy[cury][var+y]) cout<<"Yes\n";
    else cout<<"No\n";

}