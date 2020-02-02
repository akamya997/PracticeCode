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
const int maxn=105;
int dp[maxn][maxn][maxn];
int w[maxn],v[maxn];
int c[5];
int main()
{
    int n,W;
    cin>>n>>W;
    for(int i=0;i<n;i++)
        cin>>w[i]>>v[i];
    vi big;
    for(int i=0;i<n;i++)
    {
        if(w[i]-w[0]==3)
        {
            big.push_back(v[i]);
            continue;
        }
        c[w[i]-w[0]]++;
        for(int j=c[0];j>=0;j--)
        {
            for(int k=c[1];k>=0;k--)
            {
                for(int l=c[2];l>=0;l--)
                {
                    if(w[i]==w[0])
                    {
                        if(j)
                            dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+v[i]);
                    }
                    else if(w[i]==w[0]+1)
                    {
                        if(k)
                            dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+v[i]);
                    }
                    else if(w[i]==w[0]+2)
                    {
                        if(l)
                            dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+v[i]);
                    }
                }
            }

        }
    }
    sort(big.begin(),big.end(),greater<int>());
    vi pre(big.size()+1);
    pre[0]=0;
    for(int i=1;i<=big.size();i++) pre[i]=pre[i-1]+big[i-1];
    int ans=0;
    for(int i=0;i<=c[0];i++)
    {
        for(int j=0;j<=c[1];j++)
        {
            for(int k=0;k<=c[2];k++)
            {
                for(int l=0;l<=pre.size();l++)
                {
                    ll curw=1LL*i*w[0]+1LL*j*(w[0]+1)+1LL*k*(w[0]+2)+1LL*l*(w[0]+3);
                    if(curw>W) break;
                    ans=max(ans,dp[i][j][k]+pre[l]);
                }
            }
        }
    }
    cout<<ans<<'\n';
    
}