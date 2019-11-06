#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
char num[100];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int ans=1;
		int cur=0;
		scanf("%s",num);
		for(int i=2;i<strlen(num);i++)
		{
			cur=cur*10+(num[i]-'0');
			ans*=10;
		}
		if(cur==0) puts("1");
		else{
			while(cur%10==0) ans/=10,cur/=10;
			printf("%d\n",ans/__gcd(ans,cur));
		}
	}
}
