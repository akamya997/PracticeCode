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
const int mod=1e9+7;
const int maxn=1005;
int C[maxn][maxn];
int fac[maxn],invfac[maxn];
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
ll inv(ll a){return quick(a,mod-2);}
void init()
{
    fac[0]=1;
    invfac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]=1LL*fac[i-1]*i%mod;
        invfac[i]=inv(fac[i]);
    }
    for(int i=0;i<maxn;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
string s;
inline int comb(int n,int m)
{
    if(m>n) return 0;
    return C[n][m];
}
vi apos;
int ca=0;
int n,k;
vi f;
int solve()
{
    if(!f.size()) return 1;
    int pr=f.size()-1,pb=f.size()-1,pc=f.size()-1,pd=f.size()-1;
    vi len(f.size());
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='r')
        {
            if(pr>=0)
            {
                len[pr]++;
                pr--;
            }
            else{
                while(pc>=0&&len[pc]==f[pc]) pc--;
                if(pc>=0&&len[pc]>1) len[pc]++;
            }
        }
        else{
            bool use=0;
            if(pb>=0)
            {
                while(pb>=0&&len[pb]==f[pb]) pb--;
                if(pb>=0&&len[pb])
                {
                    len[pb]++;
                    pb--;
                    use=1;
                }
            }
            if(!use)
            {
                while(pd>=0&&len[pd]==f[pd]) pd--;
                if(pd>=0&&len[pd]>1) len[pd]++;
            }
        }
    }
    for(int i=0;i<f.size();i++) if(f[i]!=len[i]) return 0;
    int L=f.size()-1;
    int cnt=f.size()+1;
    for(int i=0;i<f.size();i++)
    {
        if(f[i]==1) 
        {
            L++;
            cnt++;
        }
        else {
            L+=2*f[i]-3;
            cnt+=2*f[i]-1;
        }
    }
    //dbg(f);
    int ret=comb(n-L+cnt-1,cnt-1);
    //dbg(ret,L,cnt);
    return ret;
}
int dfs(int r,int mx,int cc,int len=0)
{
    if(len+(int)f.size()-1>n) return 0;
    int ret=1LL*solve()*invfac[cc]%mod*fac[f.size()]%mod;
    if(r==0) return ret;
    if(f.size()>=ca) return ret;
    for(int i=mx;i<=r;i++)
    {
        f.push_back(i);
        int cur=dfs(r-i,i,(i==mx)?cc+1:1,i==1?len+1:len+2*i-3);
        if(i!=mx) cur=1LL*cur*invfac[cc]%mod;
        ret=(ret+cur)%mod;
        f.pop_back();
    }
    return ret;
}
int main()
{
    init();
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<k;i++) 
    {
        ca+=s[i]=='r';
        if(s[i]=='r') apos.push_back(i);
    }
    print(dfs(k,1,0));
}