#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int main()
{
	ll n;
	while(cin>>n)
	{
		ll ans=0;
		for(int i=0;;i++)
		{
			ll tmp=(ll)pow(n,1.0/prime[i]);
			if(tmp<2) break;
			ans+=tmp-1;
			for(int j=i+1;;j++)
			{
				tmp=(ll)(pow(n,1.0/(prime[i]*prime[j])));
				if(tmp<2) break;
				ans-=tmp-1;
				for(int k=j+1;;k++)
				{
					tmp=(ll)(n,1.0/(prime[i]*prime[j]*prime[k]));
					if(tmp<2) break;
					ans+=tmp-1;
				}
			}
		}
		cout<<ans+1<<endl;
	}
}
