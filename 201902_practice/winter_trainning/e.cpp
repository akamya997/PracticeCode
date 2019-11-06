#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
int arr[maxn];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	int mx=0;
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&arr[i]);
		if(arr[i]>m) cnt++;
		mx=max(arr[i],mx);
	}
	if(mx<m)
	{
		if(k) puts("YES");
		else puts("NO");
	}
	else{
		if(cnt>k) puts("NO");
		else puts("YES");
	}

}
