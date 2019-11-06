#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll quick_pow(ll a, ll n, ll MOD){
    ll ans = 1;
    while (n){
        if (n & 1) ans = ans*a%MOD;
        a = a*a%MOD;
        n >>= 1;
    }
    return ans;
}

int main(){
    int T;
    ll n,p,ans,x;
    scanf("%d",&T);
    while (T--){
        ans=0;
        scanf("%lld%lld",&n,&p);
        for (int i=0;i<min(n,p+1);++i){
            x=quick_pow(2,i,p)+quick_pow(2,n-i-1,p);
            ans=max(ans,x%p);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
