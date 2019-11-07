#include<bits/stdc++.h>
using namespace std;
int a[100];
long long solve(long long up,__int128 cur,long long k)
{
	long long ret=0;
	ret=up/cur-up/(cur*k);
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		long long l,r,k,m;
		cin>>l>>r>>k>>m;
		__int128 base=1;
		for(int i=0;i<m;i++)
		{
			base*=k;
			if(base>r) break;
		}
		if(base>r)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<solve(r,base,k)-solve(l-1,base,k)<<endl;
	}

}
