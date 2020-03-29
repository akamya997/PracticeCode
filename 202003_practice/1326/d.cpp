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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
string Mnc(string &s)
{
    string t = "$#";
    for (int i = 0; i < s.length(); ++i) //构造辅助串
    {
        t += s[i];
        t += '#';
    }

    int ml = 0, p = 0, R = 0, M = 0;
    //最大长度，最长回文中心，当前最大回文串右端，当前最长回文中心

    int len = t.length();
    vi P(len, 0); //回长度数组
    for (int i = 0; i < len; ++i)
    {
        P[i] = R > i ? min(P[2 * M - i], R - i) : 1; //转移方程

        while (t[i + P[i]] == t[i - P[i]]) //长度扩张
            ++P[i];

        if (i + P[i] > R) //更新右端和中心
        {
            R = i + P[i];
            M = i;
        }
        if (ml < P[i] && (i-P[i])/2==0) //记录极大
        {
            ml = P[i];
            p = i;
        }
    }

    return s.substr((p - ml) / 2, ml - 1); //返回回文串
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        string sm;
        bool suc=0;
        for(int i=0;i<s.length();i++)
        {
            if(i>=s.length()-i-1)
            {
                suc=1;
                break;
            }
            if(s[i]==s[s.length()-i-1])
                sm+=s[i];
            else break;
        }
        if(suc) cout<<s<<'\n';
        else{
            string mid;
            int len=sm.length();
            for(int i=len;i<s.length()-len;i++) mid+=s[i];
            //dbg(mid);
            string pre=Mnc(mid);
            reverse(mid.begin(),mid.end());
            string suf=Mnc(mid);
            string ans;
            //dbg(pre,suf);
            if(pre.length()>suf.length()) ans=pre;
            else ans=suf;
            ans=sm+ans;
            reverse(sm.begin(),sm.end());
            ans+=sm;
            cout<<ans<<'\n';

        }
    }
}