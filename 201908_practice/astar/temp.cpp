#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;

ll phi(ll x)
{
    ll res=x,a=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}


ll powmod(ll a,ll n,ll mod)
{
	ll ans=1;
	while(n)
	{
		if(n&1)
			ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}

ll mypow(ll a,ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)
			ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}

ll getans(ll a,ll n,ll m)
{
	if(m==1)	return 0;
	if(n==1)	return a%m;
	ll temp=phi(m);
	if(__gcd(a,m)==1)	return powmod(a,n%temp,m);
	if(n<temp)	return powmod(a,n,m);
	return powmod(a,getans(a,n-1,temp)+temp,m);
}

void dbg()
{
	ll mod=1e9+7;
	cout<<phi(mod)<<endl;
	ll a,n;
	while(cin>>a>>n)
		cout<<getans(a,n,mod)<<endl;
}

int main()
{
//	dbg();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll a,b;
		scanf("%lld%lld%lld",&a,&b,&mod);
		if(b==0)
		{
			printf("%lld\n",1%mod);
			continue;
		}
		printf("%lld\n",getans(a,b,mod));
	}
}

