#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+7;
const int mod=1e9+7;
char str[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		int len=strlen(str);
		long long numa=0,numb=0;
		long long ans=0;
		for(int i=len-1;i>=0;i--)
		{
			if(str[i]=='b')
			{
				numb++;
			}
			else if(str[i]=='a')
			{
				ans+=numb;
				ans%=mod;
				numb*=2;
			}
			numb%=mod;
		}
		printf("%lld\n",ans);
	}
}
