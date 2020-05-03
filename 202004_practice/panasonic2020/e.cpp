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
const int maxn=2e3+7;
bool ok[3][3][maxn];
int main()
{
    string s[3];
    for(int i=0;i<3;i++) cin>>s[i];
    vi id={0,1,2};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j) continue;
            for(int ii=0;ii<s[i].length();ii++)
            {
                bool yes=1;
                for(int jj=0;ii+jj<s[i].length()&&jj<s[j].length();jj++)
                {
                    if(s[i][ii+jj]==s[j][jj]||s[i][ii+jj]=='?'||s[j][jj]=='?');
                    else{
                        yes=0;
                        break;
                    }
                }
                if(yes) ok[i][j][ii]=1;
                //dbg(i,j,ii,ok[i][j][ii]);
            }
            ok[i][j][s[i].length()]=1;
        }
    }
    int ans=0x3f3f3f3f;
    do{
        //dbg(id);
        for(int i=0;i<=s[id[0]].length();i++)
        {
            if(ok[id[0]][id[1]][i])
            {
                int same=min(s[id[0]].length()-i,s[id[1]].length());
                int len=s[id[0]].length()+s[id[1]].length()-same;
                for(int j=0;j<=len;j++)
                {
                    //dbg(i,j,ok[id[0]][id[2]][i]);
                    if(j<s[id[0]].length()&&!ok[id[0]][id[2]][j]) continue;
                    if(j>=i)
                    {
                        int pos=j-i;
                        if(!ok[id[1]][id[2]][pos]) continue;
                    }
                    else{
                        if(j+s[id[2]].length()>i)
                        {
                            int pos=i-j;
                            if(!ok[id[2]][id[1]][pos]) continue;
                        }
                    }
                    int s2=min<int>(len-j,s[id[2]].length());
                    //dbg(i,j,same,s2);
                    ans=min<int>(ans,s[0].length()+s[1].length()+s[2].length()-same-s2);
                }
            }
        }
    }while(next_permutation(id.begin(),id.end()));
    
    print(ans);
}