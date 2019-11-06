#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
char ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,s;
		cin>>n>>s;
		if(n*9<s||(n%2==0&&s%2!=0)||(s==1&&n!=1)) cout<<"-1\n";
		else {
			ans[n]=0;
			for(int i=0;i<n/2;i++)
			{
				if(s/2>=9)
				{
					ans[i]='9';
					ans[n-i-1]='9';
					s-=18;
				}
				else {
					int cur=s/2;
					ans[i]=cur+'0';
					ans[n-i-1]=cur+'0';
					s-=2*cur;
				}
			}
			if(n%2) ans[n/2]=s+'0';
			cout<<ans<<'\n';
		}
	}
}

