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
const int ptr=6;
int prezero[maxn];
ll base[ptr][maxn];
ll mod[ptr]={1000000007,998244353,1000000009,998244353,1000000009,998244353};
ll preodd[ptr][maxn],preeven[ptr][maxn];
int n;
string t;

void init()
{
    for(int i=1;i<=n;i++)
    {
        prezero[i]=prezero[i-1]+(t[i-1]=='0');
        if(t[i-1]=='0')
        {
            if(i&1)
            {
                for(int j=0;j<ptr;j++)
                {
                    preodd[j][i]=(preodd[j][i-1]*base[j][1]%mod[j]+1)%mod[j];
                    preeven[j][i]=preeven[j][i-1]*base[j][1]%mod[j];
                }
            }
            else{
                for(int j=0;j<ptr;j++)
                {
                    preodd[j][i]=preodd[j][i-1]*base[j][1]%mod[j];
                    preeven[j][i]=(preeven[j][i-1]*base[j][1]%mod[j]+1)%mod[j];
                }
            }
        }
        else{
            for(int j=0;j<6;j++)
            {
                preodd[j][i]=preodd[j][i-1];
                preeven[j][i]=preeven[j][i-1];
            }
        }
    }
}
vc<ll> getval(int l,int r)
{
    int zero=prezero[r]-prezero[l-1];
    vc<ll> ret(ptr);
    for(int j=0;j<6;j++)
    {
        if(l&1) ret[j]=(preodd[j][r]-preodd[j][l-1]*base[j][zero]%mod[j]+mod[j])%mod[j];
        else ret[j]=(preeven[j][r]-preeven[j][l-1]*base[j][zero]%mod[j]+mod[j])%mod[j];
    }
    return ret;
}
int main()
{
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<ptr;i++)
    {
        base[i][0]=1;
        base[i][1]=rand()%10000;
        for(int j=2;j<maxn;j++)
            base[i][j]=base[i][j-1]*base[i][1]%mod[i];
    }
    cin>>n;
    cin>>t;
    init();
    int q;
    cin>>q;
    while(q--)
    {
        int l1,l2,len;
        cin>>l1>>l2>>len;
        if(prezero[l2+len-1]-prezero[l2-1]!=prezero[l1+len-1]-prezero[l1-1])
            cout<<"No\n";
        else{
            if(getval(l1,l1+len-1)==getval(l2,l2+len-1)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}