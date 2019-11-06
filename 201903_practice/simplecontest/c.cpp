#include<bits/stdc++.h>
using namespace std;
long long ans[]={0,4,10,20,35,56,83,116,155,198,244,292,341,390};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		if(n<=13)
			cout<<ans[n]<<endl;
		else{
			cout<<ans[13]+49*(n-13)<<endl;
		}
	}
}
