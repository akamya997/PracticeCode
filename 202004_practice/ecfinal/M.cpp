#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const int maxn=1e5+7;
int vis[maxn];
int sld[maxn];
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    memset(vis,0,sizeof(vis));
    ans=a[1];
    for(int i=2;i<=n;i++)
    {
        if(vis[i]) continue;
        ll cur=i;
        vi st;
        while(cur<=n)
        {
            assert(!vis[cur]);
            vis[cur]=1;
            st.push_back(cur);
            cur*=i;
        }
        vector<vi> dp(st.size(),vi(1<<(st.size())));
        auto check=[&](int x,int y)
        {
            ll cc=x;
            while(cc<y)
                cc*=x;
            return cc==y;
        };
        for(int i=0;i<st.size();i++)
        {
            for(int S=0;S<(1<<i);S++)
            {
                ll cost=a[st[i]];
                int cnt=0;
                for(int j=0;j<i;j++)
                {
                    if(S>>j&1&&check(st[j],st[i])) cnt++;
                }
                cost-=1LL*cnt*b[st[i]];
                dp[i][S]=i?dp[i-1][S]:0;
                dp[i][S|(1<<i)]=(i?dp[i-1][S]:0)+cost;
            }
        }
        ll ccc=-0x3f3f3f3f3f3f3f3f;
        for(int S=0;S<(1<<st.size());S++)
            ccc=max(ccc,dp[st.size()-1][S]);
        ans+=ccc;
    }
    cout<<ans<<'\n';
}