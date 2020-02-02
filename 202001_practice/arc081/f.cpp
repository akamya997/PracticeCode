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
const int maxn=2005;
string s[maxn];
int a[maxn][maxn];
int H[maxn];
int sta[maxn];
int main()
{
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>s[i];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            a[i][j]=s[i][j]=='#';
    }
    int ans=max(h,w);
    for(int i=0;i<h;i++)
    {
        if(!i) for(int j=1;j<w;j++) H[j]=1;
        else{
            for(int j=1;j<w;j++)
            {
                if(a[i][j]^a[i][j-1]==a[i-1][j]^a[i-1][j-1])
                    H[j]++;
                else H[j]=1;
            }
        }
        stack<int> st;
        H[w]=-1;
        st.push(0);
        for(int j=1;j<=w;j++)
        {
            while(st.size()&&H[st.top()]>=H[j]) 
            {
                ans=max(ans,H[st.top()]*(j-sta[st.top()]));
                //dbg(i,j,st.top());
                st.pop();
            }
            if(j!=w)
                sta[j]=st.top();
            st.push(j);
        }
    }
    cout<<ans<<'\n';
}