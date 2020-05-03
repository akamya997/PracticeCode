#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll a,b;
        scanf("%lld.%lld",&a,&b);
        a=b;
        b=1e18;
        bool suc=0;
        for(int i=0;i<=10;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                ll g=__gcd(a-i,b-j);
                if((b-j)/g<=1000000000)
                {
                    printf("%lld %lld\n",(a-i)/g,(b-j)/g);
                    suc=1;
                }
                if(suc) break;
            }
            if(suc) break;
        }
        assert(suc);
    }
}