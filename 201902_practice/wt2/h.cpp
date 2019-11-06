#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int var=(1+n)*n/2;
		if(k>=var)
		{
			if((k-var)%n==0) printf("%d\n",(k-var)/n+n+1);
			else puts("Too drunk to count");
		}
		else{
			puts("Too drunk to count");
		}
	}
}
