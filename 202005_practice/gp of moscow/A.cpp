#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=305;
typedef vector<int> vi;
typedef long long ll;
vi G[maxn];
int f[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    string col;
    cin>>col;
    for(int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back(v);
    }
    for(int i=n-1;i>=0;i--)
    {
        f[i]=0;
        for(auto v:G[i])
        {
            if(col[v]==col[i])
                f[i]=max(f[i],f[v]+1);
            else f[i]=max(f[i],1-f[v]);
        }
        //if(!G[i].size()) f[i]=0;
        //printf("i:%d f[i]:%d\n",i,f[i]);
    }
    const int var=maxn*maxn;
    vector<ll> dp(var*2);
    dp[var]=1;
    for(int i=n-1;i>=0;i--)
    {
        vector<ll> g(maxn*maxn*2);
        for(int j=0;j<maxn*maxn*2;j++)
        {
            g[j]=(g[j]+dp[j])%mod;
            if(col[i]=='W'&&j>=f[i])
                g[j]=(g[j]+dp[j-f[i]])%mod;
            else if(col[i]=='B'&&j+f[i]<var*2)
                g[j]=(g[j]+dp[j+f[i]])%mod;
        }
        dp=g;
    }
    ll ans=0;
    for(int i=var+1;i<var*2;i++)
        ans=(ans+dp[i])%mod;
    cout<<ans<<'\n';
}