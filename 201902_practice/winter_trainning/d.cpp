#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,s;
	cin>>n>>a>>b>>s;
	if(n<=2)
	{
		if(n==1)
		{
			if(s==a&&s==b) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			cout<<((s==a+b)?"YES":"NO")<<endl;
		}
	}
	else{
		s-=a;
		s-=b;
		double avg=(double) s/(n-2);
		if(avg>=a&&avg<=b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
