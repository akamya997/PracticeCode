#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<b&&a<c)
		{
			cout<<"First\n";
		}
		else if(b<a&&b<c)
		{
			cout<<"Second\n";
		}
		else cout<<"Third\n";
	}
}
