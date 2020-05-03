#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=5e3+7;
int dp[maxn][61][61];
int a[maxn];
int m;
int ten[5005];
int dfs(int u,int sum=0,int rem=0,int limit=1)
{
    if(u==-1)
        return rem==0;
    if(!limit&&dp[u][sum][rem]!=-1) return dp[u][sum][rem];
    int ret=0;
    int up=limit?a[u]:9;
    for(int i=0;i<=up;i++)
        ret=(ret+dfs(u-1,(sum+i)%m,(rem+(ten[u]-sum+m)%m*i)%m,limit&&i==up))%mod;
    //printf("a[u]:%d pos:%d sum:%d rem:%d limit:%d ret:%d\n",a[u],u,sum,rem,(int)limit,ret);
    //dbg(u,sum,rem,limit,ret);
    if(!limit) dp[u][sum][rem]=ret;
    return ret;
}
int solve(string& s)
{
    int pos=0;
    for(int i=s.length()-1;i>=0;i--)
        a[pos++]=s[i]-'0';
    return dfs(pos-1,0,0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        string L,R;
        cin>>L>>R;
        cin>>m;
        ten[0]=1;
        for(int i=0;i<=R.length();i++) memset(dp[i],-1,sizeof(dp[i]));
        for(int i=1;i<=R.length();i++)
            ten[i]=(ll)ten[i-1]*10%m;
        for(int i=L.length()-1;i>=0;i--)
        {
            if(L[i]!='0')
            {
                L[i]--;
                break;
            }
            else L[i]='9';
        }
        string tmp;
        if(L[0]=='0')
        {
            for(int i=1;i<L.length();i++) tmp+=L[i];
            L=tmp;
        }
        int ans=(solve(R)-solve(L)+mod)%mod;
        cout<<ans<<'\n';
    }
}