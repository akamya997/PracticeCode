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
const int maxn=1e3+7;
int cnt[maxn][maxn][2][2];
int pre[maxn][maxn][2][2];
inline int getcnt(int x,int y,int col)
{
    if(x<0||y<0) return 0;
    if(col==0)
        return pre[x][y][0][1]+pre[x][y][1][0];
    return pre[x][y][0][0]+pre[x][y][1][1];
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x,y;
        string c;
        cin>>x>>y>>c;
        cnt[x%k][y%k][(x/k+y/k)&1][c=="W"]++;
    }
    for(int j=0;j<k;j++)
    {
        for(int p=0;p<2;p++)
        {
            for(int q=0;q<2;q++)
            {
                pre[0][j][p][q]=(j?pre[0][j-1][p][q]:0)+cnt[0][j][p][q];
                pre[j][0][p][q]=(j?pre[j-1][0][p][q]:0)+cnt[j][0][p][q];
            }
        }
    }
    for(int i=1;i<k;i++)
    {
        for(int j=1;j<k;j++)
        {
            for(int p=0;p<2;p++)
            {
                for(int q=0;q<2;q++)
                    pre[i][j][p][q]=(-pre[i-1][j-1][p][q]+pre[i][j-1][p][q]+pre[i-1][j][p][q]+cnt[i][j][p][q]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            int cur=getcnt(k-1,k-1,0)-getcnt(i-1,k-1,0)-getcnt(k-1,j-1,0)+2*getcnt(i-1,j-1,0)+getcnt(i-1,k-1,1)-2*getcnt(i-1,j-1,1)+getcnt(k-1,j-1,1);
            cur=max(cur,getcnt(k-1,k-1,1)-getcnt(i-1,k-1,1)-getcnt(k-1,j-1,1)+2*getcnt(i-1,j-1,1)+getcnt(i-1,k-1,0)-2*getcnt(i-1,j-1,0)+getcnt(k-1,j-1,0));
            ans=max(ans,cur);
        }
    }
    print(ans);

}