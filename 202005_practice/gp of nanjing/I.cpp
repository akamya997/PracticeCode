#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int mod=1e9+7;
ll fac[100];
ll inv[100];
ll C[105][105];
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
const int maxn=105;

ll calc(ll n,ll m)
{
    ll ret=0;
    ll invk=inv[m];
    for(int j=0;j<=m;j++)
    {
        if((m-j)&1)
            ret=(ret+mod-invk*C[m][j]%mod*quick(j,n)%mod)%mod;
        else ret=(ret+invk*C[m][j]%mod*quick(j,n)%mod)%mod;
    }
    return ret;
}
int main()
{
    for(int i=0;i<105;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    fac[0]=1;
    inv[0]=1;
    for(int i=1;i<100;i++) fac[i]=fac[i-1]*i%mod,inv[i]=quick(fac[i],mod-2);
    vector<vi> cango(5);
    auto check=[&](vi a,int sz)->bool{
        //if(tot!=S) return false;
        vi st(sz+1);
        int cc=0;
        for(auto u:a)
        {
            int cur=0;
            while(u)
            {
                if(u&1) st[cur]|=1<<cc;
                u>>=1;
                cur++;
            }
            cc++;
        }
        if(!cc) return false;
        map<int,int> ext;
        for(int i=0;i<sz;i++)
        {
            if(st[i]==0||st[i]==(1<<cc)-1||ext.count(st[i])) return false;
            ext[st[i]]=1;
        }
        ext[0]=1;
        ext[(1<<cc)-1]=1;
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(!ext.count(st[i]&st[j])||!ext.count(st[i]|st[j])) return false;
            }
        }
        return true;
    };
    vector<vi> cnt(5,vi(10));
    for(int i=0;i<=4;i++)
    {
        int k=1<<i;
        for(int S=0;S<(1<<k);S++)
        {
            vi cur;
            for(int j=0;j<k;j++)
                if(S>>j&1) cur.push_back(j);
            if(check(cur,i))
                cango[i].push_back(cur.size());
        }
        for(auto u:cango[i]) cnt[i][u]++;
    }
    int T;
    cin>>T;
    while(T--)
    {
        ll n;
        int m;
        cin>>n>>m;
        ll ans=0;
        for(int i=1;i<6;i++)
        {
            if(cnt[m-2][i])
                ans=(ans+calc(n,i)*fac[i]%mod*m*(m-1)%mod*cnt[m-2][i]%mod)%mod;
        }
        //for(auto u:cango[m-2])
        cout<<ans<<'\n';
    }

}