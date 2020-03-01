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
const int maxn=2e5+7;
const int mod=998244353;
set<string> all;
void dfs(string s)
{
    if(all.count(s)) return;
    //dbg(s);
    all.insert(s);
    for(int i=0;i<s.length()-1;i++)
    {
        string tmp=s;
        if(s[i]!=s[i+1])
        {
            if(s[i]!='a'&&s[i+1]!='a') tmp[i]=tmp[i+1]='a';
            if(s[i]!='b'&&s[i+1]!='b') tmp[i]=tmp[i+1]='b';
            if(s[i]!='c'&&s[i+1]!='c') tmp[i]=tmp[i+1]='c';
            dfs(tmp);
        }
    }
}
ll dp[maxn][3][3][2];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int pre=0;
    bool sa=1;
    for(int i=0;i<s.length();i++) 
    {
        pre+=s[i]-'a';
        if(i&&s[i]!=s[i-1]) sa=0;
    }
    pre%=3;
    ll ans=0;
    if(sa) ans=1;
    else if(n<=3)
    {
        dfs(s);
        ans=all.size();
    }
    else{
        dp[0][0][0][0]=dp[0][1][1][0]=dp[0][2][2][0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    for(int cc=0;cc<3;cc++)
                    {
                        if(j==cc)
                            dp[i][cc][(k+cc)%3][1]=(dp[i-1][j][k][0]+dp[i-1][j][k][1]+dp[i][cc][(k+cc)%3][1])%mod;
                        else{
                            dp[i][cc][(k+cc)%3][1]=(dp[i-1][j][k][1]+dp[i][cc][(k+cc)%3][1])%mod;
                            dp[i][cc][(k+cc)%3][0]=(dp[i-1][j][k][0]+dp[i][cc][(k+cc)%3][0])%mod;
                        }
                    }
                }
            }
        }
        for(int j=0;j<3;j++) ans=(ans+dp[n-1][j][pre][1])%mod;
        bool ad=1;
        for(int i=1;i<n;i++) if(s[i]==s[i-1]) ad=0;
        ans=(ans+ad)%mod;
    }
    print(ans);
}