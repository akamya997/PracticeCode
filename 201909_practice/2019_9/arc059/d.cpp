#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
char s[maxn];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(i<n&&s[i]==s[i+1])
		{
			printf("%d %d\n",i,i+1);
			return 0;
		}
		if(i<n-1&&s[i]==s[i+2])
		{
			printf("%d %d\n",i,i+2);
			return 0;
		}
	}
	printf("-1 -1\n");
}
