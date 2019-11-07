#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int arr[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	long long sqrsum=0;
	long long sum=0;
	for(int i=0;i<m;i++) 
	{
		sqrsum+=arr[i]*arr[i];
		sum+=arr[i];
	}
	long long ans=1LL*m*sqrsum-sum*sum;
	for(int l=1,r=m;r<n;l++,r++)
	{
		sum+=arr[r]-arr[l-1];
		sqrsum-=arr[l-1]*arr[l-1];
		sqrsum+=arr[r]*arr[r];
		ans=min(ans,1LL*m*sqrsum-sum*sum);
	}
	cout<<ans<<endl;

}
