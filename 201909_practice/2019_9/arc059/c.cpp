#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0x3f3f3f3f;
	for(int t=-100;t<=100;t++)
	{
		int cur=0;
		for(int i=0;i<n;i++)
			cur+=(a[i]-t)*(a[i]-t);
		ans=min(ans,cur);
	}
	cout<<ans<<endl;
}
