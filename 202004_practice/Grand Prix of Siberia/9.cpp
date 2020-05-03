#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
typedef long long ll;
vector<int> prime;
bool isp[maxn];
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(!isp[i]) prime.push_back(i);
        for(auto &p:prime)
        {
            if(p*i>=maxn) break;
            isp[i*p]=1;
            if(i%p==0) break;
        }
    }
}
ll quick(ll a,ll b,int mod)
{
    ll ret=1;
    //printf("ksm:%lld %lld %d\n",a,b,mod);
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    init();
    int q,n;
    cin>>q>>n;
    vector<int> ans;
    for(int k=1;k*n<10000000;k++)
    {
        if(isp[k*n+1]) continue;
        int cur=k*n;
        //printf("%d,%lld\n",cur,quick(q,n,cur+1));
        if(quick(q,n,cur+1)!=1) continue;
        bool suc=0;
        for(int i=1;i*i<=cur;i++)
        {
            if(i>=n) break;
            if(cur%i==0)
            {
                if(quick(q,i,cur+1)==1)
                {
                    suc=1;
                    break;
                }
                if(cur/i<n)
                {
                    if(quick(q,cur/i,cur+1)==1)
                    {
                        suc=1;
                        break;
                    }
                }
            }
        }
        if(!suc) ans.push_back(k*n+1);
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==(ans.size()-1)];

}