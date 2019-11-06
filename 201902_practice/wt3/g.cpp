#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
long long arr[maxn];
long long tot;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		tot=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			tot+=arr[i];
		}
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			long long lcm=1;
			long long sum=0;
			for(int j=i;j<n;j++)
			{
				lcm=lcm/__gcd(lcm,arr[j])*arr[j];
				sum+=arr[j];
				if(sum%lcm==0) ans++;
				if(lcm>tot) break;
			}
		}
		cout<<ans<<endl;
	}
}
