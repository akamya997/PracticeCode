#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	long long n[3],d[3];
	while(T--)
	{
		char ch;
		for(int i=0;i<3;i++)
			scanf("%lld%c%lld",&n[i],&ch,&d[i]);
		long long mother=1;
		mother=d[0]*d[1]*d[2];
		long long son=n[0]*d[1]*d[2]+n[1]*d[0]*d[2]+n[2]*d[0]*d[1];
		long long gcd=__gcd(son,mother);
		mother/=gcd;
		son/=gcd;
		printf("%lld/%lld\n",son,mother);
	}
}
