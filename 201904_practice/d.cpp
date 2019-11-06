#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int t;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ans = sqrt(n);
		if(ans*ans == n)
		{
			cout << "infty" << endl;	
		}
		else
		{
			if(n%4 != 0)
			{
				cout << 0 << " " << 0 << endl;
			}
			else
			{
				int num = 0;
				int ans1 = 0;
				int res = sqrt(n/4);
				int res2 = n/4;
				for(int i = 1; i <= res; i++)
				{
					if(res2%i==0)
					{
						ans1 = (ans1 + ((res2/i + i)*1ll)*ll(res2)%mod)%mod;
						num = num + 1;
					}
				}
				cout << num << " " << ans1 << endl;
			}
					
		}		
	}
	return 0;	
}